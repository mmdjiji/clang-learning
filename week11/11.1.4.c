#include <stdio.h>

void average1(int (*p)[5],int n);
void average2(int *p, float *a);
void find1(int (*p)[5],float *a);
void find2(int *p,float *a);

int main() {
	int score[4][5];
	int i,j;
	float aver[4];
	for (i=0; i<4; i++)       //输入4个学生5门课的成绩
		for (j=0; j<5; j++)
			scanf("%d",*(score+i)+j);
	average1(score,4);        //计算第一门课的平均分
	average2(*score,aver);    //计算每个学生的平均分放在数组aver中
	find1(score,aver);        //输出有两门以上不及格的学生
	find2(*score,aver);       //输出平均分在90分以上或每门课85分以上的学生*/
	return 0;
}

/* 你的程序将嵌在这里 */
void average1(int (*p)[5],int n) {
	int i,sum=0;
	for(i=0;i<n;i++) sum+=*(p+i)[0];
	printf("average of score 1 is %.2f\n",(float)sum/n);
}
void average2(int *p, float *a){
	int i,j,sum;
	for(i=0;i<4;i++){
		sum=0;
		for(j=0;j<5;j++)
			sum += *(p+5*i+j);
		*(a+i)=(float)sum/5;
	}
}
void find1(int (*p)[5],float *a){
	int i,j,flag;
	for(i=0;i<4;i++){
		flag=0;
		for(j=0;j<5;j++)
			if(p[i][j] < 60) flag++;
		if(flag>=2)
			printf("number %d failed with %d\nhis score is%4d%4d%4d%4d%4d\naverage score is %.2f\n",i+1,flag,p[i][0],p[i][1],p[i][2],p[i][3],p[i][4],a[i]);
	}
}
void find2(int *p,float *a){
	int i,j,min;
	for(i=0;i<4;i++){
		min = *(p+5*i);
		for(j=1;j<5;j++)
			if(*(p+5*i+j) < min) min=*(p+5*i+j);
		if(a[i]> 90 || min>85)
			printf("number %d is very good\nhis score is%4d%4d%4d%4d%4d\naverage score is %.2f\n",i+1,*(p+5*i),*(p+5*i+1),*(p+5*i+2),*(p+5*i+3),*(p+5*i+4),a[i]);
	}
}
