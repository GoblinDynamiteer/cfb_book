#include "funktioner.h" //deklaration av funktioner i denna fil
#include <stdio.h>

//funktion fr�n sida 115 - skriver ut new line n antal g�nger
void new_lines(int n){
	for (int i=1;i<=n;i++)
		printf("\n");
}

//funktion fr�n sida 112 - l�ser in en double och returnerar

double read_double(void){
	double x;
	scanf("%lf", &x);
	return x;
}

//funktion fr�n �vning 6.4 - l�ser in en int och returnerar
int read_int(void){
	int a;
	scanf("%d", &a);
	return a;
}