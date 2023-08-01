#ifndef COMM_UTILS_H
#define COMM_UTILS_H

#include <stdint.h>

#define COM_BUFFER_SIZE 1<<8 


#define TLV_TAG_UNIVERSAL 0
#define TLV_TAG_APPLICATION 1 
#define TLV_TAG_CONTEXTSPEC 2
#define TLV_TAG_PRIVATE 3

#define TLV_TAG_PRIMITIVE 0
#define TLV_TAG_CONSTUCTED 1

/**
 *  @struct Struct tag information
*/
typedef struct tag_t
{
    uint8_t class : 2;
    uint8_t constructed: 1;
    uint16_t tagNr; 
} tag_t;

/**
 *  @struct Struct storing TLV frame
*/
typedef struct tlv_frame_t
{
    tag_t tag;
    uint16_t len;
    uint8_t * value;
}tlv_frame_t;

uint8_t CRC(const uint8_t * memory_ptr, uint16_t memLenght);


#endif // COMM_UTILS_H
