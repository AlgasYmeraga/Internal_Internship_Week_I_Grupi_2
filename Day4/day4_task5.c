struct Student {
    int id;
    char name[50];
    float grade;
    int attendance;
};

void searchStudent(struct Student students[], int count) {
    int choice;
    printf("\nSearch by:\n1. ID\n2. Name\nChoice: ");
    scanf("%d", &choice);

    int found = 0;

    if (choice == 1) {
        int searchId;
        printf("Enter ID: ");
        scanf("%d", &searchId);

        for (int i = 0; i < count; i++) {
            if (students[i].id == searchId) {
                displayStudent(students[i]);
                evaluateStudent(students[i]);
                found = 1;
            }
        }
    } else if (choice == 2) {
        char searchName[50];
        printf("Enter Name: ");
        scanf("%s", searchName);

        for (int i = 0; i < count; i++) {
            if (strcmp(students[i].name, searchName) == 0) {
                displayStudent(students[i]);
                evaluateStudent(students[i]);
                found = 1;
            }
        }
    }

    if (!found) {
        printf("\nNo matching record found.\n");
    }
}

void displayStudent(struct Student s) {
    printf("\n--- Student Found ---\n");
    printf("ID: %d\n", s.id);
    printf("Name: %s\n", s.name);
    printf("Grade: %.2f\n", s.grade);
    printf("Attendance: %d%%\n", s.attendance);
}

void evaluateStudent(struct Student s) {
    printf("\n--- System Evaluation ---\n");

    if (s.grade < 6 && s.attendance < 50) {
        printf("Critical: Low grade and poor attendance. Immediate action needed.\n");
    }
    else if (s.grade < 6 && s.attendance >= 50) {
        printf("Warning: Grade is low. Focus on studying.\n");
    }
    else if (s.grade >= 6 && s.attendance < 50) {
        printf("Warning: Attendance is poor. Risk of failing.\n");
    }
    else if (s.grade >= 9 && s.attendance > 80) {
        printf("Excellent: Keep going like this.\n");
    }
    else {
        printf("Stable: Performance is acceptable.\n");
    }
}

printf("5. Search Student\n");

case 5:
    searchStudent(students, count);
    break;
