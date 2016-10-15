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
	struct person per3 = {"Bengt", "Unesson", 1954};

	//array med tre bilar:
	struct bil bil_info[2];

	strcpy(bil_info[0].regNr,"SZS361");
	strcpy(bil_info[0].fabrikat, "Polaris BIG Boss 6X6");
	bil_info[0].arsModell = 2002;
	bil_info[0].tjansteVikt = 420;
	bil_info[0].motorEffekt = 23000;
	bil_info[0].agare = &per3;
	//printf("%s - adress: %p\n", bil_info[0].agare -> fornamn, bil_info[0].agare -> fornamn);

	strcpy(bil_info[1].regNr,"SZS351");
	strcpy(bil_info[1].fabrikat, "Volvo V70");
	bil_info[1].arsModell = 2001;
	bil_info[1].tjansteVikt = 1610;
	bil_info[1].motorEffekt = 103000;
	bil_info[1].agare = &per2;
	//printf("%s - adress: %p\n", bil_info[1].agare -> fornamn, bil_info[1].agare -> fornamn);
	
	strcpy(bil_info[2].regNr,"ABC351");
	strcpy(bil_info[2].fabrikat, "Volvo XC 90");
	bil_info[2].arsModell = 2010;
	bil_info[2].tjansteVikt = 2110;
	bil_info[2].motorEffekt = 163000;
	bil_info[2].agare = &per1;
	//printf("%s - adress: %p\n", bil_info[2].agare -> fornamn, bil_info[2].agare -> fornamn);
	
	printf("Utskrift med pekare (och funktion): \n");

	//Utskrift av bil struct-array:
	for(int i = 0; i < 3; i++){
		printf("\n\n");
		printf("Registreringsnummer: %s\n",bil_info[i].regNr);
		printf("Fabrikat: %s\n", bil_info[i].fabrikat);
		printf("Årsmodell: %d\n", bil_info[i].arsModell);
		printf("Tjänstevikt: %d kg\n", bil_info[i].tjansteVikt);
		printf("Motoreffekt: %d kW\n", bil_info[i].motorEffekt/1000);
		printf("-------------------\nÄgare: %s %s, född %d\n", bil_info[i].agare->fornamn, bil_info[i].agare->efternamn, bil_info[i].agare->fodd_ar);
		//printf("%s - adress: %p\n", bil_info[i].agare -> fornamn, bil_info[i].agare -> fornamn);
	}

	return 0;
}
