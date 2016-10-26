#include <stdio.h>
#define PI 3.14159265359 //sätter "PI" som en konstant

/* Övning 2.5, Sida 42
Använd koden på sida 39 för att skapa ett program som räknar och skriver ut 
arean och omkretsen för en cirkel med radien 5

Skriv ut resultaten på ett snyggt sätt med tre decimaler

Omkretsen för en cirkel beräknas med 2PIr
Arean för en cirkel beräknas med PIr^2 */

int main()
{
	int radie = 5; //Anger radien för en cirkel, i detta fall 5
	//printf kan skriva ut värdet från flera variabler / beräkningar i samma anrop
	//formatet %.3f skrivet ut en float-variabel med tre decimaler
	printf("Omkretsen för en cirkel med radien %d är %.3f \n", 
		radie, //det går att ha radbrytningar, utskriften blir korrekt ändå
		2 * radie * PI);
	printf("Arean för en cirkel med radien %d är %.3f", 
		radie, 
		radie * radie * PI);
	return 0;
}