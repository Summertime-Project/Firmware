#ifndef COMM_INPUT_H
#define COMM_INPUT_H

#include <stdint.h>
#include "Utils.h"
#include "Comm_utils.h"

ErrorCode_t COM_Input_TLV_tag(uint8_t **const buffptr2, tag_t *const tag);

ErrorCode_t COM_Input_TLV_len(uint8_t **const buffptr2, uint16_t *const len);

ErrorCode_t COM_Input_Decode_3DCordinates(uint8_t* buffptr, uint32_t* cordinates);

ErrorCode_t COM_Input_Decode_Message(StateStruct* statestruct);

#endif // COMM_INPUT_H
