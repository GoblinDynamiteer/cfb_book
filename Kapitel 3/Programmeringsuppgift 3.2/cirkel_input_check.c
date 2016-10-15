#include <stdio.h>
#include <math.h>

//#define PI 3.14159265359 //sätter "PI" som en konstant - Ändring, M_PI finns in math.h

/*
Programmeringsuppgift 3.2, sida 72
Skriv om programmet i övning 2.6, om det inmatade värdet för cirkelns radie
inte är större än 0 ska programmet visa en felutskrift.
*/

int main()
{
	float radie; 
	printf("Ange radien för en cirkel: ");
	scanf("%f", &radie); //input för användare: radien kan innehålla decimaler
	//test för om inmatad radie är mindre eller lika med noll, om så är fallet fortsätter ej programmet, annars beräknas area och cirkel
	if (radie <= 0){
		printf("Radien är under eller lika med 0! Avbryter");
	}
	else {
		//printf kan skriva ut värdet från flera variabler / beräkningar i samma anrop
		printf("Omkretsen för en cirkel med radien %.3f är %.3f \n", radie, 2 * radie * M_PI); //Omkretsen för en cirkel beräknas med 2PIr
		printf("Arean för en cirkel med radien %.3f är %.3f", radie, radie * radie * M_PI); //Arean för en cirkel beräknas med PIr^2
	}
	return 0;
}