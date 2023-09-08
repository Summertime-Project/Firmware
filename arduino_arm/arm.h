#ifndef ARM_H
#define ARM_H

#include "Utils.h"

#ifdef __cplusplus
extern "C" {
#endif

#define P1 10  // Długości członów w tych samych jednostach, w których będą zadawane wartości położenia końcówki x, y, z
#define P2 15
#define P3 15

ErrorCode_t reverseKinematics(float outTab[2][3], float x, float y, float z);

#ifdef __cplusplus
}
#endif
#endif //ARM_H
