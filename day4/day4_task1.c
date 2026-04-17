#include <stdio.h>
#include <string.h>

#define MAX 5

struct Regjistrim {
    char emri[50];
    int mosha;
    float progresi;
};

int main() {
    struct Regjistrim lista[MAX];
    int count = 0;
    int zgjedhja;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Shto regjistrim\n");
        printf("2. Shfaq te gjitha\n");
        printf("3. Dil\n");
        printf("Zgjedhja: ");
        scanf("%d", &zgjedhja);

        switch(zgjedhja) {

            case 1:
                if(count >= MAX) {
                    printf("Keni arritur numrin maksimal te regjistrimeve!\n");
                } else {
                    printf("Emri: ");
                    scanf("%s", lista[count].emri);

                    printf("Mosha: ");
                    scanf("%d", &lista[count].mosha);

                    printf("Progresi: ");
                    scanf("%f", &lista[count].progresi);

                    count++;
                    printf("Regjistrimi u shtua me sukses!\n");
                }
                break;

            case 2:
                if(count == 0) {
                    printf("Nuk ka regjistrime!\n");
                } else {
                    printf("\n--- LISTA E REGJISTRIMEVE ---\n");
                    for(int i = 0; i < count; i++) {
                        printf("\nRegjistrimi %d\n", i + 1);
                        printf("Emri: %s\n", lista[i].emri);
                        printf("Mosha: %d\n", lista[i].mosha);
                        printf("Progresi: %.2f\n", lista[i].progresi);
                    }
                }
                break;

            case 3:
                printf("Duke dale nga programi...\n");
                break;

            default:
                printf("Zgjedhje e pavlefshme!\n");
        }

    } while(zgjedhja != 3);

    return 0;
}
