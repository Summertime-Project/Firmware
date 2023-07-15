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

typedef uint8_t ErrorCode;

#define OK (ErrorCode)0
#define ERROR (ErrorCode)1
#define TIMEOUT (ErrorCode)2
#define LOOPOUT (ErrorCode)3
#define WRONGINPUT (ErrorCode)4

typedef struct
{
    // |2| ARC| Arm's Clamp Open/Closed| BOOL(DER???     FF=True, 00=False, else error?)|
    // |00| ALL| All available data transfered inside this tag !!!Dificult!!!| device specific|
    // |01| CHV| Chassis's Velocity|         3xINT32/FLOAT|
    // |02| CHW| Chassis's Angular velocity| 3xINT32/FLOAT|
    // |03| ARP| Arm's Position|         3xINT32/FLOAT|
    // |04| ARA| _Arm's Angle_|            3xINT32/FLOAT|
    // |05| PRS| Singular obstacle position| 3xINT32/FLOAT|
    // |06| PRM| Multiple obstacles positions| NxPRS|

    //comment unused in your module, 0-x, 1-y, 2-z
    int32_t CH_vel[3];
    int32_t CH_ang_vel[3];
    int32_t AR_ang_vel[3];
    int32_t AR_ang_vel[3];
    int32_t PR_obst_pos[PROX_SENSORS_NUM][3];
    uint8_t AR_clamp;

}StateStruct;

typedef uint8_t ErrorCode; // 0=OK, 1=Error, else RFU

//Communication
ErrorCode COM_Decoder(uint8_t* in_message_buffer, StateStruct* desired_state);
//In every function use doxygen comments in .c file
/**
 * @brief function encoding data from actual_state using TLV and big encapsulation to send to network
*/
ErrorCode COM_Encoder( uint8_t* out_message_buffer, StateStruct* actual_state);
ErrorCode COM_Send( uint8_t* out_message_buffer);
ErrorCode COM_Receive( uint8_t* in_message_buffer);

//Chassis
ErrorCode CH_CalcMotorsSpeed( const int32_t* rel_cart_vel, const int32_t* rel_ang_vel, int32_t* motors_speed);
ErrorCode CH_OutputMotorsSpeed( const int32_t* motors_speed); //Probably in Arduino

//Arm
/**
 * @brief Fucntion calculating servos' angles when given arm's cartesian cordinates
 * @param rel_cart_pos 
 * @param rel_ang for now it is output
 * @param clamp_state
 * @param servos_ang  output
*/
ErrorCode AR_CalcInvKin(const int32_t* rel_cart_pos, const int32_t* rel_ang, const int32_t clamp_state, int32_t* servos_ang);
ErrorCode AR_OutputServos(int32_t* servos_ang);

//Prox
}

#ifdef __cplusplus
}
#endif
#endif
