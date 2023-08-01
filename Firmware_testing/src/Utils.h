#ifndef UTILS_H
#define UTILS_H
#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>


/**
 * @section Module specific definitions
*/
/** @subsection MAIN_MCU*/

/** @subsection PROX_SENSORS*/ 
#define PRS_MAX_SENSORS_NUM 8
/** @subsection CHASSIS*/

/** @subsection ARM*/

/** @subsection CAMERA*/



/**
 * @section Error codes definitions
*/
typedef uint8_t ErrorCode_t;
#define E_OK (ErrorCode_t)0
#define E_ERROR (ErrorCode_t)1
#define E_TIMEOUT (ErrorCode_t)2
#define E_LOOPOUT (ErrorCode_t)3
#define E_WRONGINPUT (ErrorCode_t)4


/**
 *  @section State struct definition and global intialization???
*/
typedef struct
{
    int32_t CH_vel[3];
    int32_t CH_ang_vel[3];
    int32_t AR_pos[3];
    int32_t AR_ang_pos[3];
    int32_t PR_obst_pos[PRS_MAX_SENSORS_NUM][3];
    uint8_t AR_clamp;

}StateStruct;


#ifdef __cplusplus
}
#endif
#endif // UTILS_H