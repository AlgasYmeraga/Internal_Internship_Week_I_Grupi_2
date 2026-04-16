#include <stdio.h>

int main() {
    // Deklarimi i variablave sipas kerkeses
    int mosha, opsioni;
    char iniciali;
    double piket;

    // Marrja e input-it nga perdoruesi
    printf("Vendosni inicialin e emrit tuaj: ");
    scanf(" %c", &iniciali); // Hapesira para %c sherben per te shmangur leximin e 'newline'

    printf("Vendosni moshen tuaj: ");
    scanf("%d", &mosha);

    printf("Vendosni piket paraprake: ");
    scanf("%lf", &piket);

    printf("Zgjidhni opsionin e punetorise (1, 2 ose 3): ");
    scanf("%d", &opsioni);

    printf("\n--- REZULTATI I REGJISTRIMIT ---\n");

    // Kontrolli i moshes per pjesemarrje (p.sh. 15-30 vjec)
    if (mosha < 15 || mosha > 30) {
        printf("Statusi: Ju nuk jeni brenda kufirit te moshes per pjesemarrje.\n");
    } else {
        // Klasifikimi me if/else if/else bazuar ne piket
        printf("Iniciali: %c\n", iniciali);
        printf("Mosha: %d vjec\n", mosha);
        printf("Piket e fituara: %.2f\n", piket);

        if (piket < 50.0) {
            printf("Klasifikimi: Nevojitet me shume ushtrim\n");
        } else if (piket >= 50.0 && piket <= 80.0) {
            printf("Klasifikimi: Gati per vazhdim\n");
        } else {
            printf("Klasifikimi: Gati per sfide\n");
        }

        // Perdorimi i switch per emrin e punetorise
        printf("Punetoria: ");
        switch (opsioni) {
            case 1:
                printf("Bazat e Programimit ne C\n");
                break;
            case 2:
                printf("Zhvillimi Web (HTML/CSS)\n");
                break;
            case 3:
                printf("Analiza e te Dhenave\n");
                break;
            default:
                printf("Opsion i pavlefshem i zgjedhur.\n");
                break;
        }
    }

    return 0;
}
