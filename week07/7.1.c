#include <stdio.h>
void swap(int *p,int *q) {*p^=*q;*q^=*p;*p^=*q;}
int main(){
	int i,arr[8];
	for(i=0;i<8;i++)scanf("%d",&arr[i]);
	for(i=0;i<8;i++)if(arr[i]>arr[i+1]) swap(&arr[i],&arr[i+1]);
	for(i=0;i<8;i++)printf("%3d",arr[i]);
	return 0;
}
