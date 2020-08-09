#include <stdio.h>
void swap(int *p, int *q) {if(*p!=*q){*p^=*q;*q^=*p;*p^=*q;}}
void func(int (*p)[5]){
	int i,j,tmp=p[0][0],i_tmp=0,j_tmp=0,max;
	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
			if(p[i][j]>tmp){tmp=p[i][j];i_tmp=i;j_tmp=j;}
	max=tmp;
	swap(&p[2][2],&p[i_tmp][j_tmp]);
	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
			if(p[i][j]<tmp){tmp=p[i][j];i_tmp=i;j_tmp=j;}
	swap(&p[0][0],&p[i_tmp][j_tmp]);
	tmp=max;
	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
			if(p[i][j]<tmp && !(i==0 && j==0)){tmp=p[i][j];i_tmp=i;j_tmp=j;}
	swap(&p[0][4],&p[i_tmp][j_tmp]);
	tmp=max;
	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
			if(p[i][j]<tmp && !(i==0 && j==0) && !(i==0 && j==4)){tmp=p[i][j];i_tmp=i;j_tmp=j;}
	swap(&p[4][0],&p[i_tmp][j_tmp]);
	tmp=max;
	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
			if(p[i][j]<tmp && !(i==0 && j==0) && !(i==0 && j==4) && !(i==4 && j==0)){tmp=p[i][j];i_tmp=i;j_tmp=j;}
	swap(&p[4][4],&p[i_tmp][j_tmp]);
}
int main(){
	int i,j,matrix[5][5];
	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
			scanf("%d",&matrix[i][j]);
	func(matrix);
	for(i=0;i<5;i++){
		for(j=0;j<5;j++)
			printf("%3d",matrix[i][j]);
		printf("\n");
	}
	return 0;
} 
