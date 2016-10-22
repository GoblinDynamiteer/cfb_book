#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100000
#define TSU "\x1b[4m" 		//Understruken
#define F "\x1b[0m" 			//Återställer färg
#define FCY "\x1b[96m" 	//Ljusblå (cyan)
#define FRO "\x1b[91m"

/* Övning 13.6, Sida 329

13.5:
Antag att du ska söka igenom ett fält med 100000 element
Hur många tal måste du maximalt undersöka om du använder

a, rak sökning 	- 	Svar: 100000
b, binär sökning 	-	Svar: 2^x = 100000
								x~16,6 = 16 (17?) ggr

13.6:
Vilka ändringar måste du göra i sökalgoritmen om fältet är i 
fallande ordning? (Störta talet först).

svar: 
a, rak sökning 	- 	Svar: Ingen ändring
b, binär sökning 	-	Svar: Invertera större/lika med i if-satserna

*/
void sok_binar(int a[], int n, int hitta);
void sok_rak(int a[], int n, int hitta);

int main(){
	system("cls");
	int nummer[N], index;
	for(int i=N, j=0;i>=0;j++){
		nummer[j] = i--; 
	}
	srand(time(NULL));
	for(int a=0;a<30;a++){
		printf(FRO"Test %d:\n"F,a+1);
		int letaefter = rand() % N;
		sok_rak(nummer, N, letaefter);
		sok_binar(nummer, N, letaefter);
		printf("-------------------------------------------------\n\n");
	}
}

void sok_rak(int a[], int n, int hitta){
int index;
	for(int i=0;i<n;i++){
		if(hitta == a[i]){
			index = i;
			break;
		}
	}
	printf("\nFunktion "TSU"sok_rak"F":\nHittade tal: "FCY"%d"F" efter %d varv!\n", hitta, index); //byt 12
	printf("Plats: a[%d] = %d\n", index, a[index]);
	return;
}

//Funktion byggd från pseudokod på sida 328
void sok_binar(int a[], int n, int hitta){
	int i1 = 0, i2 = n, m, raknare = 0;
	while(i1 <= i2){
		raknare++;
		//sätt m till det index som ligger i intervallet i1 - i2    
		//ex om i1 =50 i2 = 100
		//mitten: 100-50 = 50  --> 50+(50/2) = 75
		m = i1 + ((i2 - i1) / 2);
		//om det sökta elementet är större än elementet på plats m
		if(hitta > a[m]){
			//så sätt i2 till m-1
			i2 = m-1;
		}
		//om det sökta elementet är mindre än elementet på plats m
		else if(hitta < a[m]){
			//så sätt i1 till m+1
			i1 = m+1;
		}
		//annars är det sökta elementet lika med elementet på plats m
		else{
			break;
		}
	}
	printf("\nFunktion "TSU"sok_binar"F": \nHittade tal: "FCY"%d "F"efter %d varv!\n", hitta, raknare);
	printf("Plats: a[%d] = %d\n", m, a[m]);
	return;
}