#include <stdio.h>
#include <string.h>

#define MAX 50

typedef struct {
    char emri[50];
    int progresi;
    int status;
} Regjistrim;

/* --- Prototipet --- */
void menu();
void shto(Regjistrim lista[], int *nr);
void shfaq(Regjistrim lista[], int nr);
void perditesoStatus(Regjistrim *r);
void perditeso(Regjistrim lista[], int nr);
void kerko(Regjistrim lista[], int nr);
void rendit(Regjistrim lista[], int nr);
void ranko(Regjistrim lista[], int nr);
void ndrysho(Regjistrim lista[], int nr);
void fshij(Regjistrim lista[], int *nr);

int main() {
    Regjistrim lista[MAX];
    int nr = 0, zgjedhja;

    do {
        menu();
        scanf("%d", &zgjedhja);

        switch(zgjedhja) {
            case 1: shto(lista,&nr); break;
            case 2: shfaq(lista,nr); break;
            case 3: perditeso(lista,nr); break;
            case 4: kerko(lista,nr); break;
            case 5: rendit(lista,nr); ranko(lista,nr); break;
            case 6: ndrysho(lista,nr); break;
            case 7: fshij(lista,&nr); break;
        }

    } while(zgjedhja!=0);

    return 0;
}

/* --- Funksionet --- */

void menu(){
    printf("\n===============================\n");
    printf("       MINI PROJEKT FINAL\n");
    printf("===============================\n");
    printf("1. Shto\n");
    printf("2. Shfaq\n");
    printf("3. Perditeso progresin\n");
    printf("4. Kerko\n");
    printf("5. Ranko\n");
    printf("6. Ndrysho\n");
    printf("7. Fshij\n");
    printf("0. Dil\n");
    printf("Zgjedhja: ");
}

void perditesoStatus(Regjistrim *r){
    if(r->progresi >= 100)
        r->status = 1;
    else
        r->status = 0;
}

void shto(Regjistrim lista[], int *nr){
    printf("Emri: ");
    scanf(" %[^\n]", lista[*nr].emri);

    printf("Progresi: ");
    scanf("%d",&lista[*nr].progresi);

    perditesoStatus(&lista[*nr]);
    (*nr)++;
}

void shfaq(Regjistrim lista[], int nr){
    printf("\n------ REGJISTRIMET ------\n");
    for(int i=0;i<nr;i++){
        printf("[%d] %-15s %3d%%  %s\n",
        i,
        lista[i].emri,
        lista[i].progresi,
        lista[i].status ? "Perfundoar":"Ne proces");
    }
}

void perditeso(Regjistrim lista[], int nr){
    int i,p;
    printf("Indeksi: ");
    scanf("%d",&i);

    if(i<0 || i>=nr){
        printf("Jo valid\n");
        return;
    }

    printf("Progresi i ri: ");
    scanf("%d",&p);

    lista[i].progresi=p;
    perditesoStatus(&lista[i]);
}

void kerko(Regjistrim lista[], int nr){
    char emri[50];
    printf("Kerko: ");
    scanf(" %[^\n]",emri);

    for(int i=0;i<nr;i++){
        if(strcmp(lista[i].emri,emri)==0){
            printf("U gjet: %s %d%%\n",
            lista[i].emri,
            lista[i].progresi);
            return;
        }
    }
    printf("Nuk u gjet\n");
}

void rendit(Regjistrim lista[], int nr){
    for(int i=0;i<nr-1;i++){
        for(int j=i+1;j<nr;j++){
            if(lista[j].progresi>lista[i].progresi){
                Regjistrim temp=lista[i];
                lista[i]=lista[j];
                lista[j]=temp;
            }
        }
    }
}

void ranko(Regjistrim lista[], int nr){
    printf("\n------ RANKIMI ------\n");
    for(int i=0;i<nr;i++){
        printf("%d. %s - %d%%\n",
        i+1,
        lista[i].emri,
        lista[i].progresi);
    }
}

void ndrysho(Regjistrim lista[], int nr){
    int i;
    printf("Indeksi: ");
    scanf("%d",&i);

    if(i<0 || i>=nr){
        printf("Jo valid\n");
        return;
    }

    printf("Emri i ri: ");
    scanf(" %[^\n]",lista[i].emri);

    printf("Progresi i ri: ");
    scanf("%d",&lista[i].progresi);

    perditesoStatus(&lista[i]);
}

void fshij(Regjistrim lista[], int *nr){
    int i;
    printf("Indeksi: ");
    scanf("%d",&i);

    if(i<0 || i>=*nr){
        printf("Jo valid\n");
        return;
    }

    for(int j=i;j<*nr-1;j++)
        lista[j]=lista[j+1];

    (*nr)--;
}
