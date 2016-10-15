#include <stdio.h>
#include <string.h>
#include <limits.h> //f�r INT_MIN

/* �vning 10.4, Sida 231

Skriv ett program som l�ser en loggfil f�r en datasal och som unders�ker
vilken anv�ndare som har varit inloggad under l�ngst tid.

Anv�ndarens namn och totala tid ska skrivas ut!


Loggfilen �r en textfil d�r anv�ndarnamnen st�r p� var sin rad, 
med inloggade minuter (per tillf�lle) efter varje namn.

Ex:

kallep 25 40 15
hannak 30 45 15 33 14
svenneb 14 23 58 74 10
hakans 12 12 12 13 12 */

int main(){
	FILE * loggfil = fopen("loggfil_datasal2.txt", "r");
	/*Variabler f�r kopiering fr�n textfil, h�llare av anv�ndarnamn, 
	samt h�llare av anv�ndare med max antal minuter loggade*/
	char s[100], anvandarnamn[30], anvandare_maxtid[30];
	/*Variabler f�r h�llare av tid session/totalt, i=f�r f�rl�nging av str�ngl�ngd att l�sa ifr�n, 
	maxtid s�tts till minsta v�rdet en int kan ha, 
	s� den s�tts till den f�rsta totala loggade tiden f�rsta g�ngen*/
	int tid_total, tid_session = 0, i, inlasta_tecken=0, maxtid=INT_MIN;
	/*whilesats som k�rs s� l�nge text kan l�sas fr�n textfilen, 
	fgets skriver till variabeln s, fr�n textfilen, en rad i taget eller tills 100 tecken har l�sts in*/
	while (fgets(s, 100, loggfil) != NULL){
		tid_total = 0;
		/* sscanf fungerar som scanf fast den f�r texten fr�n en textstr�ng (s i detta fall). D� jag
		antar att anv�ndarnamnen best�r av ett ord, s� kan jag anv�nda en enda sscanf*/
		sscanf(s, "%s", anvandarnamn);
		//i s�tts till l�ngen av det inl�sta anv�ndarnamnet, s� att n�sta inl�sning blir ett siffer-tal med s+i
		i = strlen(anvandarnamn);
		/*whilsesats som k�rs s� l�nge sscanf returnerar 1, dvs en inl�sning har lyckats, 
		%n �r antal inl�sta tecken som sscanf l�ser in, s�tts till inlasta_tecken */
		while(sscanf(s+i, "%d%n", &tid_session, &inlasta_tecken) == 1){
			//tid_total s�tts till summan av sessionstiderna
			tid_total += tid_session;
			//i �kar med antal inl�sta tecken, s� att n�sta inl�sning ovan blir till tecknen efter den inl�sta siffran
			i += inlasta_tecken;
		}
		/*om maxtid �r mindre �n den totala tiden s�tts maxtid till totaltid, 
		och anv�ndarnamnet kopieras till en h�llare med strcpy. OBS det g�r inte anv�nda array = array */
		if (maxtid<tid_total){
			maxtid = tid_total;
			strcpy(anvandare_maxtid, anvandarnamn);
		}
	}
	printf("Anv�ndaren '%s' har anv�nt datasalen mest!\nTotal loggad tid: %d minuter", anvandare_maxtid, maxtid);
}