#include <stdio.h>

/*
Programmeringsuppgift 6.6, Sida 121

https://www.wikiwand.com/sv/Binomialkoefficient

Wolfram Alpha för 9 / 7 (ger 36) -- bra för test
https://www.wolframalpha.com/input/?i=binomial+coefficient+(9+7)


De så kallade bionominalkoefficienterna kan beräknas 
för icke-negativa heltal n & k enligt följande:

(n|k) = n!/(k!+(n-k)!)

Utropstecknen efter talen innebär fakulteten av dessa tal.
fakulteten innebär produkten av 1*2*3*4*5*....n

Använd funktionen nfak från övning 6.1 för att skriva
en funktion som beräknar bionominalkoefficienten för
två tal (n och k) talen är parametrar till funktionen.

*/

//funktionen kopierad från övning 6.1, beräknar fakulteten för inmatat tal
double nfak(double n){
	double sum =1;
	for (int i=1; i<=n;i++)
		sum *= i;
	return sum;
}

//funktion för bionominalkoefficienten
double bnok (int n, int k){ 
	return nfak(n)/(nfak(k)*(nfak(n-k))); //byter ut "!" i "n!/(k!+(n-k)!)" till nfak()
};


int main(){
	int k, n;
	printf("Ange n: ");
	scanf("%d", &n);
	printf("Ange k: ");
	scanf("%d", &k);
	printf("Bionominalkoefficienten för %d och %d är %.3lf !",n ,k ,bnok(n,k));
	return 0;
}


