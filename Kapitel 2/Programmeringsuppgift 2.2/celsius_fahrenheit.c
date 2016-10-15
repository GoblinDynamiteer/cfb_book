#include <stdio.h>
/*
Programmet ska omvandla inmatat v�rde i grader celsius till grader fahrenheit.
Resultatet ska skrivas ut.

Formler:
Omvandling F till C
C = (F-32)*5/9

Omvandling C till F
F= C /(5/9)+32
*/

int main()
{
	float tc; //deklarerar variabel f�r temperatur i celsius
	printf("Ange temperatur i grader celsius: ");
	scanf("%f", &tc);
	printf("%.2f�C �r %.2f�F", tc, tc / (5.0/9.0) + 32); //OBS anv�nd 5.0/9.0 ist�llet f�r 5/9 f�r att undvika heltalsdivision.
	return 0;
}