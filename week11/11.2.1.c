#include <stdio.h>
void swap(int *p, int *q) {*p^=*q;*q^=*p;*p^=*q;}
int main(){
	int i,j,N,M,arr[100];
	scanf("%d %d",&N,&M);
	for(i=0;i<N;i++)
		scanf("%d",&arr[i]);
	for(i=0;i<M;i++)
		for(j=N-1;j>0;j--)
			swap(&arr[j],&arr[j-1]);
	for(i=0;i<N;i++)
		printf("%3d",arr[i]);
	return 0;
}
