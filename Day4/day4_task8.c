int main() {
    int choice;

    do {
        showMenu();
        scanf("%d", &choice);

        switch(choice) {
            case 1: addStudent(students, &count); break;
            case 2: displayAll(students, count); break;
            case 3: searchStudent(students, count); break;
            case 4: updateStudent(students, count); break;
            case 5: deleteStudent(students, &count); break;
            case 6: rankStudents(students, count); break;
            case 0: printf("Exiting...\n"); break;
            default: printf("Invalid option.\n");
        }

    } while(choice != 0);

    return 0;
}

void printStudent(struct Student s) {
    printf("ID: %d | Name: %s | Grade: %.2f | Attendance: %d%%\n",
           s.id, s.name, s.grade, s.attendance);
}

void showMenu() {
    printf("\n=== STUDENT MANAGEMENT SYSTEM ===\n");
    printf("1. Add Student\n");
    printf("2. Show All\n");
    printf("3. Search\n");
    printf("4. Update\n");
    printf("5. Delete\n");
    printf("6. Ranking\n");
    printf("0. Exit\n");
    printf("Choice: ");
}

printf("\n=== STUDENT LIST ===\n");
printf("\n=== SEARCH RESULT ===\n");
printf("\n=== SYSTEM EVALUATION ===\n");
