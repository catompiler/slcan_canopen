#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
// slcan.
#include "slcan/slcan.h"
#include "slcan/slcan_slave.h"
// CANopen.
#include "CANopenNode/CANopen.h"
#include "OD.h"


// slcan.
#ifdef __linux
// socat -d -d pty,rawer,echo=0,link=/tmp/ttyV0,perm=0777 pty,rawer,echo=0,link=/tmp/ttyV1,perm=0777
#define SLAVE_TTY "/tmp/ttyV1"
#else
// cygwin + com0com
#define SLAVE_TTY "/dev/ttyS21"
#endif

static slcan_t slave_slcan;
static slcan_slave_t slave;

// CANopen.
CO_t* co_ptr = NULL;


// slcan.
static int init_slcan_slave(slcan_slave_t* scs, slcan_t* sc, slcan_slave_callbacks_t* scb, const char* serial_port_name)
{
    if(slcan_init(sc) != 0){
        printf("Cann't init slcan!\n");
        return -1;
    }

    if(slcan_open(sc, serial_port_name) != 0){
        printf("Cann't open serial port: %s\n", serial_port_name);
        return -1;
    }

    slcan_port_conf_t port_conf;
    slcan_get_default_port_config(&port_conf);

    port_conf.baud = SLCAN_PORT_BAUD_115200;

    if(slcan_configure(sc, &port_conf) != 0){
        printf("Error configuring serial port!\n");
        slcan_deinit(sc);
        return -1;
    }

    if(slcan_slave_init(scs, sc, scb) != 0){
        printf("Error init slcan slave!\n");
        slcan_deinit(sc);
        return -1;
    }

    return 0;
}


// CANopen.

static int create_CO(CO_t** co)
{
    if(co == NULL) return -1;

    CO_t* co_res = CO_new(NULL, NULL);

    //printf("co: 0x%x\n", (int)(long)co);

    if(co_res == NULL) return -1;

    *co = co_res;

    return 0;
}

static CO_ReturnError_t init_CO(CO_t* co, slcan_slave_t* scs)
{
    if(co == NULL) return CO_ERROR_ILLEGAL_ARGUMENT;
    if(scs == NULL) return CO_ERROR_ILLEGAL_ARGUMENT;

    CO_ReturnError_t coerr = CO_ERROR_NO;

    coerr = CO_CANinit(co, scs, 125);
    if(coerr != CO_ERROR_NO) return coerr;

    uint32_t errInfo = 0;

    coerr = CO_CANopenInit(co,
            NULL, NULL, OD, NULL, CO_CONFIG_NMT, FIRST_HB_TIME_MS, SDO_SERVER_TIMEOUT_MS, SDO_CLIENT_TIMEOUT_MS, SDO_CLIENT_BLOCK_TRANSFER, NODE_ID, &errInfo);

    if(coerr != CO_ERROR_NO){
        printf("CANopen init fail! (err: %d err_info: %d)\n", (int)coerr, (int)errInfo);
        return coerr;
    }

    coerr = CO_CANopenInitPDO(co, co->em, OD, NODE_ID, &errInfo);

    if(coerr != CO_ERROR_NO){
        printf("CANopen init PDO fail! (err: %d err_info: %d)\n", (int)coerr, (int)errInfo);
        return coerr;
    }

    /* Разрешение работы */
    CO_CANsetNormalMode(co->CANmodule);

    return CO_ERROR_NO;
}

static void deinit_CO(CO_t* co)
{
    if(co == NULL || co->CANmodule == NULL || co->CANmodule->CANptr == NULL) return;
    CO_CANsetConfigurationMode(co->CANmodule->CANptr);
    CO_delete(co);
}


static void main_poll(slcan_slave_t* slave, CO_t* co)
{
    int max_polls = 1000;

    CO_NMT_reset_cmd_t reset_cmd = CO_NMT_NO_COMMAND;

    //slcan_err_t err = E_SLCAN_NO_ERROR;

    struct timespec ts;
    ts.tv_sec = 0; ts.tv_nsec = 1000000; // 1 ms.
    while(--max_polls != 0){
        /*err = */slcan_slave_poll(slave);

        //if(err == E_SLCAN_NO_ERROR){
            CO_CANinterrupt(co->CANmodule);
        //}

        reset_cmd = CO_process(co, false, 1000, NULL);

        if(reset_cmd == CO_RESET_NOT){
            //printf("CO_NMT_NO_COMMAND");
        }else if(reset_cmd == CO_RESET_COMM){
            printf("CO_RESET_COMM");
        }else if(reset_cmd == CO_RESET_APP){
            printf("CO_RESET_APP");
        }else if(reset_cmd == CO_RESET_QUIT){
            printf("CO_RESET_QUIT");
        }

        nanosleep(&ts, NULL);
    }
}


int main(int argc, char* argv[])
{

    const char* slave_serial_port_name = SLAVE_TTY;

    int res;
    CO_ReturnError_t coerr;

    res = init_slcan_slave(&slave, &slave_slcan, NULL, slave_serial_port_name);
    if(res == -1){
        printf("Error init slave slcan!\n");
        return -1;
    }

    CO_t* co = NULL;

    res = create_CO(&co);
    if(res == -1 || co == NULL){
        printf("Error create CO!\n");

        slcan_slave_deinit(&slave);
        slcan_close(&slave_slcan);
        slcan_deinit(&slave_slcan);
        return -1;
    }

    coerr = init_CO(co, &slave);
    if(coerr != CO_ERROR_NO){
        printf("Error init CO (%d)!\n", (int)coerr);

        slcan_slave_deinit(&slave);
        slcan_close(&slave_slcan);
        slcan_deinit(&slave_slcan);
        return -1;
    }


    printf("Polling...\n");

    main_poll(&slave, co);

    printf("Done.\n");

    deinit_CO(co);

    slcan_slave_deinit(&slave);
    slcan_close(&slave_slcan);
    slcan_deinit(&slave_slcan);

    return 0;
}
