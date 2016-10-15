#include "funktioner.h" //deklaration av funktioner i denna fil
#include <stdio.h>

//funktion från sida 115 - skriver ut new line n antal gånger
void new_lines(int n){
	for (int i=1;i<=n;i++)
		printf("\n");
}

//funktion från sida 112 - läser in en double och returnerar

double read_double(void){
	double x;
	scanf("%lf", &x);
	return x;
}

//funktion från övning 6.4 - läser in en int och returnerar
int read_int(void){
	int a;
	scanf("%d", &a);
	return a;
}