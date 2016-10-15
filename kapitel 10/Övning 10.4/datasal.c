#include <stdio.h>
#include <string.h>
#include <limits.h> //för INT_MIN

/* Övning 10.4, Sida 231

Skriv ett program som läser en loggfil för en datasal och som undersöker
vilken användare som har varit inloggad under längst tid.

Användarens namn och totala tid ska skrivas ut!


Loggfilen är en textfil där användarnamnen står på var sin rad, 
med inloggade minuter (per tillfälle) efter varje namn.

Ex:

kallep 25 40 15
hannak 30 45 15 33 14
svenneb 14 23 58 74 10
hakans 12 12 12 13 12 */

int main(){
	FILE * loggfil = fopen("loggfil_datasal2.txt", "r");
	/*Variabler för kopiering från textfil, hållare av användarnamn, 
	samt hållare av användare med max antal minuter loggade*/
	char s[100], anvandarnamn[30], anvandare_maxtid[30];
	/*Variabler för hållare av tid session/totalt, i=för förlänging av stränglängd att läsa ifrån, 
	maxtid sätts till minsta värdet en int kan ha, 
	så den sätts till den första totala loggade tiden första gången*/
	int tid_total, tid_session = 0, i, inlasta_tecken=0, maxtid=INT_MIN;
	/*whilesats som körs så länge text kan läsas från textfilen, 
	fgets skriver till variabeln s, från textfilen, en rad i taget eller tills 100 tecken har lästs in*/
	while (fgets(s, 100, loggfil) != NULL){
		tid_total = 0;
		/* sscanf fungerar som scanf fast den får texten från en textsträng (s i detta fall). Då jag
		antar att användarnamnen består av ett ord, så kan jag använda en enda sscanf*/
		sscanf(s, "%s", anvandarnamn);
		//i sätts till längen av det inlästa användarnamnet, så att nästa inläsning blir ett siffer-tal med s+i
		i = strlen(anvandarnamn);
		/*whilsesats som körs så länge sscanf returnerar 1, dvs en inläsning har lyckats, 
		%n är antal inlästa tecken som sscanf läser in, sätts till inlasta_tecken */
		while(sscanf(s+i, "%d%n", &tid_session, &inlasta_tecken) == 1){
			//tid_total sätts till summan av sessionstiderna
			tid_total += tid_session;
			//i ökar med antal inlästa tecken, så att nästa inläsning ovan blir till tecknen efter den inlästa siffran
			i += inlasta_tecken;
		}
		/*om maxtid är mindre än den totala tiden sätts maxtid till totaltid, 
		och användarnamnet kopieras till en hållare med strcpy. OBS det går inte använda array = array */
		if (maxtid<tid_total){
			maxtid = tid_total;
			strcpy(anvandare_maxtid, anvandarnamn);
		}
	}
	printf("Användaren '%s' har använt datasalen mest!\nTotal loggad tid: %d minuter", anvandare_maxtid, maxtid);
}