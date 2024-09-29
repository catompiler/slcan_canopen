cmake_minimum_required(VERSION "3.10")
set(TARGET_NAME "slcan_canopen")
project(${TARGET_NAME})
#include(CMakePrintHelpers)

list(APPEND TARGET_SOURCES
    main.c
    CO_driver_slcan_slave.c
    OD.c
)
    
list(APPEND CANOPENNODE_SOURCES
    CANopenNode/301/CO_Emergency.c
    CANopenNode/301/CO_fifo.c
    CANopenNode/301/CO_HBconsumer.c
    CANopenNode/301/CO_NMT_Heartbeat.c
    CANopenNode/301/CO_Node_Guarding.c
    CANopenNode/301/CO_ODinterface.c
    CANopenNode/301/CO_PDO.c
    CANopenNode/301/CO_SDOclient.c
    CANopenNode/301/CO_SDOserver.c
    CANopenNode/301/CO_SYNC.c
    CANopenNode/301/CO_TIME.c
    CANopenNode/301/crc16-ccitt.c
    CANopenNode/303/CO_LEDs.c
    CANopenNode/304/CO_GFC.c
    CANopenNode/304/CO_SRDO.c
    CANopenNode/305/CO_LSSmaster.c
    CANopenNode/305/CO_LSSslave.c
    CANopenNode/309/CO_gateway_ascii.c
    CANopenNode/CANopen.c
    CANopenNode/extra/CO_trace.c
    CANopenNode/storage/CO_storage.c
    CANopenNode/storage/CO_storageEeprom.c
)

list(APPEND SLCAN_SOURCES
    slcan/slcan.c
    slcan/slcan_can_ext_fifo.c
    slcan/slcan_can_fifo.c
    slcan/slcan_can_msg.c
    slcan/slcan_cmd_buf.c
    slcan/slcan_cmd.c
    slcan/slcan_io_fifo.c
    slcan/slcan_master.c
    slcan/slcan_port.c
    slcan/slcan_resp_out_fifo.c
    slcan/slcan_slave.c
)

#cmake_print_variables(TARGET_SOURCES)
#cmake_print_variables(TARGET_NAME)


add_executable(${TARGET_NAME})
target_compile_features(${TARGET_NAME} PUBLIC c_std_11)
target_include_directories(${TARGET_NAME} PRIVATE ".")
target_include_directories(${TARGET_NAME} PRIVATE "CANopenNode")
target_include_directories(${TARGET_NAME} PRIVATE "slcan")
target_sources(${TARGET_NAME} PRIVATE ${TARGET_SOURCES} ${CANOPENNODE_SOURCES} ${SLCAN_SOURCES})
#add_subdirectory("CANopenNode")
#add_subdirectory("slcan")
