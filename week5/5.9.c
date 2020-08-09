#include <stdio.h>
#include <math.h>
int isprime(int num){
	int i;
	if(num == 1)return 0;
	if(num<0)num=-num;
	for(i=2;i<=sqrt(num);i++){
		if(num%i==0)return 0;
	}
	return 1;
}
int main(){
	int N;
	scanf("%d",&N);
	printf("%d",N);
	if(isprime(N))printf(" is a prime.");else printf(" is not a prime.");
	return 0;
}
