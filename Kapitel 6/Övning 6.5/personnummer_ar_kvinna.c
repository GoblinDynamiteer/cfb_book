#include <stdio.h>

/*
�vning 6.5, sida 114

Skriv om programmeringsuppgift 3.4, s� att k�n best�ms av 
funktionen ar_kvinna p� sida 114

*/

//Funktion fr�n sida 114
_Bool ar_kvinna(long long int nr){ //_Bool kan enbart returnera 1 eller 0
	nr /= 10;
	//Om nr % 2 == 0 s� returnerar funktionen 1, annars 0 (om man)
	return nr % 2 == 0;
}

int main(){
	long long int personnummer; 
	int kon; //k�n
	printf("Ange ditt k�n, 1 f�r hane, 0 f�r hona:");
	scanf("%d", &kon);
	printf("Ange ditt personnummer: ");
	scanf("%lld", &personnummer);
	//D� jag har valt 1 f�r hane och 0 f�r hona, s� st�mmer k�n med personnummer om k�n inte �r samma som returv�rdet fr�n ar_kvinna
	if (kon != ar_kvinna(personnummer)) 
		printf("\nSt�mmer!");
	else 
		printf("\nSt�mmer inte!");
	return 0;
}