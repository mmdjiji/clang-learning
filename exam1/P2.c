#include <stdio.h>
const double PI = 3.14159;
int main(){
	int h, r;
	scanf("%d %d", &h, &r);
	printf("%d", (int) (20000.0 / (PI * r * r * h) + 1));
	return 0;
}
