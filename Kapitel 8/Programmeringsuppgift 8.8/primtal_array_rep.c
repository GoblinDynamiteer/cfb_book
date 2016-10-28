/* Programmeringsuppgift 8.8, Sida 180 - repetition

Skriv ett program som ber�kna och l�gger de f�rsta 50 primtalen i en array. 
Skriv ut f�ltet. 
Ett primtal �r ett tal som enbart �r j�mnt delbart med sig sj�lv (och talet 1). */

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
	//F�r 0 och 1, som inte anses vara primtal?
	if(tal == 1 || tal == 0){
		return 0; //Ej primtal
	}
	//J�mf�r om tal �r j�mt delbart med n�got tal i spannet 2->(tal-1)
	while(n>1){
		if(!(tal % n--)){ //Om modulus 0 (!0 = 1) - Ingen rest, j�mnt delbart
			return 0; //Ej primtal
		}
	}
	return 1; //Primtal
}