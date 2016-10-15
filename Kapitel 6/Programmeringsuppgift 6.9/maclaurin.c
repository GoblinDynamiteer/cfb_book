#include <stdio.h>
#include <math.h> //f�r pow(x,y), och test av pow(M_E,y) M_E �r konstanten e

/*
Programmeringsuppgift 6.9, Sida 122

Skriv en funktion som anv�nder "Maclaurin-formeln" f�r att
ber�kna v�rdet av e^x. Ta inte med s�dana termer i summan 
som �r mindre �n 10^-7

(Term + Term = Summa)

https://www.wikiwand.com/sv/Taylorserie <-- maclaurin finns d�r  ocks�
https://www.wikiwand.com/sv/E_(tal)
*/

//funktionen kopierad fr�n �vning 6.1, ber�knar fakulteten f�r inmatat tal
double nfak(double n){
	double sum =1;
	for (int i=1; i<=n;i++)
		sum *= i;
	return sum;
}


/*funktion f�r att ber�kna e^x, med Maclaurin-serie:
pow(x,i) kan anv�ndas f�r den f�rsta termen efter 1, d� x^1 = x
Han har bara inte skrivit s� i formeln i boken
*/
double maclaurin(int x){
	double summa;
	int i=1;
	while (pow(x,i)/nfak(i) > pow(10,-7)){ //k�rs medan pow(x,i)/nfak(i) �r st�rre �n 10^-7
		//printf("10^-7: %.10lf Term: %.10lf \n", pow(10,-7), pow(x,i)/nfak(i)); //skriver ut termen, f�r test. -- avkommentera f�r att anv�nda
		summa += pow(x,i)/nfak(i); //adderar term till summan
		i++;
	}
	return 1 + summa; //returnerar summan + 1 (jag l�gger till 1 sist, spelar ingen roll)
}

int main(){
	int x;
	printf("Ange x f�r e^x: ");
	scanf("%d",&x);
	printf("e^%d = %lf", x, maclaurin(x));
	//skriver ut e^x med pow(M_E,x) fr�n math.h. Detta ska bli samma v�rde som ovan:
	printf("\nF�r j�mf�relse: %lf", pow(M_E, x)); 
	return 0;
}