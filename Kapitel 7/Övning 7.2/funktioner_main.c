#include "funktioner.h" //deklaration av funktioner i funktioner.c
#include <stdio.h>

/*
�vning 7.2, Sida 130

Skapa ett funktionsbibliotek best�ende av funktionerna
new_lines			- sida 115
read_double		- sida 112
read_int				- �vning 6.4

filer:
funktioner_main.c
funktioner.c
funktioner.h

*/


int main(){
	printf("Ange ett decimalt tal!: ");
	double tal1= read_double();
	printf("Hur m�nga \\n?: ");
	int rader;
	scanf("%d", &rader);
	printf("Ange ett heltal!!: ");
	int tal2= read_int();
	printf("%.3lf", tal1);
	new_lines(rader);
	printf("%d", tal2);
	return 0;
}