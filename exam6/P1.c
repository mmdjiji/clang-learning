#include <stdio.h>
#include <math.h>
int iftzs(int a){
	int s = a*a, len = log10(a)+1, i;
	for(i=0;i<len;i++){
		if(s%10!=a%10)return 0;
		else s/=10,a/=10;
	}
	return 1;
}
int main(){
	int i,k;
	scanf("%d",&k);
	for(i=2;i<=k;i++)
		if(iftzs(i))
			printf("%d\n",i);
	return 0;
}
