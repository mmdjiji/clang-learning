#include<stdio.h>
void aver_stu(int a[10][5]);
void aver_sco(int a[10][5]);
void max(int a[10][5]);
int main()
{ int a[10][5];
  int i,j;
  for(i=0; i<10; i++)
      for(j=0; j<5; j++)
          scanf("%d",&a[i][j]);
  aver_stu(a);
  aver_sco(a);
  max(a);
  return 0;
}
/* 你的程序将被嵌在这里 */

void aver_stu(int a[10][5]){
	int i,j,tmp;
	for(i=0;i<10;i++){
		tmp=0;
		for(j=0;j<5;j++)
			tmp+=a[i][j];
		printf("%3d",tmp/5);
	}
	printf("\n");
}

void aver_sco(int a[10][5]){
	int i,j,tmp;
	for(i=0;i<5;i++){
		tmp=0;
		for(j=0;j<10;j++)
			tmp+=a[j][i];
		printf("%3d",tmp/10);
	}
	printf("\n");
}

void max(int a[10][5]){
	int i,j,tmp=0,max_i,max_j;
	for(i=0;i<10;i++)
		for(j=0;j<5;j++)
			if(a[i][j]>tmp){
				tmp = a[i][j];
				max_i=i;
				max_j=j;
			}
	printf("%3d%3d",max_i+1,max_j+1);
}
