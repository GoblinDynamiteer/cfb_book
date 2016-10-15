#include <stdio.h>

/*

Övning 6.7, Sida 116

Konstruera en funktion draw_line som skriver ut ett antal
understrykningstecken ( _ ).
Dess parameter ska vara antalet tecken raden ska bestå av

Sist i funktionen ska en ny rad matas fram
*/

//funktion för att skriva ut underscore lika många gånger som "tecken" är stor
void draw_line(int tecken)
{
	for (int i=1; i<=tecken;i++)
		printf("_");
	printf("\n");
}

int main(){
	int tecken;
	printf("Ange antal tecken i linjen!: ");
	scanf("%d", &tecken);
	draw_line(tecken);
	return 0;
}