
#include <stdio.h>
#include <math.h> 
#define PI 3.14159265359 //konstanten PI ska vara definierad i math.h? Funkar ej för mig. Jag definierar den manuellt här

/*
Volym för en sfär där r=radie:
V=(4PIr^3)/3

Area för en sfär:
A=4PIr^2
*/

int main()
{
	float radie, area, volym; //deklarerar variabler för sfärens radie, volym och area.
	printf("Ange sfärens radie: ");
	scanf("%f", &radie); //Användarinmatning av sfärens radie, sätts till var radie
	volym = (4 * PI * pow(radie, 3) ) / 3; //pow(x,y) finns i math.h och innebär x upphöjt i y (x^y)
	area = 4 * PI * pow(radie, 2);
	printf("Arean för en sfär med radien %.3f är A = %.3f", radie, area);
	printf("\nVolymen för en sfär med radien %.3f är V = %.3f", radie, volym);
	return 0;
}