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
	FILE *f = fopen("mobildata.dat", "rb");
	//Scannar in textfilen till struct
	while(fread(&a[n], sizeof(struct abonnemang), 1, f) == 1){
		n++;	//öka typer av abonnemang med 
	}
	for(int i=0;i<n;i++){
		printf("Namn: %s\nPer månad %.2f kr\nGratisminuter: %d\nPris per min: %.2f kr\nFri surf: %.2f GB\nPris per GB: %.2f kr\n\n", 
		a[i].namn,
		a[i].per_manad,
		a[i].fria_min,
		a[i].extra_min,
		a[i].fria_gb,
		a[i].extra_gb
		);
	}

}