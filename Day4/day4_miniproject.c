#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 5

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

// FUNCTION to display students
void displayStudents(Student students[], int count) {
    if (count == 0) {
        printf("No students added yet.\n");
        return;
    }

    printf("\n--- Student List ---\n");

    for (int i = 0; i < count; i++) {
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

        printf("----------------------\n");
    }
}

int main() {
    Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Add Student\n");
        printf("2. Show Students\n");
        printf("0. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (count < MAX_STUDENTS) {
                    addStudent(&students[count]);
                    count++;
                } else {
                    printf("Student list is full.\n");
                }
                break;

            case 2:
                displayStudents(students, count);
                break;

            case 0:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid option.\n");
        }

    } while (choice != 0);

    return 0;
}
