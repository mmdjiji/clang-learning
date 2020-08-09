#include "stdio.h"
void sort(int **p,int N);


int main()
{int i,j;
 int N,**k;
 scanf("%d",&N);
 k=(int **)malloc(N*sizeof(int *));
 for (i=0; i<N; i++) 
 { k[i]=(int*)malloc(sizeof(int));
   scanf("%d",k[i]);   //输入N个整数
 }
 sort(k,N);   //利用指向指针的指针排序
 for(i=0; i<N; i++) 
      printf("%d ",*(*(k+i)));
 printf("\n");
 for(i=0; i<N; i++)
     free(k[i]);
 free(k);
 return 0;
}

/*你的程序将嵌在这里 */
void swap(int *p,int *q) {*p^=*q;*q^=*p;*p^=*q;}
void sort(int **p,int N){
	int i,j;
	for(i=0;i<N;i++)
		for(j=0;j<N-i-1;j++)
			if(*p[j+1]<*p[j])
				swap(p[j+1],p[j]);
}
