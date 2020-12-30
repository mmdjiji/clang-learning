#include <stdio.h>
int main(){
	int i,j,n,matrix[10][10];
	scanf("%d",&n);
	matrix[0][0] = 1;
	for(i=1;i<n;i++)
	for(j=0;j<=i;j++){
		if(j==0 || j==i)
			matrix[i][j]=1;
		else
			matrix[i][j] = matrix[i-1][j-1]+matrix[i-1][j];
	}
	for(i=0;i<n;i++){
		for(j=0;j<=i;j++)
			printf("%4d",matrix[i][j]);
		printf("\n");
	}	
	return 0;
}
