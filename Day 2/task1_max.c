#include <stdio.h>

int main() {
    int a, b;
    
    printf("Enter first number");
    scanf("%d", &a);
    
    printf("Enter second number: ");
    scanf("%d", &b);

    if (a > b) {
	printf("First number is bigger\n");
    } else if (b > a) {
	printf("Second number is bigger\n");
    } else {
	printf("Both are equal\n");
    }

    return 0;

}
