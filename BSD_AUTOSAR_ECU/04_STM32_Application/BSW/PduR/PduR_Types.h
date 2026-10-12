/*
 * PduR_Types.h
 *
 *  Created on: Oct 6, 2026
 *      Author: pc
 */

#ifndef CAN_PDUR_TYPES_H_
#define CAN_PDUR_TYPES_H_

typedef struct {
    uint8* SduDataPtr;  /* Pointer to the actual data bytes */
    uint8  SduLength;   /* Length of the data (DLC) */
} PduInfoType;

typedef uint8  PduIdType;   /*  0..255 */
#endif /* CAN_PDUR_TYPES_H_ */
