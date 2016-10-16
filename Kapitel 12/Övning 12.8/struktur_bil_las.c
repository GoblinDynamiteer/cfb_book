#include <stdio.h>
#include <string.h>
#include "bil.h" //Deklaration av struct bil

/* Övning 12.8, Sida 309

Gör om programmet med bil-structarna. 
Skapa två program, ett som skriver structen till en fil, och en som läser structen
från filen och skriver ut innehållet på skärmen.

*/

int main(){
	//filvariabel med write och binärt mode, för inläsning av structar
	FILE *bilfil = fopen("bil_data.dat", "rb");
	
	//hitta antal structar sparade i fil:
	//Spolar till filens slut?
	fseek(bilfil, 0, SEEK_END);
	
	//ftell anger aktuell position i filen, mäts i antal bytes
	//delas sedan med storleken på en bil struct för att hitta antal structar
	int n = ftell(bilfil) / sizeof(struct bil);
	//spola tillbaka filen
	rewind(bilfil);
	//skapar array med structar - n stycket (lika många som i datafilen)
	struct bil bil_info[n];
	//läser in n antal strucar till bil_info array
	fread(&bil_info, sizeof(struct bil), n, bilfil);
	//Utskrift av bil struct-array:
	for(int i = 0; i < 3; i++){
		printf("\n\n");
		printf("Registreringsnummer: %s\n",bil_info[i].regNr);
		printf("Fabrikat: %s\n", bil_info[i].fabrikat);
		printf("Årsmodell: %d\n", bil_info[i].arsModell);
		printf("Tjänstevikt: %d kg\n", bil_info[i].tjansteVikt);
		printf("Motoreffekt: %d kW\n", bil_info[i].motorEffekt/1000);
	}
	return 0;
}
