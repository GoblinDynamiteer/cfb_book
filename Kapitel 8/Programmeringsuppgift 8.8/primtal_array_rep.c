/* Programmeringsuppgift 8.8, Sida 180 - repetition

Skriv ett program som beräkna och lägger de första 50 primtalen i en array. 
Skriv ut fältet. 
Ett primtal är ett tal som enbart är jämnt delbart med sig själv (och talet 1). */

#include <stdio.h>
#define N 50

_Bool checkPrimtal(int tal);

int main(){
	int primtal[N];
	int raknare = 0;
	for(int i=0;raknare<N;i++){
		if(checkPrimtal(i)){
			primtal[raknare++] = i;
			printf("Primtal %2d:\t%3d\n", raknare, primtal[raknare-1]);
		}
	}
	return 0;
}

_Bool checkPrimtal(int tal){
	int n = tal-1;
	//För 0 och 1, som inte anses vara primtal?
	if(tal == 1 || tal == 0){
		return 0; //Ej primtal
	}
	//Jämför om tal är jämt delbart med något tal i spannet 2->(tal-1)
	while(n>1){
		if(!(tal % n--)){ //Om modulus 0 (!0 = 1) - Ingen rest, jämnt delbart
			return 0; //Ej primtal
		}
	}
	return 1; //Primtal
}