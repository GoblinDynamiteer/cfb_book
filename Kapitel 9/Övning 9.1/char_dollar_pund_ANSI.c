#include <stdio.h>

/*
�vning 9.1, Sida 188

**ANSI**

Skriv ett program som inneh�ller deklarationer av tv� char-variabler.
De ska heta c1 och c2. Tilldela sedan ett dollartecken till c1 och ett
pundtecken till c2. G�r programmet att kompilera?! Om inte, f�rklara varf�r.

Om du har m�jlighet s� prova med en texteditor som kan lagra programtexten
antingen som LATIN_1 (ANSI) eller UTF-8.

---
Programmet g�r att kompilera i ANSI, men inte i UTF-8.
UTF-8 har mer �n ett tecken f�r $/� (sant?)
och char kan bara lagra ett enstaka tecken.

*/

int main(){
	char c1, c2;
	c1 = '$';
	c1 = '�';
	/*printf("c1:");
	putchar(c1);
	printf("\nc2:");
	putchar(c2);*/
	return 0;
}