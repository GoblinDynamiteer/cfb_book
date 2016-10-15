#include <stdio.h>

/*
Programmeringsuppgift 6.6, Sida 121

https://www.wikiwand.com/sv/Binomialkoefficient

Wolfram Alpha f�r 9 / 7 (ger 36) -- bra f�r test
https://www.wolframalpha.com/input/?i=binomial+coefficient+(9+7)


De s� kallade bionominalkoefficienterna kan ber�knas 
f�r icke-negativa heltal n & k enligt f�ljande:

(n|k) = n!/(k!+(n-k)!)

Utropstecknen efter talen inneb�r fakulteten av dessa tal.
fakulteten inneb�r produkten av 1*2*3*4*5*....n

Anv�nd funktionen nfak fr�n �vning 6.1 f�r att skriva
en funktion som ber�knar bionominalkoefficienten f�r
tv� tal (n och k) talen �r parametrar till funktionen.

*/

//funktionen kopierad fr�n �vning 6.1, ber�knar fakulteten f�r inmatat tal
double nfak(double n){
	double sum =1;
	for (int i=1; i<=n;i++)
		sum *= i;
	return sum;
}

//funktion f�r bionominalkoefficienten
double bnok (int n, int k){ 
	return nfak(n)/(nfak(k)*(nfak(n-k))); //byter ut "!" i "n!/(k!+(n-k)!)" till nfak()
};


int main(){
	int k, n;
	printf("Ange n: ");
	scanf("%d", &n);
	printf("Ange k: ");
	scanf("%d", &k);
	printf("Bionominalkoefficienten f�r %d och %d �r %.3lf !",n ,k ,bnok(n,k));
	return 0;
}


