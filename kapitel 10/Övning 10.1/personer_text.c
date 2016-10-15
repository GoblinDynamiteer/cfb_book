#include <stdio.h>

/* Skriv ett program som l�ser in ett antal namn fr�n tangentbordet 
och sparar de inl�sta namnen i en textfil 'personer.txt'. Varje namn
ska st� p� en egen rad. Om texfilen redan finns ska den inte skrivas
�ver, utan namnen ska skrivas till i slutet.

K�r programmet flera g�nger och kontrollera textfilen med en text-editor */

int main(){
	char person_inmatning[40];
	/*
	Datatyp FILE f�r textfiler, fopen har argumenten "textfilnamn", och "mode": 
	"a": append, skriver till slutet av en textfil om den redan existerar 
	"r": read - �ppnar textfil
	"w": write - skriver �ver data i textfil (till skillnad mot "a")
	*/
	FILE *personer_textfil = fopen("personer.txt", "a");
	while(1){
		printf("Ange ett namn: ");
			/*
			if-sats triggar om anv�ndaren matar in EOF? Anv�nd fgets f�r att kunna sl� in mellanslag
			i namnet, scanf fungerar ocks�, men is�fall bara f�r ett namn i taget, d� den inte l�ser
			in vittecken
			*/
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
  while (fgets(s, 100, stdin) != NULL) {
    fputs(s, f);
    printf("? ");
  }
  fclose(f);
} 

*/