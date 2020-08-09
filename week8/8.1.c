#include <stdio.h>
void swap(int *p,int *q) {*p^=*q;*q^=*p;*p^=*q;}
int main(){
	int i,j,N,arr[10];
	scanf("%d",&N);
	for(i=0;i<=N;i++)scanf("%d",&arr[i]);
	for(i=0;i<=N;i++)
		for(j=0;j<N-i;j++)
			if(arr[j+1]<arr[j])
				swap(&arr[j+1],&arr[j]);
	for(i=0;i<=N;i++)printf("%d ",arr[i]);
	return 0;
}
