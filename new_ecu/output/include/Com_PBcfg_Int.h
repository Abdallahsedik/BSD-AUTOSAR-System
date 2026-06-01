#ifndef COM_PBCFG_INT_H
#define COM_PBCFG_INT_H

/**
 * \file
 *
 * \brief AUTOSAR Com
 *
 * This file contains the implementation of the AUTOSAR
 * module Com.
 *
 * \version 7.0.4
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2025 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/*==================[includes]==============================================*/

#include <Com_Rules.h>         /* Module pre-compile time config */


/*==================[macros]================================================*/

#if (defined COM_IPDU_INIT_ARRAY_SIZE) /* To prevent double declaration */
#error COM_IPDU_INIT_ARRAY_SIZE already defined
#endif /* if (defined COM_IPDU_INIT_ARRAY_SIZE) */

/* Generator has to set the value */
/** \brief Define COM_IPDU_INIT_ARRAY_SIZE */
#define COM_IPDU_INIT_ARRAY_SIZE 8U


#if (defined COM_IPDU_TMS_FLAGS_INIT_VALUES_ARRAY_SIZE) /* To prevent double declaration */
#error COM_IPDU_TMS_FLAGS_INIT_VALUES_ARRAY_SIZE already defined
#endif /* if (defined COM_IPDU_TMS_FLAGS_INIT_VALUES_ARRAY_SIZE) */

/* Generator has to set the value */
/** \brief Define COM_IPDU_TMS_FLAGS_INIT_VALUES_ARRAY_SIZE */
#define COM_IPDU_TMS_FLAGS_INIT_VALUES_ARRAY_SIZE 0U

#if (defined COM_RX_IPDU_TIMEOUT_NOTIFICATION_ARRAY_SIZE) /* To prevent double declaration */
#error COM_RX_IPDU_TIMEOUT_NOTIFICATION_ARRAY_SIZE already defined
#endif /* if (defined COM_RX_IPDU_TIMEOUT_NOTIFICATION_ARRAY_SIZE) */

/* Generator has to set the value */
/** \brief Define COM_RX_IPDU_TIMEOUT_NOTIFICATION_ARRAY_SIZE */
#define COM_RX_IPDU_TIMEOUT_NOTIFICATION_ARRAY_SIZE 0U


#if (defined COM_TX_IPDU_TIMEOUT_NOTIFICATION_ARRAY_SIZE) /* To prevent double declaration */
#error COM_TX_IPDU_TIMEOUT_NOTIFICATION_ARRAY_SIZE already defined
#endif /* if (defined COM_TX_IPDU_TIMEOUT_NOTIFICATION_ARRAY_SIZE) */

/* Generator has to set the value */
/** \brief Define COM_TX_IPDU_TIMEOUT_NOTIFICATION_ARRAY_SIZE */
#define COM_TX_IPDU_TIMEOUT_NOTIFICATION_ARRAY_SIZE 0U


#if (defined COM_TX_IPDU_NOTIFICATION_ARRAY_SIZE) /* To prevent double declaration */
#error COM_TX_IPDU_NOTIFICATION_ARRAY_SIZE already defined
#endif /* if (defined COM_TX_IPDU_NOTIFICATION_ARRAY_SIZE) */

/* Generator has to set the value */
/** \brief Define COM_TX_IPDU_NOTIFICATION_ARRAY_SIZE */
#define COM_TX_IPDU_NOTIFICATION_ARRAY_SIZE 0U


#if (defined COM_RX_SIGNAL_ARRAY_SIZE) /* To prevent double declaration */
#error COM_RX_SIGNAL_ARRAY_SIZE already defined
#endif /* if (defined COM_RX_SIGNAL_ARRAY_SIZE) */

/* Generator has to set the value */
/** \brief Define COM_RX_SIGNAL_ARRAY_SIZE */
#define COM_RX_SIGNAL_ARRAY_SIZE 8U

#if (defined COM_TX_SIGNAL_ARRAY_SIZE) /* To prevent double declaration */
#error COM_TX_SIGNAL_ARRAY_SIZE already defined
#endif /* if (defined COM_TX_SIGNAL_ARRAY_SIZE) */

/* Generator has to set the value */
/** \brief Define COM_TX_SIGNAL_ARRAY_SIZE */
#define COM_TX_SIGNAL_ARRAY_SIZE 3U


#if (defined COM_RX_FIRST_TIMEOUT_FACTOR_ARRAY_SIZE) /* To prevent double declaration */
#error COM_RX_FIRST_TIMEOUT_FACTOR_ARRAY_SIZE already defined
#endif /* if (defined COM_RX_FIRST_TIMEOUT_FACTOR_ARRAY_SIZE) */

