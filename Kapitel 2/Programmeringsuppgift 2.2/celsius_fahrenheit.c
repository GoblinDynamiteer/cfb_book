#include <stdio.h>
/*
Programmet ska omvandla inmatat värde i grader celsius till grader fahrenheit.
Resultatet ska skrivas ut.

Formler:
Omvandling F till C
C = (F-32)*5/9

Omvandling C till F
F= C /(5/9)+32
*/

int main()
{
	float tc; //deklarerar variabel för temperatur i celsius
	printf("Ange temperatur i grader celsius: ");
	scanf("%f", &tc);
	printf("%.2f°C är %.2f°F", tc, tc / (5.0/9.0) + 32); //OBS använd 5.0/9.0 istället för 5/9 för att undvika heltalsdivision.
	return 0;
}