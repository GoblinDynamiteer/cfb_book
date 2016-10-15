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
	/* textsträng att konvertera, samt hållare för de olika konverteringsstegen 
	palindrom_3 och palindrom_4 kommer innehålla texten utan vita tecken
	vara i lowercase, samt kommer palindrom_4 att vara texten bakifrån */
	char palindrom_1[50] = "Dogma I am God";
	char palindrom_2[50] = "";
	char palindrom_3[50] = "";
	char palindrom_4[50] = "";
	
	//anrop av funktioner som manipulerar textsträngen och sätter den i en annan array
	remove_white(palindrom_2,palindrom_1);
	baklanges(palindrom_3,palindrom_2);
	tolower_str(palindrom_4,palindrom_3);
	remove_white(palindrom_2,palindrom_1);
	tolower_str(palindrom_3,palindrom_2);
	
	//variabel som sätts till noll om texten ej är ett palindrom, för utskrift
	_Bool arIntePalindrom = 1;
	puts("----------------------------------------");
	//For-sats som kör så länge inte ett nolltecken läses i palindrom_3
	for(int i=0;palindrom_3[i]!='\0';i++){
		if (palindrom_3[i] != palindrom_4[i]){
			printf("%s är ej ett palindrom!\n", palindrom_1);
			arIntePalindrom = 0;
			break;
		}
	}
	if (arIntePalindrom){
		printf("%s är ett palindrom!\n", palindrom_1);
	}
	puts("----------------------------------------");
	return 0;
}