/* Generator has to set the value */
/** \brief Define COM_RX_FIRST_TIMEOUT_FACTOR_ARRAY_SIZE */
#define COM_RX_FIRST_TIMEOUT_FACTOR_ARRAY_SIZE 0U


#if (defined COM_RX_TIMEOUT_FACTOR_ARRAY_SIZE) /* To prevent double declaration */
#error COM_RX_TIMEOUT_FACTOR_ARRAY_SIZE already defined
#endif /* if (defined COM_RX_TIMEOUT_FACTOR_ARRAY_SIZE) */

/* Generator has to set the value */
/** \brief Define COM_RX_TIMEOUT_FACTOR_ARRAY_SIZE */
#define COM_RX_TIMEOUT_FACTOR_ARRAY_SIZE 0U

#if (defined COM_TX_TIMEOUT_FACTOR_ARRAY_SIZE) /* To prevent double declaration */
#error COM_TX_TIMEOUT_FACTOR_ARRAY_SIZE already defined
#endif /* if (defined COM_TX_TIMEOUT_FACTOR_ARRAY_SIZE) */

/* Generator has to set the value */
/** \brief Define COM_TX_TIMEOUT_FACTOR_ARRAY_SIZE */
#define COM_TX_TIMEOUT_FACTOR_ARRAY_SIZE 0U

#if (defined COM_TX_IPDU_MINIMUM_DELAY_TIME_FACTOR_ARRAY_SIZE) /* To prevent double declaration */
#error COM_TX_IPDU_MINIMUM_DELAY_TIME_FACTOR_ARRAY_SIZE already defined
#endif /* if (defined COM_TX_IPDU_MINIMUM_DELAY_TIME_FACTOR_ARRAY_SIZE) */

/* Generator has to set the value */
/** \brief Define COM_TX_IPDU_MINIMUM_DELAY_TIME_FACTOR_ARRAY_SIZE */
#define COM_TX_IPDU_MINIMUM_DELAY_TIME_FACTOR_ARRAY_SIZE 0U


#if (defined COM_RX_IPDU_ARRAY_SIZE) /* To prevent double declaration */
#error COM_RX_IPDU_ARRAY_SIZE already defined
#endif /* if (defined COM_RX_IPDU_ARRAY_SIZE) */

/* Generator has to set the value */
/** \brief Define COM_RX_IPDU_ARRAY_SIZE */
#define COM_RX_IPDU_ARRAY_SIZE 6U


#if (defined COM_TX_IPDU_ARRAY_SIZE) /* To prevent double declaration */
#error COM_TX_IPDU_ARRAY_SIZE already defined
#endif /* if (defined COM_TX_IPDU_ARRAY_SIZE) */

/* Generator has to set the value */
/** \brief Define COM_TX_IPDU_ARRAY_SIZE */
#define COM_TX_IPDU_ARRAY_SIZE 2U

#if (defined COM_RX_SIGNAL_GROUP_ARRAY_SIZE) /* To prevent double declaration */
#error COM_RX_SIGNAL_GROUP_ARRAY_SIZE already defined
#endif /* if (defined COM_RX_SIGNAL_GROUP_ARRAY_SIZE) */

/* Generator has to set the value */
/** \brief Define COM_RX_SIGNAL_GROUP_ARRAY_SIZE */
#define COM_RX_SIGNAL_GROUP_ARRAY_SIZE 0U

#if (defined COM_TX_SIGNAL_GROUP_ARRAY_SIZE) /* To prevent double declaration */
#error COM_TX_SIGNAL_GROUP_ARRAY_SIZE already defined
#endif /* if (defined COM_TX_SIGNAL_GROUP_ARRAY_SIZE) */

/* Generator has to set the value */
/** \brief Define COM_TX_SIGNAL_GROUP_ARRAY_SIZE */
#define COM_TX_SIGNAL_GROUP_ARRAY_SIZE 0U


#if (defined COM_TX_MODE_N_TIMES_ARRAY_SIZE) /* To prevent double declaration */
#error COM_TX_MODE_N_TIMES_ARRAY_SIZE already defined
#endif /* if (defined COM_TX_MODE_N_TIMES_ARRAY_SIZE) */

/* Generator has to set the value */
/** \brief Define COM_TX_MODE_N_TIMES_ARRAY_SIZE */
#define COM_TX_MODE_N_TIMES_ARRAY_SIZE 0U

