#include <stdio.h>
#include <math.h>
int isprime(int num){
	int i;
	if(num <= 1)return 0;
	for(i=2;i<=sqrt(num);i++)
		if(num%i==0) return 0;
	return 1;
}
int main(){
	int i,X,N,count=0;
	scanf("%d%d",&X,&N);
	for(i=X+1;count<N;i++)
	if(isprime(i)){	
		count++;
		printf("%d",i);
		if(count%5==0) printf("\n"); else if(count != N) printf(" ");
	}
	return 0;
}
