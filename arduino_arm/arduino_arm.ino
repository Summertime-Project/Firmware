#include <Servo.h>
#include <math.h>
extern "C" ErrorCode_t reverseKinematics(float outTab[2][3], float x, float y, float z);

Servo servo1;
Servo servo2;
Servo servo3;

void setup() {
  servo1.attach(9);  // Piny obsługujące PWM w Arduino Uno R3
  servo2.attach(10);
  servo3.attach(11);

  // Serial.begin(9600);
}

float prevPos[3] = {0, 0, 0};

// Początkowe współrzędne zadanego położenia końcówki ramienia, nie wiem skąd będą brane
float x = 0, y = 0, z = 0;

void loop() {
  // TODO: Tu musi być aktualizacja zadanych wartości x, y i z
  float new_x = 0, new_y = 0, new_z = 0;
  // Jeśli zmieniły się zadane wartości
  if (x != new_x || y != new_y || z != new_z) {
    float result[2][3];
    ErrorCode_t eCode = reverseKinematics(result, x, y, z);
    // Jeśli x, y, z w zasięgu
    if (eCode == E_OK){
      // Wybór bliższego z dwóch rozwiązań
      if (pow(result[0][1] - prevPos[1], 2) + pow(result[0][2] - prevPos[2], 2) <= pow(result[1][1] - prevPos[1], 2) + pow(result[1][2] - prevPos[2], 2)){
        float pos[3] = {result[0][0], result[0][1], result[0][2]};
      } else {
        float pos[3] = {result[1][0], result[1][1], result[1][2]};
      }

      servo1.write(pos[0]);
      servo2.write(pos[1]);
      servo3.write(pos[2]);

      prevPos[0] = pos[0];
      prevPos[1] = pos[1];
      prevPos[2] = pos[2];

    }
    // Serial.println("Kąty serwomechanizmów: %f, %f, %f", prevPos[0], prevPos[1], prevPos[2]);
  }
}
