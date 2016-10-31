/* Övning 10.4, Sida 231 - Repetition

Skriv ett program som läser en loggfil för en datasal och som undersöker
vilken användare som har varit inloggad under längst tid.

Användarens namn och totala tid ska skrivas ut!

Loggfilen är en textfil där användarnamnen står på var sin rad, 
med inloggade minuter (per tillfälle) efter varje namn.

Ex:

kallep 25 40 15
hannak 30 45 15 33 14
svenneb 14 23 58 74 10
hakans 12 12 12 13 12 */

#define FILNAMN "loggfil_datasal2.txt"
#define N 200
#include <stdio.h>
#include <string.h>

int main(){
	char rad[N], user[10], usermax[10]; //För inläsning av filrad, hållare av namn
	int tid, tidin, max = 0, i, n;
	FILE *fil = fopen(FILNAMN, "r");
	while(fgets(rad, N, fil) != NULL){
		sscanf(rad, "%s", user); printf("user: %s\t\t", user);
		tid = 0;
		n = strlen(user);
		while(sscanf(rad+n, "%d%n", &tidin, &i) == 1){ //%n antal inlästa tecken
			tid += tidin; //printf("tid: %d\n", tid);
			n += i; //printf("i: %d\n",i);
		}
		printf("tid: %d\n", tid);
		if(tid>max){
			max = tid;
			strcpy(usermax,user);
		}
	}
	printf("Användare med längst tid: %s %d min.", usermax, max);
	return 0;
}