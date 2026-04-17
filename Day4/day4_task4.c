#include <stdio.h>
#include <string.h>

#define MAX_RECORDS 5

typedef enum {
    IN_PROGRESS = 1,
    COMPLETED,
    FAILED
} Status;

typedef struct {
    int id;
    char name[50];
    float progress;
    Status status;
} Student;

// Requirement: Use a pointer in a function with a practical role
// This function directly modifies the progress in the array memory
void modifyProgress(float *currentValue, float newValue) {
    if (newValue >= 0 && newValue <= 100) {
        *currentValue = newValue;
    }
}

void printStatus(Status s) {
    switch(s) {
        case IN_PROGRESS: printf("In Progress"); break;
        case COMPLETED: printf("Completed  "); break;
        case FAILED: printf("Failed     "); break;
        default: printf("Unknown    "); break;
    }
}

int main() {
    Student records[MAX_RECORDS]; 
    int currentCount = 0; 
    int choice;

    while (1) {
        printf("\n--- Student Progress Tracker ---");
        printf("\n1. Add Student Record");
        printf("\n2. Display All Records");
        printf("\n3. Update Student Progress (Task 4)");
        printf("\n4. View Analytics Report");
        printf("\n0. Exit");
        printf("\nSelect an option: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("\n[Error] Invalid input. Enter a number.\n");
            while(getchar() != '\n'); 
            continue; 
        }

        switch (choice) {
            case 1:
                if (currentCount >= MAX_RECORDS) {
                    printf("\n[Error] Maximum capacity reached!\n");
                    break;
                }
                printf("\nEnter ID: ");
                scanf("%d", &records[currentCount].id);
                printf("Enter Name: ");
                scanf("%s", records[currentCount].name);
                printf("Enter Progress (0-100): ");
                scanf("%f", &records[currentCount].progress);
                printf("Select Status (1: In Progress, 2: Completed, 3: Failed): ");
                int st; scanf("%d", &st);
                records[currentCount].status = (Status)st;
                currentCount++;
                break;

            case 2:
                if (currentCount == 0) printf("\nNo records.\n");
                else {
                    for (int i = 0; i < currentCount; i++) {
                        printf("ID: %d | Name: %s | Progress: %.1f%% | Status: ", 
                                records[i].id, records[i].name, records[i].progress);
                        printStatus(records[i].status);
                        printf("\n");
                    }
                }
                break;

            case 3:
                // Requirement: Update logic using search and pointers
                if (currentCount == 0) {
                    printf("\n[Error] No records to update.\n");
                } else {
                    int searchID;
                    int found = 0;
                    printf("\nEnter Student ID to update: ");
                    scanf("%d", &searchID);

                    // Requirement: Use a loop to find the record
                    for (int i = 0; i < currentCount; i++) {
                        if (records[i].id == searchID) {
                            float newProg;
                            printf("Current progress for %s is %.1f%%. Enter new progress: ", 
                                    records[i].name, records[i].progress);
                            scanf("%f", &newProg);

                            // Requirement: Practical use of pointer to update value
                            modifyProgress(&records[i].progress, newProg);
                            
                            // Automatically update status if progress hits 100
                            if (records[i].progress == 100) {
                                records[i].status = COMPLETED;
                            }
                            
                            printf("[Success] Progress updated.\n");
                            found = 1;
                            break;
                        }
                    }
                    if (!found) printf("[Error] Student with ID %d not found.\n", searchID);
                }
                break;

            case 4:
                // Analytics report (from previous task)
                if (currentCount > 0) {
                    float total = 0;
                    for(int i=0; i<currentCount; i++) total += records[i].progress;
                    printf("\n--- Analytics ---\nAvg Progress: %.2f%%\n", total/currentCount);
                }
                break;

            case 0:
                return 0;

            default:
                printf("\nInvalid option.\n");
        }
    }
    return 0;
}
