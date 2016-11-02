#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
Programmeringsuppgift 9.4, Sida 215

Skriv en funktion 'ar_anagram', som jämför två textsträngar.
Om den ena strängen är ett anagram av den andra, så ska 1
returneras, annars 0. Funktionen ska vara booleansk typ och
ha de två textsträngarna som parametrar.

Tips: Ta bort vita tecken i texterna innan jämförelse.

Ett anagram är en tex/mening som bildar en annan text/mening
om man kastar om bokstäverna.

Ex:
Curt Ärlig -> C är lurigt 
Melt Rolls -> Slemtroll
Rack Rots -> RockStar
*/

/* Funktion som kopierar text från en sträng till en annan
och plockar bort alla vita tecken. 
- Från övning 9.10 */
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

//Funktion som jämför om två textsträngar är anagram av varandra
_Bool ar_anagram(char *a, char *b){
	//Anropar funktionen remove_white för att ta bort mellanslag i textsträngarna
	remove_white(a,a);
	remove_white(b,b);
	int raknare_aa, raknare_ab, raknare_ba, raknare_bb;
	//for-sats körs så länge ett nolltecken inte hittas i någon av strängarna.
	for(int i=0;a[i]!='\0' || b[i]!='\0';i++){
		raknare_aa = 0; //räknare för antal tecken av a[i] i a-strängen
		raknare_ab = 0;	//räknare för antal tecken av a[i] i b-strängen
		raknare_ba = 0; //räknare för antal tecken av b[i] i a-strängen
		raknare_bb = 0;	//räknare för antal tecken av b[i] i b-strängen
		//fyra for-satser som räknar ur många tecken av a[i] & b[i] det finns i a & b respektive
		for(int j=0;b[j]!='\0';j++)
			//tolower används för att returnera tecknets gemen
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
		om raknare_a är lika stor som raknare_b så returneras 0, 
		strängarna har olika många instanser av ett specifikt tecken
		*/
		if(raknare_aa != raknare_ab || raknare_ba != raknare_bb)
			return 0;
	}
	return 1;
}

int main(){
	char string1[25] = "Rack Rots", string2[25] = "RockStar";
	if(ar_anagram(string1,string2)){
		printf("%s -> %s är anagram!",string1, string2);
	}
	else 
		printf("Ej anagram");
}