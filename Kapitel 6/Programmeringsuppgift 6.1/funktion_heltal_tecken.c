#include <stdio.h>

/*
Programmeringsuppgift 6.1, sida 120

Skriv en funktion som beräknar ett heltals tecken.
Som resultat ska funktionen ge värdet:
- 1 om talet är större än 0
- 0 om talet är lika med 0
- -1 om talet är mindre än 0

*/


int talkoll (int x){
	if (x>0)
		return 1;
	if (x<0)
		return -1;
	else 
		return 0;
}

int main(){
	int tal;
	printf("Ange tal!");
	scanf("%d", &tal);
	if (talkoll(tal) == 1)
		printf("Talet är större än 0!");
	else if (talkoll(tal) == -1)
		printf("Talet är mindre än 0!");
	else
		printf("Talet är 0!");
	return 0;
}