#include <stdio.h>

/*
Programmeringsuppgift 3.4, sida 73
Mata in personnummer (utan bindestreck) och k�n. Kolla att personnummer och k�n matchar. 
Personnummer med n�st sista siffra udda = m�n, j�mn f�r kvinnor. K�n kan anges som 1/0.
Texten som matas ut ska vara "St�mmer" eller "St�mmer inte"

Tips: L�s in personnummer som long long int, (typspec. lld), g�r division med 10 f�r
att f� bort den sista siffran
*/

int main(){
	//Variabler f�r personnummer och k�n
	long long int personnummer; //ett personnummer blir f�r stort f�r en vanlig int
	int kon;
	printf("Ange ditt k�n, 1 f�r hane, 0 f�r hona:");
	scanf("%d", &kon);
	printf("Ange ditt personnummer: ");
	scanf("%lld", &personnummer);
	/*Heltalsdivision med 10 f�r att f� bort sista siffran, 
	samt rest av division med 2 f�r att se om talet �r j�mt eller udda
	om rest = 1 s� �r talet udda och lika med k�n=hane=1
	om rest = 0 s� �r talet udda och lika med k�n=hona=0
	st�mmer inte k�ns-siffra med rest av 2 s� st�mmer inte personnummer
	Jag vet inte om det �r en bra l�sning f�r if-kollen, men den k�ndes snygg iaf
	*/
	if (personnummer/10 % 2 == kon)
		printf("\nSt�mmer!");
	else 
		printf("\nSt�mmer inte!");
	return 0;
}