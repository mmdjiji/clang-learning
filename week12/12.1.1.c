#include<stdio.h>
#include "string.h"
#define N 10
void sort(char (*p)[20]) ;
int main()
{char ch[N][20]; int i;
 for (i=0; i<N; i++)        //输入10个串
   scanf("%s",ch[i]);
 sort(ch);                  //利用行指针排序
 for(i=0; i<N; i++)         //输出
    printf("%s\n",ch[i]);
  return 0;
}

/* 你的程序将被嵌在这里 */
void swop(char **str1, char **str2) {char *tmp = NULL;tmp = *str1;*str1 = *str2;*str2 = tmp;}
void sort(char (*p)[20]) {
	int i,j;
	for(i=0;i<10;i++)
		for(j=0;j<9-i;j++)
			if(strcmp(p+j,p+j+1)>0)
				swop(p+j,p+j+1);
}
