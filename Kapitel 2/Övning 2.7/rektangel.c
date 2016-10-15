#include <stdio.h>

int main ()
{
	float sid1, sid2;
	printf("Ange rektangels ena sida: ");
	scanf("%f", &sid1);
	printf("Ange rektangels andra sida: ");
	scanf("%f", &sid2);
	printf("\nRektangelns area är: %.3f, dess omkrets är %.3f", sid1 * sid2, 2 * (sid1 + sid2));
	return 0;
}