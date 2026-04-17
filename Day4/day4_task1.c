#include <stdio.h>
#include <string.h>

// Defines the maximum capacity of our tracker
#define MAX_RECORDS 5 

typedef enum {
    IN_PROGRESS = 1,
    COMPLETED,
    FAILED
} Status;

// Base structure for keeping data organized
typedef struct {
    int id;
    char name[50];
    float progress;
    Status status;
} Student;

void updateProgress(float *pProgress, float newValue) {
    if (newValue >= 0 && newValue <= 100) {
        *pProgress = newValue;
    }
}

int main() {
    // Array to store multiple records up to the fixed limit
    Student records[MAX_RECORDS]; 
    
    // Tracks the current number of records separately from the max capacity
    int currentCount = 0; 
    int choice;

    while (1) {
        printf("\n--- Student Progress Tracker ---");
        printf("\n1. Add Student Record");
        printf("\n2. Display All Records");
        printf("\n0. Exit");
        printf("\nSelect an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Prevent adding records if we hit the maximum limit
                if (currentCount >= MAX_RECORDS) {
                    printf("\n[Error] Maximum capacity reached! Cannot add more than %d records.\n", MAX_RECORDS);
                    break;
                }

                printf("\nEnter ID: ");
                scanf("%d", &records[currentCount].id);
                printf("Enter Name: ");
                scanf("%s", records[currentCount].name);
                
                float startProgress;
                printf("Enter Initial Progress (0-100): ");
                scanf("%f", &startProgress);
                updateProgress(&records[currentCount].progress, startProgress);
                
                printf("Select Status (1: In Progress, 2: Completed, 3: Failed): ");
                int statusChoice;
                scanf("%d", &statusChoice);
                records[currentCount].status = (Status)statusChoice;

                currentCount++;
                printf("\n[Success] Record added. Current records: %d/%d\n", currentCount, MAX_RECORDS);
                break;

            case 2:
                // Display all stored records neatly
                if (currentCount == 0) {
                    printf("\nNo records stored yet.\n");
                } else {
                    printf("\n======================================================\n");
                    printf("ID\tName\t\tProgress\tStatus\n");
                    printf("------------------------------------------------------\n");
                    for (int i = 0; i < currentCount; i++) {
                        printf("%d\t%s\t\t%.1f%%\t\t%d\n", 
                                records[i].id, 
                                records[i].name, 
                                records[i].progress, 
                                records[i].status);
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
