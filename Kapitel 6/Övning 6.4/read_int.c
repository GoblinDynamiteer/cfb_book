/*
Övning 6.4, Sida 113

Skriv om programmet på sida 108, så att inmatning av heltal sker i en egen funktion kallad read_int
använd också  funktionen read_double på sida 112

*/

#include <stdio.h>

//Funktion som läser in ett heltal till sin lokala variabel a, och returnerar den.
int read_int(void){
	int a;
	scanf("%d", &a);
	return a;
}


//Funktion från sida 112, läser in och returnerar a
double read_double(void){
	double a;
	scanf("%lf", &a);
	return a;
}

//Funktion från sida 108, ger returnerar x^n
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
	double x; //för x^y
	int y;		//för x^y
	printf("Ange x: ");
	x = read_double(); 	//anropar funktionen read_double och sätter dess returvärde till variabeln x
	printf("Ange y: ");	
	y = read_int();		//anropar funktionen read_int och sätter dess returvärde till variabeln y
	printf("Resultat: %lf^%d = %f", x , y, upphojt_till(x,y));
	return 0;
}