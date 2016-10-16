#include <stdio.h>
#include <string.h>
#include "bil.h" //Deklaration av struct bil

/* Övning 12.47, Sida 302

Gör om programmet i övning 12.3.
Gör ett fält med tre bilar!
Använd en for-loop för att skriva ut dess variabler.
*/

int main(){
	//Initierar tre struct person personer
	struct person per1 = {"Boris", "Karlsson", 1975};
	struct person per2 = {"Rolf", "Svensson", 1995};
	struct person per3 = {"Linda", "Unesson", 1954};
	
	//array med tre bilar:
	struct bil bil_info[3] = {
		{&per3, "SZS361", "Polaris BIG Boss 6X6", 2002, 420, 23000},
		{&per2, "SZS351", "Volvo V70", 2001, 1610, 103000},
		{&per1, "ABC351", "Volvo XC 90", 2010, 2110, 163000}
	};

	//Utskrift av bil struct-array:
	for(int i = 0; i < 3; i++){
		printf("\n\n");
		printf("Registreringsnummer: %s\n",bil_info[i].regNr);
		printf("Fabrikat: %s\n", bil_info[i].fabrikat);
		printf("Årsmodell: %d\n", bil_info[i].arsModell);
		printf("Tjänstevikt: %d kg\n", bil_info[i].tjansteVikt);
		printf("Motoreffekt: %d kW\n", bil_info[i].motorEffekt/1000);
		printf("-------------------\nÄgare: %s %s, född %d\n", bil_info[i].agare->fornamn, bil_info[i].agare->efternamn, bil_info[i].agare->fodd_ar);
	}
	return 0;
}
