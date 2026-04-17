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
        case NOT_STARTED: return "Not Started";
        case IN_PROGRESS: return "In Progress";
        case COMPLETED: return "Completed";
        case FAILED: return "Failed";
        default: return "Unknown";
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

void analyticsReport(StudentProgress records[], int count) {
    int i;
    int completedCount = 0;
    int inProgressCount = 0;
    int failedCount = 0;
    int totalProgress = 0;
    float totalScore = 0.0f;
    int highestProgress;
    int lowestProgress;
    float highestScore;
    float lowestScore;
    float averageProgress;
    float averageScore;

    if (count == 0) {
        printf("\n--- Raporti Analitik ---\n");
        printf("Lista eshte bosh. Shto fillimisht te pakten nje regjistrim.\n");
        return;
    }

    highestProgress = records[0].progress;
    lowestProgress = records[0].progress;
    highestScore = records[0].score;
    lowestScore = records[0].score;

    for (i = 0; i < count; i++) {
        totalProgress += records[i].progress;
        totalScore += records[i].score;

        if (records[i].status == COMPLETED) {
            completedCount++;
        } else if (records[i].status == IN_PROGRESS) {
            inProgressCount++;
        } else if (records[i].status == FAILED) {
            failedCount++;
        }

        if (records[i].progress > highestProgress) {
            highestProgress = records[i].progress;
        }

        if (records[i].progress < lowestProgress) {
            lowestProgress = records[i].progress;
        }

        if (records[i].score > highestScore) {
            highestScore = records[i].score;
        }

        if (records[i].score < lowestScore) {
            lowestScore = records[i].score;
        }
    }

    averageProgress = (float) totalProgress / count;
    averageScore = totalScore / count;

    printf("\n--- Raporti Analitik ---\n");
    printf("Numri total i regjistrimeve: %d\n", count);
    printf("Te perfunduara: %d\n", completedCount);
    printf("Ne progres: %d\n", inProgressCount);
    printf("Te deshtuara: %d\n", failedCount);
    printf("Mesatarja e progresit: %.2f%%\n", averageProgress);
    printf("Mesatarja e rezultatit: %.2f\n", averageScore);
    printf("Progresi me i larte: %d%%\n", highestProgress);
    printf("Progresi me i ulet: %d%%\n", lowestProgress);
    printf("Rezultati me i larte: %.2f\n", highestScore);
    printf("Rezultati me i ulet: %.2f\n", lowestScore);

    if (averageProgress >= 85) {
        printf("Klasifikim: Grupi po ecen shume mire.\n");
    } else if (averageProgress >= 60) {
        printf("Klasifikim: Grupi eshte ne rruge te mire, por ka vend per permiresim.\n");
    } else {
        printf("Klasifikim: Nevojitet me shume pune.\n");
    }

    if (completedCount == count) {
        printf("Mesazh: Te gjitha regjistrimet jane perfunduar.\n");
    } else if (completedCount == 0) {
        printf("Mesazh: Asnje regjistrim nuk eshte perfunduar ende.\n");
    } else {
        printf("Mesazh: Disa jane perfunduar, disa ende jo.\n");
    }
}

int main() {
    StudentProgress records[MAX_RECORDS];
    int count = 0;
    int choice;

    do {
        printf("\n===== Student Progress Tracker - Task 3 =====\n");
        printf("1. Shto regjistrim\n");
        printf("2. Shfaq te gjitha regjistrimet\n");
        printf("3. Raport analitik\n");
        printf("4. Dil\n");

        choice = readInt("Zgjedh nje opsion: ", 1, 4);

        switch (choice) {
            case 1:
                addRecord(records, &count);
                break;
            case 2:
                showAllRecords(records, count);
                break;
            case 3:
                analyticsReport(records, count);
                break;
            case 4:
                printf("Programi u mbyll.\n");
                break;
            default:
                printf("Opsion i pavlefshem.\n");
        }

    } while (choice != 4);

    return 0;
}
