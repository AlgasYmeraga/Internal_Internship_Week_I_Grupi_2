#include <stdio.h>
#include <string.h>

#define MAX_RECORDS 10
#define NAME_LENGTH 50

typedef enum {
    NOT_STARTED = 1,
    IN_PROGRESS,
    COMPLETED,
    FAILED
} Status;

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int progress;
    float score;
    Status status;
} StudentProgress;

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

int readInt(const char *message, int min, int max) {
    int value;
    int result;

    while (1) {
        printf("%s", message);
        result = scanf("%d", &value);

        if (result != 1) {
            printf("Input i pavlefshem. Shkruaj nje numer.\n");
            clearInputBuffer();
            continue;
        }

        clearInputBuffer();

        if (value < min || value > max) {
            printf("Vlera duhet te jete nga %d deri ne %d.\n", min, max);
            continue;
        }

        return value;
    }
}

float readFloat(const char *message, float min, float max) {
    float value;
    int result;

    while (1) {
        printf("%s", message);
        result = scanf("%f", &value);

        if (result != 1) {
            printf("Input i pavlefshem. Shkruaj nje numer.\n");
            clearInputBuffer();
            continue;
        }

        clearInputBuffer();

        if (value < min || value > max) {
            printf("Vlera duhet te jete nga %.2f deri ne %.2f.\n", min, max);
            continue;
        }

        return value;
    }
}

void readString(const char *message, char text[], int size) {
    while (1) {
        printf("%s", message);
        fgets(text, size, stdin);
        text[strcspn(text, "\n")] = '\0';

        if (strlen(text) == 0) {
            printf("Teksti nuk mund te jete bosh.\n");
            continue;
        }

        return;
    }
}

const char *statusToString(Status status) {
    switch (status) {
        case NOT_STARTED:
            return "Not Started";
        case IN_PROGRESS:
            return "In Progress";
        case COMPLETED:
            return "Completed";
        case FAILED:
            return "Failed";
        default:
            return "Unknown";
    }
}

Status chooseStatus() {
    int choice;

    while (1) {
        printf("\nZgjedh statusin:\n");
        printf("1. Not Started\n");
        printf("2. In Progress\n");
        printf("3. Completed\n");
        printf("4. Failed\n");

        choice = readInt("Zgjedhja juaj: ", 1, 4);

        switch (choice) {
            case 1: return NOT_STARTED;
            case 2: return IN_PROGRESS;
            case 3: return COMPLETED;
            case 4: return FAILED;
            default:
                printf("Status i pavlefshem.\n");
        }
    }
}

void addRecord(StudentProgress records[], int *count) {
    StudentProgress *current;

    if (*count >= MAX_RECORDS) {
        printf("\nNuk mund te shtoni me regjistrime. Eshte arritur maksimumi prej %d.\n", MAX_RECORDS);
        return;
    }

    current = &records[*count];

    printf("\n--- Shto regjistrim te ri ---\n");
    current->id = readInt("Shkruaj ID (1-9999): ", 1, 9999);
    readString("Shkruaj emrin: ", current->name, NAME_LENGTH);
    current->progress = readInt("Shkruaj progresin (0-100): ", 0, 100);
    current->score = readFloat("Shkruaj rezultatin (0-100): ", 0.0f, 100.0f);
    current->status = chooseStatus();

    (*count)++;
    printf("Regjistrimi u shtua me sukses. Keni %d/%d regjistrime.\n", *count, MAX_RECORDS);
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
        printf("Statusi: %s\n", statusToString(records[i].status));
    }
}

int main() {
    StudentProgress records[MAX_RECORDS];
    int count = 0;
    int choice;

    do {
        printf("\n===== Student Progress Tracker - Task 2 =====\n");
        printf("1. Shto regjistrim\n");
        printf("2. Shfaq te gjitha regjistrimet\n");
        printf("3. Dil\n");

        choice = readInt("Zgjedh nje opsion: ", 1, 3);

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
