#include <stdio.h>
#include <string.h>
#define MAXLEN 700 //300!сп614н╩ 
int main(){
	int n,i,j,up=0,tmp;
	int arr[MAXLEN+1] = {0};
	scanf("%d",&n);
	arr[0] = 1;
	for(i=2;i<=n;i++){
		up = 0;
		for(j=0;j<=MAXLEN;j++){
			tmp=arr[j]*i+up;
			arr[j]=tmp%10;
			up=tmp/10;
		}
	}
	tmp=0;
	for(i=MAXLEN;i>=0;i--){
		if(arr[i]!=0)for(i;i>=0;i--){
			printf("%d",arr[i]);
			if(++tmp>=40){
				tmp=0;
				printf("\n");
			}
		}
	}
	return 0;
}
