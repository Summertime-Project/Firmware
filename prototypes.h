#ifndef PROTOTYPES_H
#define PROTOTYPES_H
#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

//Use define to define XD eg. physical constraints
#define CH_WHELLS_BREADTH 
#define AR_FIRST_SEGMENT_LEN
#define PROX_SENSORS_NUM 2



typedef struct
{
    //comment unused in your module
    int32_t p_vel[3];
    int32_t p_ang_vel[3];
    int32_t p_ang_vel[3];
    int32_t p_ang_pos[3];
    int32_t obst_pos[PROX_SENSORS_NUM];

}StateStruct;

typedef uint8_t ErrorCode; // 0=OK, 1=Error, else RFU

//Communication
ErrorCode COM_Decoder(uint8_t* in_message_buffer, StateStruct* desired_state);
//In every function use doxygen comments in .c file
/**
 * @brief function encoding data from actual_state using TLV and big encapsulation to send to network
*/
ErrorCode COM_Encoder(uint8_t* out_message_buffer, StateStruct* actual_state);
ErrorCode COM_Send(uint8_t* out_message_buffer);
ErrorCode COM_Receive(uint8_t* in);

//Chassis
ErrorCode CH_CalcMotorsSpeed(const int32_t* rel_cart_vel, const int32_t* rel_ang_vel, int32_t* motors_speed);
ErrorCode CH_OutputMotorsSpeed( const int32_t* motors_speed); //Probably in Arduino

//Arm
ErrorCode AR_CalcInvKin(const int32_t* rel_cart_pos, const int32_t* rel_ang, const int32_t clamp_state, int32_t* servos_ang);
ErrorCode AR_OutputServos(int32_t* servos_ang);

//Prox
//ErrorCode 
}

#ifdef __cplusplus
}
#endif

