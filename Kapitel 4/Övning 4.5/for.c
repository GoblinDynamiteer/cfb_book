#include <stdio.h>

/*
�vning 4.5, sida 83
Skriv om programmet p� s. 76 s� att det 
anv�nder en for-sats i st�llet f�r en while-sats.

kod fr�n sida 76:

int main(){
	printf("n? ");
	int n;
	scanf("%d", &n);
	int summa=0;
	int k=1;
	while (k <= n){
		summa = summa + k;
		k = k + k;
	}
	printf("Summan blir %d\n, summa");
}
*/
int main(){
	printf("n? ");
	int n;
	scanf("%d", &n);
	int summa=0;
	//int k=1; -- initieras i for-satsen
	//while (k <= n){ -- byts ut mot for-sats
	for (int k=1;k<=n;k=k+k){
		summa = summa + k;
		//k = k + k; -- k�rs i for-satsen
	}
	printf("Summan blir %d\n", summa);
}