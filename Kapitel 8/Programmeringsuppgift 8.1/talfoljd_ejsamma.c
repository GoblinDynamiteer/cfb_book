#include <stdio.h>
#define N 1000
/*
Programmeringsuppgift 8.1, Sida 178

Skriv ett program som l�ser in ett antal heltal, max 1000 st.
Programmet ska skriva ut talen i samma ordning som de skrevs in,
dock ska inte dubletter f�rekomma.

Anv�ndaren avbryter inmatning av tal med EOF (ctrl+z i Windows).

Ex:
Om f�ljande tal l�ses in:
45 77 -22 3 45 0 21 -1 3
s� ska utskrifter bli
45 77 -22 3 0 21 -1
*/

int main(){
	//raknare = variabel som h�ller r�kningen p� hur m�nga tal som sl�s in, anv�nds ocks� f�r array-index
	int tal[N], raknare = 0; 
	//while-loop k�rs 1000 g�nger, eller tills anv�ndaren avbryter med EOF (ctrl+z)
	while(raknare < N){
		printf("(%d av max 1000) Skriv in ett heltal: ",raknare+1);
		if(scanf("%d", &tal[raknare]) == EOF){
			break;
		}
	raknare++;
	}
	/*
	hallare[] f�r kopiering/h�llare av tal i f�rsta arrayen
	variabel check s�tts till det v�rde man vill kolla dubletter f�r, 
	och j�mf�rs med v�rdena i hallare-arrayen. Om samma v�rde hittas
	�kar variabeln hittadubletter med 1, den kommer alltid bli minst 1 
	i och med att man alltid kommer ha samma v�rde minst en g�ng
	i hallare[]. Om fler en ett av samma v�rde hittas kommer 
	hittadubletter bli ett v�rde �ver 1.
	I slutet anv�nds en if-sats som skriver ut v�rdet, s� l�nge hittadubletter
	�r 1 (allts� enbart har hittat v�rdet en g�ng.)
	
	Eventuellt en kr�nglig l�sning, finns antagligen mycket b�ttre s�tt.
	*/
	puts("-----------------------------------------------------");
	puts("Talen i den ordning de skrevs in, utan dubletter:");
	int hallare[N], hittadubletter, check;
	for(int i=0;i<raknare;i++){
		hittadubletter = 0;
		hallare[i] = tal[i];
		check = tal[i];
		for(int j=0;j<raknare;j++){
			if(check == hallare[j]){
				hittadubletter++;
			}
		}
		if(hittadubletter==1){
			printf("%d ", tal[i]);
		}
	}
	puts("\n-----------------------------------------------------");
	return 0;
}