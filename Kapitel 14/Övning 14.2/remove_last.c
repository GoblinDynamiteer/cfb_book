#include <stdio.h>
#include <stdlib.h>
#include "array_list.h"
#include "libtxt.h"

/* Övning 14.2, Sida 348
Lägg till i modulen 'array_list': en funktion 'remove_last', som tar bort det sista elementet. 
Funktionen ska returnera en pekare till det borttagna elementet om det gick bra, annars NULL. */

int main(){
	struct array_list *lista = new_list();
	int nummer, *pnummer;
	system("cls");
	//För att sätta värden till listan
	printf("Skriv in värde: ");
	while((scanf("%d", &nummer) == 1  )){
		pnummer = malloc(sizeof(int)); //Detta verkar behöva göras för varje varv, det går inte att initiera pekaren ovan till malloc
		*pnummer = nummer;
		printf(FORM_MAGENTA"pnummer pekar på värdet:"FORM_UNDER"%d"FORM_END"\n", *pnummer);
		add_last(lista, pnummer); //array_list.c - add_last - lägger till värde sist i lista.
		printf("Skriv in värde (avsluta med ctrl+z): ");
	}
	//Tömmer listan bakifrån tills NULL-pekare returneras
	while(1){
		pnummer = remove_last(lista); //remove_last funktionen i uppgiften
		if(pnummer == NULL){
			printf(FORM_RED"Pekare är NULL!"FORM_END);
			break;
		}
		printf("Tog bort sista element, värde: %d\n", *pnummer);
		printf("Antal element kvar: %d\n", size(lista));
	}
	return 0;
}


