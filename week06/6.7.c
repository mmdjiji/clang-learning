#include <stdio.h>
#include <math.h>
int main(){
	long i,j,N,tmp,start=0,len=0;
	scanf("%d",&N);
	for(i=2;i<=sqrt(N);i++){
		tmp=1;
		for(j=i;tmp*j<=N;j++){
			tmp*=j;
			if(N%tmp == 0 && j-i+1 > len){
				start = i;
				len = j-i+1;
			}
		}
	}
	if(start == 0){
		printf("1\n%d",N);
	}else{
		printf("%d\n",len);
		printf("%d",start);
		for(i=start+1;i<start+len;i++)
			printf("*%d",i);
	}
	return 0;
}
