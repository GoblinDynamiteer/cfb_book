/* 
Programmeringsuppgift 4.7, Sida 91 - repetition

Simhopp-tävling: Minst 3 domare, varje domare ger poäng 1-10. 
Ta bort minsta och högsta poäng -> beräkna medelvärde av återstående. 
Multiplicera med 3 och tal som anger svårighetsgrad. 

Programmet ska läsa in antal domare, sedan domarpoäng. 
Beräkna och skriv ut poäng. 
Det ska gå att avsluta programmet vid alla inläsningar med EOF */


#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include "libtxt.h" //eget funktionsbibliotek för printLine() och färgformatering

#define MINDOMARE 3

int main(){
	int antalDomare;
	srand(time(NULL));
	//Blankar skärmen och sätter teckenkodning till 1252
	system("cls");
	system("chcp 1252");
	
	printLine('-', 40, 1);
	printf("  SIMHOPP!\n Skriv EOF (ctrl+z) för att avsluta programmet");
	printLine('-', 40, 1);
	
	while(1){ //Loopar om medans användaren skriver in fel antal domare
		printf("  Ange antal domare: ");
		if(scanf("%d", &antalDomare) == EOF){
			printf("  EOF! Avslutar!");
			return 0;
		}
		if(antalDomare < MINDOMARE){
			printf(FORM_RED"  Fel antal domare!\n"FORM_END);
			continue; //Går tillbaka till början av loopen
		}
		break; //bryter loopen
	}
	int domarPoang = 0, minPoang = INT_MAX, maxPoang = INT_MIN;
	double totalPoang = 0.0;
	for(int i=1;i<=antalDomare;i++){
		while(1){
			printf("  Ange poäng för domare %d: ", i);
			if(scanf("%d", &domarPoang) == EOF){
				printf("  EOF! Avslutar!");
				return 0;
			}
			if((domarPoang < 1) || (domarPoang > 10)){
				printf(FORM_RED"  Felaktig poäng!\n"FORM_END);
				continue; //Går tillbaka till början av loopen
			}
			break;
		}
		totalPoang += domarPoang;
		minPoang = fmin(minPoang, domarPoang);
		maxPoang = fmax(maxPoang, domarPoang);
	}
	printLine('#', 40, 1);
	printLine('#', 40, 1);
	//Jag väljer att randomisera svårighetsgraden
	double svarighetsFaktor = 1.0 + (1.0 / (rand() % 10 + 1));
	printf(" Slumpad svårighetsgrad: %.3f\n", svarighetsFaktor);
	printf(" Domarpoäng: %.3f - ", totalPoang);
	totalPoang -= (minPoang + maxPoang);
	printf("%d - %d = %.3f\n", 
		minPoang, 
		maxPoang, 
		totalPoang);
	printf(" Medelvärde = %.3f\n", totalPoang / (antalDomare - 2));
	printf(" Resultat: %.3f * 3 * %.3f = "FORM_GREEN"%.3f"FORM_END"\n", 
		totalPoang / (antalDomare-2), 
		svarighetsFaktor, 
		(totalPoang / (antalDomare-2))*3*svarighetsFaktor);
	printLine('#', 40, 1);
	return 0;
}
