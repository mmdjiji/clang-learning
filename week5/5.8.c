#include <stdio.h>
#include <math.h>
int main(){
	double eps,sum=0,tmp=1;
	int i=0;
	scanf("%lf",&eps);
	do{
		tmp = ((i%2==0)?(1):(-1))*1/(double)(3*i+1);
		sum += tmp;
		i++;
	}while(fabs(tmp)>eps);
	printf("sum = %.6lf",sum);
	return 0;
}
