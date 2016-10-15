#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void vand(char *a){
	//char c[25] = "Test";
	char *b = calloc(25, sizeof(char));
	//char *b = c;
	while(*a++){
		printf("+");
		;
	}
	*a--;
	while (*b++ = *a--){
		printf("-");
		;
	} 
	printf("%s",*b);
}

int main(){
	char text[25] = "Kalle Anka";
	vand(text);
	//printf("%s", text);
}


/*författarens
#include <string.h>
void vand(char *s) {
  char c, *t = s+strlen(s)-1;
  for (; s<t; s++, t--) {

    c = *s; 
    *s = *t; 
    *t = c;
  }
}
*/