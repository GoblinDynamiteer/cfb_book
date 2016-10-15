#include <stdio.h>
#include <string.h>

/* Programmeringsuppgift 9.6, Sida 215

Skriv en funktion som får två texter, 's1' & 's2', samt ett heltal 'n'
Funktionen ska kopiera texten från s2 till s1, men texten som läggs
i s1 ska alltid ha längden n. OM texten i s2 är längre än n så skall
resultatet innehålla de sista n tecknen i s2. annars ska resultatet
innehålla texten i s2 'högerjusterad'.
Man skall alltså fylla ut med ett lämpligt antal blanka tecken till vänster */

void texter(char *s1, char *s2, int n){
	int i, j=0;
	//om s2 är kortare än n sätts i till 0, annars till längd av s2 - n
	i = (strlen(s2)<n) ? 0 : strlen(s2)-n ;
	//om n är längre än s2, sätts mellanslag till s1, tills j är större än längd av s2 - n
	if(n>strlen(s2)){
		while(j<n-strlen(s2)){
		s1[j++] = ' '; //OBS enkla citationstecken för skrivning av enskilt tecken
		}	
	}
	/*
	text skrivs från s2 till s1, medans ett nolltecken inte hittas i s2
	j börjar på en högre siffra än i, om mellanslag har satts i s1, enl ovan
	*/
	while(s2[i]!='\0'){
		s1[j++] = s2[i++];
	}
	s1[j] = '\0';
}

int main(){
	char s1[100]; 
	//char s2[100] = "lång textremsa att kopiera från s2 till s1, endast slutet ska synas om längre än n";
	char s2[100] = "kort text <n - högerjustera!";
	int n = 10;
	//printf("n: %d, s1: %s, s2: %s",n,s1,s2);
	texter(s1,s2,n);
	printf("\nEfter funktion:\nn: %d\ns1: %s\ns2: %s",n,s1,s2);
	printf("\nstrlen(s1): %d",strlen(s1));
}