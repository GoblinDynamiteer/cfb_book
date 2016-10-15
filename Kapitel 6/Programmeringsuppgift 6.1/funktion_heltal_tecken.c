#include <stdio.h>

/*
Programmeringsuppgift 6.1, sida 120

Skriv en funktion som ber�knar ett heltals tecken.
Som resultat ska funktionen ge v�rdet:
- 1 om talet �r st�rre �n 0
- 0 om talet �r lika med 0
- -1 om talet �r mindre �n 0

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
		printf("Talet �r st�rre �n 0!");
	else if (talkoll(tal) == -1)
		printf("Talet �r mindre �n 0!");
	else
		printf("Talet �r 0!");
	return 0;
}