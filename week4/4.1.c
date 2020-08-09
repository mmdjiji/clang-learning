#include <stdio.h>
int main(){
	int x;
	scanf("%d", &x);
	if(x<1)	printf("y=%d", x);
	else if(x<10) printf("y=%d", 2*x-1);
	else printf("y=%d", 3*x-11);
	return 0;
}
