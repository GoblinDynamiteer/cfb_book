#include <stdio.h>

int main()
{
	int tal1; //int = integer, vilket ger variablen datatypen heltal
	int tal2;
	printf("Ange ett heltal för tal 1: ");
	//scanf får input från användaren, och skriver datan till variabel. obs att "&" måste anges innan variabelnamnet vid skrivning
	//%d innebär att datan som skrivs in är ett decimalt heltal
	scanf("%d", &tal1);
	printf("Ange ett heltal för tal 2: ");
	scanf("%d", &tal2);
	printf("Summan av talen är %d", tal1);
	printf(" + %d = ", tal2);
	printf("%d", tal1 + tal2); //printf kan skriva ut en beräkning, den behöver inte sättas i en egen variabel
	printf("\nSkillnaden av talen är %d", tal1);
	printf(" - %d = ", tal2);
	printf("%d", tal1 - tal2); //skriver ut skillnaden mellan tal1 och tal2
	return 0;
}