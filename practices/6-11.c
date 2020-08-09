#include <stdio.h>

#define MAXN 10
typedef float ElementType;

ElementType Median( ElementType A[], int N );

int main ()
{
    ElementType A[MAXN];
    int N, i;

    scanf("%d", &N);
    for ( i=0; i<N; i++ )
        scanf("%f", &A[i]);
    printf("%.2f\n", Median(A, N));

    return 0;
}

/* 你的代码将被嵌在这里 */

void ShellSort(ElementType* A, int N){
	for(int gap=N/2;gap>0;gap=gap/2){
		for(int j=gap;j<N;j++){
			if(A[j]<A[j-gap]){//先判断该元素是否需要开始组内插入排序
				ElementType tmp=A[j];
				int k=j-gap;
				while(k>=0 && tmp<A[k]){ //一直往前找，直到找到正确应该插入的位置
					A[k+gap]=A[k]; //当前元素后移
					k=k-gap;
				}
				A[k+gap]=tmp;
			}
		}
	}
}
ElementType Median( ElementType A[], int N ){
	ShellSort(A,N); 
	return A[N/2];
}
