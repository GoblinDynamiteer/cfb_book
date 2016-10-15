#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/* Övning 11.6, Sida 260
Skriv en ny version av övning 10.1, där textfilens namn hämtas från kommandoraden */

/* parametrar för main-funktionen, tas från start från kommandofönstret 
Ex: "personer_text.exe personer.txt" ska läsa in filen personer.txt */
int main(int argc, char *argv[]){
	//Check för argument vid körning av program, ska vara 2 (textfilens namn + (programnamnet))
	if(argc != 2){
		fprintf(stderr, "Fel antal argument!\n");
		exit(1);
	}
	char person_inmatning[40];
	//Test:
	//printf("ANGIVNA ARGUMENT FÖR PROGRAMMET: %s %s",argv[0], argv[1]);
	/*  Sätter Filvariabel till att öppna filen som matas in som argument till programmet argumentens 
	index börjar på 0, så andra argumentet är 1 */
	FILE *personer_textfil = fopen(argv[1], "a");
	if (personer_textfil == NULL){
		fprintf(stderr, "Kan ej öppna filen %s!\n", argv[1]);
		exit(2);
	}
	while(1){
		printf("Ange ett namn: ");
			/* if-sats triggar om användaren matar in EOF? Använd fgets för att kunna slå in mellanslag
			i namnet, scanf fungerar också, men isåfall bara för ett namn i taget, då den inte läser
			in vittecken. */
			if (fgets(person_inmatning, 40, stdin) == NULL){
				break;
			} 
		//fputs skriver textsträngen person_inmatning tilll filen personer_textfil
		fputs(person_inmatning, personer_textfil);
		//lägger till en newline efter personnamnet, så nästa inmatning blir på raden under
		//fputs("\n", personer_textfil); 
	}
	return 0;
}

/*
Författarens: 

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