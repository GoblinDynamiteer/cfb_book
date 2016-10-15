#include <stdio.h>
#define PI 3.14159265359 //sätter "PI" som en konstant

int main()
{
	float radie; 
	printf("Ange radien för en cirkel: ");
	scanf("%f", &radie); //iput för användare: radien kan innehålla decimaler
	//printf kan skriva ut värdet från flera variabler / beräkningar i samma anrop
	printf("Omkretsen för en cirkel med radien %.3f är %.3f \n", radie, 2 * radie * PI); //Omkretsen för en cirkel beräknas med 2PIr
	printf("Arean för en cirkel med radien %.3f är %.3f", radie, radie * radie * PI); //Arean för en cirkel beräknas med PIr^2
	return 0;
}