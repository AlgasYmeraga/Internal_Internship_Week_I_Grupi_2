void sortByGrade(struct Student students[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (students[j].grade < students[j + 1].grade) {
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void displayRanking(struct Student students[], int count) {
    printf("\n=== STUDENT RANKING (by Grade) ===\n");

    for (int i = 0; i < count; i++) {
        printf("%d. %s | Grade: %.2f | Attendance: %d%%\n",
               i + 1,
               students[i].name,
               students[i].grade,
               students[i].attendance);
    }
}

void rankStudents(struct Student students[], int count) {
    sortByGrade(students, count);
    displayRanking(students, count);
}

printf("6. Show Ranking\n");

case 6:
    rankStudents(students, count);
    break;
