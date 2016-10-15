#include <stdio.h>
#include <float.h> //Innehåller definition för maxvärde double DBL_MAX
#define N 100

/*
Övning 8.4, Sida 158

Skriv om programmet på sida 158, så att det utförs utan att
använda en array för hållande av pris.

Uträkning av billigast pris ska ske direkt i while-satsen när 
priser matas in
*/

int main(){
	//double pris[N];	//Fält för priser
	//Hållare för billigaste priset sätts initialt till högsta värde en double kan ha
	double pris, BilligastePris = DBL_MAX;	
	int KortNummer;	//Hållare av billigaste kortnumret
	int n = 1;			//Räknare för antal typer av kort
	while(n<N){
		printf("Pris/min för kort nr %d?: ", n);
		//if (scanf("%lf", &pris[n]) != 1){
		if (scanf("%lf", &pris) != 1){
			break;
		}
		if (pris < BilligastePris){
			KortNummer = n;
			BilligastePris = pris;
		}
		n++; //Öka antalet typer av kort med 1	
	}
	//beräkna lägsta priset
	/*
	int billigast = 0;
	for(int i=1;i<n;i++){
		if (pris[i] < pris[billigast]){
			billigast = i; // nytt lägsta pris funnet!	
			printf("\nBILLIGAST: %d", billigast);
		}
	}
	*/
	printf("\nKort nr %d är billigast. \n", KortNummer);
	printf("\nKostnad: %4.2f kr/minut", BilligastePris);
}