#include <stdio.h>

/* Programmeringsuppgift 12.3, Sida 311

Ett rationellt tal t/n �r ett tal som kan skrivas som kvoten
mellan tv� heltal, en t�ljare och en n�mnare.

ex: 5/9, 1/3, 7/12

Skapa en struktur 'rat_tal' som h�ller rationella tal, och initera de 
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