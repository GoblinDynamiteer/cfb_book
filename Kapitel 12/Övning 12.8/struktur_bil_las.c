#include <stdio.h>
#include <string.h>
#include "bil.h" //Deklaration av struct bil

/* �vning 12.8, Sida 309

G�r om programmet med bil-structarna. 
Skapa tv� program, ett som skriver structen till en fil, och en som l�ser structen
fr�n filen och skriver ut inneh�llet p� sk�rmen.

*/

int main(){
	//filvariabel med write och bin�rt mode, f�r inl�sning av structar
	FILE *bilfil = fopen("bil_data.dat", "rb");
	
	//hitta antal structar sparade i fil:
	//Spolar till filens slut?
	fseek(bilfil, 0, SEEK_END);
	
	//ftell anger aktuell position i filen, m�ts i antal bytes
	//delas sedan med storleken p� en bil struct f�r att hitta antal structar
	int n = ftell(bilfil) / sizeof(struct bil);
	//spola tillbaka filen
	rewind(bilfil);
	//skapar array med structar - n stycket (lika m�nga som i datafilen)
	struct bil bil_info[n];
	//l�ser in n antal strucar till bil_info array
	fread(&bil_info, sizeof(struct bil), n, bilfil);
	//Utskrift av bil struct-array:
	for(int i = 0; i < 3; i++){
		printf("\n\n");
		printf("Registreringsnummer: %s\n",bil_info[i].regNr);
		printf("Fabrikat: %s\n", bil_info[i].fabrikat);
		printf("�rsmodell: %d\n", bil_info[i].arsModell);
		printf("Tj�nstevikt: %d kg\n", bil_info[i].tjansteVikt);
		printf("Motoreffekt: %d kW\n", bil_info[i].motorEffekt/1000);
	}
	return 0;
}
