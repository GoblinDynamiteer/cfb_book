#include <stdio.h>
#include <math.h>

/*
�vning 6.1, Sida 107.

Skriv om programmet i �vning 2.6 s� att area och omkrets ber�knas i egna funktioner

*/

//funktion f�r att ber�kna arean f�r en cirkel beroende av dess radie
double cirkel_area (double r){
	return M_PI * pow(r, 2);
}

//funktion f�r att ber�kna omkretsen f�r en cirkel beroende av dess radie
double cirkel_omkrets (double r){
	return M_PI * 2 * r;
}

int main()
{
	double radie; 
	printf("Ange radien f�r en cirkel: ");
	scanf("%lf", &radie);
	printf("Omkretsen f�r en cirkel med radien %.3lf �r %.3lf \n", radie, cirkel_omkrets(radie));
	printf("Arean f�r en cirkel med radien %.3lf �r %.3lf", radie, cirkel_area(radie));
	return 0;
}