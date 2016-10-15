#include <stdio.h>
#include <string.h>

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


void split(char *s, char *tab[], int max){
	int i = 0, sl = strlen(s);
	//S�tter nollpekare till elementen i tab
	while(i<max){
		tab[i++] = 0;
		}
	/* Loopen k�r s� l�nge *pekare inte �r st�rre �n s+sl-1 (b�rjar p� 0), i f�r pekarindex i tab s�tts till 0 
	Det hade g�tt att anv�nda pekaren 's' direkt, utan att deklarera en ny pekare */
	for(char *pekare = s, i=0;pekare < s+sl-1;pekare++){
		//Pekare �kar medans mellanslag hittas, och det pekaren pekar p� inte �r nolltecken
		printf("Pekaradress i b�rjan av loopen:\t\t %p\n", pekare);
		while(*pekare && *pekare == ' '){
			pekare++;
		}
		/*  Om det pekaren pekar p� �r nolltecken avslutas funktionen (void avslutas med return; ) 
		Denna triggar inte efter att nolltecken s�tts i slutet av for-loopen, f�r pekaren �kar med 1
		i loopens argument.  */
		if(*pekare == '\0'){
			return;
		}
		//Elementet i, som �r en pekare i tab, s�tts till det pekaren pekar p�, i �kar sedan med 1
		tab[i++] = pekare;
		//Pekaren �kar medans inga mellanslag hittas, 
		while(*pekare && *pekare != ' '){
			pekare++;
		}
		//Det pekaren pekar p� s�tts till nolltecken
		*pekare = '\0';
		printf("Pekaradress efter nolltecken satt:\t %p\n", pekare);
		//Om i �r st�rre �n max element f�r tab s� avslutas funktionen
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
	//F�r utskrift:
	for(int i = 0; i<antal_element;i++){
		printf("text[%d] %s\n", i, delar[i]);
	}
}



/* F�rfattarens:
void split(char *s, char *tab[], int max) {
  int i;
  for (i=0; i<max; i++)
    tab[i] = 0;		//s�tter tomma pekare.
  for (i=0; i<max; i++) {
    while (*s && *s == ' ')  //letar mellanslag i b�rjan?
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
  char txt[] = "Nu l�r  vi  oss C! ";
  char *tokens[N];
  split(txt, tokens, N);
  for (i=0; i< N && tokens[i]; i++) 
    printf("%s\n", tokens[i]);
} */