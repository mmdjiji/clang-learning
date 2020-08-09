#include <stdio.h>
//根据PTA的BUG 不加time.h就会在最后一个测试点上超时 
#include <time.h>
int main(){
	int N,i,sum=0;
	scanf("%d",&N);
	for(i=1;i<N;i++)
		if(N%i == 0)
			sum+=i;
	if(N == sum) printf("Yes"); else printf("No");
	return 0;
}
