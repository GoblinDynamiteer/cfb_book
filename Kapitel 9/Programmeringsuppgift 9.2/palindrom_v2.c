#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

/* Programmeringsuppgift 9.2, Sida 214

Skapa ett program som testar om en textsträng är en palindrom
En palindrom är en mening som blir samma både bakifrån och
framifrån.

Tips: Ta bort vita tecken och byt ut alla bokstäver till gemener.

Använd funktionerna 
remove_white från övning 9.10
tolower_str från sida 211
baklanges från programmeringsuppgift 9.1

Exempel:
Ah Satan sees Natasha
Dogma I am God
Flee to me remote elf

Från hemsidan: mystring.c */
void tolower_str(char *to, const char *from) {
  setlocale(LC_ALL, "");
  int i = 0;
  for (; from[i] != '\0'; i++)
    to[i] = tolower(from[i]);
  to[i] = '\0';
}

//från programmeringsuppgift 9.1
void baklanges(char *till, char *fran){
	int raknare = 0;
	for(int i=strlen(fran)-1;i>=0;i--){
		till[raknare] = fran[i];
		raknare++;
	}
	till[raknare]='\0';
}

//från övning 9.10
void remove_white(char *to, char *from){
	int raknare=0;
	for(int i=0;from[i]!='\0';i++){
		if(!isspace(from[i])){
		to[raknare] = from[i];
		raknare++;
		} 
	}
	to[raknare] = '\0';
}

int main(){
	/* textsträng att konvertera, samt hållare av modifierad sträng att jämföra med */
	char p_1[50] = "Dogma I    aM God", p_2[50];
	//anrop av funktioner, samma sträng kan användas både som till och från
	//första strängen reverseras, görs om till endast gemener, samt tas vita tecken bort
	remove_white(p_2, p_1);
	tolower_str(p_2, p_2);
	baklanges(p_2, p_2);
	//den första strängen görs om till endast gemener, samt tas vita tecken bort, reverseras ej
	remove_white(p_1, p_1);
	tolower_str(p_1, p_1);
	//strängarna jämförs med funktionen strcmp. Villkoret inverteras, då strcmp returnerar 0 om strängarna är lika
	if (!strcmp(p_1, p_2))
		printf("%s är en palindrom!", p_1);
	else 
		printf("%s är ej en palindrom!", p_1);
	return 0;
}














