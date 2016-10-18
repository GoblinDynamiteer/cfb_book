#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Programmeringsuppgift 12.5, Sida 311

Definiera en struktur 'kort' som kan användas för
att beskriva en kortlek. Avänd helta 0,1,2,3 för att
representera kortfärgerna.

Skriv sedan ett program som skapar ett fält som innehåller
en hel kortlek med 52 kort. Initiera alla korten.

Blanda sedan kortleken, lämpligtvis genom att låta två
randomiserade platser byta plats med varandra i leken.
Använd rand() i stdlib.harderr

Leken ska sedan delas ut, upprepade gånger. Användaren
ska ange hur många kort denne vill ha vid varje utdelning! */


//!Uppdatera kommentarer..



struct kort{
	int farg; //0: Hjärter, 1: Ruter, 2:Spader, 3: Klöver
	int varde; //1: ess 11:knekt 12: dam 13:kung
};

void blandaKort(struct kort *k, int n);
void delaUtKort(struct kort *k, int n);
	
int main(){
	struct kort kortlek1[52];
	//sätt värden:
	int kort_nr = 0, raknare = 0, spader = 9827;
	while(kort_nr < 52)
		for(int farg = 0;farg<4;farg++){
			for(int varde=1;varde<14;varde++){
				kortlek1[kort_nr].farg = farg;
				kortlek1[kort_nr++].varde = varde;
			}
		}
	int antal;
	printf("Hur många gånger ska kort byta plats? :");
	scanf("%d", &antal);
	blandaKort(kortlek1, antal);
	
	printf("Blandning klar!\nHur många kort vill du ha? :");
	while(1){
		scanf("%d", &antal);
		printf("------------------------------\n");
		printf("Du fick kort:\n");
		delaUtKort(kortlek1, antal);
		putchar(spader);
		printf("%c", spader);
		printf("------------------------------\n");
		printf("Fler kort: ");
	}
	return 0;
}

//n = antal kort spelaren vill ha
void delaUtKort(struct kort *k, int n){
	char *kort_farg[4] ={
		"Hjärter",
		"Ruter",
		"Spader",
		"Klöver"
	};
	static int kort_nr = 0;
	while(n--){
				//Färg:
				if(kort_nr == 52){
					printf("\nSlut på kort!");
					exit(0);
				}
				printf("%s ", kort_farg[ (k+kort_nr) -> farg ]  );
				//Värde
				switch(  (k+kort_nr) -> varde  ){
					case 1: 
						printf("Ess\n");
						break;
					case 11: 
						printf("Knekt\n");
						break;
					case 12: 
						printf("Dam\n");
						break;
					case 13: 
						printf("Kung\n");
						break;
					default:
						printf("%d\n", (k+kort_nr) -> varde);
				}
				kort_nr++;
			}
		printf("(%d kort kvar)\n", 52 - kort_nr);
	return;
}

void blandaKort(struct kort *k, int n){
	srand(time(NULL));
	int kort1, kort2, temp[2];
	while(n--){
		do{
			kort1 = rand() % 52;
			kort2 = rand() % 52;
		}while(kort1 == kort2);
		// printf("Random kort: kort1: %d\n", kort1);
		// printf("Random kort: kort2: %d\n\n", kort2);
		// printf("Varde kort1: (k+%d) -> varde: %d\n", kort1, (k+kort1) -> varde);
		// printf("Varde kort2: (k+%d) -> varde: %d\n\n", kort2, (k+kort2) -> varde);
		temp[0] = (k+kort1) -> farg;
		temp[1] = (k+kort1) -> varde;
		(k+kort1) -> farg = (k+kort2) -> farg;
		(k+kort1) -> varde = (k+kort2) -> varde;
		(k+kort2) -> farg = temp[0];
		(k+kort2) -> varde = temp[1];
	};
	return;
}




