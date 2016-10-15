static int a = 7;

int g(void){
	extern int b;
	return a+b;
}