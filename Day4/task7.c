#include <stdio.h>
#include <string.h>
#include <ctype.h>

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

        if (fgets(text, size, stdin) == NULL) {
            printf("Gabim gjate leximit.\n");
            continue;
        }

        text[strcspn(text, "\n")] = '\0';

        if (strlen(text) == 0) {
            printf("Teksti nuk mund te jete bosh.\n");
            continue;
        }

        return;
    }
}

void toLowerCase(char source[], char destination[]) {
    int i;
    for (i = 0; source[i] != '\0'; i++) {
        destination[i] = (char)tolower((unsigned char)source[i]);
    }
    destination[i] = '\0';
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
            case 1:
                return NOT_STARTED;
            case 2:
                return IN_PROGRESS;
            case 3:
                return COMPLETED;
            case 4:
                return FAILED;
            default:
                printf("Status i pavlefshem.\n");
        }
    }
}

void showSingleRecord(StudentProgress record) {
    printf("ID: %d\n", record.id);
    printf("Emri: %s\n", record.name);
    printf("Progresi: %d%%\n", record.progress);
    printf("Rezultati: %.2f\n", record.score);
    printf("Statusi: %s\n", statusToString(record.status));
}

void showEvaluation(StudentProgress record) {
    printf("Vleresimi: ");

    if (record.status == FAILED && record.progress < 50 && record.score < 50) {
        printf("Paralajmerim serioz - progres dhe rezultat i ulet.\n");
    } else if (record.status == NOT_STARTED && record.progress == 0) {
        printf("Nxenesi ende nuk e ka filluar punen.\n");
    } else if (record.status == IN_PROGRESS && record.progress >= 70 && record.score >= 70) {
        printf("Nxenesi eshte ne rruge shume te mire.\n");
    } else if (record.status == IN_PROGRESS && (record.progress < 40 || record.score < 50)) {
        printf("Ka shenja vonese. Duhet me shume pune.\n");
    } else if (record.status == COMPLETED && record.score >= 90) {
        printf("Shkelqyeshem - perfundim me rezultat te larte.\n");
    } else if (record.status == COMPLETED && record.score >= 60) {
        printf("Puna eshte perfunduar me sukses.\n");
    } else {
        printf("Gjendje mesatare. Kerkohet monitorim.\n");
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
        printf("\nIndeksi: %d\n", i);
        showSingleRecord(records[i]);
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
}

void searchById(StudentProgress records[], int count) {
    int id;
    int i;
    int found = 0;

    if (count == 0) {
        printf("\nNuk ka regjistrime per kerkim.\n");
        return;
    }

    id = readInt("Shkruaj ID-ne qe po e kerkon: ", 1, 9999);

    printf("\n--- Rezultati i kerkimit sipas ID-se ---\n");

    for (i = 0; i < count; i++) {
        if (records[i].id == id) {
            found = 1;
            showSingleRecord(records[i]);
            showEvaluation(records[i]);
            printf("\n");
        }
    }

    if (!found) {
        printf("Nuk u gjet asnje regjistrim me kete ID.\n");
    }
}

void searchByName(StudentProgress records[], int count) {
    char searchName[NAME_LENGTH];
    char searchNameLower[NAME_LENGTH];
    char currentNameLower[NAME_LENGTH];
    int i;
    int found = 0;

    if (count == 0) {
        printf("\nNuk ka regjistrime per kerkim.\n");
        return;
    }

    readString("Shkruaj emrin qe po e kerkon: ", searchName, NAME_LENGTH);
    toLowerCase(searchName, searchNameLower);

    printf("\n--- Rezultati i kerkimit sipas emrit ---\n");

    for (i = 0; i < count; i++) {
        toLowerCase(records[i].name, currentNameLower);

        if (strcmp(currentNameLower, searchNameLower) == 0) {
            found = 1;
            showSingleRecord(records[i]);
            showEvaluation(records[i]);
            printf("\n");
        }
    }

    if (!found) {
        printf("Nuk u gjet asnje regjistrim me kete emer.\n");
    }
}

void searchMenu(StudentProgress records[], int count) {
    int choice;

    if (count == 0) {
        printf("\nNuk ka regjistrime per kerkim.\n");
        return;
    }

    while (1) {
        printf("\n--- Menuja e Kerkimit ---\n");
        printf("1. Kerko sipas ID-se\n");
        printf("2. Kerko sipas emrit\n");
        printf("3. Kthehu\n");

        choice = readInt("Zgjedh nje opsion: ", 1, 3);

        switch (choice) {
            case 1:
                searchById(records, count);
                break;
            case 2:
                searchByName(records, count);
                break;
            case 3:
                return;
            default:
                printf("Opsion i pavlefshem.\n");
        }
    }
}

StudentProgress *findRecordById(StudentProgress records[], int count, int id) {
    int i;

    for (i = 0; i < count; i++) {
        if (records[i].id == id) {
            return &records[i];
        }
    }

    return NULL;
}

void updateRecordWithPointer(StudentProgress *record) {
    int option;

    while (1) {
        printf("\n--- Perditeso regjistrimin ---\n");
        printf("1. Ndrysho progresin\n");
        printf("2. Ndrysho rezultatin\n");
        printf("3. Ndrysho statusin\n");
        printf("4. Kthehu\n");

        option = readInt("Zgjedh nje opsion: ", 1, 4);

        switch (option) {
            case 1:
                record->progress = readInt("Shkruaj progresin e ri (0-100): ", 0, 100);
                printf("Progresi u perditesua me sukses.\n");
                break;
            case 2:
                record->score = readFloat("Shkruaj rezultatin e ri (0-100): ", 0.0f, 100.0f);
                printf("Rezultati u perditesua me sukses.\n");
                break;
            case 3:
                record->status = chooseStatus();
                printf("Statusi u perditesua me sukses.\n");
                break;
            case 4:
                return;
            default:
                printf("Opsion i pavlefshem.\n");
        }
    }
}

void updateRecordMenu(StudentProgress records[], int count) {
    int id;
    StudentProgress *foundRecord;

    if (count == 0) {
        printf("\nNuk ka regjistrime per perditesim.\n");
        return;
    }

    id = readInt("Shkruaj ID-ne e regjistrimit qe deshiron te perditesosh: ", 1, 9999);
    foundRecord = findRecordById(records, count, id);

    if (foundRecord == NULL) {
        printf("Nuk u gjet asnje regjistrim me kete ID.\n");
        return;
    }

    printf("\n--- Te dhenat para perditesimit ---\n");
    showSingleRecord(*foundRecord);

    updateRecordWithPointer(foundRecord);

    printf("\n--- Te dhenat pas perditesimit ---\n");
    showSingleRecord(*foundRecord);
}

void sortByScoreDescending(StudentProgress records[], int count) {
    int i, j;
    StudentProgress temp;

    if (count == 0) {
        printf("\nNuk ka regjistrime per renditje.\n");
        return;
    }

    for (i = 0; i < count - 1; i++) {
        for (j = 0; j < count - i - 1; j++) {
            if (records[j].score < records[j + 1].score) {
                temp = records[j];
                records[j] = records[j + 1];
                records[j + 1] = temp;
            }
        }
    }

    printf("\nRenditja sipas rezultatit u krye me sukses.\n");
}

void showRanking(StudentProgress records[], int count) {
    int i;

    if (count == 0) {
        printf("\nNuk ka regjistrime per rankim.\n");
        return;
    }

    sortByScoreDescending(records, count);

    printf("\n--- Rankimi Final sipas rezultatit ---\n");

    for (i = 0; i < count; i++) {
        printf("\nPozita %d\n", i + 1);
        showSingleRecord(records[i]);
    }
}

void editTwoFieldsMenu(StudentProgress records[], int count) {
    int id;
    StudentProgress *foundRecord;

    if (count == 0) {
        printf("\nNuk ka regjistrime per ndryshim.\n");
        return;
    }

    id = readInt("Shkruaj ID-ne e regjistrimit qe deshiron te ndryshosh: ", 1, 9999);
    foundRecord = findRecordById(records, count, id);

    if (foundRecord == NULL) {
        printf("Nuk u gjet asnje regjistrim me kete ID.\n");
        return;
    }

    printf("\n--- Para ndryshimit ---\n");
    showSingleRecord(*foundRecord);

    readString("Shkruaj emrin e ri: ", foundRecord->name, NAME_LENGTH);
    foundRecord->progress = readInt("Shkruaj progresin e ri (0-100): ", 0, 100);

    printf("\n--- Pas ndryshimit ---\n");
    showSingleRecord(*foundRecord);
}

void deleteById(StudentProgress records[], int *count) {
    int id;
    int i, j;
    int found = 0;

    if (*count == 0) {
        printf("\nNuk ka regjistrime per fshirje.\n");
        return;
    }

    id = readInt("Shkruaj ID-ne e regjistrimit qe deshiron te fshish: ", 1, 9999);

    for (i = 0; i < *count; i++) {
        if (records[i].id == id) {
            found = 1;

            for (j = i; j < *count - 1; j++) {
                records[j] = records[j + 1];
            }

            (*count)--;
            printf("Regjistrimi u fshi me sukses.\n");
            return;
        }
    }

    if (!found) {
        printf("Nuk u gjet asnje regjistrim me kete ID.\n");
    }
}

void deleteByIndex(StudentProgress records[], int *count) {
    int index;
    int j;

    if (*count == 0) {
        printf("\nNuk ka regjistrime per fshirje.\n");
        return;
    }

    showAllRecords(records, *count);
    index = readInt("Shkruaj indeksin qe deshiron te fshish: ", 0, *count - 1);

    for (j = index; j < *count - 1; j++) {
        records[j] = records[j + 1];
    }

    (*count)--;
    printf("Regjistrimi u fshi me sukses sipas indeksit.\n");
}

void deleteMenu(StudentProgress records[], int *count) {
    int choice;

    if (*count == 0) {
        printf("\nNuk ka regjistrime per fshirje.\n");
        return;
    }

    while (1) {
        printf("\n--- Menuja e Fshirjes ---\n");
        printf("1. Fshi sipas ID-se\n");
        printf("2. Fshi sipas indeksit\n");
        printf("3. Kthehu\n");

        choice = readInt("Zgjedh nje opsion: ", 1, 3);

        switch (choice) {
            case 1:
                deleteById(records, count);
                return;
            case 2:
                deleteByIndex(records, count);
                return;
            case 3:
                return;
            default:
                printf("Opsion i pavlefshem.\n");
        }
    }
}

int main() {
    StudentProgress records[MAX_RECORDS];
    int count = 0;
    int choice;

    do {
        printf("\n========================================\n");
        printf(" Student Progress Tracker - Task 7\n");
        printf("========================================\n");
        printf("1. Shto regjistrim\n");
        printf("2. Shfaq te gjitha regjistrimet\n");
        printf("3. Raport analitik\n");
        printf("4. Kerko regjistrim\n");
        printf("5. Perditeso regjistrim me pointer\n");
        printf("6. Shfaq rankimin final\n");
        printf("7. Ndrysho 2 fusha te regjistrimit\n");
        printf("8. Fshi regjistrim\n");
        printf("9. Dil\n");

        choice = readInt("Zgjedh nje opsion: ", 1, 9);

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
                searchMenu(records, count);
                break;
            case 5:
                updateRecordMenu(records, count);
                break;
            case 6:
                showRanking(records, count);
                break;
            case 7:
                editTwoFieldsMenu(records, count);
                break;
            case 8:
                deleteMenu(records, &count);
                break;
            case 9:
                printf("Programi u mbyll.\n");
                break;
            default:
                printf("Opsion i pavlefshem.\n");
        }

    } while (choice != 9);

    return 0;
}
