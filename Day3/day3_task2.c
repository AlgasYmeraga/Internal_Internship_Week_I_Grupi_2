int main() {
    int fillimi, fundi;
    int count_cift = 0, count_tek = 0;
    long shuma_cift = 0, shuma_tek = 0;

    // Marrja e vlerave te intervalit nga perdoruesi
    printf("Shisni vleren fillestare te intervalit: ");
    scanf("%d", &fillimi);
    printf("Shisni vleren perfundimtare te intervalit: ");
    scanf("%d", &fundi);

    // Validimi i intervalit
    if (fillimi > fundi) {
        printf("Gabim: Vlera fillestare nuk mund te jete me e madhe se ajo perfundimtare.\n");
        return 1; 
    }

    // Perdorimi i for loop per te kontrolluar cdo numer
    for (int i = fillimi; i <= fundi; i++) {
        // Kontrolli me operatorin % per cift/tek
        if (i % 2 == 0) {
            count_cift++;
            shuma_cift += i;
        } else {
            count_tek++;
            shuma_tek += i;
        }
    }

    // Shfaqja e rezultateve finale
    printf("\n--- ANALIZA E INTERVALIT [%d, %d] ---\n", fillimi, fundi);
    printf("Totali i vlerave ne interval: %d\n", (fundi - fillimi) + 1);
    printf("Numra cift: %d (Shuma: %ld)\n", count_cift, shuma_cift);
    printf("Numra tek: %d (Shuma: %ld)\n", count_tek, shuma_tek);

    // Percaktimi i kategorise me me shume numra
    if (count_cift > count_tek) {
        printf("Kategoria me me shume numra: Cift\n");
    } else if (count_tek > count_cift) {
        printf("Kategoria me me shume numra: Tek\n");
    } else {
        printf("Kategorite kane numer te barabarte vlerash.\n");
    }

    return 0;
}
