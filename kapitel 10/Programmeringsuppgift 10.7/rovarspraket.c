#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "strings_text_v1.h" //eget funktionsbibliotek
#define N 100

/* Programmeringsuppgift 10.7, Sida 237

Skriv ut en fil som innehåller text på rövarspråket till skärmen, 
omvandlat till vanlig svenska.

info:
Rövarspråket innebär att alla konsonanter är fördubblade med ett
'o' mellan.

ex:
Skriv ett program som läser en textfil som innehåller rövarspråk.
Programmet skall översätta rövarspråket tillbaka till vanlig text.

--->

SoSkokrorivov etottot poprorogogroramom sosomom loläsoseror enon totexoxtotfofilol 
sosomom inonnonehohålolloleror rorövovarorsospoproråkok.
PoProrogogroramommometot soskokalollol övoverorsosätottota rorövovarorsospoproråkoketot 
totilollolbobakoka totilollol vovanonloligog totexoxtot.
texten finns i rovartext.txt

Konsonanter:
b, c, d, f, g, h, j, k, l, m, n, p, q, r, s, t, v, w, x, z
*/
int main(){
	FILE *rovarefil= fopen("rovartext.txt", "r");
	char s[N];
	//while-sats körs så länge textfilTillString returnerar 1 (returnerar 0 när text i fil är slut)
	while(textfilTillString(s, N, rovarefil)){
		//for-sats kör lika många varv som s har antal tecken
		for(int i =0; i<strlen(s);i++){
			/*om s[i] hittas i strängen innehållande konsonanter, ökas i med 2 (hoppar över två tecken)
			med tolower() testar den gemena versionen av tecknet i s[i]. Ett alternativ hade varit att också ha med
			de versala konsonanterna i strängen att testa mot */
			if(strchr("bcdfghjklmnpqrstvwxz", tolower(s[i])) != NULL){
				i += 2;
			}
			//putchar skriver ut tecknet i s[i]
			putchar(s[i]);
		}
		/*textfilTillString plockar bort newline vid inläsning från textfil till variabeln, 
		\n skrivs ut manuellt vid varje while-satsvarv*/
		printf("\n");
	}
	return 0;
}



