void updateStudent(struct Student students[], int count) {
    int id;
    printf("Enter ID to update: ");
    scanf("%d", &id);

    int found = -1;

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        printf("\nStudent not found.\n");
        return;
    }

    printf("\nEditing student: %s\n", students[found].name);

    printf("Enter new name: ");
    scanf("%s", students[found].name);

    printf("Enter new grade: ");
    scanf("%f", &students[found].grade);

    printf("Enter new attendance: ");
    scanf("%d", &students[found].attendance);

    printf("\nStudent updated successfully.\n");
}

void deleteStudent(struct Student students[], int *count) {
    int choice;
    printf("\nDelete by:\n1. ID\n2. Index\nChoice: ");
    scanf("%d", &choice);

    int index = -1;

    if (choice == 1) {
        int id;
        printf("Enter ID: ");
        scanf("%d", &id);

        for (int i = 0; i < *count; i++) {
            if (students[i].id == id) {
                index = i;
                break;
            }
        }
    } else if (choice == 2) {
        printf("Enter index (0 to %d): ", *count - 1);
        scanf("%d", &index);

        if (index < 0 || index >= *count) {
            printf("\nInvalid index.\n");
            return;
        }
    } else {
        printf("\nInvalid choice.\n");
        return;
    }

    if (index == -1) {
        printf("\nStudent not found.\n");
        return;
    }

    for (int i = index; i < *count - 1; i++) {
        students[i] = students[i + 1];
    }

    (*count)--;

    printf("\nStudent deleted successfully.\n");
}

printf("7. Update Student\n");
printf("8. Delete Student\n");

case 7:
    updateStudent(students, count);
    break;

case 8:
    deleteStudent(students, &count);
    break;

students[index] = NULL;

