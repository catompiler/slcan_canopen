#ifndef REG_DATA_H
#define REG_DATA_H

#include <stdint.h>


// THIS FILE IS GENERATED AUTOMATICALLY!
// DO NOT EDIT THIS FILE!


// user code begin

// user code end

struct _S_reg_data {

struct _S_deviceType {
    uint32_t value; /*  */
} deviceType;

struct _S_errorRegister {
    uint8_t value; /*  */
} errorRegister;

struct _S_pre_definedErrorField {
    uint8_t numberOfErrors; /* Number of sub-entries */
    uint32_t pre_definedErrorField[16]; /*  */
} pre_definedErrorField;

struct _S_COB_ID_SYNCMessage {
    uint32_t value; /*  */
} COB_ID_SYNCMessage;

struct _S_communicationCyclePeriod {
    uint32_t value; /*  */
} communicationCyclePeriod;

struct _S_synchronousWindowLength {
    uint32_t value; /*  */
} synchronousWindowLength;

struct _S_storeParameters {
    uint8_t highestSub_indexSupported; /* Number of sub-entries */
    uint32_t storeParameters[4]; /*  */
} storeParameters;

struct _S_restoreDefaultParameters {
    uint8_t highestSub_indexSupported; /* Number of sub-entries */
    uint32_t restoreDefaultParameters[4]; /*  */
} restoreDefaultParameters;

struct _S_COB_IDTimeStampObject {
    uint32_t value; /*  */
} COB_IDTimeStampObject;

struct _S_COB_ID_EMCY {
    uint32_t value; /*  */
} COB_ID_EMCY;

struct _S_inhibitTimeEMCY {
    uint16_t value; /*  */
} inhibitTimeEMCY;

struct _S_consumerHeartbeatTime {
    uint8_t highestSub_indexSupported; /* Number of sub-entries */
    uint32_t consumerHeartbeatTime[8]; /*  */
} consumerHeartbeatTime;

struct _S_producerHeartbeatTime {
    uint16_t value; /*  */
} producerHeartbeatTime;

struct _S_identity {
    uint8_t highestSub_indexSupported; /* Number of sub-entries */
    uint32_t vendor_id; /*  */
    uint32_t productCode; /*  */
    uint32_t revisionNumber; /*  */
    uint32_t serialNumber; /*  */
} identity;

struct _S_synchronousCounterOverflowValue {
    uint8_t value; /*  */
} synchronousCounterOverflowValue;

struct _S_SDOServerParameter {
    uint8_t highestSub_indexSupported; /* Number of sub-entries */
    uint32_t COB_IDClientToServer_rx_; /*  */
    uint32_t COB_IDServerToClient_tx_; /*  */
} SDOServerParameter;

struct _S_SDOClientParameter {
    uint8_t count; /* Number of sub-entries */
    uint32_t COB_IDClientToServer_tx_; /*  */
    uint32_t COB_IDServerToClient_rx_; /*  */
    uint8_t node_idOfTheSDOServer; /*  */
} SDOClientParameter;

struct _S_RPDOCommunicationParameter {
    uint8_t highestSub_indexSupported; /* Number of sub-entries */
    uint32_t COB_IDUsedByRPDO; /*  */
    uint8_t transmissionType; /*  */
    uint16_t eventTimer; /*  */
} RPDOCommunicationParameter;

struct _S_RPDOCommunicationParameter_1401 {
    uint8_t highestSub_indexSupported; /* Number of sub-entries */
    uint32_t COB_IDUsedByRPDO; /*  */
    uint8_t transmissionType; /*  */
    uint16_t eventTimer; /*  */
} RPDOCommunicationParameter_1401;

struct _S_RPDOCommunicationParameter_1402 {
    uint8_t highestSub_indexSupported; /* Number of sub-entries */
    uint32_t COB_IDUsedByRPDO; /*  */
    uint8_t transmissionType; /*  */
    uint16_t eventTimer; /*  */
} RPDOCommunicationParameter_1402;

struct _S_RPDOCommunicationParameter_1403 {
    uint8_t highestSub_indexSupported; /* Number of sub-entries */
    uint32_t COB_IDUsedByRPDO; /*  */
    uint8_t transmissionType; /*  */
    uint16_t eventTimer; /*  */
} RPDOCommunicationParameter_1403;

struct _S_RPDOMappingParameter {
    uint8_t numberOfMappedApplicationObjectsInPDO; /* Number of sub-entries */
    uint32_t applicationObject1; /*  */
    uint32_t applicationObject2; /*  */
    uint32_t applicationObject3; /*  */
    uint32_t applicationObject4; /*  */
    uint32_t applicationObject5; /*  */
    uint32_t applicationObject6; /*  */
    uint32_t applicationObject7; /*  */
    uint32_t applicationObject8; /*  */
} RPDOMappingParameter;

struct _S_RPDOMappingParameter_1601 {
    uint8_t numberOfMappedApplicationObjectsInPDO; /* Number of sub-entries */
    uint32_t applicationObject1; /*  */
    uint32_t applicationObject2; /*  */
    uint32_t applicationObject3; /*  */
    uint32_t applicationObject4; /*  */
    uint32_t applicationObject5; /*  */
    uint32_t applicationObject6; /*  */
    uint32_t applicationObject7; /*  */
    uint32_t applicationObject8; /*  */
} RPDOMappingParameter_1601;

struct _S_RPDOMappingParameter_1602 {
    uint8_t numberOfMappedApplicationObjectsInPDO; /* Number of sub-entries */
    uint32_t applicationObject1; /*  */
    uint32_t applicationObject2; /*  */
    uint32_t applicationObject3; /*  */
    uint32_t applicationObject4; /*  */
    uint32_t applicationObject5; /*  */
    uint32_t applicationObject6; /*  */
    uint32_t applicationObject7; /*  */
    uint32_t applicationObject8; /*  */
} RPDOMappingParameter_1602;

struct _S_RPDOMappingParameter_1603 {
    uint8_t numberOfMappedApplicationObjectsInPDO; /* Number of sub-entries */
    uint32_t applicationObject1; /*  */
    uint32_t applicationObject2; /*  */
    uint32_t applicationObject3; /*  */
    uint32_t applicationObject4; /*  */
    uint32_t applicationObject5; /*  */
    uint32_t applicationObject6; /*  */
    uint32_t applicationObject7; /*  */
    uint32_t applicationObject8; /*  */
} RPDOMappingParameter_1603;

struct _S_TPDOCommunicationParameter {
    uint8_t highestSub_indexSupported; /* Number of sub-entries */
    uint32_t COB_IDUsedByTPDO; /*  */
    uint8_t transmissionType; /*  */
    uint16_t inhibitTime; /*  */
    uint16_t eventTimer; /*  */
    uint8_t SYNCStartValue; /*  */
} TPDOCommunicationParameter;

struct _S_TPDOCommunicationParameter_1801 {
    uint8_t highestSub_indexSupported; /* Number of sub-entries */
    uint32_t COB_IDUsedByTPDO; /*  */
    uint8_t transmissionType; /*  */
    uint16_t inhibitTime; /*  */
    uint16_t eventTimer; /*  */
    uint8_t SYNCStartValue; /*  */
} TPDOCommunicationParameter_1801;

struct _S_TPDOCommunicationParameter_1802 {
    uint8_t highestSub_indexSupported; /* Number of sub-entries */
    uint32_t COB_IDUsedByTPDO; /*  */
    uint8_t transmissionType; /*  */
    uint16_t inhibitTime; /*  */
    uint16_t eventTimer; /*  */
    uint8_t SYNCStartValue; /*  */
} TPDOCommunicationParameter_1802;

struct _S_TPDOCommunicationParameter_1803 {
    uint8_t highestSub_indexSupported; /* Number of sub-entries */
    uint32_t COB_IDUsedByTPDO; /*  */
    uint8_t transmissionType; /*  */
    uint16_t inhibitTime; /*  */
    uint16_t eventTimer; /*  */
    uint8_t SYNCStartValue; /*  */
} TPDOCommunicationParameter_1803;

struct _S_TPDOMappingParameter {
    uint8_t numberOfMappedApplicationObjectsInPDO; /* Number of sub-entries */
    uint32_t applicationObject1; /*  */
    uint32_t applicationObject2; /*  */
    uint32_t applicationObject3; /*  */
    uint32_t applicationObject4; /*  */
    uint32_t applicationObject5; /*  */
    uint32_t applicationObject6; /*  */
    uint32_t applicationObject7; /*  */
    uint32_t applicationObject8; /*  */
} TPDOMappingParameter;

struct _S_TPDOMappingParameter_1a01 {
    uint8_t numberOfMappedApplicationObjectsInPDO; /* Number of sub-entries */
    uint32_t applicationObject1; /*  */
    uint32_t applicationObject2; /*  */
    uint32_t applicationObject3; /*  */
    uint32_t applicationObject4; /*  */
    uint32_t applicationObject5; /*  */
    uint32_t applicationObject6; /*  */
    uint32_t applicationObject7; /*  */
    uint32_t applicationObject8; /*  */
} TPDOMappingParameter_1a01;

struct _S_TPDOMappingParameter_1a02 {
    uint8_t numberOfMappedApplicationObjectsInPDO; /* Number of sub-entries */
    uint32_t applicationObject1; /*  */
    uint32_t applicationObject2; /*  */
    uint32_t applicationObject3; /*  */
    uint32_t applicationObject4; /*  */
    uint32_t applicationObject5; /*  */
    uint32_t applicationObject6; /*  */
    uint32_t applicationObject7; /*  */
    uint32_t applicationObject8; /*  */
} TPDOMappingParameter_1a02;

struct _S_TPDOMappingParameter_1a03 {
    uint8_t numberOfMappedApplicationObjectsInPDO; /* Number of sub-entries */
    uint32_t applicationObject1; /*  */
    uint32_t applicationObject2; /*  */
    uint32_t applicationObject3; /*  */
    uint32_t applicationObject4; /*  */
    uint32_t applicationObject5; /*  */
    uint32_t applicationObject6; /*  */
    uint32_t applicationObject7; /*  */
    uint32_t applicationObject8; /*  */
} TPDOMappingParameter_1a03;

struct _S_counter {
    uint32_t value; /*  */
} counter;

struct _S_quit {
    uint32_t value; /*  */
} quit;

struct _S_values {
    uint8_t count; /* Number of sub-entries */
    int32_t values[2]; /*  */
} values;

};
extern struct _S_reg_data reg_data;


#endif /* REG_DATA_H */
