#include <stdio.h>

/*
Programmeringsuppgift 3.3, sida 73
Skriv ett program som visar vilken region ett inmatat postnummer tillhör. 
De två första siffrorna anger regionen. 
20-62,65,66: Götaland
>=80: Norrland
Övriga: Svealand 

Tips: Använd long int som datatyp och dividera variabeln med 1000 för
för att få de två första siffrorna
*/

int main(){
	long int postnummer; //variabel för postnummer, long int pga tipset ovan. Varför skulle inte int fungera lika??
	printf("Ange postnummer: ");
	scanf("%d", &postnummer);
	//dividerar postnummer med 1000, variabeln innehåller heltal och tar enbart de första siffrorna (heltalsdivison), jag sätter dem till samma variabel
	postnummer = postnummer / 1000; 
	//if-satser som kollar till vilken region postnumret tillhör:
	//första: (större än/lika med 20 OCH (&&) mindre än/lika med 62) ELLER (||) lika med 65 ELLER lika med 66
	if ((postnummer >= 20 && postnummer <= 62) || postnummer == 65 || postnummer == 66)
		printf("Postnumret tillhör Götaland!");
	//andra: större än eller lika med (>=) 80
	else if (postnummer >= 80)
		printf("Postnumret tillhör Norrland!");
	//tredje: om första eller andra inte triggar (blir sant)
	else 
		printf("Postnumret tillhör Svealand!");
	return 0;
}