
#include "Port.h"


static const Port_ConfigPinType Port_PinConfigTable[] =
{
	{ GPIOA_ID, PIN13, PORT_PIN_OUT, PORT_PIN_MODE_OUTPUT_PP, STD_LOW, PORT_NO_REMAP },
	{ GPIOA_ID, PIN14, PORT_PIN_OUT, PORT_PIN_MODE_OUTPUT_PP, STD_LOW, PORT_NO_REMAP },
//	{ GPIOB_ID, PIN8,  PORT_PIN_IN,  PORT_PIN_MODE_AF_PP,      STD_LOW, PORT_REMAP_CAN1_PB89 },  /* CAN_RX */
//	{ GPIOB_ID, PIN9,  PORT_PIN_OUT, PORT_PIN_MODE_AF_PP,      STD_LOW, PORT_REMAP_CAN1_PB89 },  /* CAN_TX */
	{ GPIOA_ID, PIN11, PORT_PIN_IN,  PORT_PIN_MODE_AF_PP, STD_LOW, PORT_NO_REMAP },  /* CAN_RX */
	{ GPIOA_ID, PIN12, PORT_PIN_OUT, PORT_PIN_MODE_AF_PP, STD_LOW, PORT_NO_REMAP },  /* CAN_TX */

};
const Port_ConfigType Port_Config =
{
    .Pins         = Port_PinConfigTable,
    .NumberOfPins = (uint8)(sizeof(Port_PinConfigTable) / sizeof(Port_PinConfigTable[0]))
};
