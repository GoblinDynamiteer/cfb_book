#include <stdio.h>

/* Programmeringsuppgift 12.3, Sida 311

Ett rationellt tal t/n är ett tal som kan skrivas som kvoten
mellan två heltal, en täljare och en nämnare.

ex: 5/9, 1/3, 7/12

Skapa en struktur 'rat_tal' som håller rationella tal, och initera de 
tre talen i exemplet. */

struct rat_tal{
	int taljare, namnare;
};

int main(){
	struct rat_tal tal[3] = {
		{5,9},
		{1,3},
		{7,12}
	};
	for (int i=0;i<3;i++){
		printf("%d / %d \n", tal[i].taljare, tal[i].namnare);
	}
	return 0;
}