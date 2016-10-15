#include <stdio.h>
#define N 10

void split(char *s, char *tab[], int max) {
  int i;
  for (i=0; i<max; i++)
    tab[i] = 0;		//s�tter tomma pekare.
  for (i=0; i<max; i++) {
    while (*s && *s == ' ')  //letar mellanslag i b�rjan?
      s++;
    if (!*s)					//om nolltecken hittas?
      return; 				//avslutar void-funk
	  printf("funktion: s: %s\n", s);
    tab[i] = s;
	printf("funktion: tab[%d]: %s\n", i, tab[i]);
    while (*s && *s != ' ') 
      s++;
    if (!*s)
      return;
    *s++ = '\0';
	printf("funktion: tab[%d]: %s\n", i, tab[i]);
  }  
}




int main() {
  int i;
  char txt[] = "      !Nu !l�r  vi  oss C! ";
  char *tokens[N];
  split(txt, tokens, N);
  for (i=0; i< N && tokens[i]; i++) 
    printf("%s\n", tokens[i]);
}