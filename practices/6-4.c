#include <stdio.h>

#define MAXN 10
typedef float ElementType;

ElementType Average( ElementType S[], int N );

int main ()
{
    ElementType S[MAXN];
    int N, i;

    scanf("%d", &N);
    for ( i=0; i<N; i++ )
        scanf("%f", &S[i]);
    printf("%.2f\n", Average(S, N));

    return 0;
}

/* 你的代码将被嵌在这里 */

ElementType Average( ElementType S[], int N ){
	int i;
	ElementType sum=0;
	
	for(i=0;i<N;i++)
		sum+=S[i];
	sum /= N;
	
	return sum;
}
