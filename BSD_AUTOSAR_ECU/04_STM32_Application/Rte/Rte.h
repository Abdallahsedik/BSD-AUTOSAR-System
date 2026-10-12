#ifndef RTE_H_
#define RTE_H_

/* ========================================================================== */
/* 1. AUTOSAR Standard Types & Return Codes                                   */
/* ========================================================================== */
#include "Std_Types.h"

/* RTE Status Codes (used for Implicit/Explicit reads) */
typedef uint8 Rte_StatusType;

#define RTE_E_OK               (0x00U)  /* Data read/write successful           */
#define RTE_E_NEVER_RECEIVED   (0x01U)  /* No CAN frame received yet            */
#define RTE_E_LOST_DATA        (0x40U)  /* CAN frame timeout / overwritten      */
#define RTE_E_LIMIT            (0x82U)  /* Data out of bounds                   */

/* ========================================================================== */
/* 2. AUTOSAR Application Data Types                                          */
/* ========================================================================== */
#include "Rte_Type.h"  /* Contains BSDState_T, RadarStatus_T, Distance_m_T, etc. */

/* ========================================================================== */
/* 3. SWC RTE Interfaces                                                      */
/* ========================================================================== */

#include "RadarInput_swc/Rte_RadarInput.h"
#include "VehicleSignal_swc/Rte_VehicleSignals.h"
#include "Algorithm_swc/Rte_Algorithm.h"
#include "Warning_swc/Rte_Warning.h"
#include "Diagnostic_swc/Rte_Diagnostic.h"

#endif /* RTE_H_ */
