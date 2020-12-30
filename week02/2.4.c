#include <stdio.h>
#include <math.h>
const double PI = 3.141592653589793;
int main(){
	int angle;
	scanf("%d", &angle);
	printf("%.2lf", sin(angle*PI/180));
	return 0;
}
