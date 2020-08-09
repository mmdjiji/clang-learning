#include <stdio.h>
int main(){
	double sum=0,tmp,N=0;
	while(1){
		scanf("%lf",&tmp);
		if(tmp == -1)break;
		else {
			sum+=tmp;
			N++;
		}
	}
	if(N==0)printf("0.00");else printf("%.2lf",(double)sum/(double)N);
	return 0;
}
