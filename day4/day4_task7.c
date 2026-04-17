#include <stdio.h>
#include <string.h>

#define MAX 50

typedef struct {
    char emri[50];
    int progresi;
    int status;
} Regjistrim;

void shto(Regjistrim lista[], int *nr);
void shfaqTeGjitha(Regjistrim lista[], int nr);
void perditesoProgres(Regjistrim *r, int progresiRi);
void kerko(Regjistrim lista[], int nr);
void renditSipasProgresit(Regjistrim lista[], int nr);
void shfaqRankim(Regjistrim lista[], int nr);
void ndryshoRegjistrim(Regjistrim lista[], int nr);
void fshijRegjistrim(Regjistrim lista[], int *nr);

int main() {
    Regjistrim lista[MAX];
    int nr = 0;
    int zgjedhja;

    do {
        printf("\n============================\n");
        printf("       MINI PROJEKT\n");
        printf("============================\n");
        printf("1. Shto regjistrim\n");
        printf("2. Shfaq regjistrimet\n");
        printf("3. Perditeso progresin\n");
        printf("4. Kerko regjistrim\n");
        printf("5. Ranko sipas progresit\n");
        printf("6. Ndrysho regjistrim\n");
        printf("7. Fshij regjistrim\n");
        printf("0. Dil\n");
        printf("Zgjedhja: ");
        scanf("%d", &zgjedhja);

        switch(zgjedhja) {

            case 1:
                shto(lista, &nr);
                break;

            case 2:
                shfaqTeGjitha(lista, nr);
                break;

            case 3: {
                int index, progresiRi;

                printf("Jep indeksin: ");
                scanf("%d", &index);

                if(index >= 0 && index < nr) {
                    printf("Progresi i ri: ");
                    scanf("%d", &progresiRi);
                    perditesoProgres(&lista[index], progresiRi);
                } else {
                    printf("Indeks jo valid!\n");
                }
                break;
            }

            case 4:
                kerko(lista, nr);
                break;

            case 5:
                renditSipasProgresit(lista, nr);
                shfaqRankim(lista, nr);
                break;

            case 6:
                ndryshoRegjistrim(lista, nr);
                break;

            case 7:
                fshijRegjistrim(lista, &nr);
                break;

        }

    } while(zgjedhja != 0);

    return 0;
}

void shto(Regjistrim lista[], int *nr) {
    printf("Emri: ");
    scanf(" %[^\n]", lista[*nr].emri);

    printf("Progresi: ");
    scanf("%d", &lista[*nr].progresi);

    if(lista[*nr].progresi >= 100)
        lista[*nr].status = 1;
    else
        lista[*nr].status = 0;

    (*nr)++;
}

void shfaqTeGjitha(Regjistrim lista[], int nr) {
    for(int i = 0; i < nr; i++) {
        printf("\n[%d] %s - %d%% - ",
               i,
               lista[i].emri,
               lista[i].progresi);

        if(lista[i].status == 1)
            printf("Perfundoar");
        else
            printf("Ne proces");
    }
    printf("\n");
}

void perditesoProgres(Regjistrim *r, int progresiRi) {
    r->progresi = progresiRi;

    if(r->progresi >= 100)
        r->status = 1;
    else
        r->status = 0;
}

void kerko(Regjistrim lista[], int nr) {
    char emri[50];
    printf("Kerko emrin: ");
    scanf(" %[^\n]", emri);

    for(int i = 0; i < nr; i++) {
        if(strcmp(lista[i].emri, emri) == 0) {
            printf("U gjet: %s - %d%%\n",
                   lista[i].emri,
                   lista[i].progresi);
            return;
        }
    }
    printf("Nuk u gjet!\n");
}

void renditSipasProgresit(Regjistrim lista[], int nr) {
    for(int i = 0; i < nr - 1; i++) {
        for(int j = i + 1; j < nr; j++) {
            if(lista[j].progresi > lista[i].progresi) {
                Regjistrim temp = lista[i];
                lista[i] = lista[j];
                lista[j] = temp;
            }
        }
    }
}

void shfaqRankim(Regjistrim lista[], int nr) {
    printf("\n===== RANKIMI =====\n");
    for(int i = 0; i < nr; i++) {
        printf("%d. %s - %d%%\n",
               i + 1,
               lista[i].emri,
               lista[i].progresi);
    }
}

void ndryshoRegjistrim(Regjistrim lista[], int nr) {
    int index;

    printf("Jep indeksin per ndryshim: ");
    scanf("%d", &index);

    if(index < 0 || index >= nr) {
        printf("Indeks jo valid!\n");
        return;
    }

    printf("Emri i ri: ");
    scanf(" %[^\n]", lista[index].emri);

    printf("Progresi i ri: ");
    scanf("%d", &lista[index].progresi);

    if(lista[index].progresi >= 100)
        lista[index].status = 1;
    else
        lista[index].status = 0;

    printf("Regjistrimi u ndryshua!\n");
}

void fshijRegjistrim(Regjistrim lista[], int *nr) {
    int index;

    printf("Jep indeksin per fshirje: ");
    scanf("%d", &index);

    if(index < 0 || index >= *nr) {
        printf("Indeks jo valid!\n");
        return;
    }

    for(int i = index; i < *nr - 1; i++) {
        lista[i] = lista[i + 1];
    }

    (*nr)--;

    printf("Regjistrimi u fshi me sukses!\n");
}
