#include <stdio.h>
#include <math.h>
int main(){
	int i,N,len,sum=0;
	scanf("%d",&N);
	len = log10(N)+1;
	for(i=0;i<len;i++)
		sum+=N/(int)pow(10,i)%10;
	printf("%d %d",len,sum);
	return 0;
}
