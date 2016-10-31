/* Programmeringsuppgift 11.8, Sida 277
Skriv en funktion som delar upp en textsträng
i så kallade tokens. Varje token avgränsas av ett mellanslag
Först och sista token behöver inte ha initialt mellanslag eller efterliggande mellanslag (eller vittecken?)

Ex: Jag Heter Kalle 
ska delas upp i:
Jag
Heter
Kalle

Funktionen: 
void split(char *s, char *tab[], int max)

s är en pekare till den text som ska delas upp, ska avslutas med nolltecken \0
tab är en pekare till ett oiniterat fält, antal element i fältet ska vara max

funktionen ska fylla elementen i fältet tab så att de pekar på de token som finns i s

Om fältet tab innehåller färre element (variabel max) än antal token, så ska enbart dessa
första element fyllas. Å andra hållet, om det finns färre tokens än element i tab, så ska de
övriga elementen fyllas med tomma pekare.

Funktionen split ska lägga nolltecken efter varje token. */
#include <stdio.h>
#include <ctype.h>
#define MAX 12
#define N 128

void split(char *s, char *tab[], int max);

int main(){
	char *tokens[MAX];
	char delaUpp[N] = "        Dela upp mig i en jävla massa tokens tokens tokens ! tokens omg!    ";
	split(delaUpp, tokens, MAX);
	printf("\n\n");
	char delaUppLiten[N] = "   Bara några    tokens  ";
	split(delaUppLiten, tokens, MAX);
}

void split(char *s, char *tab[], int max){
	for(int i=0;i<max;i++){
		tab[i] = 0; //sätter nollpekare till arrayen
	}
	int n = 0; //index för tab, för pekare till "tokens"
	while(n<max){
		if(*s == '\0'){
			return; //avslutar funktion om nolltecken hittas i strängen (meningen är slut)
		}
		 //rasslar på pekaren s tills ett tecken hittas som inte är space & s inte är nolltecken
		if (isspace(*s) && *s){
			while(isspace(*s)){
			s++;
			}
		}
		if(*s == '\0'){
			return; //avslutar funktion om nolltecken hittas i strängen (meningen är slut)
		}
		tab[n] = s; //Sätter pekare på plats n till pekare s
		 //rasslar på pekaren s tills ett tecken hittas som är space & s inte är nolltecken
		while(!isspace(*s) && *s){
			s++;
		}
		*s = '\0'; //sätter nolltecken där space hittas
		s++; //ökar pekaren ett steg
		printf("tab[%d]: %s\n", n, tab[n]);
		n++;
	}
}