#ifndef COMSTACK_CFG_H
/* !LINKSTO Base.ASR403.COMTYPE016,1 */
#define COMSTACK_CFG_H

/**
 * \file
 *
 * \brief AUTOSAR Base
 *
 * This file contains the implementation of the AUTOSAR
 * module Base.
 *
 * \version 5.6.1
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2025 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/* !LINKSTO Base.SWS_Comtype_00015,1, Base.ASR403.COMTYPE029,1 */

/*==================[macros]=================================================*/

/*------------------[Size of Autosar Comstack Types]-------------------------*/

#if (defined TS_SIZE_PduIdType)
#error TS_SIZE_PduIdType already defined
#endif
/** \brief Size of AUTOSAR standard type PduIdType
 *
 * this value is fixed to 2U (see deviations of EcuC)
 */
#define TS_SIZE_PduIdType 2U

#if (defined TS_SIZE_PduLengthType)
#error TS_SIZE_PduLengthType already defined
#endif
/** \brief Size of AUTOSAR standard type PduLengthType
 *
 * this value depends on EcuC parameter PduLengthType (see deviations of EcuC)
 */
#define TS_SIZE_PduLengthType 2U

/*==================[type definitions]======================================*/

/* !LINKSTO Base.SWS_Comtype_00030,1,Base.SWS_COMTYPE_00005,1,Base.SWS_Comtype_00006,1,Base.SWS_Comtype_00007,1,Base.SWS_Comtype_00014,1, Base.SWS_Comtype_00017,1,Base.ASR403.COMTYPE029,1 */
/** \brief Type for a unique identifier for a PDU
 *
 * this type is fixed to uint16 (see deviations of EcuC)
 * - range: 0 .. PduIdmax
 */
typedef uint16 PduIdType;

/* !LINKSTO Base.SWS_Comtype_00030,1,Base.SWS_COMTYPE_00008,1,Base.SWS_Comtype_00010,1,Base.ASR403.COMTYPE029,1 */
/** \brief Type for lengths information of a PDU
 *
 * this type is configurable to uint16 and uint32 (see deviations of EcuC)
 * - range: 0 .. PduLengthmax
 */
typedef uint16 PduLengthType;

#endif /* ifndef COMSTACK_CFG_H */
/*==================[end of file]============================================*/
