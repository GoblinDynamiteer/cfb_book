/*
Programmeringsuppgift 5.1, Sida 99
Skriv i pseudokod: 
Läs in ett antal tal, undersök om de har skrivits in i storleksordning eller inte

PSEUDOKOD:
ange en array kallad tal
ange n och sätt till 1
ange stege_upp och stege_ner
upprepa följande ett  godtyckligt antal gånger
	läs in ett tal till tal arrayplats n, bryt om användaren vill
	öka n med 1
upprepa följande n gånger
	jämför värden i arrayen med varandra i ordning, är de i stigande ordning, och steg_upp inte är 0, sätt stege_upp till 1
	annars sätt stege_upp till 0
	jämför värden i arrayen med varandra i ordning, är de i fallande ordning, och steg_ner inte är 0 sätt stege_ner till 1
	annars sätt stege_ner till 0
om stege_ner eller stege_upp är 1, skriv ut att talen är i ordning
annars skriv ut att talen ej är i ordning

KOD + PSEUDOKOD:
*/

#include <stdio.h>

int main(){
	/*
	ange en array kallad tal
	ange n och sätt till 1
	ange stege_upp och stege_ner
	*/
	int tal[100], stege_upp, stege_ner, n=1;
	/*
	upprepa följande ett  godtyckligt antal gånger
	läs in ett tal till tal arrayplats n, bryt om användaren vill
	öka n med 1
	*/
	while(1){
		printf("Ange tal: ");
		if (scanf("%d", &tal[n]) != 1)
			break;
		n++;
	}
	/*
	upprepa följande n gånger
	jämför värden i arrayen med varandra i ordning, är de i stigande ordning, och steg_upp inte är 0, sätt stege_upp till 1
	annars sätt stege_upp till 0
	jämför värden i arrayen med varandra i ordning, är de i fallande ordning, och steg_ner inte är 0 sätt stege_ner till 1
	annars sätt stege_ner till 0
	*/
	for (int i=1;i!=n-1;i++){
		if (tal[i] < tal[i+1] && stege_upp != 0)
			stege_upp = 1;
		else
			stege_upp = 0;
		if (tal[i] > tal[i+1] && stege_ner != 0)
			stege_ner = 1;
		else 
			stege_ner = 0;
	}
	/*
	om stege_ner eller stege_upp är 1, skriv ut att talen är i ordning
	annars skriv ut att talen ej är i ordning
	*/
	if (stege_ner == 1 || stege_upp == 1)
		printf("\nTalen är i storleksordning");
	else
		printf("\nTalen är ej i storleksordning");
	return 0;
}