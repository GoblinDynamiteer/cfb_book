#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "strings_text_v1.h"
#include "abonnemang.h"
#define N 100

double pris(const struct abonnemang *p, int min, double gb){
	double antal_min = fmax(min - p->fria_min, 0);
	double antal_gb = fmax(gb - p->fria_gb, 0);
	return p->per_manad + antal_min * p->extra_min + antal_gb * p->extra_gb;
}

int main(){
	struct abonnemang a[N];
	int n = 0;
	FILE *f = fopen("mobildata.txt", "r");
	//Scannar in textfilen till struct
	while(TTS(a[n].namn, ABNAMN_LANGD, f)){
		fscanf(f, "%lf%d%lf%lf%lf",
			&a[n].per_manad,
			&a[n].fria_min,
			&a[n].extra_min,
			&a[n].fria_gb,
			&a[n].extra_gb);
		clearBufferFil(f); //t�m teckenbuffer (fil)
		n++;	//�ka typer av abonnemang med 1
	}
	int min;
	double gb;
	printf("Hur m�nga minuter ringer du f�r?: ");
	scanf("%d", &min);
	printf("Hur m�nga gigabyte anv�nder du?: ");
	scanf("%lf", &gb);
	
	//Ber�kna det l�gsta priset
	int b = 0;	//index f�r billigaste
	for(int i=1; i<n; i++){
		if(pris(&a[i], min, gb) < pris(&a[b], min , gb))
			b = i; //l�gsta pris funnet.
	}
	printf("\n%s �r billigast.\n", a[b].namn);
	printf("kostnad: %4.2f kr", pris(&a[b], min, gb));
}