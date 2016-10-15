#include <math.h> //f�r pow(x), cos(x), sqrt(x), fabs(x), M_PI
#include <stdio.h>
#define LT pow(10, -10) //"Litet tal", anv�nds f�r att se om sidor �r lika i if-satser

/*
Ange sida a & b, samt vinkel f�r en triangel. 
ber�kna sida c med cosinussatsen. 
Best�m om triangeln �r likbent, liksidig eller oliksidig. 
Skriv ut resultatet.

sida c ber�knas med

c = sqrt(a^2 + b^2 -2ab * cos(vinkel)

grader till radianer omvandlas med 
x grader = (pi*x)/180

bra f�r test:
http://www.calculator.net/triangle-calculator.html

f�r att f� en liksidig triangel kan man s�tta sida a=b samt vinkel=60
f�r att f� en likbent triangel kan man s�tta sida a=b sant vinkel!=60
*/

int main()
{
	float a,b,c,v; //variabler f�r sida a,b,c samt vinkel v.
	printf("Ange l�ngd f�r sida a: ");
	scanf("%f", &a);
	printf("Ange l�ngd f�r sida b: ");
	scanf("%f", &b);
	printf("Ange vinkeln v: ");
	scanf("%f", &v);
	//omvandlar vinkeln till radianer f�r cos(x)
	v = (M_PI * v) / 180;
	//ber�kna sida c
	c = sqrt(pow(a, 2) + pow(b, 2) - 2 * a * b * cos(v));
	/*tips fr�n boken: anv�nd det absoluta talet av skillnaden mellan sidorna och j�mf�r mot ett litet tal (10^-10)
	f�r att avg�ra om sidorna �r lika. Anv�nd ej == pga att talen lagras i approximativ form (ej exakt) */
	if (fabs(a-b) < LT && fabs(a-c) < LT) //om a-b ~ 0 och a-c ~ 0 s� �r triangeln liksidig (alla sidor lika)
		printf("Triangeln �r liksidig!");
	//om n�gon av sidorna minus en annan av sidorna �r ~ 0 och inte f�rsta if-satsen uppfyllts s� �r triangeln likbent (tv� lika sidor)
	else if (fabs(a-b) < LT || fabs(b-c) < LT || fabs(a-c) < LT) 
		printf("Triangeln �r likbent!");
	//om ingen av de tv� f�rsta if-satserna har uppfyllts s� �r triangeln oliksidig (alla sidor har olika l�ngd)
	else 
		printf("Triangeln �r oliksidig!");
	printf("\nSida a: %.2f, sida b: %.2f, sida c: %.2f", a, b, c);
}