#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    int id;
    char emri[50];
    int progresi;
    int statusi; // 0 = ne proces, 1 = perfunduar
} Regjistrim;

void kerko(Regjistrim r[], int n) {
    int zgjedhja;
    int u_gjet = 0;

    printf("\nKerko sipas:\n");
    printf("1. ID\n");
    printf("2. Emrit\n");
    printf("Zgjedhja: ");
    scanf("%d", &zgjedhja);

    if (zgjedhja == 1) {
        int id;
        printf("Jep ID: ");
        scanf("%d", &id);

        for (int i = 0; i < n; i++) {
            if (r[i].id == id) {
                u_gjet = 1;

                printf("\n--- Regjistrimi i gjetur ---\n");
                printf("ID: %d\n", r[i].id);
                printf("Emri: %s\n", r[i].emri);
                printf("Progresi: %d\n", r[i].progresi);
                printf("Statusi: %d\n", r[i].statusi);

                // Mesazh inteligjent me kushte te kombinuara
                printf("\n--- Vleresimi ---\n");
                if (r[i].statusi == 0 && r[i].progresi < 30) {
                    printf("Paralajmerim: Progres shume i ulet dhe ende ne proces.\n");
                } 
                else if (r[i].statusi == 0 && r[i].progresi >= 30 && r[i].progresi < 70) {
                    printf("Rekomandim: Progres mesatar, duhet permiresim.\n");
                } 
                else if (r[i].statusi == 1 && r[i].progresi < 50) {
                    printf("Kujdes: E perfunduar por me rezultat te ulet.\n");
                } 
                else if (r[i].statusi == 1 && r[i].progresi >= 50) {
                    printf("Mire: Regjistrim i perfunduar me sukses.\n");
                }
            }
        }
    }
    else if (zgjedhja == 2) {
        char emri[50];
        printf("Jep emrin: ");
        scanf("%s", emri);

        for (int i = 0; i < n; i++) {
            if (strcmp(r[i].emri, emri) == 0) {
                u_gjet = 1;

                printf("\n--- Regjistrimi i gjetur ---\n");
                printf("ID: %d\n", r[i].id);
                printf("Emri: %s\n", r[i].emri);
                printf("Progresi: %d\n", r[i].progresi);
                printf("Statusi: %d\n", r[i].statusi);

                printf("\n--- Vleresimi ---\n");
                if (r[i].statusi == 0 && r[i].progresi < 30) {
                    printf("Paralajmerim: Progres shume i ulet.\n");
                } 
                else if (r[i].progresi >= 70) {
                    printf("Rezultat shume i mire.\n");
                } 
                else {
                    printf("Rezultat mesatar.\n");
                }
            }
        }
    }

    if (!u_gjet) {
        printf("\nAsnje regjistrim nuk u gjet.\n");
    }
}
