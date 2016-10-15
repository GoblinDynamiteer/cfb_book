#include <stdio.h>

/*
Programmeringsuppgift 8.8, Sida 180

Skapa en funktion som ber�knar de f�rsta 50 primtalen och
s�tter dem i en array!

Anv�nd s�ttet att ett primtal inte �r delbart med n�got annat
tal �n sig sj�lv eller 1;

*/

//Funktion fr�n �vning 6.3 som returnerar 1 om inmatat tal �r ett primtal
_Bool primtal(int t){
	for (int k=2;k<t;k++){
		if (t % k == 0)
			return 0;
	}
	return 1;
}

//funktion som s�tter de f�rsta 50 heltalen til en array som matas in
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

