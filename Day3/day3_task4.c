#include <stdio.h>

int main() {
    // [cite: 98] Two numeric variables: one int and one double
    int valInt;
    double valDouble;

    // [cite: 98] Create pointers for each variable
    int *pInt = &valInt;
    double *pDouble = &valDouble;

    printf("--- Task 4: Memory and Pointer Analysis ---\n");
    printf("Enter an integer value: ");
    scanf("%d", &valInt);
    printf("Enter a double value: ");
    scanf("%lf", &valDouble);

    // Save initial value for later comparison [cite: 100]
    int originalValInt = valInt;

    //  Display direct values, memory addresses, and values via pointers
    printf("\n[Initial Data Analysis]\n");
    printf("Integer: Direct Value = %d, Address = %p, Via Pointer (*) = %d\n", valInt, (void*)&valInt, *pInt);
    printf("Double:  Direct Value = %.2f, Address = %p, Via Pointer (*) = %.2f\n", valDouble, (void*)&valDouble, *pDouble);

    // [cite: 100] Change the integer value through the pointer
    // For this task, we will add 20 to whatever the user entered
    *pInt = *pInt + 20;

    printf("\n[Modification Phase]\n");
    printf("Value before change: %d\n", originalValInt);
    printf("Value after change (*pInt + 20): %d\n", valInt);

    //  Logic check for final status and intervals
    printf("\n[Final Evaluation]\n");
    if (valInt > originalValInt) {
        printf("Status: The value has increased.\n");
    } else if (valInt < originalValInt) {
        printf("Status: The value has decreased.\n");
    } else {
        printf("Status: The value remained the same.\n");
    }

    // Checking if the final value enters a specific interval (e.g., 0 to 100)
    if (valInt >= 0 && valInt <= 100) {
        printf("Interval Check: The final value is within the [0, 100] range.\n");
    } else {
        printf("Interval Check: The final value is outside the [0, 100] range.\n");
    }

    return 0;
}
