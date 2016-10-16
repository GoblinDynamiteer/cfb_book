#include <stdio.h>
#define N 100

/* Programmeringsuppgift 12.1, Sida 310

Definiera en struktur 'bok', som beskriver  en bok.
Varje bok har:
	titel
	författare
	sidantal
	pris
Initiera två strukturvariabler, beskriv två böcker
Låt programmet skriva ut variablerna. */

int main(){
	struct bok{
		char titel[N];
		char forfattare[N];
		int sidantal;
		double pris;
};
	struct bok bok_info[2] = {
		{"C Från Början", "Jan Skansholm", 408, 310.00},
		{"American Gods", "Neil Gaiman", 784, 180.50}
	};
	
	for(int i=0; i<2;i++){
		printf("%s av %s, %d sidor, %.2f kr\n", 
		bok_info[i].titel, 
		bok_info[i].forfattare,
		bok_info[i].sidantal,
		bok_info[i].pris);
	}
	
}