#if (defined COM_TX_MODE_PERIODIC_ARRAY_SIZE) /* To prevent double declaration */
#error COM_TX_MODE_PERIODIC_ARRAY_SIZE already defined
#endif /* if (defined COM_TX_MODE_PERIODIC_ARRAY_SIZE) */

/* Generator has to set the value */
/** \brief Define COM_TX_MODE_PERIODIC_ARRAY_SIZE
 * Note: in the TxModePeriodicArray also the parameters of the
 * COM_TX_MODE_MIXED_DIRECT are stored */
#define COM_TX_MODE_PERIODIC_ARRAY_SIZE 1U

#if (defined COM_TX_MODE_MIXED_N_TIMES_ARRAY_SIZE) /* To prevent double declaration */
#error COM_TX_MODE_MIXED_N_TIMES_ARRAY_SIZE already defined
#endif /* if (defined COM_TX_MODE_MIXED_N_TIMES_ARRAY_SIZE) */

/* Generator has to set the value */
/** \brief Define COM_TX_MODE_MIXED_N_TIMES_ARRAY_SIZE */
#define COM_TX_MODE_MIXED_N_TIMES_ARRAY_SIZE 0U


#if (defined COM_SIGGW_RX_IPDU_LIST_ARRAY_SIZE) /* To prevent double declaration */
#error COM_SIGGW_RX_IPDU_LIST_ARRAY_SIZE already defined
#endif /* if (defined COM_SIGGW_RX_IPDU_LIST_ARRAY_SIZE) */

/** \brief Define COM_SIGGW_RX_IPDU_LIST_ARRAY_SIZE */
#define COM_SIGGW_RX_IPDU_LIST_ARRAY_SIZE 0U


#if (defined COM_RX_IPDU_SIGNAL_GROUP_LIST_ARRAY_SIZE) /* To prevent double declaration */
#error COM_RX_IPDU_SIGNAL_GROUP_LIST_ARRAY_SIZE already defined
#endif /* if (defined COM_RX_IPDU_SIGNAL_GROUP_LIST_ARRAY_SIZE) */

/* Generator has to set the value */
/** \brief Define COM_RX_IPDU_SIGNAL_GROUP_LIST_ARRAY_SIZE */
#define COM_RX_IPDU_SIGNAL_GROUP_LIST_ARRAY_SIZE 0U


#if (defined COM_TX_IPDU_SIGNAL_GROUP_LIST_ARRAY_SIZE) /* To prevent double declaration */
#error COM_TX_IPDU_SIGNAL_GROUP_LIST_ARRAY_SIZE already defined
#endif /* if (defined COM_TX_IPDU_SIGNAL_GROUP_LIST_ARRAY_SIZE) */

/* Generator has to set the value */
/** \brief Define COM_TX_IPDU_SIGNAL_GROUP_LIST_ARRAY_SIZE */
#define COM_TX_IPDU_SIGNAL_GROUP_LIST_ARRAY_SIZE 0U


#if (defined COM_RX_IPDU_SIGNAL_LIST_ARRAY_SIZE) /* To prevent double declaration */
#error COM_RX_IPDU_SIGNAL_LIST_ARRAY_SIZE already defined
#endif /* if (defined COM_RX_IPDU_SIGNAL_LIST_ARRAY_SIZE) */

/* Generator has to set the value */
/** \brief Define COM_RX_IPDU_SIGNAL_LIST_ARRAY_SIZE */
#define COM_RX_IPDU_SIGNAL_LIST_ARRAY_SIZE 8U

#if (defined COM_TX_IPDU_SIGNAL_LIST_ARRAY_SIZE) /* To prevent double declaration */
#error COM_TX_IPDU_SIGNAL_LIST_ARRAY_SIZE already defined
#endif /* if (defined COM_TX_IPDU_SIGNAL_LIST_ARRAY_SIZE) */

/* Generator has to set the value */
/** \brief Define COM_TX_IPDU_SIGNAL_LIST_ARRAY_SIZE */
#define COM_TX_IPDU_SIGNAL_LIST_ARRAY_SIZE 3U


#if (defined COM_MDT_QUEUE_ARRAY_SIZE) /* To prevent double declaration */
#error COM_MDT_QUEUE_ARRAY_SIZE already defined
#endif /* if (defined COM_MDT_QUEUE_ARRAY_SIZE) */

/* Generator has to set the value */
/** \brief Define COM_MDT_QUEUE_ARRAY_SIZE */
#define COM_MDT_QUEUE_ARRAY_SIZE 0U


#if (defined COM_PERIODIC_QUEUE_ARRAY_SIZE) /* To prevent double declaration */
#error COM_PERIODIC_QUEUE_ARRAY_SIZE already defined
#endif /* if (defined COM_PERIODIC_QUEUE_ARRAY_SIZE) */

