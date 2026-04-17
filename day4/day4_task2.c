#include <stdio.h>

#define MAX 100

// Enum për status
typedef enum {
    AKTIV = 1,
    JO_AKTIV,
    NE_PROCES
} Status;

typedef struct {
    int id;
    char emri[50];
    Status status;
} Regjistrim;

void shfaqStatus(Status s) {
    switch(s) {
        case AKTIV:
            printf("Aktiv");
            break;
        case JO_AKTIV:
            printf("Jo Aktiv");
            break;
        case NE_PROCES:
            printf("Ne Proces");
            break;
        default:
            printf("I panjohur");
    }
}

int main() {
    Regjistrim lista[MAX];
    int count = 0;
    int zgjedhja;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Shto regjistrim\n");
        printf("2. Shfaq regjistrimet\n");
        printf("0. Dil\n");
        printf("Zgjedhja: ");
        scanf("%d", &zgjedhja);

        switch(zgjedhja) {
            case 1: {
                if(count >= MAX) {
                    printf("Lista eshte plot!\n");
                    break;
                }

                printf("ID: ");
                scanf("%d", &lista[count].id);

                printf("Emri: ");
                scanf("%s", lista[count].emri);

                int statusInput;
                do {
                    printf("Statusi:\n");
                    printf("1. Aktiv\n");
                    printf("2. Jo Aktiv\n");
                    printf("3. Ne Proces\n");
                    printf("Zgjedhja: ");
                    scanf("%d", &statusInput);

                    if(statusInput < 1 || statusInput > 3) {
                        printf("Status i pavlefshem! Provo perseri.\n");
                    }

                } while(statusInput < 1 || statusInput > 3);

                lista[count].status = (Status)statusInput;
                count++;

                printf("Regjistrimi u shtua me sukses!\n");
                break;
            }

            case 2:
                if(count == 0) {
                    printf("Nuk ka regjistrime.\n");
                } else {
                    for(int i = 0; i < count; i++) {
                        printf("\nID: %d\n", lista[i].id);
                        printf("Emri: %s\n", lista[i].emri);
                        printf("Status: ");
                        shfaqStatus(lista[i].status);
                        printf("\n");
                    }
                }
                break;

            case 0:
                printf("Duke dale...\n");
                break;

            default:
                printf("Zgjedhje e pavlefshme! Provo perseri.\n");
        }

    } while(zgjedhja != 0);

    return 0;
}
