#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Programmeringsuppgift 12.5, Sida 311

Definiera en struktur 'kort' som kan anv�ndas f�r
att beskriva en kortlek. Av�nd helta 0,1,2,3 f�r att
representera kortf�rgerna.

Skriv sedan ett program som skapar ett f�lt som inneh�ller
en hel kortlek med 52 kort. Initiera alla korten.

Blanda sedan kortleken, l�mpligtvis genom att l�ta tv�
randomiserade platser byta plats med varandra i leken.
Anv�nd rand() i stdlib.harderr

Leken ska sedan delas ut, upprepade g�nger. Anv�ndaren
ska ange hur m�nga kort denne vill ha vid varje utdelning! */

struct kort{
	int farg; //0: Hj�rter, 1: Ruter, 2:Spader, 3: Kl�ver
	int varde; //1: ess 11:knekt 12: dam 13:kung
};

void blandaKort(struct kort *k, int n);
void delaUtKort(struct kort *k, int n);
	

int main(){
	 //KOLLA OM FUNK BEH�VER EGEN
	struct kort kortlek1[52];
	char *kort_farg[4] ={
		"Hj�rter",
		"Ruter",
		"Spader",
		"Kl�ver"
	};
	//s�tt v�rden:
	int kort_nr = 0, raknare = 0;
	while(kort_nr < 52)
		for(int farg = 0;farg<4;farg++){
			for(int varde=1;varde<14;varde++){
				kortlek1[kort_nr].farg = farg;
				kortlek1[kort_nr++].varde = varde;
			}
		}
	int antalBlandningar;
	printf("Hur m�nga g�nger ska kort byta plats? :");
	scanf("%d", &antalBlandningar);
	blandaKort(kortlek1, antalBlandningar);
	
	printf("Hur m�nga g�nger ska kort byta plats? :");
	scanf("%d", &antalBlandningar);
	

//n = antal kort spelaren vill ha
	void delaUtKort(struct kort *k, int n){
		static int kort_kvar = 52;
		while(kort_nr < 52){
			for(int farg = 0;farg<4;farg++){
				for(int varde=1;varde<14;varde++){
					//F�rg:
					printf("Kort nr %d: ", raknare);
					raknare++;
					printf("%s ",kort_farg[ kortlek1[kort_nr].farg ]);
					//V�rde
					switch(kortlek1[kort_nr].varde){
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
							printf("%d\n",kortlek1[kort_nr].varde);
					}
					kort_nr++;
				}
			}
		}
		//printf("Hittade %d st kort i leken", raknare);
		return 0;
}
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