/* Generator has to set the value */
/** \brief Define COM_PERIODIC_QUEUE_ARRAY_SIZE */
#define COM_PERIODIC_QUEUE_ARRAY_SIZE 2U


#if (defined COM_N_TIMES_QUEUE_ARRAY_SIZE) /* To prevent double declaration */
#error COM_N_TIMES_QUEUE_ARRAY_SIZE already defined
#endif /* if (defined COM_N_TIMES_QUEUE_ARRAY_SIZE) */

/* Generator has to set the value */
/** \brief Define COM_N_TIMES_QUEUE_ARRAY_SIZE */
#define COM_N_TIMES_QUEUE_ARRAY_SIZE 0U

#if (defined COM_RX_TIMEOUT_QUEUE_ARRAY_SIZE) /* To prevent double declaration */
#error COM_RX_TIMEOUT_QUEUE_ARRAY_SIZE already defined
#endif /* if (defined COM_RX_TIMEOUT_QUEUE_ARRAY_SIZE) */

/* Generator has to set the value */
/** \brief Define COM_RX_TIMEOUT_QUEUE_ARRAY_SIZE */
#define COM_RX_TIMEOUT_QUEUE_ARRAY_SIZE 0U

#if (defined COM_RX_TIMEOUT_SIGNAL_QUEUE_ARRAY_SIZE) /* To prevent double declaration */
#error COM_RX_TIMEOUT_SIGNAL_QUEUE_ARRAY_SIZE already defined
#endif /* if (defined COM_RX_TIMEOUT_SIGNAL_QUEUE_ARRAY_SIZE) */

/* Generator has to set the value */
/** \brief Define COM_RX_TIMEOUT_SIGNAL_QUEUE_ARRAY_SIZE */
#define COM_RX_TIMEOUT_SIGNAL_QUEUE_ARRAY_SIZE 0U

#if (defined COM_RX_TIMEOUT_SIGNAL_GROUP_QUEUE_ARRAY_SIZE) /* To prevent double declaration */
#error COM_RX_TIMEOUT_SIGNAL_GROUP_QUEUE_ARRAY_SIZE already defined
#endif /* if (defined COM_RX_TIMEOUT_SIGNAL_GROUP_QUEUE_ARRAY_SIZE) */

/* Generator has to set the value */
/** \brief Define COM_RX_TIMEOUT_SIGNAL_GROUP_QUEUE_ARRAY_SIZE */
#define COM_RX_TIMEOUT_SIGNAL_GROUP_QUEUE_ARRAY_SIZE 0U

#if (defined COM_TX_TIMEOUT_QUEUE_ARRAY_SIZE) /* To prevent double declaration */
#error COM_TX_TIMEOUT_QUEUE_ARRAY_SIZE already defined
#endif /* if (defined COM_TX_TIMEOUT_QUEUE_ARRAY_SIZE) */

/* Generator has to set the value */
/** \brief Define COM_TX_TIMEOUT_QUEUE_ARRAY_SIZE */
#define COM_TX_TIMEOUT_QUEUE_ARRAY_SIZE 0U

#if (defined COM_CBK_TX_ACK_DEFERRED_ARRAY_SIZE) /* To prevent double declaration */
#error COM_CBK_TX_ACK_DEFERRED_ARRAY_SIZE already defined
#endif /* if (defined COM_CBK_TX_ACK_DEFERRED_ARRAY_SIZE) */

/* Generator has to set the value */
/** \brief Define COM_CBK_TX_ACK_DEFERRED_ARRAY_SIZE */
#define COM_CBK_TX_ACK_DEFERRED_ARRAY_SIZE 0U


#if (defined COM_CONFIGURATION_ARRAY_SIZE) /* To prevent double declaration */
#error COM_CONFIGURATION_ARRAY_SIZE already defined
#endif /* if (defined COM_CONFIGURATION_ARRAY_SIZE) */

/* Generator has to set the value */
/** \brief Define COM_CONFIGURATION_ARRAY_SIZE */
#define COM_CONFIGURATION_ARRAY_SIZE 0U /* still hardcoded */


#if (defined COM_GW_SOURCE_ARRAY_SIZE) /* To prevent double declaration */
#error COM_GW_SOURCE_ARRAY_SIZE already defined
#endif /* if (defined COM_GW_SOURCE_ARRAY_SIZE) */

/* Generator has to set the value */
/** \brief Define COM_GW_SOURCE_ARRAY_SIZE */
#define COM_GW_SOURCE_ARRAY_SIZE 0U


