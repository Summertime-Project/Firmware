#include "Comm_utils.h"


/**
 * @brief Function calculates 8bit cyclic redundancy check from message memory block of given lenght
 * @param message [IN] pointer to memory block
 * @param memLenght [IN] lenght of memory block
 * @returns 8bit checksum
*/
uint8_t CRC(const uint8_t* message, uint16_t memLenght)
{
    uint8_t data;
    uint8_t remainder = 0;
} 
