#include <stdio.h>
#include <string.h>

/* Programmeringsuppgift 9.3, Sida 215.

Skriv ett prgoram som l�ser en text och omvandlar den fr�n 'p-spr�ket'
till vanlig text.
I p-spr�ket dubbleras alla vokaler, och tecknet 'p' placeras mellan
dem.

Ex: 
"Apallapa kapan C"  --> "Alla kan C"
JopoHapaN �par B�pasT! */

int main(){
	//Variabler f�r input av text i p-spr�ket, konverterad text, och en variabel som inneh�ller svenska vokaler
	char p_kodad_text[100], avkodad_text[100], vokaler[25]="AaEeIiOoUuYy������";
	printf("Skriv en text i p-spr�ket f�r att avkoda den!: ");
	//printf skriver avbryter inl�sning vid ett vitt tecken, anv�nd fgets f�r korrekt inmatning av text
	fgets(p_kodad_text,100,stdin);
	//Index f�r char arrayen som konverterad text ska skrivas till 
	int raknare = 0;
	//for-sats k�r s� l�nge ett nolltecken inte hittas i str�ngen med p-spr�ket text
	for(int i=0; p_kodad_text[i]!='\0';i++){
		/* tecken skrivs fr�n kodad str�ng till avkodad str�ng, 
		om en vokal hittas i den kodade str�ngen �kar i med 2, 
		f�r att hoppa �ver tv� tecken.*/
		avkodad_text[raknare] = p_kodad_text[i];
		//strchr anv�nds f�r att s�ka om ett tecken finns i en str�ng, den returnerar NULL om den inte hittas
		if(strchr(vokaler,p_kodad_text[i]) != NULL){
			i+=2;
		}
		raknare++;
	}
	//sist s�tts ett nolltecken i str�ngen avkodad_text, och den skrivs ut
	avkodad_text[raknare] = '\0';
	printf("Avkodad text: %s", avkodad_text);
	return 0;
}

