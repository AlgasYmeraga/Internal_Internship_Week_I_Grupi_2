#include <stdio.h>
#include <string.h>

#define MAX_RECORDS 10
#define NAME_LENGTH 50
#define STATUS_LENGTH 20

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int progress;
    float score;
    char status[STATUS_LENGTH];
} StudentProgress;

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

void addRecord(StudentProgress records[], int *count) {
    if (*count >= MAX_RECORDS) {
        printf("\nNuk mund te shtoni me regjistrime. Eshte arritur maksimumi prej %d.\n", MAX_RECORDS);
        return;
    }

    printf("\n--- Shto regjistrim te ri ---\n");

    printf("Shkruaj ID: ");
    scanf("%d", &records[*count].id);
    clearInputBuffer();

    printf("Shkruaj emrin: ");
    fgets(records[*count].name, NAME_LENGTH, stdin);
    records[*count].name[strcspn(records[*count].name, "\n")] = '\0';

    printf("Shkruaj progresin (0-100): ");
    scanf("%d", &records[*count].progress);
    clearInputBuffer();

    printf("Shkruaj rezultatin: ");
    scanf("%f", &records[*count].score);
    clearInputBuffer();

    printf("Shkruaj statusin: ");
    fgets(records[*count].status, STATUS_LENGTH, stdin);
    records[*count].status[strcspn(records[*count].status, "\n")] = '\0';

    (*count)++;
    printf("Regjistrimi u shtua me sukses. Aktualisht keni %d/%d regjistrime.\n", *count, MAX_RECORDS);
}

void showAllRecords(StudentProgress records[], int count) {
    int i;

    if (count == 0) {
        printf("\nNuk ka asnje regjistrim te ruajtur.\n");
        return;
    }

    printf("\n--- Te gjitha regjistrimet ---\n");
    for (i = 0; i < count; i++) {
        printf("\nRegjistrimi %d\n", i + 1);
        printf("ID: %d\n", records[i].id);
        printf("Emri: %s\n", records[i].name);
        printf("Progresi: %d%%\n", records[i].progress);
        printf("Rezultati: %.2f\n", records[i].score);
        printf("Statusi: %s\n", records[i].status);
    }
}

int main() {
    StudentProgress records[MAX_RECORDS];
    int count = 0;
    int choice;

    do {
        printf("\n===== Student Progress Tracker - Task 1 =====\n");
        printf("1. Shto regjistrim\n");
        printf("2. Shfaq te gjitha regjistrimet\n");
        printf("3. Dil\n");
        printf("Zgjedh nje opsion: ");
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice) {
            case 1:
                addRecord(records, &count);
                break;
            case 2:
                showAllRecords(records, count);
                break;
            case 3:
                printf("Programi u mbyll.\n");
                break;
            default:
                printf("Opsion i pavlefshem.\n");
        }

    } while (choice != 3);

    return 0;
}
