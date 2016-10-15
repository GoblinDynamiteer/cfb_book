#include <stdio.h>
#include <stdlib.h> //f�r "pause"

/*
Programmeringsuppgift 5.3, Sida 99

Anv�nd programmet p� sida 98.

Skriv ett nytt program som l�ser in ett positivt heltal n, 
och skriver ut alla primtal som �r mindre eller lika med n
utforma utskriften s� att h�gst 10 primtal visas per rad

Tips: Prova alla tal i intervallet 1-n och e om de �r primtal.

Ett primtal �r ett naturligt tal, som �r st�rre �n 1 och 
som inte har n�gra andra positiva delare �n 1 och talet sj�lvt.

*/

int main(){
	int antal, counter = 0; //variabler antal tal att testa och f�r r�knare (lista 10 primtal �t g�ngen)
	printf("Ange antal: ");
	scanf("%d", &antal);
	for (int primtal_test=1; primtal_test<=antal;primtal_test++){ //lika m�nga g�nger som antalet inmatat v�rde till "antal"
		_Bool ar_primtal = 1; //booleansk "�r Primtal"-variabel som enbart kan vara 1 eller 0
		for (int k=2; k<primtal_test; k++){
			//om talet som testas �r delbart med n�got annat �n sig sj�lv, s� s�tts "�r Primtal"-variabeln till 0 (falsk)
			if (primtal_test % k == 0) 
				ar_primtal = 0;
		}
		//om ar_primtal == 1 (sann) s� �r talet ett primtal och skrivs ut
		if (ar_primtal){
			printf("Primtal: %d\n", primtal_test);
			counter++; //om ett primtal hittas �kar counter med 1 (endast tio ska listas �t g�ngen)
		}
		/*n�r tio primtal har hittats k�rs systemkommandot pause, det g�r s� att programmet v�ntar tills anv�ndaren
		trycker p� en tangent*/
		if (counter == 10){
			counter = 0;
			printf("10 primtal listade!\n");
			system("pause");
		}
	}
return 0;
}
