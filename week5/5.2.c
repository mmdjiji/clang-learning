#include <stdio.h>
int main(){
	int a,n,i,j,tmp=0,sum=0;
	scanf("%d %d",&a,&n);
	for(i=0;i<n;i++){
		tmp = tmp*10 + a;
		sum += tmp;
	}
	printf("%d",sum);
	return 0;
}
