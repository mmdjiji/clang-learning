#include <stdio.h>
int main(){
	char a, b;
	scanf("%c%*c%c", &a, &b);
	printf("%c0%c", a, b);
	return 0;
}
