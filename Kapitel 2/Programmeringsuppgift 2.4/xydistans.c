#include <stdio.h>
#include <math.h> //inkluderas f�r matematiska funktioner som pow() och sqrt()

/*
Programmet ska ber�kna avst�ndet mellan tv� punkter i ett tv�dimensionellt koordinatsystem
Anv�ndaren anger x och y f�r de b�da punkterna.

Avst�ndet ber�knas med formeln

d = ((x1-x2)^2 + (y1-y2)^2)^(1/2)

kvadratroten ur x �r detsamma som x^(1/2)

Ex:
*******I********
*******I**1***** x1 = 3
*******I******** y1 = 2
-------+-------- x2 = -4
***2***I******** y2 = -1
*******I********
*******I********

d = ((3+4)^2 + (2+1)^2)^(1/2) ~~ 7.62

*/

int main()
{
	float x1, x2, y1, y2; //deklarerar variabler f�r x och y-koordinater f�r punkter 1 och 2
	printf("Ange X f�r punkt 1: ");
	//Anv�ndarinmatning f�r x1,x2,y1,y2:
	scanf("%f", &x1);
	printf("Ange Y f�r punkt 1: ");
	scanf("%f", &y1);
	printf("Ange X f�r punkt 2: ");
	scanf("%f", &x2);
	printf("Ange Y f�r punkt 2: ");
	scanf("%f", &y2);
	//Avst�ndet mellan punkterna ber�knas med formeln ovan. sqrt(x) �r kvadratroten ur x, och pow(x, 2) �r x^2
	printf("Avst�ndet mellan punkt 1 (X%.3f, Y%.3f) och punkt2 (X%.3f, Y%.3f) �r ca %.3f", x1, y1, x2, y2, sqrt(pow((x1-x2),2) + pow((y1-y2),2)));
	return 0;
}