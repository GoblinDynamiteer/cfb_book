/* 
Programmeringsuppgift 4.7, Sida 91 - repetition

Simhopp-t�vling: Minst 3 domare, varje domare ger po�ng 1-10. 
Ta bort minsta och h�gsta po�ng -> ber�kna medelv�rde av �terst�ende. 
Multiplicera med 3 och tal som anger sv�righetsgrad. 

Programmet ska l�sa in antal domare, sedan domarpo�ng. 
Ber�kna och skriv ut po�ng. 
Det ska g� att avsluta programmet vid alla inl�sningar med EOF */


#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include "libtxt.h" //eget funktionsbibliotek f�r printLine() och f�rgformatering

#define MINDOMARE 3

int main(){
	int antalDomare;
	srand(time(NULL));
	//Blankar sk�rmen och s�tter teckenkodning till 1252
	system("cls");
	system("chcp 1252");
	
	printLine('-', 40, 1);
	printf("  SIMHOPP!\n Skriv EOF (ctrl+z) f�r att avsluta programmet");
	printLine('-', 40, 1);
	
	while(1){ //Loopar om medans anv�ndaren skriver in fel antal domare
		printf("  Ange antal domare: ");
		if(scanf("%d", &antalDomare) == EOF){
			printf("  EOF! Avslutar!");
			return 0;
		}
		if(antalDomare < MINDOMARE){
			printf(FORM_RED"  Fel antal domare!\n"FORM_END);
			continue; //G�r tillbaka till b�rjan av loopen
		}
		break; //bryter loopen
	}
	int domarPoang = 0, minPoang = INT_MAX, maxPoang = INT_MIN;
	double totalPoang = 0.0;
	for(int i=1;i<=antalDomare;i++){
		while(1){
			printf("  Ange po�ng f�r domare %d: ", i);
			if(scanf("%d", &domarPoang) == EOF){
				printf("  EOF! Avslutar!");
				return 0;
			}
			if((domarPoang < 1) || (domarPoang > 10)){
				printf(FORM_RED"  Felaktig po�ng!\n"FORM_END);
				continue; //G�r tillbaka till b�rjan av loopen
			}
			break;
		}
		totalPoang += domarPoang;
		minPoang = fmin(minPoang, domarPoang);
		maxPoang = fmax(maxPoang, domarPoang);
	}
	printLine('#', 40, 1);
	printLine('#', 40, 1);
	//Jag v�ljer att randomisera sv�righetsgraden
	double svarighetsFaktor = 1.0 + (1.0 / (rand() % 10 + 1));
	printf(" Slumpad sv�righetsgrad: %.3f\n", svarighetsFaktor);
	printf(" Domarpo�ng: %.3f - ", totalPoang);
	totalPoang -= (minPoang + maxPoang);
	printf("%d - %d = %.3f\n", 
		minPoang, 
		maxPoang, 
		totalPoang);
	printf(" Medelv�rde = %.3f\n", totalPoang / (antalDomare - 2));
	printf(" Resultat: %.3f * 3 * %.3f = "FORM_GREEN"%.3f"FORM_END"\n", 
		totalPoang / (antalDomare-2), 
		svarighetsFaktor, 
		(totalPoang / (antalDomare-2))*3*svarighetsFaktor);
	printLine('#', 40, 1);
	return 0;
}
