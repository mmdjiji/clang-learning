#include <stdio.h>
void swap(int *p, int *q) {*p^=*q;*q^=*p;*p^=*q;}
int main(){
	int i,j,arr[7][7];
	for(i=0;i<6;i++)
		for(j=0;j<7;j++)
			scanf("%d",&arr[i][j]);
	
	for(i=0;i<6;i++)
		for(j=i+1;j<7;j++)
			swap(&arr[i][j],&arr[j][i]);
	
	for(i=0;i<7;i++){
		for(j=0;j<6;j++)
			printf("%3d",arr[i][j]);
		printf("\n");
	}
	return 0;
}
