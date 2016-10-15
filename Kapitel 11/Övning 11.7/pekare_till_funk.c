#include <stdio.h>
#include <math.h>
#define LITETTAL 0.0000000000001

/* �vning 11.7, Sida 272

Skriv en version av c++-algoritmen 'equal', som kan anv�ndas
f�r att testa om alla elementen i tv� f�lt �r lika.

Funktionen ska ha datatypen _Bool. Dess tre f�rsta parametrar
ska vara samma som funktionen transform p� sida 272, fast
typen ska vara double. Den tredje parametern kan ha const.

Den fj�rde parametern ska vara en pekare till en funktion som
f�r tv� double parametrar och ger ett sanningsv�rde som resultat.

Anv�nd denna funktion inne i funktionen equal f�r att j�mf�ra motsvarande
element i de tv� f�lten.
*/
_Bool jamforElement(double a, double b){
	//printf("Funktion: a:%.2f b:%.2f\n", a, b);
	//absolutv�rdet av differensen mellan talen j�mf�rs mot ett "litet tal", om det �r st�rre �n det talet anses elementen vara olika
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

/*F�rfattarens:
_Bool equal(const double *first,  const double *last, double *first2, 		     _Bool (*f)(double, double)) */

_Bool equal(const double *start, const double *end, double *array2, _Bool(*op)(double, double)){
	//Element 4 '_Bool(*op)(double, double))' �r en pekare till en _Bool funktion som f�r tv� double som parametrar
	//i forsatsens initieras en pekare till pekaren start, forloopen k�rs s� l�nge pekare inte �r st�rre �n pekaren end
	for(const double *pekare=start;pekare<end;pekare++){
		if(!op(*pekare, *array2)){ //om funktionen som op pekar p� returnerar 0 (!inverterat), returneras 0
			//printf("Funktion: OLIKA!\n");
			return 0;
		}
		array2++; //denna g�r att ha i forloopen, men jag f�redrar att ha den utanf�r
	}
	//printf("Funktion: LIKA!\n");
	//om op inte returnerar 0 f�r n�gon av j�mf�relserna s� returneras 1 (elementen �r lika i arrayerna)
	return 1;
	
}
/* 
F�rfattarens:
  for (const double *p=first; p<last; p++, first2++) 
    if (!f(*p, *first2))
      return 0;
  return 1; */


int main(){
	double array1[5] = {1.4, 2.2, 1.3, 6.5, 1.000001};
	double array2[5] = {1.4, 2.2, 1.3, 6.5, 1.005001};
	int storlek = sizeof array1/sizeof array1[0];
	//if(equal(array1, array1+storlek, array2, testFunktion)){
/* 	om funktionen equal returnerar 1 �r elementen lika, 
	equal anv�nder i sin tur en annan funktion 'jamforElement' f�r att j�mf�ra talen
	equal har som sin fj�rde parameter en pekare till funktioner av samma type
	som jamforElement */
	if(equal(array1, array1+storlek, array2, jamforElement)){
		printf("Elementen �r lika!\n");
	}
	else{
		printf("Elementen �r olika!\n");
	}
	return 0;
}

/*
Funktionen transform p� sida 272:

void transform(const int *first, const int *last, int *result, int (*op)(int)){
	for(const int *p = first; p<last;p++){
		*result++ = op(*p);
	}
}
*/