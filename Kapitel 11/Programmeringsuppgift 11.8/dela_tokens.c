#include <stdio.h>
#include <string.h>

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


void split(char *s, char *tab[], int max){
	int i = 0, sl = strlen(s);
	//Sätter nollpekare till elementen i tab
	while(i<max){
		tab[i++] = 0;
		}
	/* Loopen kör så länge *pekare inte är större än s+sl-1 (börjar på 0), i för pekarindex i tab sätts till 0 
	Det hade gått att använda pekaren 's' direkt, utan att deklarera en ny pekare */
	for(char *pekare = s, i=0;pekare < s+sl-1;pekare++){
		//Pekare ökar medans mellanslag hittas, och det pekaren pekar på inte är nolltecken
		printf("Pekaradress i början av loopen:\t\t %p\n", pekare);
		while(*pekare && *pekare == ' '){
			pekare++;
		}
		/*  Om det pekaren pekar på är nolltecken avslutas funktionen (void avslutas med return; ) 
		Denna triggar inte efter att nolltecken sätts i slutet av for-loopen, för pekaren ökar med 1
		i loopens argument.  */
		if(*pekare == '\0'){
			return;
		}
		//Elementet i, som är en pekare i tab, sätts till det pekaren pekar på, i ökar sedan med 1
		tab[i++] = pekare;
		//Pekaren ökar medans inga mellanslag hittas, 
		while(*pekare && *pekare != ' '){
			pekare++;
		}
		//Det pekaren pekar på sätts till nolltecken
		*pekare = '\0';
		printf("Pekaradress efter nolltecken satt:\t %p\n", pekare);
		//Om i är större än max element för tab så avslutas funktionen
		if(i>=max){
			return;
		}
	}
}

int main(){
	int antal_element = 8;
	char text[] = "   Jag ska delas upp      text   ";
	//Pekare till flera char-arrayer:
	char *delar[antal_element];
	split(text, delar, antal_element);
	//För utskrift:
	for(int i = 0; i<antal_element;i++){
		printf("text[%d] %s\n", i, delar[i]);
	}
}



/* Författarens:
void split(char *s, char *tab[], int max) {
  int i;
  for (i=0; i<max; i++)
    tab[i] = 0;		//sätter tomma pekare.
  for (i=0; i<max; i++) {
    while (*s && *s == ' ')  //letar mellanslag i början?
      s++;
    if (!*s)					//om nolltecken hittas?
      return; 				//avslutar void-funk
    tab[i] = s;
    while (*s && *s != ' ') 
      s++;
    if (!*s)
      return;
    *s++ = '\0';
  }  
}


// Testprogram, ingick inte i uppgiften
#include <stdio.h>
#define N 10
int main() {
  int i;
  char txt[] = "Nu lär  vi  oss C! ";
  char *tokens[N];
  split(txt, tokens, N);
  for (i=0; i< N && tokens[i]; i++) 
    printf("%s\n", tokens[i]);
} */