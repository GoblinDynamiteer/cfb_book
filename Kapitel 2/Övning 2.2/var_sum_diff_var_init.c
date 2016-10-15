#include <stdio.h>

int main()
{
	int tal1 = 33, tal2 = 82; //flera variabler kan deklareras och initieras samtidigt.
	/*
	Kod kommenterad för att den inte ska kompileras:
	printf("Ange ett heltal för tal 1: "); 
	scanf("%d", &tal1);
	printf("Ange ett heltal för tal 2: ");
	scanf("%d", &tal2);
	*/
	printf("Summan av talen är %d", tal1);
	printf(" + %d = ", tal2);
	printf("%d", tal1 + tal2); //printf kan skriva ut en beräkning, den behöver inte sättas i en egen variabel
	printf("\nSkillnaden mellan talen är %d", tal1);
	printf(" - %d = ", tal2);
	printf("%d", tal1 - tal2); //skriver ut skillnaden mellan tal1 och tal2
	return 0;
}