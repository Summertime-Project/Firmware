#define TEST
#ifdef TEST

#include "unity.h"

#include "stdint.h"

#include "Comm_input.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_COM_Input_TLV_tag_onebyte(void)
{
    {
    uint8_t tagbyte[] = {1};
    uint8_t* tagptr = tagbyte;
    tag_t tag;
    tag_t expected_tag = {0, 0, 1};
    ErrorCode_t errorcode = E_ERROR;
    errorcode = COM_Input_TLV_tag(&tagptr, &tag);

    TEST_ASSERT_EQUAL_HEX16(E_OK, errorcode);
    TEST_ASSERT_EQUAL_HEX8(TLV_TAG_UNIVERSAL, tag.class);
    TEST_ASSERT_EQUAL_HEX8(TLV_TAG_PRIMITIVE, tag.constructed);
    TEST_ASSERT_EQUAL_HEX8(1, tag.tagNr);
    }

    {
    uint8_t tagbyte[] = {0b10101101};
    uint8_t* tagptr = tagbyte;
    tag_t tag;
    tag_t expected_tag = {0, 0, 1};
    ErrorCode_t errorcode = E_ERROR;
    errorcode = COM_Input_TLV_tag(&tagptr, &tag);

    TEST_ASSERT_EQUAL_HEX16_MESSAGE(E_OK, errorcode, "Errorcode");
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(TLV_TAG_CONTEXTSPEC, tag.class, "Class");
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(TLV_TAG_CONSTUCTED, tag.constructed, "Constructed");
    TEST_ASSERT_EQUAL_HEX16_MESSAGE(0x0D, tag.tagNr, "Tag Nr");
    }
}

void test_COM_Input_TLV_len_onebyte(void)
{
    {
    uint8_t byte = 2;
    uint8_t * byteptr = &byte;
    uint16_t len;
    ErrorCode_t errorcode = E_ERROR;

    errorcode = COM_Input_TLV_len(&byteptr, &len);
    
    TEST_ASSERT_EQUAL_HEX16_MESSAGE(E_OK, errorcode, "Errorcode");
    TEST_ASSERT_EQUAL_HEX16_MESSAGE(2, len, "Len");
    }

    {
    uint8_t byte = 0x7F;
    uint8_t * byteptr = &byte;
    uint16_t len;
    ErrorCode_t errorcode = E_ERROR;

    errorcode = COM_Input_TLV_len(&byteptr, &len);
    
    TEST_ASSERT_EQUAL_HEX16_MESSAGE(E_OK, errorcode, "Errorcode");
    TEST_ASSERT_EQUAL_HEX16_MESSAGE(127, len, "Len");
    }
}

#endif // TEST
