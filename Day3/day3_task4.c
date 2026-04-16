int main() {
    // Requirement: Use at least two numeric variables 
    int count;
    double price;

    // Requirement: Create pointers for each 
    int *pCount = &count;
    double *pPrice = &price;

    printf("--- Task 4: Pointer Operations ---\n");
    printf("Enter an integer value (count): ");
    scanf("%d", &count);
    printf("Enter a double value (price): ");
    scanf("%lf", &price);

    // Store original value for comparison [cite: 59, 60]
    int initialCount = count;

    // Requirement: Display values, addresses, and pointer access 
    printf("\n[Initial State]\n");
    printf("Variable 'count': Value = %d, Address = %p\n", count, (void*)&count);
    printf("Via pCount: Value = %d, Stored Address = %p\n", *pCount, (void*)pCount);
    
    printf("\nVariable 'price': Value = %.2f, Address = %p\n", price, (void*)&price);
    printf("Via pPrice: Value = %.2f, Stored Address = %p\n", *pPrice, (void*)pPrice);

    // Requirement: Change at least one value through a pointer 
    // Example: Adding 10 to the count through the pointer
    *pCount = *pCount + 10;

    printf("\n[After Modification via Pointer]\n");
    printf("New value of 'count': %d\n", count);

    // Requirement: if/else check to show change status 
    if (count > initialCount) {
        printf("Status: The value has increased.\n");
    } else if (count < initialCount) {
        printf("Status: The value has decreased.\n");
    } else {
        printf("Status: The value remained the same.\n");
    }

    return 0;
}
