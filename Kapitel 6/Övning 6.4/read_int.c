/*
�vning 6.4, Sida 113

Skriv om programmet p� sida 108, s� att inmatning av heltal sker i en egen funktion kallad read_int
anv�nd ocks�  funktionen read_double p� sida 112

*/

#include <stdio.h>

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