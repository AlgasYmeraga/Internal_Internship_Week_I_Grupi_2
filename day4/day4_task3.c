#include <stdio.h>

#define MAX 100

int main() {
    int progresi[MAX];
    int statusi[MAX]; // 0 = ne proces, 1 = perfunduar
    int n;

    printf("Sa regjistrime deshironi te shtoni: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("\nNuk ka te dhena per raport.\n");
        return 0;
    }

    // Marrja e te dhenave
    for (int i = 0; i < n; i++) {
        printf("\nRegjistrimi %d\n", i + 1);

        printf("Progresi (0-100): ");
        scanf("%d", &progresi[i]);

        printf("Statusi (0 = ne proces, 1 = perfunduar): ");
        scanf("%d", &statusi[i]);
    }

    // Analiza
    int total = n;
    int perfunduar = 0;
    int max = progresi[0];
    int min = progresi[0];
    int shuma = 0;

    for (int i = 0; i < n; i++) {
        shuma += progresi[i];

        if (statusi[i] == 1) {
            perfunduar++;
        }

        if (progresi[i] > max) {
            max = progresi[i];
        }

        if (progresi[i] < min) {
            min = progresi[i];
        }
    }

    float mesatarja = (float)shuma / n;

    // Raporti
    printf("\n--- RAPORT ANALITIK ---\n");
    printf("Total regjistrime: %d\n", total);
    printf("Te perfunduara: %d\n", perfunduar);
    printf("Mesatarja e progresit: %.2f\n", mesatarja);
    printf("Progresi maksimal: %d\n", max);
    printf("Progresi minimal: %d\n", min);

    // Klasifikim me if/else
    if (mesatarja >= 80) {
        printf("Vleresim: Progres shume i mire\n");
    } else if (mesatarja >= 50) {
        printf("Vleresim: Progres mesatar\n");
    } else {
        printf("Vleresim: Progres i ulet\n");
    }

    return 0;
}
