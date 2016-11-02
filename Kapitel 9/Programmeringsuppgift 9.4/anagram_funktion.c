#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
Programmeringsuppgift 9.4, Sida 215

Skriv en funktion 'ar_anagram', som j�mf�r tv� textstr�ngar.
Om den ena str�ngen �r ett anagram av den andra, s� ska 1
returneras, annars 0. Funktionen ska vara booleansk typ och
ha de tv� textstr�ngarna som parametrar.

Tips: Ta bort vita tecken i texterna innan j�mf�relse.

Ett anagram �r en tex/mening som bildar en annan text/mening
om man kastar om bokst�verna.

Ex:
Curt �rlig -> C �r lurigt 
Melt Rolls -> Slemtroll
Rack Rots -> RockStar
*/

/* Funktion som kopierar text fr�n en str�ng till en annan
och plockar bort alla vita tecken. 
- Fr�n �vning 9.10 */
void remove_white(char *to, char *from){
	int raknare=0;
	for(int i=0;from[i]!='\0';i++){
		if(!isspace(from[i])){
		to[raknare] = from[i];
		raknare++;
		} 
	}
	to[raknare] = '\0';
}

//Funktion som j�mf�r om tv� textstr�ngar �r anagram av varandra
_Bool ar_anagram(char *a, char *b){
	//Anropar funktionen remove_white f�r att ta bort mellanslag i textstr�ngarna
	remove_white(a,a);
	remove_white(b,b);
	int raknare_aa, raknare_ab, raknare_ba, raknare_bb;
	//for-sats k�rs s� l�nge ett nolltecken inte hittas i n�gon av str�ngarna.
	for(int i=0;a[i]!='\0' || b[i]!='\0';i++){
		raknare_aa = 0; //r�knare f�r antal tecken av a[i] i a-str�ngen
		raknare_ab = 0;	//r�knare f�r antal tecken av a[i] i b-str�ngen
		raknare_ba = 0; //r�knare f�r antal tecken av b[i] i a-str�ngen
		raknare_bb = 0;	//r�knare f�r antal tecken av b[i] i b-str�ngen
		//fyra for-satser som r�knar ur m�nga tecken av a[i] & b[i] det finns i a & b respektive
		for(int j=0;b[j]!='\0';j++)
			//tolower anv�nds f�r att returnera tecknets gemen
			if (tolower(a[i]) == tolower(b[j])){
				raknare_ab++;
			}
		for(int j=0;a[j]!='\0';j++)
			if (tolower(a[i]) == tolower(a[j])){
				raknare_aa++;
			}
		for(int j=0;b[j]!='\0';j++)
			if (tolower(b[i]) == tolower(b[j])){
				raknare_bb++;
			}
		for(int j=0;a[j]!='\0';j++)
			if (tolower(b[i]) == tolower(a[j])){
				raknare_ba++;
			}
		/*
		om raknare_a �r lika stor som raknare_b s� returneras 0, 
		str�ngarna har olika m�nga instanser av ett specifikt tecken
		*/
		if(raknare_aa != raknare_ab || raknare_ba != raknare_bb)
			return 0;
	}
	return 1;
}

int main(){
	char string1[25] = "Rack Rots", string2[25] = "RockStar";
	if(ar_anagram(string1,string2)){
		printf("%s -> %s �r anagram!",string1, string2);
	}
	else 
		printf("Ej anagram");
}