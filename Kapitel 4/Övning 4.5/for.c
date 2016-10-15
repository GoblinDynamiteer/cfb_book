#include <stdio.h>

/*
Övning 4.5, sida 83
Skriv om programmet på s. 76 så att det 
använder en for-sats i stället för en while-sats.

kod från sida 76:

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
		//k = k + k; -- körs i for-satsen
	}
	printf("Summan blir %d\n", summa);
}