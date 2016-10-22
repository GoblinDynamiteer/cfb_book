#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100000
#define TSU "\x1b[4m" 		//Understruken
#define F "\x1b[0m" 			//�terst�ller f�rg
#define FCY "\x1b[96m" 	//Ljusbl� (cyan)
#define FRO "\x1b[91m"

/* �vning 13.6, Sida 329

13.5:
Antag att du ska s�ka igenom ett f�lt med 100000 element
Hur m�nga tal m�ste du maximalt unders�ka om du anv�nder

a, rak s�kning 	- 	Svar: 100000
b, bin�r s�kning 	-	Svar: 2^x = 100000
								x~16,6 = 16 (17?) ggr

13.6:
Vilka �ndringar m�ste du g�ra i s�kalgoritmen om f�ltet �r i 
fallande ordning? (St�rta talet f�rst).

svar: 
a, rak s�kning 	- 	Svar: Ingen �ndring
b, bin�r s�kning 	-	Svar: Invertera st�rre/lika med i if-satserna

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

//Funktion byggd fr�n pseudokod p� sida 328
void sok_binar(int a[], int n, int hitta){
	int i1 = 0, i2 = n, m, raknare = 0;
	while(i1 <= i2){
		raknare++;
		//s�tt m till det index som ligger i intervallet i1 - i2    
		//ex om i1 =50 i2 = 100
		//mitten: 100-50 = 50  --> 50+(50/2) = 75
		m = i1 + ((i2 - i1) / 2);
		//om det s�kta elementet �r st�rre �n elementet p� plats m
		if(hitta > a[m]){
			//s� s�tt i2 till m-1
			i2 = m-1;
		}
		//om det s�kta elementet �r mindre �n elementet p� plats m
		else if(hitta < a[m]){
			//s� s�tt i1 till m+1
			i1 = m+1;
		}
		//annars �r det s�kta elementet lika med elementet p� plats m
		else{
			break;
		}
	}
	printf("\nFunktion "TSU"sok_binar"F": \nHittade tal: "FCY"%d "F"efter %d varv!\n", hitta, raknare);
	printf("Plats: a[%d] = %d\n", m, a[m]);
	return;
}