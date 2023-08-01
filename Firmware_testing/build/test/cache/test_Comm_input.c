#include "src/Comm_input.h"
#include "C:/Ruby30-x64/lib/ruby/gems/3.0.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"














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

    ErrorCode_t errorcode = (ErrorCode_t)1;

    errorcode = COM_Input_TLV_tag(&tagptr, &tag);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)(((ErrorCode_t)0)), (UNITY_INT)(UNITY_INT16)((errorcode)), (

   ((void *)0)

   ), (UNITY_UINT)(28), UNITY_DISPLAY_STYLE_HEX16);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0)), (UNITY_INT)(UNITY_INT8 )((tag.class)), (

   ((void *)0)

   ), (UNITY_UINT)(29), UNITY_DISPLAY_STYLE_HEX8);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0)), (UNITY_INT)(UNITY_INT8 )((tag.constructed)), (

   ((void *)0)

   ), (UNITY_UINT)(30), UNITY_DISPLAY_STYLE_HEX8);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((1)), (UNITY_INT)(UNITY_INT8 )((tag.tagNr)), (

   ((void *)0)

   ), (UNITY_UINT)(31), UNITY_DISPLAY_STYLE_HEX8);

    }



    {

    uint8_t tagbyte[] = {0b10101101};

    uint8_t* tagptr = tagbyte;

    tag_t tag;

    tag_t expected_tag = {0, 0, 1};

    ErrorCode_t errorcode = (ErrorCode_t)1;

    errorcode = COM_Input_TLV_tag(&tagptr, &tag);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)(((ErrorCode_t)0)), (UNITY_INT)(UNITY_INT16)((errorcode)), (("Errorcode")), (UNITY_UINT)(42), UNITY_DISPLAY_STYLE_HEX16);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((2)), (UNITY_INT)(UNITY_INT8 )((tag.class)), (("Class")), (UNITY_UINT)(43), UNITY_DISPLAY_STYLE_HEX8);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((1)), (UNITY_INT)(UNITY_INT8 )((tag.constructed)), (("Constructed")), (UNITY_UINT)(44), UNITY_DISPLAY_STYLE_HEX8);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0D)), (UNITY_INT)(UNITY_INT16)((tag.tagNr)), (("Tag Nr")), (UNITY_UINT)(45), UNITY_DISPLAY_STYLE_HEX16);

    }

}



void test_COM_Input_TLV_len_onebyte(void)

{

    {

    uint8_t byte = 2;

    uint8_t * byteptr = &byte;

    uint16_t len;

    ErrorCode_t errorcode = (ErrorCode_t)1;



    errorcode = COM_Input_TLV_len(&byteptr, &len);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)(((ErrorCode_t)0)), (UNITY_INT)(UNITY_INT16)((errorcode)), (("Errorcode")), (UNITY_UINT)(59), UNITY_DISPLAY_STYLE_HEX16);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((2)), (UNITY_INT)(UNITY_INT16)((len)), (("Len")), (UNITY_UINT)(60), UNITY_DISPLAY_STYLE_HEX16);

    }



    {

    uint8_t byte = 0x7F;

    uint8_t * byteptr = &byte;

    uint16_t len;

    ErrorCode_t errorcode = (ErrorCode_t)1;



    errorcode = COM_Input_TLV_len(&byteptr, &len);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)(((ErrorCode_t)0)), (UNITY_INT)(UNITY_INT16)((errorcode)), (("Errorcode")), (UNITY_UINT)(71), UNITY_DISPLAY_STYLE_HEX16);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((127)), (UNITY_INT)(UNITY_INT16)((len)), (("Len")), (UNITY_UINT)(72), UNITY_DISPLAY_STYLE_HEX16);

    }

}
