#include <stdio.h>

int main() {
    int rezultati;

    printf("Ju lutem jepni rezultatin (0-100): ");
    scanf("%d", &rezultati);

    if (rezultati < 0 || rezultati > 100) {
        printf("Gabim: Input-i nuk është valid. Ju lutem jepni një numër nga 0 deri në 100.\n");
    } 
    else if (rezultati >= 90) {
        printf("Vlerësimi: Shkëlqyeshëm\n");
    } 
    else if (rezultati >= 75) {
        printf("Vlerësimi: Shumë mirë\n");
    } 
    else if (rezultati >= 50) {
        printf("Vlerësimi: Mirë\n");
    } 
    else {
        printf("Vlerësimi: Në përmirësim\n");
    }

    return 0;
}
