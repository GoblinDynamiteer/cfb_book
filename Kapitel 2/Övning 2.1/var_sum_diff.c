#include <stdio.h>

int main()
{
	int tal1; //int = integer, vilket ger variablen datatypen heltal
	int tal2;
	printf("Ange ett heltal f�r tal 1: ");
	//scanf f�r input fr�n anv�ndaren, och skriver datan till variabel. obs att "&" m�ste anges innan variabelnamnet vid skrivning
	//%d inneb�r att datan som skrivs in �r ett decimalt heltal
	scanf("%d", &tal1);
	printf("Ange ett heltal f�r tal 2: ");
	scanf("%d", &tal2);
	printf("Summan av talen �r %d", tal1);
	printf(" + %d = ", tal2);
	printf("%d", tal1 + tal2); //printf kan skriva ut en ber�kning, den beh�ver inte s�ttas i en egen variabel
	printf("\nSkillnaden av talen �r %d", tal1);
	printf(" - %d = ", tal2);
	printf("%d", tal1 - tal2); //skriver ut skillnaden mellan tal1 och tal2
	return 0;
}