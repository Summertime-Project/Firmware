#include "arm.h"
#include "Utils.h"

int main(void){
    float result[2][3];

    ErrorCode_t eCode = reverseKinematics(result, 30, 0, 10);
    printf("%d\n", eCode);

    if (eCode == E_OK){
        for(int i=0; i < 2; ++i){
            for(int j=0; j < 3; ++j){
                printf("%f ", result[i][j]);
            }
            printf("; ");
        }
        printf("\n");
    } else if (eCode == E_WRONGINPUT) {
        printf("Wartości poza zakresem!\n");
    }

    return 0;
}
