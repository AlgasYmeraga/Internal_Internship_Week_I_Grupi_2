int main() {
    int option;

    while(1) {
        printf("\n===== MENU =====\n");
        printf("1. Shto regjistrim\n");
        printf("2. Shfaq regjistrimet\n");
        printf("3. Dil\n");
        printf("Zgjedhja: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                addRecord();
                break;
            case 2:
                showRecords();
                break;
            case 3:
                printf("Programi u mbyll.\n");
                return 0;
            default:
                printf("Zgjedhje e pavlefshme! Provo perseri.\n");
        }
    }
}
