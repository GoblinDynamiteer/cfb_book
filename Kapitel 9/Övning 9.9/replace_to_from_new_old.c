#include <stdio.h>
#include <string.h>
#include <locale.h>
/*
�vning 9.9, Sida 211

Skriv en funktion 'replace', som har fyra parametrar, tv� pekare
'to' och 'from' och tv� enstaka tecken 'old' och 'new'.

From pekar p� en text som skall kopieras till det teckenf�lt to
pekar p�. Vid kopieringen ska alla f�rekomster av tecknet old
ers�ttas med tecknet new.
*/

/*
Funktion f�r att kopiera text fr�n en str�ng (from) till en annan (to)
alla instanser av chartecknet i 'old' byts ut till 'new'.
*/
void replace(char *from, char *to, char old, char new){
	//F�r att kunna hantera ������ anv�nds setlocale
	setlocale(LC_ALL, "");
	//while-loop som k�rs tills nolltecken '\0' hittas i textstr�ngen from
	for(int i = 0;from[i] != '\0';i++){
		/*
		if-sats som triggar i fall from[i] �r samma tecken som det som ska bytas ut, 'old'
		i s� fall s�tts to[i] till tecknet i new, p� samma plats som i from-str�ngen.
		Om inte if-satsen triggar, dvs om bokstaven inte ska bytas ut, s�tts platsen
		i to-str�ngen till samma tecken som den i from.
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
	//Variabler f�r test av funktionen replace
	char text_fran[100] = "The quick brown fox jumps over the lazy dog!";
	char text_till[100] = "JAGSKABYTASUTJAGSKABYTASUTJAGSKABY!";
	int bytfran = 'o', byttill = '�';
	//Textstr�ngarna skrivs ut:
	printf("Text fr�n: %s\n\n", text_fran);
	replace(text_fran, text_till, bytfran, byttill);
	printf("Text till: %s\n", text_till);
}

