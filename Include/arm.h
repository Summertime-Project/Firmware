#ifndef ARM_H
#define ARM_H

#include "Utils.h"

#define P1 15  // Długości członów w tych samych jednostach, w których będą zadawane wartości położenia końcówki x, y, z
#define P2 15
#define P3 10

ErrorCode_t **reverseKinematics(**float outTab, double x, double y, double z);

#endif //ARM_H
