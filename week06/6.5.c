#include <stdio.h>
#include <math.h>
int isprime(int num){
	int i;
	if(num <= 1) return 0;
	for(i=2;i<=sqrt(num);i++)
		if(num%i==0) return 0;
	return 1;
}
int main(){
	int i,n,found=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		if(isprime((int)pow(2,i)-1) && (found=1))
			printf("%d\n",(int)pow(2,i)-1);
	if(!found)
		printf("None");
	return 0;
}
