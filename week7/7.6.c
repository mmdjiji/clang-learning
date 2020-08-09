/*
Issues:
	1. Cannot judge more than one saddle point.
	2. If a row has more than one maximum value 
	or a column has more than one minimum value, 
	maybe cause bug. The reason is I used unsteady sort.
	But PTA gave this code AC.
*/
#include <stdio.h>
int main(){
	
	int i,j,n,matrix[6][6],possible1[6][6],possible2[6][6],tmp,location;
	scanf("%d",&n);
	for(i=0;i<n;i++)for(j=0;j<n;j++){
		scanf("%d",&matrix[i][j]);
		possible1[i][j] = possible2[i][j] = 0;
	}
	
	//tmp->max
	for(i=0;i<n;i++){
		tmp = matrix[i][0];
		location=0;
		for(j=1;j<n;j++){
			if(matrix[i][j]>=tmp){
				tmp=matrix[i][j];
				location=j;
			}
		}
		possible1[i][location] = 1;
	}
	
	//tmp->min
	for(i=0;i<n;i++){
		tmp = matrix[0][i];
		location=0;
		for(j=1;j<n;j++){
			if(matrix[j][i]<=tmp){
				tmp=matrix[j][i];
				location=j;
			}
		}
		possible2[location][i] = 1;
	}
	
	for(i=0;i<n;i++)for(j=0;j<n;j++)
	if(possible1[i][j] == 1 && possible2[i][j] == 1){
		printf("%d %d",i,j);
		return 0;
	}
	printf("NONE");
	return 0;
}
