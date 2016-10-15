#include <stdio.h>
#include <string.h>
#include <locale.h>
/*
Övning 9.9, Sida 211

Skriv en funktion 'replace', som har fyra parametrar, två pekare
'to' och 'from' och två enstaka tecken 'old' och 'new'.

From pekar på en text som skall kopieras till det teckenfält to
pekar på. Vid kopieringen ska alla förekomster av tecknet old
ersättas med tecknet new.
*/

/*
Funktion för att kopiera text från en sträng (from) till en annan (to)
alla instanser av chartecknet i 'old' byts ut till 'new'.
*/
void replace(char *from, char *to, char old, char new){
	//För att kunna hantera ÅÄÖåäö används setlocale
	setlocale(LC_ALL, "");
	//while-loop som körs tills nolltecken '\0' hittas i textsträngen from
	for(int i = 0;from[i] != '\0';i++){
		/*
		if-sats som triggar i fall from[i] är samma tecken som det som ska bytas ut, 'old'
		i så fall sätts to[i] till tecknet i new, på samma plats som i from-strängen.
		Om inte if-satsen triggar, dvs om bokstaven inte ska bytas ut, sätts platsen
		i to-strängen till samma tecken som den i from.
		*/
		if(from[i] == old){
			to[i] = new;
		}
		else{
			to[i] = from[i];
		}
	}
}

int main(){
	//Variabler för test av funktionen replace
	char text_fran[100] = "The quick brown fox jumps over the lazy dog!";
	char text_till[100] = "JAGSKABYTASUTJAGSKABYTASUTJAGSKABY!";
	int bytfran = 'o', byttill = 'å';
	//Textsträngarna skrivs ut:
	printf("Text från: %s\n\n", text_fran);
	replace(text_fran, text_till, bytfran, byttill);
	printf("Text till: %s\n", text_till);
}

