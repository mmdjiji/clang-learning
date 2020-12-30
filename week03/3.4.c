#include <stdio.h>
int main(){
	double weight,height,BMI;
	scanf("%lf %lf",&weight,&height);
	BMI = weight / (height * height);
	printf("%.1lf\n%s",BMI,(BMI>25)?"PANG":"Hai Xing");
	return 0;
} 
