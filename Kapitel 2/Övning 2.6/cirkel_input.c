#include <stdio.h>

//Definierar "PI" som en konstant
#define PI 3.14159265359 

/* �vning 2.6, Sida 44
Skriv om programmet i �vning 2.5, anv�nd standardfunktionen scanf
f�r att l�sa in cirkelns area.

Omkretsen f�r en cirkel ber�knas med 2PIr
Arean f�r en cirkel ber�knas med PIr^2 */

int main()
{
	float radie; 
	printf("Ange radien f�r en cirkel: ");
	scanf("%f", &radie); //iput f�r anv�ndare: radien kan inneh�lla decimaler
	//printf kan skriva ut v�rdet fr�n flera variabler / ber�kningar i samma anrop
	printf("Omkretsen f�r en cirkel med radien %.3f �r %.3f \n", 
		radie, 
		2 * radie * PI); 
	printf("Arean f�r en cirkel med radien %.3f �r %.3f", 
		radie, 
		radie * radie * PI);
	return 0;
}