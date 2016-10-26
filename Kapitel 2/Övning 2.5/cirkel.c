#include <stdio.h>
#define PI 3.14159265359 //s�tter "PI" som en konstant

/* �vning 2.5, Sida 42
Anv�nd koden p� sida 39 f�r att skapa ett program som r�knar och skriver ut 
arean och omkretsen f�r en cirkel med radien 5

Skriv ut resultaten p� ett snyggt s�tt med tre decimaler

Omkretsen f�r en cirkel ber�knas med 2PIr
Arean f�r en cirkel ber�knas med PIr^2 */

int main()
{
	int radie = 5; //Anger radien f�r en cirkel, i detta fall 5
	//printf kan skriva ut v�rdet fr�n flera variabler / ber�kningar i samma anrop
	//formatet %.3f skrivet ut en float-variabel med tre decimaler
	printf("Omkretsen f�r en cirkel med radien %d �r %.3f \n", 
		radie, //det g�r att ha radbrytningar, utskriften blir korrekt �nd�
		2 * radie * PI);
	printf("Arean f�r en cirkel med radien %d �r %.3f", 
		radie, 
		radie * radie * PI);
	return 0;
}