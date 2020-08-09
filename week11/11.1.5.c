#include <stdio.h>

void input(int *p);
void proc(int *p);
void output(int *p);

main()
{int a[10];
 input(a);     //输入10个整数
 proc(a);      //调换
 output(a);    //输出
 return 0;
}

/* 请在这里填写答案 */
void swap(int *p, int *q) {if(*p!=*q){*p^=*q;*q^=*p;*p^=*q;}}
void input(int *p) {int i;for(i=0;i<10;i++)scanf("%d",p+i);}
void output(int *p){int i;for(i=0;i<10;i++)printf("%3d",*(p+i));}
void proc(int *p){
	int i,min,max,i_min,i_max;
	min=max=*p;i_min=0,i_max=0;
	for(i=1;i<10;i++)
		if(*(p+i) < min){min = *(p+i);i_min=i;}
	swap(p,p+i_min);
	min=max=*p;i_min=0,i_max=0;
	for(i=1;i<10;i++)
		if(*(p+i) > max){max = *(p+i);i_max=i;}
	swap(p+9,p+i_max);
}
