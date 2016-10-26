#include <stdio.h>

//Definierar "PI" som en konstant
#define PI 3.14159265359 

/* Övning 2.6, Sida 44
Skriv om programmet i övning 2.5, använd standardfunktionen scanf
för att läsa in cirkelns area.

Omkretsen för en cirkel beräknas med 2PIr
Arean för en cirkel beräknas med PIr^2 */

int main()
{
	float radie; 
	printf("Ange radien för en cirkel: ");
	scanf("%f", &radie); //iput för användare: radien kan innehålla decimaler
	//printf kan skriva ut värdet från flera variabler / beräkningar i samma anrop
	printf("Omkretsen för en cirkel med radien %.3f är %.3f \n", 
		radie, 
		2 * radie * PI); 
	printf("Arean för en cirkel med radien %.3f är %.3f", 
		radie, 
		radie * radie * PI);
	return 0;
}