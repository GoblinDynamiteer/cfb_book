/*
�vning 6.8, Sida 119

Skriv om progammet i �vning 6.2, s� att funktionerna ligger efter main
*/

#include <stdio.h>

//Deklarationer f�r funktioner som ligger efter main
double upphojt_till(double, int);
int read_int(void);
double read_double(void);

int main(){
	double x; //f�r x^y
	int y;		//f�r x^y
	printf("Ange x: ");
	x = read_double(); 	//anropar funktionen read_double och s�tter dess returv�rde till variabeln x
	printf("Ange y: ");	
	y = read_int();		//anropar funktionen read_int och s�tter dess returv�rde till variabeln y
	printf("Resultat: %lf^%d = %f", x , y, upphojt_till(x,y));
	return 0;
}

//Funktion som l�ser in ett heltal till sin lokala variabel a, och returnerar den.
int read_int(void){
	int a;
	scanf("%d", &a);
	return a;
}


//Funktion fr�n sida 112, l�ser in och returnerar a
double read_double(void){
	double a;
	scanf("%lf", &a);
	return a;
}

//Funktion fr�n sida 108, ger returnerar x^n
double upphojt_till(double x, int n){
	double res = 1;
	int i = 1;
	if (n>=0)
		for (;i<=n;i++)
			res *= x;
	else
		for(;i<=-n;i++)
			res /= x;
		return res;
}