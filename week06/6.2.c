#include <stdio.h>
int main(){
	int i,j,N;char a,f=1;
	scanf("%d%c",&N,&a);
	for(i=0;f?(i<N):(i>=0);f?(i++):(i--)){
		for(j=0;j<N-i-1;j++) printf(" ");
		for(j=0;j<(i+1)*2-1;j++) printf("%c",a);
		printf("\n");
		if(i==N-1){f=0;i=N-1;}
	}
	return 0;
}
