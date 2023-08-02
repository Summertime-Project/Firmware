#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "arm.h"

#define P1 15  // Długości członów w tych samych jednostach, w których będą zadawane wartości położenia końcówki x, y, z
#define P2 15
#define P3 10

// Może zmienić na float? nie wiem w sumie
// Funkcja przyjmująca współrzęne kartezjańskie końcówki robota RRR, a zwracająca współrzędne złączowe - kąty serw w stopniach,
// w postaci [[t1a, t2a, t3a], [t1b, t2b, t3b]] - istnieją dwa rozwiązania, w przypadku gdy zadany punktu jest poza zasięgiem
// ramienia zwraca NULL
double **reverseKinematics(double x, double y, double z){
    double** outCords = malloc(2 * sizeof(double*));
    for (int i = 0; i < 2; ++i)
        outCords[i] = malloc(3 * sizeof(double));

    double theta1 = atan2(y, x);
    double cost3 = (pow(z - P1, 2) + pow(x, 2) + pow(y, 2) - pow(P2, 2) - pow(P3, 2)) / (2 * P2 * P3);
    // Punkt poza zasięgiem ramiania
    if (cost3 > 1)
        return NULL;

    double sint3_a = sqrt(1 - pow(cost3, 2));
    double sint3_b = -sint3_a;
    double theta3_a = atan2(sint3_a, cost3);
    double theta3_b = atan2(sint3_b, cost3);
    double beta = atan2(z - P1, sqrt(pow(x,2) + pow(y, 2)));
    double theta2_a = beta + atan2(P3 * sint3_a, P2 + P3 * cost3);
    double theta2_b = beta + atan2(P3 * sint3_b, P2 + P3 * cost3);

    outCords[0][0] = theta1 * (180 / M_PI);
    outCords[1][0] = theta1 * (180 / M_PI);
    outCords[0][1] = theta2_a * (180 / M_PI);
    outCords[1][1] = theta2_b * (180 / M_PI);
    outCords[0][2] = theta3_a * (180 / M_PI);
    outCords[1][2] = theta3_b * (180 / M_PI);

    return outCords;
}

