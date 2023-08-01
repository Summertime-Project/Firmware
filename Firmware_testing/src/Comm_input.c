#include "Comm_input.h"
#include "Comm_utils.h"
#include "Utils.h"

uint8_t COM_input_buffer[COM_BUFFER_SIZE];
uint8_t* COM_input_currbuffptr;

/**
 * @brief 
 * @param buffptr [IN/OUT] IN - bufferptr which points to tag; OUT - bufferptr which points next mem after tag
 * @param tag [OUT] structure storing all tag information
 * @returns ErrorCode
*/
ErrorCode_t COM_Input_TLV_tag(uint8_t **const buffptr, tag_t *const tag)
{
    uint8_t* buff = *buffptr;

    //Pupulates class and constructed fields
    tag->class = ((*buff) >> 6) & 0x3;
    tag->constructed = ((*buff) >> 5) & 0x01;
    tag->tagNr = 0; //reset tagNr

    //Populates tagNr
    if(*buff == 0x1F)
    {
        return E_ERROR;
    }

    tag->tagNr = *buff & 0x1F;

    if (tag->tagNr & 0xFFE0) // checkt if tag is max 5bit
    {
        return E_ERROR;
    }

    ++*buffptr; //shift bufferpointer by one byte

    return E_OK;
}

/**
 * @brief When given correct memeory cell storing len returns valid lenght of datastructure
 * @param buffptr [IN/OUT] IN - bufferptr which points to tag; OUT - bufferptr which points next mem after len
 * @param tag [OUT] mem storing len of structure
 * @returns ErrorCode
*/
ErrorCode_t COM_Input_TLV_len(uint8_t **const buffptr2, uint16_t *const len)
{
    *len = 0;
    //checks if is correct one byte
    if(**buffptr2 >= 0x80)
    {
        return E_ERROR;
    }
    //Populates len mem
    *len = **buffptr2;
    //shift buffptr by one
    ++*buffptr2;

    return E_OK;
}

/**
 * @brief
 * @param buffptr [IN/OUT]
 * @param cordinates [OUT]
*/
ErrorCode_t COM_Input_Decode_3DCordinates(uint8_t* buffptr, uint32_t* cordinates)
{
    uint8_t* start_buffptr = buffptr;

    //check if tag belongs to cordinates

}