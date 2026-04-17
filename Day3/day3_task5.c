#include <stdio.h>

// Requirement: Create an enum with at least four values 
typedef enum {
    LOW = 1,
    MEDIUM,
    HIGH,
    CRITICAL
} PriorityLevel;

int main() {
    int choice;
    int validCount = 0;   // Requirement: Counter for valid choices 
    int invalidCount = 0; // Requirement: Counter for invalid choices 

    printf("--- Task 5: Task Priority Manager ---\n");

    // Requirement: Use a for loop for three cases/users 
    for (int i = 1; i <= 3; i++) {
        printf("\nUser %d, please select a priority level:\n", i);
        printf("1. Low\n2. Medium\n3. High\n4. Critical\n");
        printf("Enter your choice (1-4): ");
        
        // Handle non-numeric input for robustness
        if (scanf("%d", &choice) != 1) {
            printf("Error: Please enter a numeric value.\n");
            invalidCount++;
            while(getchar() != '\n'); // Clear input buffer
            continue;
        }

        // Requirement: Link numerical choice to enum value 
        PriorityLevel selection = (PriorityLevel)choice;

        // Requirement: Use switch or if/else for enum logic 
        switch (selection) {
            case LOW:
                printf("Response: Routine task. No rush.\n");
                validCount++;
                break;
            case MEDIUM:
                printf("Response: Standard task. Complete within the week.\n");
                validCount++;
                break;
            case HIGH:
                printf("Response: Urgent task. Complete within 24 hours.\n");
                validCount++;
                break;
            case CRITICAL:
                printf("Response: Immediate action required!\n");
                validCount++;
                break;
            default:
                // Requirement: Handle invalid input with a clear message 
                printf("Invalid choice! '%d' is not a valid priority level.\n", choice);
                invalidCount++;
                break;
        }
    }

    // Requirement: Display final statistics 
    printf("\n--- Session Statistics ---\n");
    printf("Valid Entries: %d\n", validCount);
    printf("Invalid Entries: %d\n", invalidCount);

    return 0;
}
