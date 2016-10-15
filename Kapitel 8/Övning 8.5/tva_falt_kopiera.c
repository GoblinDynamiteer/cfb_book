#include <stdio.h>

/*
Övning 8.5, Sid 160

Skapa två int fält a & b:

a[100] = 0,1,2,3 ... osv
b[20] = alla element 0

Kopiera fält med index 50-54 från a till 10-14 i b
Kopiera fält med index 95-99 från a till 5-9 i b

Använd for-satser för att initiera och kopiera element!

Använd till sist en forsats för att skriva ut hela fältet b

*/


int main(){
	int a[100], b[20];
	/*
	sizeof x/sizeof x[0] ger antalet element i fält x
	forsatserna körs så länge i är mindre än fältens
	antal element. Notera att fältens elementindex 
	börjar på noll så fältet a är a[0] - a[99]
	Därför sätter jag körvillkoren till i<x istället
	för i<=x.
	*/
	for (int i=0;i<sizeof a/sizeof a[0];i++){
		a[i] = i;
	}
	for (int i=0;i<sizeof b/sizeof b[0];i++){
		b[i] = 0;
	}
	/*
	Dessa for-satser går fixa på många olika
	sätt. Jag tycker denna lösning är ganska
	enkel att förstå. När i börjar på 0 blir första
	varvet 
	b[i+10] = a[i+50] == b[0+10] = a[0+50] 
	osv.
	*/
	for (int i=0;i+50<=54;i++){
		b[i+10] = a[i+50];
	}
	for (int i=0;i+95<=99;i++){
		b[i+5] = a[i+95];
	}
	printf("Element i fältet b:\n");
	//Likadan for-sats som användes för att sätta elementen i b
	for (int i=0;i<sizeof b/sizeof b[0];i++){
		printf("b[%d]: %d \n", i, b[i]);
	}
}