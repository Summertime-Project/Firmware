#include <math.h>
#include <stdio.h>
#include "Utils.h"
#include "arm.h"

/**
    Funkcja przyjmująca współrzędne kartezjańskie końcówki robota RRR,
    i obliczająca współrzędne złączowe - kąty serw w stopniach

    @param outTab: dwuwymiarowa tablica floatów o rozmiarze [2, 3] (!) rozwiązań
        w postaci [[t1a, t2a, t3a], [t1b, t2b, t3b]] - istnieją dwa rozwiązania,
        w przypadku gdy zadany punkt jest poza zasięgiem ramienia przyjmuje NULL
    @param x: float, współrzędna kartezjańska osi x
    @param y: float, współrzędna kartezjańska osi y
    @param z: float, współrzędna kartezjańska osi z

    @return kod błędu: ErrorCode_t; E_OK, gdy sukces, E_WRONGINPUT, gdy wartości
        x, y lub z spoza zasięgu ramienia
**/
ErrorCode_t reverseKinematics(float outTab[2][3], float x, float y, float z){
    float theta1 = atan2f(y, x);
    float cost3 = (float) ((pow(z - P1, 2) + pow(x, 2) + pow(y, 2) - pow(P2, 2) - pow(P3, 2)) / (2 * P2 * P3));

    // Punkt poza zasięgiem ramiania
    if (cost3 > 1) {
        outTab = NULL;
        return E_WRONGINPUT;
    }

    float sint3_a = (float) sqrt(1 - pow(cost3, 2));
    float sint3_b = -sint3_a;
    float theta3_a = atan2f(sint3_a, cost3);
    float theta3_b = atan2f(sint3_b, cost3);
    float beta = atan2f(z - P1, (float) sqrt(pow(x, 2) + pow(y, 2)));
    float theta2_a = (float) (beta + atan2f(P3 * sint3_a, P2 + P3 * cost3));
    float theta2_b = (float) (beta + atan2f(P3 * sint3_b, P2 + P3 * cost3));
    // Przeliczenie na stopnie
    outTab[0][0] = (theta1 * (180 / (float) M_PI));
    outTab[1][0] = (theta1 * (180 / (float) M_PI));
    outTab[0][1] = (theta2_a * (180 / (float) M_PI));
    outTab[1][1] = (theta2_b * (180 / (float) M_PI));
    outTab[0][2] = (theta3_a * (180 / (float) M_PI));
    outTab[1][2] = (theta3_b * (180 / (float) M_PI));

    return E_OK;
}

