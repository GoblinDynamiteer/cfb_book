#include <stdio.h>
#include <locale.h> //för setlocale()
#include <ctype.h> //för isdigit(), islower() och toupper()
/*
Övning 9.4, Sida 193

Använd programmet på sida 192.

Testa det genom att sätta en char-variabel med namnet teck.

Testa att köra programmet både med och utan setlocale(LC_ALL, "");

*/

int main(){
	setlocale(LC_ALL, ""); //utan denna kan man ej använda åäöÅÄÖ
	printf("Ange ett tecken: ");
	char teck = getchar();	//teck sätts till ett inmatat tecken
	//Från sida 192:
	if (isdigit(teck)){	//isdigit kollar om variabeln teck innehåller en siffra
			printf("Det är en siffra!\n");
	}
	if (islower(teck)){ //islower kollar om variabeln teck innehåller en liten bokstav
		printf("Det är en liten bokstav!\n");
		//toupper returnerar det stora tecknet av variabel tecks tecken (ex a->A)
		printf("Motsvarande stora bokstav är: %c!\n", toupper(teck)); 
	}
	//
	return 0;
}