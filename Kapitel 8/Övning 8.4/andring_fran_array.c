#include <stdio.h>
#include <float.h> //Inneh�ller definition f�r maxv�rde double DBL_MAX
#define N 100

/*
�vning 8.4, Sida 158

Skriv om programmet p� sida 158, s� att det utf�rs utan att
anv�nda en array f�r h�llande av pris.

Utr�kning av billigast pris ska ske direkt i while-satsen n�r 
priser matas in
*/

int main(){
	//double pris[N];	//F�lt f�r priser
	//H�llare f�r billigaste priset s�tts initialt till h�gsta v�rde en double kan ha
	double pris, BilligastePris = DBL_MAX;	
	int KortNummer;	//H�llare av billigaste kortnumret
	int n = 1;			//R�knare f�r antal typer av kort
	while(n<N){
		printf("Pris/min f�r kort nr %d?: ", n);
		//if (scanf("%lf", &pris[n]) != 1){
		if (scanf("%lf", &pris) != 1){
			break;
		}
		if (pris < BilligastePris){
			KortNummer = n;
			BilligastePris = pris;
		}
		n++; //�ka antalet typer av kort med 1	
	}
	//ber�kna l�gsta priset
	/*
	int billigast = 0;
	for(int i=1;i<n;i++){
		if (pris[i] < pris[billigast]){
			billigast = i; // nytt l�gsta pris funnet!	
			printf("\nBILLIGAST: %d", billigast);
		}
	}
	*/
	printf("\nKort nr %d �r billigast. \n", KortNummer);
	printf("\nKostnad: %4.2f kr/minut", BilligastePris);
}