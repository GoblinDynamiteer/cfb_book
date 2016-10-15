#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

/* Programmeringsuppgift 9.2, Sida 214

Skapa ett program som testar om en textstr�ng �r en palindrom
En palindrom �r en mening som blir samma b�de bakifr�n och
framifr�n.

Tips: Ta bort vita tecken och byt ut alla bokst�ver till gemener.

Anv�nd funktionerna 
remove_white fr�n �vning 9.10
tolower_str fr�n sida 211
baklanges fr�n programmeringsuppgift 9.1

Exempel:
Ah Satan sees Natasha
Dogma I am God
Flee to me remote elf

Fr�n hemsidan: mystring.c */
void tolower_str(char *to, const char *from) {
  setlocale(LC_ALL, "");
  int i = 0;
  for (; from[i] != '\0'; i++)
    to[i] = tolower(from[i]);
  to[i] = '\0';
}

//fr�n programmeringsuppgift 9.1
void baklanges(char *till, char *fran){
	int raknare = 0;
	for(int i=strlen(fran)-1;i>=0;i--){
		till[raknare] = fran[i];
		raknare++;
	}
	till[raknare]='\0';
}

//fr�n �vning 9.10
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
	/* textstr�ng att konvertera, samt h�llare av modifierad str�ng att j�mf�ra med */
	char p_1[50] = "Dogma I    aM God", p_2[50];
	//anrop av funktioner, samma str�ng kan anv�ndas b�de som till och fr�n
	//f�rsta str�ngen reverseras, g�rs om till endast gemener, samt tas vita tecken bort
	remove_white(p_2, p_1);
	tolower_str(p_2, p_2);
	baklanges(p_2, p_2);
	//den f�rsta str�ngen g�rs om till endast gemener, samt tas vita tecken bort, reverseras ej
	remove_white(p_1, p_1);
	tolower_str(p_1, p_1);
	//str�ngarna j�mf�rs med funktionen strcmp. Villkoret inverteras, d� strcmp returnerar 0 om str�ngarna �r lika
	if (!strcmp(p_1, p_2))
		printf("%s �r en palindrom!", p_1);
	else 
		printf("%s �r ej en palindrom!", p_1);
	return 0;
}














