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
	/* textstr�ng att konvertera, samt h�llare f�r de olika konverteringsstegen 
	palindrom_3 och palindrom_4 kommer inneh�lla texten utan vita tecken
	vara i lowercase, samt kommer palindrom_4 att vara texten bakifr�n */
	char palindrom_1[50] = "Dogma I am God";
	char palindrom_2[50] = "";
	char palindrom_3[50] = "";
	char palindrom_4[50] = "";
	
	//anrop av funktioner som manipulerar textstr�ngen och s�tter den i en annan array
	remove_white(palindrom_2,palindrom_1);
	baklanges(palindrom_3,palindrom_2);
	tolower_str(palindrom_4,palindrom_3);
	remove_white(palindrom_2,palindrom_1);
	tolower_str(palindrom_3,palindrom_2);
	
	//variabel som s�tts till noll om texten ej �r ett palindrom, f�r utskrift
	_Bool arIntePalindrom = 1;
	puts("----------------------------------------");
	//For-sats som k�r s� l�nge inte ett nolltecken l�ses i palindrom_3
	for(int i=0;palindrom_3[i]!='\0';i++){
		if (palindrom_3[i] != palindrom_4[i]){
			printf("%s �r ej ett palindrom!\n", palindrom_1);
			arIntePalindrom = 0;
			break;
		}
	}
	if (arIntePalindrom){
		printf("%s �r ett palindrom!\n", palindrom_1);
	}
	puts("----------------------------------------");
	return 0;
}














