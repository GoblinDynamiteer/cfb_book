#include <math.h> //för pow(x), cos(x), sqrt(x), fabs(x), M_PI
#include <stdio.h>
#define LT pow(10, -10) //"Litet tal", används för att se om sidor är lika i if-satser

/*
Ange sida a & b, samt vinkel för en triangel. 
beräkna sida c med cosinussatsen. 
Bestäm om triangeln är likbent, liksidig eller oliksidig. 
Skriv ut resultatet.

sida c beräknas med

c = sqrt(a^2 + b^2 -2ab * cos(vinkel)

grader till radianer omvandlas med 
x grader = (pi*x)/180

bra för test:
http://www.calculator.net/triangle-calculator.html

för att få en liksidig triangel kan man sätta sida a=b samt vinkel=60
för att få en likbent triangel kan man sätta sida a=b sant vinkel!=60
*/

int main()
{
	float a,b,c,v; //variabler för sida a,b,c samt vinkel v.
	printf("Ange längd för sida a: ");
	scanf("%f", &a);
	printf("Ange längd för sida b: ");
	scanf("%f", &b);
	printf("Ange vinkeln v: ");
	scanf("%f", &v);
	//omvandlar vinkeln till radianer för cos(x)
	v = (M_PI * v) / 180;
	//beräkna sida c
	c = sqrt(pow(a, 2) + pow(b, 2) - 2 * a * b * cos(v));
	/*tips från boken: använd det absoluta talet av skillnaden mellan sidorna och jämför mot ett litet tal (10^-10)
	för att avgöra om sidorna är lika. Använd ej == pga att talen lagras i approximativ form (ej exakt) */
	if (fabs(a-b) < LT && fabs(a-c) < LT) //om a-b ~ 0 och a-c ~ 0 så är triangeln liksidig (alla sidor lika)
		printf("Triangeln är liksidig!");
	//om någon av sidorna minus en annan av sidorna är ~ 0 och inte första if-satsen uppfyllts så är triangeln likbent (två lika sidor)
	else if (fabs(a-b) < LT || fabs(b-c) < LT || fabs(a-c) < LT) 
		printf("Triangeln är likbent!");
	//om ingen av de två första if-satserna har uppfyllts så är triangeln oliksidig (alla sidor har olika längd)
	else 
		printf("Triangeln är oliksidig!");
	printf("\nSida a: %.2f, sida b: %.2f, sida c: %.2f", a, b, c);
}