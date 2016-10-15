
#include <stdio.h>
#include <math.h> 
#define PI 3.14159265359 //konstanten PI ska vara definierad i math.h? Funkar ej f�r mig. Jag definierar den manuellt h�r

/*
Volym f�r en sf�r d�r r=radie:
V=(4PIr^3)/3

Area f�r en sf�r:
A=4PIr^2
*/

int main()
{
	float radie, area, volym; //deklarerar variabler f�r sf�rens radie, volym och area.
	printf("Ange sf�rens radie: ");
	scanf("%f", &radie); //Anv�ndarinmatning av sf�rens radie, s�tts till var radie
	volym = (4 * PI * pow(radie, 3) ) / 3; //pow(x,y) finns i math.h och inneb�r x upph�jt i y (x^y)
	area = 4 * PI * pow(radie, 2);
	printf("Arean f�r en sf�r med radien %.3f �r A = %.3f", radie, area);
	printf("\nVolymen f�r en sf�r med radien %.3f �r V = %.3f", radie, volym);
	return 0;
}