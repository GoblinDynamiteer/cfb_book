/* Programmeringsuppgift 11.8, Sida 277
Skriv en funktion som delar upp en textstr�ng
i s� kallade tokens. Varje token avgr�nsas av ett mellanslag
F�rst och sista token beh�ver inte ha initialt mellanslag eller efterliggande mellanslag (eller vittecken?)

Ex: Jag Heter Kalle 
ska delas upp i:
Jag
Heter
Kalle

Funktionen: 
void split(char *s, char *tab[], int max)

s �r en pekare till den text som ska delas upp, ska avslutas med nolltecken \0
tab �r en pekare till ett oiniterat f�lt, antal element i f�ltet ska vara max

funktionen ska fylla elementen i f�ltet tab s� att de pekar p� de token som finns i s

Om f�ltet tab inneh�ller f�rre element (variabel max) �n antal token, s� ska enbart dessa
f�rsta element fyllas. � andra h�llet, om det finns f�rre tokens �n element i tab, s� ska de
�vriga elementen fyllas med tomma pekare.

Funktionen split ska l�gga nolltecken efter varje token. */
#include <stdio.h>
#include <ctype.h>
#define MAX 12
#define N 128

void split(char *s, char *tab[], int max);

int main(){
	char *tokens[MAX];
	char delaUpp[N] = "        Dela upp mig i en j�vla massa tokens tokens tokens ! tokens omg!    ";
	split(delaUpp, tokens, MAX);
	printf("\n\n");
	char delaUppLiten[N] = "   Bara n�gra    tokens  ";
	split(delaUppLiten, tokens, MAX);
}

void split(char *s, char *tab[], int max){
	for(int i=0;i<max;i++){
		tab[i] = 0; //s�tter nollpekare till arrayen
	}
	int n = 0; //index f�r tab, f�r pekare till "tokens"
	while(n<max){
		if(*s == '\0'){
			return; //avslutar funktion om nolltecken hittas i str�ngen (meningen �r slut)
		}
		 //rasslar p� pekaren s tills ett tecken hittas som inte �r space & s inte �r nolltecken
		if (isspace(*s) && *s){
			while(isspace(*s)){
			s++;
			}
		}
		if(*s == '\0'){
			return; //avslutar funktion om nolltecken hittas i str�ngen (meningen �r slut)
		}
		tab[n] = s; //S�tter pekare p� plats n till pekare s
		 //rasslar p� pekaren s tills ett tecken hittas som �r space & s inte �r nolltecken
		while(!isspace(*s) && *s){
			s++;
		}
		*s = '\0'; //s�tter nolltecken d�r space hittas
		s++; //�kar pekaren ett steg
		printf("tab[%d]: %s\n", n, tab[n]);
		n++;
	}
}