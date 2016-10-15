#include <stdio.h>
#include <string.h>

/* Programmeringsuppgift 9.3, Sida 215.

Skriv ett prgoram som läser en text och omvandlar den från 'p-språket'
till vanlig text.
I p-språket dubbleras alla vokaler, och tecknet 'p' placeras mellan
dem.

Ex: 
"Apallapa kapan C"  --> "Alla kan C"
JopoHapaN äpar BäpasT! */

int main(){
	//Variabler för input av text i p-språket, konverterad text, och en variabel som innehåller svenska vokaler
	char p_kodad_text[100], avkodad_text[100], vokaler[25]="AaEeIiOoUuYyÅåÄäÖö";
	printf("Skriv en text i p-språket för att avkoda den!: ");
	//printf skriver avbryter inläsning vid ett vitt tecken, använd fgets för korrekt inmatning av text
	fgets(p_kodad_text,100,stdin);
	//Index för char arrayen som konverterad text ska skrivas till 
	int raknare = 0;
	//for-sats kör så länge ett nolltecken inte hittas i strängen med p-språket text
	for(int i=0; p_kodad_text[i]!='\0';i++){
		/* tecken skrivs från kodad sträng till avkodad sträng, 
		om en vokal hittas i den kodade strängen ökar i med 2, 
		för att hoppa över två tecken.*/
		avkodad_text[raknare] = p_kodad_text[i];
		//strchr används för att söka om ett tecken finns i en sträng, den returnerar NULL om den inte hittas
		if(strchr(vokaler,p_kodad_text[i]) != NULL){
			i+=2;
		}
		raknare++;
	}
	//sist sätts ett nolltecken i strängen avkodad_text, och den skrivs ut
	avkodad_text[raknare] = '\0';
	printf("Avkodad text: %s", avkodad_text);
	return 0;
}

