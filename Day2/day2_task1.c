#include <stdio.h>

int main() {
    // Deklarimi i variablave sipas tipeve të kërkuara 
    int mosha;
    char iniciali;
    float gjatesia;
    double mesatarja;
    short dita_internship; // Do të caktohet në kod [cite: 10]
    long kodi_identifikimit; // Do të caktohet në kod [cite: 10]

    // Caktimi i vlerave për short dhe long [cite: 10]
    dita_internship = 2;
    kodi_identifikimit = 987654321L;

    // Marrja e input-it nga përdoruesi duke përdorur specifikuesit e duhur [cite: 9, 13, 17]
    printf("--- Formulari i Profilit ---\n");

    printf("Shruani moshen tuaj (int): ");
    scanf("%d", &mosha); // Përdorimi i %d për int [cite: 13]

    printf("Shruani inicialin e emrit tuaj (char): ");
    // Hapësira para %c përdoret për të injoruar ndonjë karakter 'newline' të mbetur [cite: 13]
    scanf(" %c", &iniciali); 

    printf("Shruani gjatesine tuaj (float, p.sh. 1.82): ");
    scanf("%f", &gjatesia); // Përdorimi i %f për float [cite: 13]

    printf("Shruani mesataren tuaj (double): ");
    scanf("%lf", &mesatarja); // Përdorimi i %lf për double [cite: 13]

    // Shfaqja e të dhënave me etiketa të qarta dhe organizim në disa rreshta [cite: 11, 15]
    printf("\n============================\n");
    printf("PROFILI I PERDORUESIT\n");
    printf("============================\n");
    printf("Mosha: %d vjec\n", mosha);
    printf("Iniciali: %c\n", iniciali);
    printf("Gjatesia: %.2f m\n", gjatesia);
    printf("Mesatarja: %.2lf\n", mesatarja);
    
    // Përdorimi i format specifier-ave të duhur për short (%hd) dhe long (%ld) [cite: 14]
    printf("Dita e Internship-it: %hd\n", dita_internship);
    printf("ID-ja e sistemit: %ld\n", kodi_identifikimit);
    printf("============================\n");

    return 0;
}
