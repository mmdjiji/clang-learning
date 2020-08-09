#include<stdio.h>
#include "string.h"
#define N 10

void sort(char  *p[N]);

int main()
{char ch[N][20]; int i,j;
 char *t[N];                 //定义指针数组
 for (i=0; i<N; i++)        //输入10个串
  { scanf("%s",ch[i]);
    t[i]=ch[i];            //建立联系   
  }
 sort(t);                   //利用指针数组排序
 for(i=0; i<N; i++)         //输出
  printf("%s\n",t[i]);
  return 0;
}

/* 你写的函数将被嵌在这里 */

void swop(char **str1, char **str2) {char *tmp = NULL;tmp = *str1;*str1 = *str2;*str2 = tmp;}
void sort(char *p[N]) {
	int i,j;
	for(i=0;i<10;i++)
		for(j=0;j<9-i;j++)
			if(strcmp(p[j],p[j+1])>0)
				swop(p[j],p[j+1]);
}
