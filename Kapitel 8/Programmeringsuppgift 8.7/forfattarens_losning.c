#include <math.h>
#include <stdio.h>

double sum(double a[], int antal){
	double summa = 0;
	for(int i=0;i<antal;i++){
		summa += a[i];
	}
	return summa;
}

//funktion som summerar och retunerar värdet av alla element i kvadrat, för en array
double kvad_sum(double a[], int antal){
	double summa = 0;
	for(int i=0;i<antal;i++){
		summa += pow(a[i],2);
	}
	return summa;
}




double sigma(double f[], int n) {
	double term1 = kvad_sum(f, n);
	double sum2 = sum(f, n);
	double term2 = sum2*sum2/n;
	return sqrt((term1-term2)/(n-1));
} 

	int main(){
	double tal[]={1,4,3,15,72,41,30,27,72,8,42,36,33,46,44};
	printf("Standardavvikelsen är: %.1f", sigma(tal, sizeof tal/sizeof tal[0]));
	return 0;
}



