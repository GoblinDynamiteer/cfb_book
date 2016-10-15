#include <stdio.h>

/*
Övning 9.1, Sida 188

**UTF-8**

Skriv ett program som innehåller deklarationer av två char-variabler.
De ska heta c1 och c2. Tilldela sedan ett dollartecken till c1 och ett
pundtecken till c2. Går programmet att kompilera?! Om inte, förklara varför.

Om du har möjlighet så prova med en texteditor som kan lagra programtexten
antingen som LATIN_1 (ANSI) eller UTF-8.

---
Programmet går att kompilera i ANSI, men inte i UTF-8.
UTF-8 har mer än ett tecken för $/£ (sant?)
och char kan bara lagra ett enstaka tecken.

*/
*/

int main(){
	char c1, c2;
	c1 = '$';
	c1 = '£';
	/*printf("c1:");
	putchar(c1);
	printf("\nc2:");
	putchar(c2);*/
	return 0;
}