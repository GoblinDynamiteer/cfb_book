#include <stdio.h>
#define PI 3.14159265359 //s�tter "PI" som en konstant

int main()
{
	float radie; 
	printf("Ange radien f�r en cirkel: ");
	scanf("%f", &radie); //iput f�r anv�ndare: radien kan inneh�lla decimaler
	//printf kan skriva ut v�rdet fr�n flera variabler / ber�kningar i samma anrop
	printf("Omkretsen f�r en cirkel med radien %.3f �r %.3f \n", radie, 2 * radie * PI); //Omkretsen f�r en cirkel ber�knas med 2PIr
	printf("Arean f�r en cirkel med radien %.3f �r %.3f", radie, radie * radie * PI); //Arean f�r en cirkel ber�knas med PIr^2
	return 0;
}