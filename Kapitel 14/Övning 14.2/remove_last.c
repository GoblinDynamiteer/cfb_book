#include <stdio.h>
#include <stdlib.h>
#include "array_list.h"
#include "libtxt.h"

/* �vning 14.2, Sida 348
L�gg till i modulen 'array_list': en funktion 'remove_last', som tar bort det sista elementet. 
Funktionen ska returnera en pekare till det borttagna elementet om det gick bra, annars NULL. */

int main(){
	struct array_list *lista = new_list();
	int nummer, *pnummer;
	system("cls");
	//F�r att s�tta v�rden till listan
	printf("Skriv in v�rde: ");
	while((scanf("%d", &nummer) == 1 )){
		pnummer = malloc(sizeof(int)); //Allokerar nytt minnesplats f�r pekaren
		printf("["FORM_CYAN"pnummer address:"FORM_UNDER"%p"FORM_END"]\n", pnummer);
		*pnummer = nummer; //V�rde i minnesplatsen s�tts till den inmatade v�rdet fr�n anv�ndaren
		printf("["FORM_MAGENTA"pnummer v�rde:"FORM_UNDER"%d"FORM_END"]\n", *pnummer);
		add_last(lista, pnummer); //array_list.c - add_last - l�gger till v�rde sist i lista.
		printf("Skriv in v�rde (avsluta med ctrl+z): ");
	}
	//T�mmer listan bakifr�n tills NULL-pekare returneras
	while(1){
		pnummer = remove_last(lista); //remove_last funktionen i uppgiften
		if(pnummer == NULL){
			printf("["FORM_RED"Pekare �r NULL!"FORM_END"]");
			break;
		}
		printf("[Tog bort sista element, v�rde: %d]\n", *pnummer);
		printf("[Antal element kvar: %d]\n", size(lista));
	}
	return 0;
}


