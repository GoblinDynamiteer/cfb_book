#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "strings_text_v1.h" //eget funktionsbibliotek
#define N 100

/* Programmeringsuppgift 10.3, Sida 236

G�r om Programmeringsuppgift 10.2, 
fast �ndra filen i st�llet f�r att skriva ut till kommandof�nstret.

tabbslag.txt:
hej	hej	hej
jag	heter	kalle
1 2 3 4	4		4 2 	4
2	2	1	1
a	b	c	d
*/

int main(){
	FILE * tabbfil = fopen("tabbslag.txt", "r");
	char s[N], tempfil_namn[N];
	//generera randomiserat filnamn
	tmpnam(tempfil_namn);
	//jag v�ljer att byta ut f�rsta tecknet i tempfilen, s� att den hamnar i samma katalog som c-filen.
	tempfil_namn[0] = 'A';
	strcat(tempfil_namn, "txt");
	FILE * tempfil = fopen(tempfil_namn, "w");
	//fputs("TEXT TILL TEMPFILEN", tempfil);
	//skriver text fr�n fil till s, returnerar 0 vid slut p� text i fil
	while(textfilTillString(s, N, tabbfil)){
		//for-sats k�rs lika m�nga g�nger som s har antal tecken (olika per while-sats)
		for(int i=0; i<strlen(s);i++){
			//om ett tabb-slag hittas printas skrivs mellanslag till tempfil, annars skrivs tecknet
			if (s[i] == '\t'){
				//fputs("***", tempfil);
				fputs("   ", tempfil);
				//printf("triggar (TAB)\n");
			}
			else{
				putc(s[i], tempfil);
				//printf("%c", s[i]);
				//printf("triggar (tecken)\n");
			}
		}
		//funktionen textfilTillString tar bort returslag \n, l�gger till dem manuellt i varje while-sats
		putc('\n', tempfil);
		//printf("\n");
	}
	//st�nger och �ppnar tabblsag.txt och tempfilen, byter skrivningsr�ttigheter

	freopen("tabbslag.txt","w", tabbfil);
	freopen(tempfil_namn, "r", tempfil);
	//koperia inneh�ll fr�n temp till tabblsag.txt, skrivs �ver
	while(textfilTillString(s, N, tempfil)){
		fprintf(tabbfil, "%s\n", s);
	}
	fclose(tempfil);
	remove(tempfil_namn);
	return 0;
}