#include <stdio.h>

/*
Övning 6.5, sida 114

Skriv om programmeringsuppgift 3.4, så att kön bestäms av 
funktionen ar_kvinna på sida 114

*/

//Funktion från sida 114
_Bool ar_kvinna(long long int nr){ //_Bool kan enbart returnera 1 eller 0
	nr /= 10;
	//Om nr % 2 == 0 så returnerar funktionen 1, annars 0 (om man)
	return nr % 2 == 0;
}

int main(){
	long long int personnummer; 
	int kon; //kön
	printf("Ange ditt kön, 1 för hane, 0 för hona:");
	scanf("%d", &kon);
	printf("Ange ditt personnummer: ");
	scanf("%lld", &personnummer);
	//Då jag har valt 1 för hane och 0 för hona, så stämmer kön med personnummer om kön inte är samma som returvärdet från ar_kvinna
	if (kon != ar_kvinna(personnummer)) 
		printf("\nStämmer!");
	else 
		printf("\nStämmer inte!");
	return 0;
}