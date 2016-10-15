#include <stdio.h>
#include <math.h> //inkluderas för matematiska funktioner som pow() och sqrt()

/*
Programmet ska beräkna avståndet mellan två punkter i ett tvådimensionellt koordinatsystem
Användaren anger x och y för de båda punkterna.

Avståndet beräknas med formeln

d = ((x1-x2)^2 + (y1-y2)^2)^(1/2)

kvadratroten ur x är detsamma som x^(1/2)

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
	float x1, x2, y1, y2; //deklarerar variabler för x och y-koordinater för punkter 1 och 2
	printf("Ange X för punkt 1: ");
	//Användarinmatning för x1,x2,y1,y2:
	scanf("%f", &x1);
	printf("Ange Y för punkt 1: ");
	scanf("%f", &y1);
	printf("Ange X för punkt 2: ");
	scanf("%f", &x2);
	printf("Ange Y för punkt 2: ");
	scanf("%f", &y2);
	//Avståndet mellan punkterna beräknas med formeln ovan. sqrt(x) är kvadratroten ur x, och pow(x, 2) är x^2
	printf("Avståndet mellan punkt 1 (X%.3f, Y%.3f) och punkt2 (X%.3f, Y%.3f) är ca %.3f", x1, y1, x2, y2, sqrt(pow((x1-x2),2) + pow((y1-y2),2)));
	return 0;
}