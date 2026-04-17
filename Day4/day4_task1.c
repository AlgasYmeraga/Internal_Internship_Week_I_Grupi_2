void updateStudent(Student students[], int count) {
    if (count == 0) {
        printf("No students to update.\n");
        return;
    }

    int id;
    printf("Enter ID to update: ");
    scanf("%d", &id);

    int found = 0;

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            printf("Enter new progress (0-100): ");
            scanf("%f", &students[i].progress);

            if (students[i].progress < 0 || students[i].progress > 100) {
                printf("Invalid progress. Setting to 0.\n");
                students[i].progress = 0;
            }

            if (students[i].progress == 0) {
                students[i].status = NOT_STARTED;
            } else if (students[i].progress < 100) {
                students[i].status = IN_PROGRESS;
            } else {
                students[i].status = COMPLETED;
            }

            printf("Student updated successfully.\n");
            found = 1;
            break;
        }
    }

    if (found == 0) {
        printf("Student with that ID not found.\n");
    }
}
