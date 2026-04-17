#include <stdio.h>
#define MAX 5

struct Regjistrim {
    char emri[50];
    int mosha;
    float nota;
};

int main() {
    struct Regjistrim lista[MAX];
    int numriRegjistrimeve = 0;
    int zgjedhja;

    do {
        printf("\n1. Shto regjistrim");
        printf("\n2. Shfaq te gjitha regjistrimet");
        printf("\n3. Dil");
        printf("\nZgjedhja: ");
        scanf("%d", &zgjedhja);

        if (zgjedhja == 1) {
            if (numriRegjistrimeve < MAX) {
                printf("Emri: ");
                scanf("%s", lista[numriRegjistrimeve].emri);

                printf("Mosha: ");
                scanf("%d", &lista[numriRegjistrimeve].mosha);

                printf("Nota: ");
                scanf("%f", &lista[numriRegjistrimeve].nota);

                numriRegjistrimeve++;
                printf("Regjistrimi u shtua me sukses!\n");
            } else {
                printf("Nuk mund te shtoni me regjistrime! Kapaciteti u arrit.\n");
            }
        }

        else if (zgjedhja == 2) {
            if (numriRegjistrimeve == 0) {
                printf("Nuk ka regjistrime.\n");
            } else {
                for (int i = 0; i < numriRegjistrimeve; i++) {
                    printf("\nRegjistrimi %d\n", i + 1);
                    printf("Emri: %s\n", lista[i].emri);
                    printf("Mosha: %d\n", lista[i].mosha);
                    printf("Nota: %.2f\n", lista[i].nota);
                }
            }
        }

    } while (zgjedhja != 3);

    return 0;
}
