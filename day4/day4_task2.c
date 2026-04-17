#include <stdio.h>
#include <string.h>

#define MAX_RECORDS 5

// Requirement: Create an enum for status [cite: 171]
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

// Helper function to safely update progress via pointer
void updateProgress(float *pProgress, float newValue) {
    if (newValue >= 0 && newValue <= 100) {
        *pProgress = newValue;
    }
}

// Helper function to print enum as text
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
        printf("\n0. Exit");
        printf("\nSelect an option: ");
        
        // Requirement: Validate invalid menu choices 
        if (scanf("%d", &choice) != 1) {
            printf("\n[Error] Invalid input. Please enter a number.\n");
            while(getchar() != '\n'); // Clear the input buffer
            continue; // Restart the loop
        }

        // Requirement: Use switch for main menu 
        switch (choice) {
            case 1:
                if (currentCount >= MAX_RECORDS) {
                    printf("\n[Error] Maximum capacity reached! Cannot add more than %d records.\n", MAX_RECORDS);
                    break;
                }

                printf("\nEnter ID: ");
                while (scanf("%d", &records[currentCount].id) != 1) {
                    printf("[Error] ID must be a number. Enter ID: ");
                    while(getchar() != '\n');
                }
                
                printf("Enter Name: ");
                scanf("%49s", records[currentCount].name); // Limit input to prevent overflow
                
                float startProgress;
                printf("Enter Initial Progress (0-100): ");
                while (scanf("%f", &startProgress) != 1 || startProgress < 0 || startProgress > 100) {
                    printf("[Error] Progress must be a number between 0 and 100. Enter Progress: ");
                    while(getchar() != '\n');
                }
                updateProgress(&records[currentCount].progress, startProgress);
                
                // Requirement: Validate enum input with a secondary switch 
                int validStatus = 0;
                int statusChoice;
                while (!validStatus) {
                    printf("Select Status (1: In Progress, 2: Completed, 3: Failed): ");
                    if (scanf("%d", &statusChoice) != 1) {
                        printf("[Error] Please enter a valid number.\n");
                        while(getchar() != '\n');
                        continue;
                    }

                    switch (statusChoice) {
                        case 1:
                            records[currentCount].status = IN_PROGRESS; // Requirement: Link enum to data [cite: 172]
                            validStatus = 1;
                            break;
                        case 2:
                            records[currentCount].status = COMPLETED;
                            validStatus = 1;
                            break;
                        case 3:
                            records[currentCount].status = FAILED;
                            validStatus = 1;
                            break;
                        default:
                            printf("[Error] Invalid status choice. Must be 1, 2, or 3.\n");
                            break;
                    }
                }

                currentCount++;
                printf("\n[Success] Record added. Current records: %d/%d\n", currentCount, MAX_RECORDS);
                break;

            case 2:
                if (currentCount == 0) {
                    printf("\nNo records stored yet.\n");
                } else {
                    printf("\n======================================================\n");
                    printf("ID\tName\t\tProgress\tStatus\n");
                    printf("------------------------------------------------------\n");
                    for (int i = 0; i < currentCount; i++) {
                        printf("%d\t%s\t\t%.1f%%\t\t", 
                                records[i].id, 
                                records[i].name, 
                                records[i].progress);
                        printStatus(records[i].status); // Output text instead of numbers
                        printf("\n");
                    }
                    printf("======================================================\n");
                }
                break;

            case 0:
                printf("\nExiting program...\n");
                return 0;

            default:
                printf("\n[Error] Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
