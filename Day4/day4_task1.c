#include <stdio.h>
#include <string.h>

#define MAX 5

typedef enum {
    NOT_STARTED,
    IN_PROGRESS,
    COMPLETED
} Status;

typedef struct {
    int id;
    char name[50];
    float progress;
    Status status;
} Student;

void addStudent(Student *s) {
    printf("Enter ID: ");
    scanf("%d", &s->id);

    printf("Enter Name: ");
    scanf("%s", s->name);

    printf("Enter Progress (0-100): ");
    scanf("%f", &s->progress);

    if (s->progress < 0 || s->progress > 100) {
        printf("Invalid progress. Setting to 0.\n");
        s->progress = 0;
    }

    if (s->progress == 0) {
        s->status = NOT_STARTED;
    } else if (s->progress < 100) {
        s->status = IN_PROGRESS;
    } else {
        s->status = COMPLETED;
    }
}

void showStudents(Student students[], int count) {
    if (count == 0) {
        printf("No records found.\n");
        return;
    }

    printf("\n--- All Students ---\n");

    for (int i = 0; i < count; i++) {
        printf("\nStudent %d\n", i + 1);
        printf("ID: %d\n", students[i].id);
        printf("Name: %s\n", students[i].name);
        printf("Progress: %.2f\n", students[i].progress);

        switch (students[i].status) {
            case NOT_STARTED:
                printf("Status: Not Started\n");
                break;
            case IN_PROGRESS:
                printf("Status: In Progress\n");
                break;
            case COMPLETED:
                printf("Status: Completed\n");
                break;
        }
    }
}

int main() {
    Student students[MAX];
    int count = 0;
    int choice;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Add Student\n");
        printf("2. Show All Students\n");
        printf("0. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (count >= MAX) {
                    printf("Maximum limit reached. Cannot add more students.\n");
                } else {
                    addStudent(&students[count]);
                    count++;
                }
                break;

            case 2:
                showStudents(students, count);
                break;

            case 0:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid option.\n");
        }

    } while (choice != 0);

    return 0;
}
