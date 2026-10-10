#ifndef COM_CFG_H_
#define COM_CFG_H_

#include "Std_Types.h"

/* Number of I-PDUs  */
#define COM_NUM_TX_PDUS 2u
#define COM_NUM_RX_PDUS 6u

/* TX I-PDU IDs */
#define COM_IPDU_TX_WARNING         0u  /* CAN ID 0x300 */
#define COM_IPDU_TX_LED             1u  /* CAN ID 0x301 */

/* RX I-PDU IDs  */
#define COM_IPDU_RX_RADAR_L         0u  /* CAN ID 0x200 */
#define COM_IPDU_RX_RADAR_R         1u  /* CAN ID 0x201 */
#define COM_IPDU_RX_ABS             2u  /* CAN ID 0x100 */
#define COM_IPDU_RX_BCM             3u  /* CAN ID 0x3A0 */
#define COM_IPDU_RX_EPS             4u  /* CAN ID 0x2E0 */
#define COM_IPDU_RX_TCU             5u  /* CAN ID 0x1A0 */

/* Signal IDs */
#define COM_SIG_WARNING_STATE_LEFT   0u
#define COM_SIG_WARNING_STATE_RIGHT  1u
#define COM_SIG_LED_LEFT             2u
#define COM_SIG_LED_RIGHT            3u

#define COM_SIG_VEHICLE_SPEED        4u
#define COM_SIG_RADAR_LEFT_DIST      5u
#define COM_SIG_RADAR_LEFT_STATUS    6u
#define COM_SIG_RADAR_RIGHT_DIST     7u
#define COM_SIG_RADAR_RIGHT_STATUS   8u
#define COM_SIG_TURN_SIGNAL          9u
#define COM_SIG_STEERING_ANGLE       10u
#define COM_SIG_GEAR                 11u

/* Total number of signals */
#define COM_NUM_SIGNALS              12u

/* Signal Properties Configuration */
typedef struct {
    uint16  SignalId;
    uint16  PduId;
    uint8   BitPosition;
    uint8   BitLength;
    boolean IsTx;
} Com_SignalConfigType;

extern const Com_SignalConfigType Com_SignalConfig[COM_NUM_SIGNALS];

#endif /* COM_CFG_H_ */
