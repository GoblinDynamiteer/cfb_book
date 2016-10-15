#include <stdio.h>

/* Skriv ett program som läser in ett antal namn från tangentbordet 
och sparar de inlästa namnen i en textfil 'personer.txt'. Varje namn
ska stå på en egen rad. Om texfilen redan finns ska den inte skrivas
över, utan namnen ska skrivas till i slutet.

Kör programmet flera gånger och kontrollera textfilen med en text-editor */

int main(){
	char person_inmatning[40];
	/*
	Datatyp FILE för textfiler, fopen har argumenten "textfilnamn", och "mode": 
	"a": append, skriver till slutet av en textfil om den redan existerar 
	"r": read - öppnar textfil
	"w": write - skriver över data i textfil (till skillnad mot "a")
	*/
	FILE *personer_textfil = fopen("personer.txt", "a");
	while(1){
		printf("Ange ett namn: ");
			/*
			if-sats triggar om användaren matar in EOF? Använd fgets för att kunna slå in mellanslag
			i namnet, scanf fungerar också, men isåfall bara för ett namn i taget, då den inte läser
			in vittecken
			*/
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
  while (fgets(s, 100, stdin) != NULL) {
    fputs(s, f);
    printf("? ");
  }
  fclose(f);
} 

*/