#include <stdio.h>

/*
Programmeringsuppgift 8.8, Sida 180

Skapa en funktion som beräknar de första 50 primtalen och
sätter dem i en array!

Använd sättet att ett primtal inte är delbart med något annat
tal än sig själv eller 1;

*/

//Funktion från övning 6.3 som returnerar 1 om inmatat tal är ett primtal
_Bool primtal(int t){
	for (int k=2;k<t;k++){
		if (t % k == 0)
			return 0;
	}
	return 1;
}

//funktion som sätter de första 50 heltalen til en array som matas in
void primtal_a(int a[]){
	int tal = 2;
	for(int i=0;i<50;){
		if(primtal(tal)){
			a[i++] = tal;
		}
	tal++;
	}
}

int main(){
	int primtal_array[50], line=0;
	primtal_a(primtal_array);
	for(int i=0;i<50;i++){
		printf("%d\t", primtal_array[i]);
		line++;
		if(line==5){
			printf("\n");
			line=0;
		}
	}
}

