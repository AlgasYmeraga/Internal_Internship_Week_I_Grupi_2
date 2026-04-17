void searchStudent(Student students[], int count) {
    if (count == 0) {
        printf("No students available.\n");
        return;
    }

    int choice;
    printf("Search by:\n");
    printf("1. ID\n");
    printf("2. Name\n");
    printf("Choose: ");
    scanf("%d", &choice);

    int found = 0;

    if (choice == 1) {
        int id;
        printf("Enter ID: ");
        scanf("%d", &id);

        for (int i = 0; i < count; i++) {
            if (students[i].id == id) {
                printf("\n--- Student Found ---\n");
                printf("ID: %d\n", students[i].id);
                printf("Name: %s\n", students[i].name);
                printf("Progress: %.2f\n", students[i].progress);

                if (students[i].progress < 40) {
                    printf("Warning: Critical progress. Immediate action needed.\n");
                } else if (students[i].progress < 70 && students[i].status == IN_PROGRESS) {
                    printf("Notice: Average progress. Push harder.\n");
                } else if (students[i].progress == 100 && students[i].status == COMPLETED) {
                    printf("Excellent: Fully completed.\n");
                } else {
                    printf("Stable: Keep going.\n");
                }

                found = 1;
                break;
            }
        }
    } 
    else if (choice == 2) {
        char name[50];
        printf("Enter Name: ");
        scanf("%s", name);

        for (int i = 0; i < count; i++) {
            if (strcmp(students[i].name, name) == 0) {
                printf("\n--- Student Found ---\n");
                printf("ID: %d\n", students[i].id);
                printf("Name: %s\n", students[i].name);
                printf("Progress: %.2f\n", students[i].progress);

                if (students[i].progress < 40) {
                    printf("Warning: Critical progress. Immediate action needed.\n");
                } else if (students[i].progress < 70 && students[i].status == IN_PROGRESS) {
                    printf("Notice: Average progress. Push harder.\n");
                } else if (students[i].progress == 100 && students[i].status == COMPLETED) {
                    printf("Excellent: Fully completed.\n");
                } else {
                    printf("Stable: Keep going.\n");
                }

                found = 1;
            }
        }
    }

    if (found == 0) {
        printf("No matching student found.\n");
    }
}
