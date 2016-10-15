#include <stdio.h>
#include <math.h>
#define LITETTAL 0.0000000000001

/* Övning 11.7, Sida 272

Skriv en version av c++-algoritmen 'equal', som kan användas
för att testa om alla elementen i två fält är lika.

Funktionen ska ha datatypen _Bool. Dess tre första parametrar
ska vara samma som funktionen transform på sida 272, fast
typen ska vara double. Den tredje parametern kan ha const.

Den fjärde parametern ska vara en pekare till en funktion som
får två double parametrar och ger ett sanningsvärde som resultat.

Använd denna funktion inne i funktionen equal för att jämföra motsvarande
element i de två fälten.
*/
_Bool jamforElement(double a, double b){
	//printf("Funktion: a:%.2f b:%.2f\n", a, b);
	//absolutvärdet av differensen mellan talen jämförs mot ett "litet tal", om det är större än det talet anses elementen vara olika
	if(fabs(a-b)>LITETTAL){
		//printf("Funk: Ej lika!\n");
		return 0;
	}
	//printf("Funk: Lika!\n");
	return 1;
}

_Bool testFunktion(double a, double b){
	printf("Hej!");
	return 1;
}

/*Författarens:
_Bool equal(const double *first,  const double *last, double *first2, 		     _Bool (*f)(double, double)) */

_Bool equal(const double *start, const double *end, double *array2, _Bool(*op)(double, double)){
	//Element 4 '_Bool(*op)(double, double))' är en pekare till en _Bool funktion som får två double som parametrar
	//i forsatsens initieras en pekare till pekaren start, forloopen körs så länge pekare inte är större än pekaren end
	for(const double *pekare=start;pekare<end;pekare++){
		if(!op(*pekare, *array2)){ //om funktionen som op pekar på returnerar 0 (!inverterat), returneras 0
			//printf("Funktion: OLIKA!\n");
			return 0;
		}
		array2++; //denna går att ha i forloopen, men jag föredrar att ha den utanför
	}
	//printf("Funktion: LIKA!\n");
	//om op inte returnerar 0 för någon av jämförelserna så returneras 1 (elementen är lika i arrayerna)
	return 1;
	
}
/* 
Författarens:
  for (const double *p=first; p<last; p++, first2++) 
    if (!f(*p, *first2))
      return 0;
  return 1; */


int main(){
	double array1[5] = {1.4, 2.2, 1.3, 6.5, 1.000001};
	double array2[5] = {1.4, 2.2, 1.3, 6.5, 1.005001};
	int storlek = sizeof array1/sizeof array1[0];
	//if(equal(array1, array1+storlek, array2, testFunktion)){
/* 	om funktionen equal returnerar 1 är elementen lika, 
	equal använder i sin tur en annan funktion 'jamforElement' för att jämföra talen
	equal har som sin fjärde parameter en pekare till funktioner av samma type
	som jamforElement */
	if(equal(array1, array1+storlek, array2, jamforElement)){
		printf("Elementen är lika!\n");
	}
	else{
		printf("Elementen är olika!\n");
	}
	return 0;
}

/*
Funktionen transform på sida 272:

void transform(const int *first, const int *last, int *result, int (*op)(int)){
	for(const int *p = first; p<last;p++){
		*result++ = op(*p);
	}
}
*/