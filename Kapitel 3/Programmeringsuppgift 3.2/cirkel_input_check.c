#include <stdio.h>
#include <math.h>

//#define PI 3.14159265359 //s�tter "PI" som en konstant - �ndring, M_PI finns in math.h

/*
Programmeringsuppgift 3.2, sida 72
Skriv om programmet i �vning 2.6, om det inmatade v�rdet f�r cirkelns radie
inte �r st�rre �n 0 ska programmet visa en felutskrift.
*/

int main()
{
	float radie; 
	printf("Ange radien f�r en cirkel: ");
	scanf("%f", &radie); //input f�r anv�ndare: radien kan inneh�lla decimaler
	//test f�r om inmatad radie �r mindre eller lika med noll, om s� �r fallet forts�tter ej programmet, annars ber�knas area och cirkel
	if (radie <= 0){
		printf("Radien �r under eller lika med 0! Avbryter");
	}
	else {
		//printf kan skriva ut v�rdet fr�n flera variabler / ber�kningar i samma anrop
		printf("Omkretsen f�r en cirkel med radien %.3f �r %.3f \n", radie, 2 * radie * M_PI); //Omkretsen f�r en cirkel ber�knas med 2PIr
		printf("Arean f�r en cirkel med radien %.3f �r %.3f", radie, radie * radie * M_PI); //Arean f�r en cirkel ber�knas med PIr^2
	}
	return 0;
}