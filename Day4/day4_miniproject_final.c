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

// Helper to clear input buffer
void clearBuffer() {
    while (getchar() != '\n');
}

// Helper to print enum as text
void printStatus(Status s) {
    switch(s) {
        case IN_PROGRESS: printf("In Progress"); break;
        case COMPLETED: printf("Completed  "); break;
        case FAILED: printf("Failed     "); break;
        default: printf("Unknown    "); break;
    }
}

// Task 4: Pointer function
void updateProgressViaPointer(float *currentProgress, float newProgress) {
    if (newProgress >= 0 && newProgress <= 100) {
        *currentProgress = newProgress; 
    }
}

int main() {
    Student records[MAX_RECORDS]; 
    int currentCount = 0; 
    int choice;

    while (1) {
        printf("\n========================================");
        printf("\n    STUDENT PROGRESS TRACKER - V3.0     ");
        printf("\n========================================");
        printf("\n1. Add New Student Record");
        printf("\n2. Display All Records");
        printf("\n3. Update Student Progress (via Pointer)");
        printf("\n4. Edit Student Details (Name & Status)");
        printf("\n5. Delete Student Record");
        printf("\n6. Search & Evaluate Student");
        printf("\n7. Sort & Rank Students by Progress");
        printf("\n8. View Analytics Report");
        printf("\n0. Exit Program");
        printf("\nSelect an option: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("\n[Error] Invalid input. Please enter a number.\n");
            clearBuffer(); 
            continue; 
        }

        switch (choice) {
            case 1: // --- ADD RECORD ---
                if (currentCount >= MAX_RECORDS) {
                    printf("\n[Error] Maximum capacity reached (%d/%d).\n", MAX_RECORDS, MAX_RECORDS);
                    break;
                }

                printf("\n--- Add Record (%d/%d) ---\n", currentCount + 1, MAX_RECORDS);
                printf("Enter Student ID: ");
                while (scanf("%d", &records[currentCount].id) != 1) {
                    printf("[Error] ID must be a number. Enter ID: ");
                    clearBuffer();
                }
                
                printf("Enter Student Name: ");
                scanf("%49s", records[currentCount].name); 
                
                float startProgress;
                printf("Enter Initial Progress (0-100): ");
                while (scanf("%f", &startProgress) != 1 || startProgress < 0 || startProgress > 100) {
                    printf("[Error] Progress must be 0-100. Enter Progress: ");
                    clearBuffer();
                }
                records[currentCount].progress = startProgress;
                
                int validStatus = 0;
                int statusChoice;
                while (!validStatus) {
                    printf("Select Status (1: In Progress, 2: Completed, 3: Failed): ");
                    if (scanf("%d", &statusChoice) != 1) {
                        printf("[Error] Enter a valid number.\n");
                        clearBuffer();
                        continue;
                    }
                    switch (statusChoice) {
                        case 1: records[currentCount].status = IN_PROGRESS; validStatus = 1; break;
                        case 2: records[currentCount].status = COMPLETED; validStatus = 1; break;
                        case 3: records[currentCount].status = FAILED; validStatus = 1; break;
                        default: printf("[Error] Choice must be 1, 2, or 3.\n"); break;
                    }
                }
                currentCount++; 
                printf("\n[Success] Record added successfully.\n");
                break;

            case 2: // --- DISPLAY ALL ---
                if (currentCount == 0) {
                    printf("\n[Info] No records stored yet.\n");
                } else {
                    printf("\nID\tName\t\tProgress\tStatus\n");
                    printf("------------------------------------------------------\n");
                    for (int i = 0; i < currentCount; i++) {
                        printf("%d\t%s\t\t%.1f%%\t\t", records[i].id, records[i].name, records[i].progress);
                        printStatus(records[i].status);
                        printf("\n");
                    }
                }
                break;

            case 3: // --- UPDATE PROGRESS (POINTER) ---
                if (currentCount == 0) {
                    printf("\n[Error] No records available to update.\n");
                } else {
                    int searchID, found = 0;
                    printf("\nEnter Student ID to update progress: ");
                    scanf("%d", &searchID);

                    for (int i = 0; i < currentCount; i++) {
                        if (records[i].id == searchID) {
                            float newProg;
                            printf("Current progress for %s is %.1f%%. Enter new value: ", records[i].name, records[i].progress);
                            scanf("%f", &newProg);

                            updateProgressViaPointer(&records[i].progress, newProg);
                            if (records[i].progress == 100) records[i].status = COMPLETED;
                            printf("[Success] Progress updated.\n");
                            found = 1;
                            break;
                        }
                    }
                    if (!found) printf("[Error] Student ID %d not found.\n", searchID);
                }
                break;

            case 4: // --- TASK 7: EDIT RECORD DETAILS ---
                if (currentCount == 0) {
                    printf("\n[Error] No records to edit.\n");
                } else {
                    int editID, found = 0;
                    printf("\nEnter Student ID to edit: ");
                    scanf("%d", &editID);

                    for (int i = 0; i < currentCount; i++) {
                        if (records[i].id == editID) {
                            printf("Editing details for %s (ID: %d)\n", records[i].name, records[i].id);
                            
                            // Edit Field 1: Name
                            printf("Enter new name (or type current name '%s'): ", records[i].name);
                            scanf("%49s", records[i].name);

                            // Edit Field 2: Status
                            int newStatusChoice;
                            printf("Enter new status (1: In Progress, 2: Completed, 3: Failed): ");
                            scanf("%d", &newStatusChoice);
                            if (newStatusChoice >= 1 && newStatusChoice <= 3) {
                                records[i].status = (Status)newStatusChoice;
                                printf("[Success] Name and Status updated successfully.\n");
                            } else {
                                printf("[Error] Invalid status. Keeping old status.\n");
                            }
                            found = 1;
                            break;
                        }
                    }
                    if (!found) printf("[Error] Student ID %d not found.\n", editID);
                }
                break;

            case 5: // --- TASK 7: DELETE RECORD ---
                if (currentCount == 0) {
                    printf("\n[Error] No records to delete.\n");
                } else {
                    int delID, found = 0;
                    printf("\nEnter Student ID to DELETE: ");
                    scanf("%d", &delID);

                    for (int i = 0; i < currentCount; i++) {
                        if (records[i].id == delID) {
                            // Shift all subsequent elements one position to the left
                            for (int j = i; j < currentCount - 1; j++) {
                                records[j] = records[j + 1];
                            }
                            currentCount--; // Decrement the total count
                            printf("[Success] Record with ID %d deleted successfully.\n", delID);
                            found = 1;
                            break;
                        }
                    }
                    if (!found) printf("[Error] Student ID %d not found.\n", delID);
                }
                break;

            case 6: // --- TASK 5: SEARCH & EVALUATE ---
                if (currentCount == 0) {
                    printf("\n[Error] No records available.\n");
                } else {
                    int searchID, found = 0;
                    printf("\nEnter Student ID to evaluate: ");
                    scanf("%d", &searchID);

                    for (int i = 0; i < currentCount; i++) {
                        if (records[i].id == searchID) {
                            printf("\n--- Evaluation for %s ---\n", records[i].name);
                            if (records[i].status == FAILED) printf(">> ADVICE: Student has failed. Schedule review.\n");
                            else if (records[i].status == IN_PROGRESS && records[i].progress < 40.0) printf(">> WARNING: High risk! Low progress.\n");
                            else if (records[i].status == COMPLETED) printf(">> NOTE: Task finished. Assign next module.\n");
                            else printf(">> NOTE: Student is progressing normally.\n");
                            found = 1;
                            break;
                        }
                    }
                    if (!found) printf("[Error] Student ID %d not found.\n", searchID);
                }
                break;

            case 7: // --- TASK 6: SORT & RANK ---
                if (currentCount == 0) {
                    printf("\n[Error] No records to sort.\n");
                } else {
                    // Bubble Sort descending by progress
                    for (int i = 0; i < currentCount - 1; i++) {
                        for (int j = 0; j < currentCount - i - 1; j++) {
                            if (records[j].progress < records[j + 1].progress) {
                                Student temp = records[j];
                                records[j] = records[j + 1];
                                records[j + 1] = temp;
                            }
                        }
                    }
                    printf("\n[Success] Records ranked by Progress (Highest to Lowest).\n");
                    printf("\nRANK\tID\tName\t\tProgress\tStatus\n");
                    printf("------------------------------------------------------\n");
                    for (int i = 0; i < currentCount; i++) {
                        printf("#%d\t%d\t%s\t\t%.1f%%\t\t", i+1, records[i].id, records[i].name, records[i].progress);
                        printStatus(records[i].status);
                        printf("\n");
                    }
                }
                break;

            case 8: // --- TASK 3: ANALYTICS ---
                if (currentCount == 0) printf("\n[Analytics] Not enough data.\n");
                else {
                    float totalProgress = 0;
                    int completedCount = 0, topIndex = 0;
                    for (int i = 0; i < currentCount; i++) {
                        totalProgress += records[i].progress;
                        if (records[i].status == COMPLETED) completedCount++;
                        if (records[i].progress > records[topIndex].progress) topIndex = i;
                    }
                    float average = totalProgress / currentCount;
                    printf("\n========== ANALYTICS REPORT ==========\n");
                    printf("Total Tracked:      %d records\n", currentCount);
                    printf("Completed Tasks:    %d\n", completedCount);
                    printf("Average Progress:   %.2f%%\n", average);
                    printf("Top Performer:      %s (%.1f%%)\n", records[topIndex].name, records[topIndex].progress);
                    printf("======================================\n");
                }
                break;

            case 0:
                printf("\nExiting Student Tracker... Goodbye!\n");
                return 0;

            default:
                printf("\n[Error] Invalid choice.\n");
        }
    }
    return 0;
}