#if (defined COM_GW_DESTINATION_ARRAY_SIZE) /* To prevent double declaration */
#error COM_GW_DESTINATION_ARRAY_SIZE already defined
#endif /* if (defined COM_GW_DESTINATION_ARRAY_SIZE) */

/* Generator has to set the value */
/** \brief Define COM_GW_DESTINATION_ARRAY_SIZE */
#define COM_GW_DESTINATION_ARRAY_SIZE 0U


#if (defined COM_FILTER_8_BIT_MASK_ARRAY_SIZE) /* To prevent double declaration */
#error COM_FILTER_8_BIT_MASK_ARRAY_SIZE already defined
#endif /* if (defined COM_FILTER_8_BIT_MASK_ARRAY_SIZE) */

/* Generator has to set the value */
/** \brief Define COM_FILTER_8_BIT_MASK_ARRAY_SIZE */
#define COM_FILTER_8_BIT_MASK_ARRAY_SIZE 0U

#if (defined COM_FILTER_16_BIT_MASK_ARRAY_SIZE) /* To prevent double declaration */
#error COM_FILTER_16_BIT_MASK_ARRAY_SIZE already defined
#endif /* if (defined COM_FILTER_16_BIT_MASK_ARRAY_SIZE) */

/* Generator has to set the value */
/** \brief Define COM_FILTER_16_BIT_MASK_ARRAY_SIZE */
#define COM_FILTER_16_BIT_MASK_ARRAY_SIZE 0U

#if (defined COM_FILTER_32_BIT_MASK_ARRAY_SIZE) /* To prevent double declaration */
#error COM_FILTER_32_BIT_MASK_ARRAY_SIZE already defined
#endif /* if (defined COM_FILTER_32_BIT_MASK_ARRAY_SIZE) */

/* Generator has to set the value */
/** \brief Define COM_FILTER_32_BIT_MASK_ARRAY_SIZE */
#define COM_FILTER_32_BIT_MASK_ARRAY_SIZE 0U

#if (defined COM_FILTER_8_BIT_MASK_X_MIN_MAX_ARRAY_SIZE) /* To prevent double declaration */
#error COM_FILTER_8_BIT_MASK_X_MIN_MAX_ARRAY_SIZE already defined
#endif /* if (defined COM_FILTER_8_BIT_MASK_X_MIN_MAX_ARRAY_SIZE) */

/* Generator has to set the value */
/** \brief Define COM_FILTER_8_BIT_MASK_X_MIN_MAX_ARRAY_SIZE */
#define COM_FILTER_8_BIT_MASK_X_MIN_MAX_ARRAY_SIZE 0U

#if (defined COM_FILTER_16_BIT_MASK_X_MIN_MAX_ARRAY_SIZE) /* To prevent double declaration */
#error COM_FILTER_16_BIT_MASK_X_MIN_MAX_ARRAY_SIZE already defined
#endif /* if (defined COM_FILTER_16_BIT_MASK_X_MIN_MAX_ARRAY_SIZE) */

/* Generator has to set the value */
/** \brief Define COM_FILTER_16_BIT_MASK_X_MIN_MAX_ARRAY_SIZE */
#define COM_FILTER_16_BIT_MASK_X_MIN_MAX_ARRAY_SIZE 0U

#if (defined COM_FILTER_32_BIT_MASK_X_MIN_MAX_ARRAY_SIZE) /* To prevent double declaration */
#error COM_FILTER_32_BIT_MASK_X_MIN_MAX_ARRAY_SIZE already defined
#endif /* if (defined COM_FILTER_32_BIT_MASK_X_MIN_MAX_ARRAY_SIZE) */

/* Generator has to set the value */
/** \brief Define COM_FILTER_32_BIT_MASK_X_MIN_MAX_ARRAY_SIZE */
#define COM_FILTER_32_BIT_MASK_X_MIN_MAX_ARRAY_SIZE 0U

#if (defined COM_FILTER_ONE_EVERY_N_ARRAY_SIZE) /* To prevent double declaration */
#error COM_FILTER_ONE_EVERY_N_ARRAY_SIZE already defined
#endif /* if (defined COM_FILTER_ONE_EVERY_N_ARRAY_SIZE) */

/* Generator has to set the value */
/** \brief Define COM_FILTER_ONE_EVERY_N_ARRAY_SIZE */
#define COM_FILTER_ONE_EVERY_N_ARRAY_SIZE 0U


/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

/** @} doxygen end group definition */
#endif /* ifndef COM_PBCFG_INT_H  */
/*==================[end of file]===========================================*/
