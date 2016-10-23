#include <stdio.h>
#include <locale.h>
#include "libtxt.h"
#define N 200
#define TEXTFIL "personer.txt"

/* Programmeringsuppgift 13.1, Sida 336
Skriv en binär sökfunktion som kan söka efter en person 
med namn och efternamn i en sorterad struktur av personer. 

http://listofrandomnames.com för att generera lista med namn
*/

//Struct för personer
struct person{
	char fornamn[40];
	char efternamn[40];
};

void sortera(struct person a[], int start, int slut);
int bin_sok(struct person a[], int start, int slut, char sok[]);

int main(){
	system("cls");
	struct person personlista[N];
	char s[N];
	int n = 0, hittat_index;
	FILE *textfil = fopen(TEXTFIL, "r");
	//Läser in personers namn och efternamn från textfil till struct:
	while(TTS(s, N, textfil)){
		sscanf(s, "%s%s", personlista[n].fornamn, personlista[n].efternamn);
		n++;
	}
	sortera(personlista, 0, n); //sorterar personerna i structen efter efternamn (och förnamn om samma efternamn)
	while(1){ //Körs tills användaren dödar programmet
		printf("Ange person att sleta upp, för- och efternamn:");
		char person_leta[N];
		radInput(person_leta, N);
		 //Funktion returnerar det index där sökt person hittats, annars returneras -1, om person inte hittats
		hittat_index = bin_sok(personlista, 0, n, person_leta);
		if(hittat_index >= 0){
			printf(ADD_LINE"Hittade person %s!"ADD_LINE, person_leta);
			printf("Index: %d\n", hittat_index);
			printf(FORM_RED "%s"FORM_END" "FORM_CYAN"%s"FORM_END"\n", personlista[hittat_index].fornamn, personlista[hittat_index].efternamn);
		}
		else {
			printf("Hittade "FORM_UNDER "inte"FORM_END" person %s\n", person_leta);
		}
	}
	return 0;
}

/*Författarens if-satser för kontroll för- & efternamn:
if (strcoll(e1, e2) < 0 || (strcoll(e1, e2) == 0 && strcoll(f1, f2) < 0))
else if (strcoll(e1, e2) > 0 || (strcoll(e1, e2) == 0 && strcoll(f1, f2) > 0)) 
Han använde en egen funktion enbart för jämförelse av namn	
*/
int bin_sok(struct person a[], int start, int slut, char sok[]){
	 int i1 = start, i2 = slut, m = 0; //spann för index att söka i.
	 char sok_efternamn[N], sok_fornamn[N];
	 sscanf(sok, "%s%s", sok_fornamn, sok_efternamn);
	 //printf("Funktion har fått förnamn: %s och efternamn: %s",sok_fornamn, sok_efternamn);
	 while(i1 <= i2){
		m = (i1 + i2) / 2; //Mittenindex
		/* Triggar om sökt efternamn kommer före efternamn i index m, 
		eller om efternamn är lika med index m och sökt förnamn kommer före efternamn i index m */
		if(		(strcoll(sok_efternamn, a[m].efternamn) < 0) ||
				(strcoll(sok_efternamn, a[m].efternamn) == 0) &&
				(strcoll(sok_fornamn, a[m].fornamn) < 0) ){
			i2 = m-1; //Indexspann att söka i kortas ned (först halvan behålls)
		}
		/* Triggar om sökt efternamn kommer efter efternamn i index m, 
		eller om efternamn är lika med index m och sökt förnamn kommer efter efternamn i index m */
		else if(		(strcoll(sok_efternamn, a[m].efternamn) > 0) ||
						(strcoll(sok_efternamn, a[m].efternamn) == 0) &&
						(strcoll(sok_fornamn, a[m].fornamn) > 0) ){
			i1 = m+1; //Indexspann att söka i kortas ned (andra halvan behålls)
		}
		else {
			break; //lika
		}
	 }
	 //triggar om sökt förnamn och efternamn är lika med array index m
	 if((strcmp(sok_efternamn, a[m].efternamn) == 0) && (strcmp(sok_fornamn, a[m].fornamn) == 0)){
		//printf("Funk returnerar m!\n");
		return m;
	 }
	 //Den sökta personen hittades inte
	 return -1; //namnet hittades inte
}

//Funktion för personsortering från sida 325
void sortera(struct person a[], int start, int slut){
	setlocale(LC_ALL, ""); //lokal standard (ev svensk)
	for(int k=start; k<slut;k++){
		//Sök det minsta bland elementen nr k till slut
		int m = k; //index för hittills minsta värde.
		for (int i=k; i<=slut; i++){
			if(	(strcoll(a[i].efternamn, a[m].efternamn)) < 0 ||
				(strcoll(a[i].efternamn,  a[m].efternamn) == 0 && strcoll(a[i].fornamn, a[m].fornamn) < 0)){
				m = i; //nytt minsta värde funnet, index sätts till m
			}
		}
		struct person temp = a[k];
		a[k] = a[m];
		a[m] = temp;
	}
	setlocale(LC_ALL, "C"); //Återgå till Cs standard.
}

