#include <stdio.h>
#include <math.h> //för pow(x,y), och test av pow(M_E,y) M_E är konstanten e

/*
Programmeringsuppgift 6.9, Sida 122

Skriv en funktion som använder "Maclaurin-formeln" för att
beräkna värdet av e^x. Ta inte med sådana termer i summan 
som är mindre än 10^-7

(Term + Term = Summa)

https://www.wikiwand.com/sv/Taylorserie <-- maclaurin finns där  också
https://www.wikiwand.com/sv/E_(tal)
*/

//funktionen kopierad från övning 6.1, beräknar fakulteten för inmatat tal
double nfak(double n){
	double sum =1;
	for (int i=1; i<=n;i++)
		sum *= i;
	return sum;
}


/*funktion för att beräkna e^x, med Maclaurin-serie:
pow(x,i) kan användas för den första termen efter 1, då x^1 = x
Han har bara inte skrivit så i formeln i boken
*/
double maclaurin(int x){
	double summa;
	int i=1;
	while (pow(x,i)/nfak(i) > pow(10,-7)){ //körs medan pow(x,i)/nfak(i) är större än 10^-7
		//printf("10^-7: %.10lf Term: %.10lf \n", pow(10,-7), pow(x,i)/nfak(i)); //skriver ut termen, för test. -- avkommentera för att använda
		summa += pow(x,i)/nfak(i); //adderar term till summan
		i++;
	}
	return 1 + summa; //returnerar summan + 1 (jag lägger till 1 sist, spelar ingen roll)
}

int main(){
	int x;
	printf("Ange x för e^x: ");
	scanf("%d",&x);
	printf("e^%d = %lf", x, maclaurin(x));
	//skriver ut e^x med pow(M_E,x) från math.h. Detta ska bli samma värde som ovan:
	printf("\nFör jämförelse: %lf", pow(M_E, x)); 
	return 0;
}