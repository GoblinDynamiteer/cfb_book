/*
Programmeringsuppgift 8.6, Sida 179
Repetition
Skriv en funktion som roterar alla elementen i en heltalsarray ett steg åt höger

a[2] ska till a[3] osv!

*/


#include <stdio.h>

void shiftArray(int a[], int size);

int main(){
	int array[] = {5, 22, 3, 4, 8, 9, 77, 4, 1, 0, 3};
	int arraySize = sizeof(array) / sizeof(int);
	printf("Array innan funktion: \n");
	for(int i=0; i<arraySize;i++){
		printf("%d\t", array[i]);
	}
	shiftArray(array, arraySize);
	printf("\nArray efter funktion: \n");
	for(int i=0; i<arraySize;i++){
		printf("%d\t", array[i]);
	}
	return 0;
}

//Shifts integer values in an array, one step to the right, a[2] becomes a[3], etc.
void shiftArray(int a[], int size){
	int i = size-1;
	//Sets last value in array to temporary holder variable
	int valueHolder = a[i];
	//Loop runs through array, starting from the end. a[i] gets value from preceding array element.
	while(i>=0){
		a[i] = a[i-1];
		i--;
	}
	//first element in array gets value stored in temporary variable, the last element in the array
	a[0] = valueHolder;
	return;
}