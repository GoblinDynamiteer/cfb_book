#include <stdio.h>
#include <locale.h> //f�r setlocale()
#include <ctype.h> //f�r isdigit(), islower() och toupper()
/*
�vning 9.4, Sida 193

Anv�nd programmet p� sida 192.

Testa det genom att s�tta en char-variabel med namnet teck.

Testa att k�ra programmet b�de med och utan setlocale(LC_ALL, "");

*/

int main(){
	setlocale(LC_ALL, ""); //utan denna kan man ej anv�nda ������
	printf("Ange ett tecken: ");
	char teck = getchar();	//teck s�tts till ett inmatat tecken
	//Fr�n sida 192:
	if (isdigit(teck)){	//isdigit kollar om variabeln teck inneh�ller en siffra
			printf("Det �r en siffra!\n");
	}
	if (islower(teck)){ //islower kollar om variabeln teck inneh�ller en liten bokstav
		printf("Det �r en liten bokstav!\n");
		//toupper returnerar det stora tecknet av variabel tecks tecken (ex a->A)
		printf("Motsvarande stora bokstav �r: %c!\n", toupper(teck)); 
	}
	//
	return 0;
}