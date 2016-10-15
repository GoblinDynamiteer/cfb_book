#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/* �vning 11.6, Sida 260
Skriv en ny version av �vning 10.1, d�r textfilens namn h�mtas fr�n kommandoraden */

/* parametrar f�r main-funktionen, tas fr�n start fr�n kommandof�nstret 
Ex: "personer_text.exe personer.txt" ska l�sa in filen personer.txt */
int main(int argc, char *argv[]){
	//Check f�r argument vid k�rning av program, ska vara 2 (textfilens namn + (programnamnet))
	if(argc != 2){
		fprintf(stderr, "Fel antal argument!\n");
		exit(1);
	}
	char person_inmatning[40];
	//Test:
	//printf("ANGIVNA ARGUMENT F�R PROGRAMMET: %s %s",argv[0], argv[1]);
	/*  S�tter Filvariabel till att �ppna filen som matas in som argument till programmet argumentens 
	index b�rjar p� 0, s� andra argumentet �r 1 */
	FILE *personer_textfil = fopen(argv[1], "a");
	if (personer_textfil == NULL){
		fprintf(stderr, "Kan ej �ppna filen %s!\n", argv[1]);
		exit(2);
	}
	while(1){
		printf("Ange ett namn: ");
			/* if-sats triggar om anv�ndaren matar in EOF? Anv�nd fgets f�r att kunna sl� in mellanslag
			i namnet, scanf fungerar ocks�, men is�fall bara f�r ett namn i taget, d� den inte l�ser
			in vittecken. */
			if (fgets(person_inmatning, 40, stdin) == NULL){
				break;
			} 
		//fputs skriver textstr�ngen person_inmatning tilll filen personer_textfil
		fputs(person_inmatning, personer_textfil);
		//l�gger till en newline efter personnamnet, s� n�sta inmatning blir p� raden under
		//fputs("\n", personer_textfil); 
	}
	return 0;
}

/*
F�rfattarens: 

int main() {
  FILE *f = fopen("personer.txt", "a"); 
  if (f == NULL) {
    printf("Kan inte hitta filen");
    exit(1);
  }
  char s[100];
  printf("? ");
  while (fgets(s, 100, stdin) != NULL){
	fputs(s, f);
    printf("? ");
  }
  fclose(f);
}

*/