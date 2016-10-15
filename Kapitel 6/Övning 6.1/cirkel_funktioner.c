#include <stdio.h>
#include <math.h>

/*
Övning 6.1, Sida 107.

Skriv om programmet i övning 2.6 så att area och omkrets beräknas i egna funktioner

*/

//funktion för att beräkna arean för en cirkel beroende av dess radie
double cirkel_area (double r){
	return M_PI * pow(r, 2);
}

//funktion för att beräkna omkretsen för en cirkel beroende av dess radie
double cirkel_omkrets (double r){
	return M_PI * 2 * r;
}

int main()
{
	double radie; 
	printf("Ange radien för en cirkel: ");
	scanf("%lf", &radie);
	printf("Omkretsen för en cirkel med radien %.3lf är %.3lf \n", radie, cirkel_omkrets(radie));
	printf("Arean för en cirkel med radien %.3lf är %.3lf", radie, cirkel_area(radie));
	return 0;
}