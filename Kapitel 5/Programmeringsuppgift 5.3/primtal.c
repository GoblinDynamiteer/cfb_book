#include <stdio.h>
#include <stdlib.h> //för "pause"

/*
Programmeringsuppgift 5.3, Sida 99

Använd programmet på sida 98.

Skriv ett nytt program som läser in ett positivt heltal n, 
och skriver ut alla primtal som är mindre eller lika med n
utforma utskriften så att högst 10 primtal visas per rad

Tips: Prova alla tal i intervallet 1-n och e om de är primtal.

Ett primtal är ett naturligt tal, som är större än 1 och 
som inte har några andra positiva delare än 1 och talet självt.

*/

int main(){
	int antal, counter = 0; //variabler antal tal att testa och för räknare (lista 10 primtal åt gången)
	printf("Ange antal: ");
	scanf("%d", &antal);
	for (int primtal_test=1; primtal_test<=antal;primtal_test++){ //lika många gånger som antalet inmatat värde till "antal"
		_Bool ar_primtal = 1; //booleansk "Är Primtal"-variabel som enbart kan vara 1 eller 0
		for (int k=2; k<primtal_test; k++){
			//om talet som testas är delbart med något annat än sig själv, så sätts "Är Primtal"-variabeln till 0 (falsk)
			if (primtal_test % k == 0) 
				ar_primtal = 0;
		}
		//om ar_primtal == 1 (sann) så är talet ett primtal och skrivs ut
		if (ar_primtal){
			printf("Primtal: %d\n", primtal_test);
			counter++; //om ett primtal hittas ökar counter med 1 (endast tio ska listas åt gången)
		}
		/*när tio primtal har hittats körs systemkommandot pause, det gör så att programmet väntar tills användaren
		trycker på en tangent*/
		if (counter == 10){
			counter = 0;
			printf("10 primtal listade!\n");
			system("pause");
		}
	}
return 0;
}
