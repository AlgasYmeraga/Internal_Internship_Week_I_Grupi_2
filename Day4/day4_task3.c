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

void updateProgress(float *pProgress, float newValue) {
    if (newValue >= 0 && newValue <= 100) {
        *pProgress = newValue;
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
        printf("\n3. View Analytics Report"); // New Option for Task 3
        printf("\n0. Exit");
        printf("\nSelect an option: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("\n[Error] Invalid input. Please enter a number.\n");
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
                scanf("%49s", records[currentCount].name);
                
                float startProgress;
                printf("Enter Progress (0-100): ");
                scanf("%f", &startProgress);
                updateProgress(&records[currentCount].progress, startProgress);
                
                int statusChoice;
                printf("Select Status (1: In Progress, 2: Completed, 3: Failed): ");
                scanf("%d", &statusChoice);
                records[currentCount].status = (Status)statusChoice;

                currentCount++;
                break;

            case 2:
                if (currentCount == 0) {
                    printf("\nNo records stored yet.\n");
                } else {
                    printf("\nID\tName\t\tProgress\tStatus\n");
                    for (int i = 0; i < currentCount; i++) {
                        printf("%d\t%s\t\t%.1f%%\t\t", records[i].id, records[i].name, records[i].progress);
                        printStatus(records[i].status);
                        printf("\n");
                    }
                }
                break;

            case 3:
                // Requirement: Analytics Report logic
                if (currentCount == 0) {
                    printf("\n[Analytics] No data available to analyze.\n"); // Handle empty list 
                } else {
                    float totalProgress = 0;
                    int completedCount = 0;
                    int topIndex = 0;

                    // Requirement: Use for loop to iterate through all data 
                    for (int i = 0; i < currentCount; i++) {
                        totalProgress += records[i].progress;
                        
                        if (records[i].status == COMPLETED) {
                            completedCount++;
                        }

                        if (records[i].progress > records[topIndex].progress) {
                            topIndex = i;
                        }
                    }

                    float average = totalProgress / currentCount;

                    // Requirement: Print report in a readable block [cite: 189]
                    printf("\n========== ANALYTICS REPORT ==========\n");
                    printf("Total Students:     %d\n", currentCount);
                    printf("Completed Tasks:    %d\n", completedCount);
                    printf("Average Progress:   %.2f%%\n", average);
                    printf("Top Performer:      %s (%.1f%%)\n", records[topIndex].name, records[topIndex].progress);
                    
                    // Requirement: Classification using if/else 
                    printf("Overall Status:     ");
                    if (average >= 80) {
                        printf("EXCELLENT - The group is highly productive.\n");
                    } else if (average >= 50) {
                        printf("STABLE - Progress is on track.\n");
                    } else {
                        printf("CRITICAL - Immediate intervention required.\n");
                    }
                    printf("======================================\n");
                }
                break;

            case 0:
                return 0;

            default:
                printf("\n[Error] Invalid choice.\n");
        }
    }
    return 0;
}
