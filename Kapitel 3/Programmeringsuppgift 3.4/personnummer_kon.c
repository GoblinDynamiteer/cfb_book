#include <stdio.h>

/*
Programmeringsuppgift 3.4, sida 73
Mata in personnummer (utan bindestreck) och kön. Kolla att personnummer och kön matchar. 
Personnummer med näst sista siffra udda = män, jämn för kvinnor. Kön kan anges som 1/0.
Texten som matas ut ska vara "Stämmer" eller "Stämmer inte"

Tips: Läs in personnummer som long long int, (typspec. lld), gör division med 10 för
att få bort den sista siffran
*/

int main(){
	//Variabler för personnummer och kön
	long long int personnummer; //ett personnummer blir för stort för en vanlig int
	int kon;
	printf("Ange ditt kön, 1 för hane, 0 för hona:");
	scanf("%d", &kon);
	printf("Ange ditt personnummer: ");
	scanf("%lld", &personnummer);
	/*Heltalsdivision med 10 för att få bort sista siffran, 
	samt rest av division med 2 för att se om talet är jämt eller udda
	om rest = 1 så är talet udda och lika med kön=hane=1
	om rest = 0 så är talet udda och lika med kön=hona=0
	stämmer inte köns-siffra med rest av 2 så stämmer inte personnummer
	Jag vet inte om det är en bra lösning för if-kollen, men den kändes snygg iaf
	*/
	if (personnummer/10 % 2 == kon)
		printf("\nStämmer!");
	else 
		printf("\nStämmer inte!");
	return 0;
}