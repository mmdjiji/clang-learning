#include <stdio.h>
int main(){
	int i, tmp;
	double average = 0;
	for(i=0; i<3; i++){
		scanf("%d", &tmp);
		average += tmp;
	}
	average /= 3;
	printf("%.2lf", average);
	return 0;
}
