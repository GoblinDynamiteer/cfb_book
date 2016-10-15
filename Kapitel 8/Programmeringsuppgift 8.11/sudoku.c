#include <stdio.h>
/*
Programmeringsuppgift 8.11, Sida 181

Skriv en funktion som best�mmer om en sudoku-spelplan
�r ifylld p� korrekt s�tt.

Fnktionen ska f� ett tv�dimensionellt f�lt (array) med element
av typen int. Funktionen ska vara av booleansk typ.

En spelplan best�r av 9x9 rutor, i vilka sifforna 1-9 ska placeras
varje rad och kolumn f�r enbart ha en av varje siffra.
Dessutom ska varje "3x3"-segment i spelplanen enbart ha en av
varje siffra.


Exempel fr�n boken, p� ett sudoku-spel:

5 3 - - 7 - - - -
6 - - 1 9 5 - - -
- 9 8 - - - - 6 -
8 - - - 6 - - - 3
4 - - 8 - 3 - - 1
7 - - - 2 - - - 6
- 6 - - - - 2 8 -
- - - 4 1 9 - - 5
- - - - 8 - - 7 9

http://www.sudoku-solutions.com/
L�sning:
5 3 4 6 7 8 9 1 2
6 7 2 1 9 5 3 4 8
1 9 8 3 4 2 5 6 7
8 5 9 7 6 1 4 2 3
4 2 6 8 5 3 7 9 1
7 1 3 9 2 4 8 5 6
9 6 1 5 3 7 2 8 4
2 8 7 4 1 9 6 3 5
3 4 5 2 8 6 1 7 9
*/

/*
Funktion som kollar om en sudoku-spelplan �r korrekt ifylld
F�r check av 3x3-segmenten anv�nder jag tv� int-variabler som adderar
till arrayens element-index.
*/
_Bool sudokuCheck(int a[9][9]){
	//Summa att j�mf�ra mot: varje/kolumn och 3x3-segment ska bli 45
	int summa = 1+2+3+4+5+6+7+8+9, checkR, checkK, check3x3, segment = 1;
	//Kolla rader/kolumner
	for(int i=0;i<9;i++){
		checkR = 0;
		checkK = 0;
		for(int j=0;j<9;j++){
			checkR += a[i][j];
			checkK += a[j][i];
		}
		if(checkR != summa || checkK != summa){
			return 0;
		}
	}
	/*variabler som adderas till i och j, f�r att testa de olika 3x3-segmenten i sudoku-spelet
	de s�tts initalt till 0 f�r att checken ska starta i det �versta v�nstra h�rnet
	*/
	int ruta_r = 0;
	int ruta_k = 0;
	while(ruta_k <= 6){
		//Variabel som s�tts till summan av v�rdena i ett 3x3-segment
		check3x3 = 0;
		//N�stlade for-satser som k�r 3x3 g�nger, adderar summan av v�rdena i ett 3x3-segment
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				check3x3 += a[i+ruta_r][j+ruta_k];
			}
		}
		if(check3x3 != summa){
			return 0;
		}
		/*
		F�r varje kollad 3x3-segment �kar ruta_r med 3, f�r att resta n�sta 3x3-segment i raden
		Om ruta_r �r st�rra �n 6, och d�rmed skulle bli utanf�r spelplanen vid n�sta �kning med 3,
		s� s�tts den �ter till 0, och ruta_k �kar med 3, f�r att testa n�sta kolumn i spelplanen.
		While satsen k�r s� l�nge ruta_k inte �r st�rre �n 6.
		*/
		ruta_r += 3;
		if(ruta_r > 6){
			ruta_k += 3;
			ruta_r = 0;
		}
	}
	return 1;
}

int main(){
	int sudoku[9][9];
	printf("Sl� in en sudoku-spelplan! 9x9:\n");
	/*
	Det g�r att klistra in alla talen i "l�sningen" ovan, och trycka p� return. D� s�tts hela arrayen p� en g�ng.
	Byt ut siffror i l�sningen f�r att testa att funktionen returnerar 0 vid felaktigt ifyllt sudoku-spel.
	*/
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			scanf("%d", &sudoku[i][j]);
		}
	}
	if(sudokuCheck(sudoku)){
		printf("Sudoku-planen �r korrekt ifylld!");
	}
	else{
		printf("Sudoku-planen �r inte korrekt ifylld!");
	}
}