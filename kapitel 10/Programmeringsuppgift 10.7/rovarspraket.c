#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "strings_text_v1.h" //eget funktionsbibliotek
#define N 100

/* Programmeringsuppgift 10.7, Sida 237

Skriv ut en fil som inneh�ller text p� r�varspr�ket till sk�rmen, 
omvandlat till vanlig svenska.

info:
R�varspr�ket inneb�r att alla konsonanter �r f�rdubblade med ett
'o' mellan.

ex:
Skriv ett program som l�ser en textfil som inneh�ller r�varspr�k.
Programmet skall �vers�tta r�varspr�ket tillbaka till vanlig text.

--->

SoSkokrorivov etottot poprorogogroramom sosomom lol�soseror enon totexoxtotfofilol 
sosomom inonnonehoh�lolloleror ror�vovarorsospopror�kok.
PoProrogogroramommometot soskokalollol �voverorsos�tottota ror�vovarorsospopror�koketot 
totilollolbobakoka totilollol vovanonloligog totexoxtot.
texten finns i rovartext.txt

Konsonanter:
b, c, d, f, g, h, j, k, l, m, n, p, q, r, s, t, v, w, x, z
*/
int main(){
	FILE *rovarefil= fopen("rovartext.txt", "r");
	char s[N];
	//while-sats k�rs s� l�nge textfilTillString returnerar 1 (returnerar 0 n�r text i fil �r slut)
	while(textfilTillString(s, N, rovarefil)){
		//for-sats k�r lika m�nga varv som s har antal tecken
		for(int i =0; i<strlen(s);i++){
			/*om s[i] hittas i str�ngen inneh�llande konsonanter, �kas i med 2 (hoppar �ver tv� tecken)
			med tolower() testar den gemena versionen av tecknet i s[i]. Ett alternativ hade varit att ocks� ha med
			de versala konsonanterna i str�ngen att testa mot */
			if(strchr("bcdfghjklmnpqrstvwxz", tolower(s[i])) != NULL){
				i += 2;
			}
			//putchar skriver ut tecknet i s[i]
			putchar(s[i]);
		}
		/*textfilTillString plockar bort newline vid inl�sning fr�n textfil till variabeln, 
		\n skrivs ut manuellt vid varje while-satsvarv*/
		printf("\n");
	}
	return 0;
}



