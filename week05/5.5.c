#include <stdio.h>
int main(){
	int N,i;
	double sum=0,tmp;
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%lf",&tmp);
		sum+=tmp;
	}
	if(N==0) printf("0.00"); else printf("%.2lf",(double)sum/(double)N);
	return 0;
}
