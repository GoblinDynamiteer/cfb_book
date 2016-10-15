#include <stdio.h>

/*
Programmeringsuppgift 3.3, sida 73
Skriv ett program som visar vilken region ett inmatat postnummer tillh�r. 
De tv� f�rsta siffrorna anger regionen. 
20-62,65,66: G�taland
>=80: Norrland
�vriga: Svealand 

Tips: Anv�nd long int som datatyp och dividera variabeln med 1000 f�r
f�r att f� de tv� f�rsta siffrorna
*/

int main(){
	long int postnummer; //variabel f�r postnummer, long int pga tipset ovan. Varf�r skulle inte int fungera lika??
	printf("Ange postnummer: ");
	scanf("%d", &postnummer);
	//dividerar postnummer med 1000, variabeln inneh�ller heltal och tar enbart de f�rsta siffrorna (heltalsdivison), jag s�tter dem till samma variabel
	postnummer = postnummer / 1000; 
	//if-satser som kollar till vilken region postnumret tillh�r:
	//f�rsta: (st�rre �n/lika med 20 OCH (&&) mindre �n/lika med 62) ELLER (||) lika med 65 ELLER lika med 66
	if ((postnummer >= 20 && postnummer <= 62) || postnummer == 65 || postnummer == 66)
		printf("Postnumret tillh�r G�taland!");
	//andra: st�rre �n eller lika med (>=) 80
	else if (postnummer >= 80)
		printf("Postnumret tillh�r Norrland!");
	//tredje: om f�rsta eller andra inte triggar (blir sant)
	else 
		printf("Postnumret tillh�r Svealand!");
	return 0;
}