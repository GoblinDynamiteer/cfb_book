#include <stdio.h>
#define PI 3.14159265359 //s�tter "PI" som en konstant

int main()
{
	int radie = 5; //Anger radien f�r en cirkel, i detta fall 5
	//printf kan skriva ut v�rdet fr�n flera variabler / ber�kningar i samma anrop
	printf("Omkretsen f�r en cirkel med radien %d �r %.3f \n", radie, 2 * radie * PI); //Omkretsen f�r en cirkel ber�knas med 2PIr
	printf("Arean f�r en cirkel med radien %d �r %.3f", radie, radie * radie * PI); //Arean f�r en cirkel ber�knas med PIr^2
	return 0;
}