#include <stdio.h>
int ifwan(int N){
	int i,sum=0;
	for(i=1;i<N;i++)
		if(N%i == 0)
			sum+=i;
	if(N == sum) return 1; else return 0;
}
int main(){
	int N,i;
	scanf("%d",&N);
	for(i=1;i<=N;i++)
		if(ifwan(i)) printf("%d\n",i);
	return 0;
}
