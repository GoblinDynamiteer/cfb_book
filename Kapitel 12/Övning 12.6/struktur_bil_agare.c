#include <stdio.h>
#include "bil.h" //Deklaration av struct bil

/* �vning 12.4, Sida 292

G�r om programmet i �vning 12.3.
Anv�nd tv� pekare f�r att skriva ut informationen fr�n bil-structen.
*/

int main(){
	//Initierar tv� struct person personer
	struct person per1 = {"Kalle", "Karlsson", 1975};
	struct person per2 = {"Linda", "Svensson", 1995};

	struct bil bil1 = {
		.regNr = "SZS361",
		.fabrikat = "Polaris BIG Boss 6X6",
		.arsModell = 2002,
		.tjansteVikt = 420,
		.motorEffekt = 23000,
		.agare = &per2 //�gare �r adressen till per2 (struct person *agare)
	};

	struct bil bil2 = {
		.regNr = "SZS351",
		.fabrikat = "Volvo V70"
	};
	bil2.arsModell = 2001;
	bil2.tjansteVikt = 1610;
	bil2.motorEffekt = 103000; //103kW
	bil2.agare = &per1; //�gare �r adressen till per1

	//Pekare till struct:
	struct bil *pekare_bil;
	//Pekaren s�tts till addressen f�r bil1
	pekare_bil = &bil1;
	printf("Utskrift med pekare (och funktion): \n");
	//Skriver ut v�rden f�r bil1 med funktion:
	skrivUtStructMedPekare(pekare_bil);
	//Pekaren s�tts till addressen f�r bil2
	pekare_bil = &bil2;
	printf("\n\n");
	//Skriver ut v�rden f�r bil2 med funktion:
	skrivUtStructMedPekare(pekare_bil);
	return 0;
}

void skrivUtStructMedPekare(struct bil *p){
	printf("Registreringsnummer: %s\n",(*p).regNr);
	printf("Fabrikat: %s\n", (*p).fabrikat);
	printf("�rsmodell: %d\n", (*p).arsModell);
	printf("Tj�nstevikt: %d kg\n", (*p).tjansteVikt);
	printf("Motoreffekt: %d kW\n", (*p).motorEffekt/1000);
	/* (*p).x    �r samma som    p-> x 
	p->agare->fornamn
	p �r pekaren till en bil som i sin tur har en pekare 'agare' som pekar till en �gare */
	printf("-------------------\n�gare: %s %s, f�dd %d\n", p->agare->fornamn, p->agare->efternamn, p->agare->fodd_ar);
}
