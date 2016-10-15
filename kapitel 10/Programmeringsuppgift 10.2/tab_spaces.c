#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "strings_text_v1.h" //eget funktionsbibliotek
#define N 100

/* Programmeringsuppgift 10.2, Sida 236

Skriv ett program som läser en textfil, och skriver ut dess 
innehåll i kommandofönstret.
Alla tabb-slag ska bytas ut mot tre mellanslag 

tabbslag.txt:
hej	hej	hej
jag	heter	kalle
1 2 3 4	4		4 2 	4
2	2	1	1
a	b	c	d
*/

int main(){
	FILE * tabbfil = fopen("tabbslag.txt", "r");

	char s[N];
	//skriver text från fil till s, returnerar 0 vid slut på text i fil
	while(textfilTillString(s, N, tabbfil)){
		//for-sats körs lika många gånger som s har antal tecken (olika per while-sats)
		for(int i=0; i<strlen(s);i++){
			//om ett tabb-slag hittas printas tre mellanslag, annars skrivs tecknet ut
			if (s[i] == '\t'){
				//printf("***");
				printf("   ");
			}
			else{
				printf("%c", s[i]);
			}
		}
		//funktionen textfilTillString tar bort returslag \n, lägger till dem manuellt i varje while-sats
		printf("\n");
	}
	return 0;
}