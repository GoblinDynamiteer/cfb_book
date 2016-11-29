/*
Övning 9.5, Sida 201
Repetition

Skriv ett program som omvandlar ett svenskt datum till amerikanskt format

Amerikanskt: 	MM/DD/ÅÅÅÅ
Svenskt:			ÅÅÅÅ-MM-DD

Ex 
2016-09-13 -> 
09/13/2016

*/

#include <stdio.h>

int main(){
	char catch, sweDate[] = "2016-01-29", engDate[10];
	int year, month, day;
	sscanf(sweDate, "%d%c%d%c%d", &year, &catch, &month, &catch, &day);
	sprintf(engDate, "%d/%d/%d", month, day, year);
	puts("Swedish: ");
	puts(sweDate);
	puts("American: ");
	puts(engDate);
	return 0;
}