#include <stdio.h>
#define N 1000
/*
Programmeringsuppgift 8.1, Sida 178

Skriv ett program som läser in ett antal heltal, max 1000 st.
Programmet ska skriva ut talen i samma ordning som de skrevs in,
dock ska inte dubletter förekomma.

Användaren avbryter inmatning av tal med EOF (ctrl+z i Windows).

Ex:
Om följande tal läses in:
45 77 -22 3 45 0 21 -1 3
så ska utskrifter bli
45 77 -22 3 0 21 -1
*/

int main(){
	//raknare = variabel som håller räkningen på hur många tal som slås in, används också för array-index
	int tal[N], raknare = 0; 
	//while-loop körs 1000 gånger, eller tills användaren avbryter med EOF (ctrl+z)
	while(raknare < N){
		printf("(%d av max 1000) Skriv in ett heltal: ",raknare+1);
		if(scanf("%d", &tal[raknare]) == EOF){
			break;
		}
	raknare++;
	}
	/*
	hallare[] för kopiering/hållare av tal i första arrayen
	variabel check sätts till det värde man vill kolla dubletter för, 
	och jämförs med värdena i hallare-arrayen. Om samma värde hittas
	ökar variabeln hittadubletter med 1, den kommer alltid bli minst 1 
	i och med att man alltid kommer ha samma värde minst en gång
	i hallare[]. Om fler en ett av samma värde hittas kommer 
	hittadubletter bli ett värde över 1.
	I slutet används en if-sats som skriver ut värdet, så länge hittadubletter
	är 1 (alltså enbart har hittat värdet en gång.)
	
	Eventuellt en krånglig lösning, finns antagligen mycket bättre sätt.
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