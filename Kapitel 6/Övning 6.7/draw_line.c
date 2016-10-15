#include <stdio.h>

/*

�vning 6.7, Sida 116

Konstruera en funktion draw_line som skriver ut ett antal
understrykningstecken ( _ ).
Dess parameter ska vara antalet tecken raden ska best� av

Sist i funktionen ska en ny rad matas fram
*/

//funktion f�r att skriva ut underscore lika m�nga g�nger som "tecken" �r stor
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