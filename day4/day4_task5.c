int main() {
    Regjistrim lista[MAX];
    int nr = 1;

    strcpy(lista[0].emri, "Mini Projekt");
    lista[0].progresi = 20;
    lista[0].status = 0;

    int zgjedhja;
    int indeks;
    int progresiRi;

    do {
        printf("\n1. Shfaq\n");
        printf("2. Perditeso progresin\n");
        printf("0. Dil\n");
        printf("Zgjedhja: ");
        scanf("%d", &zgjedhja);

        switch(zgjedhja) {
            case 1:
                shfaq(lista[0]);
                break;

            case 2:
                printf("Vendos progresin e ri: ");
                scanf("%d", &progresiRi);

                // pointer po kalon adresen
                perditesoProgres(&lista[0], progresiRi);

                printf("Progresi u perditesua!\n");
                break;
        }

    } while(zgjedhja != 0);

    return 0;
}
