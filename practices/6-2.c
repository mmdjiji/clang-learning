#include <stdio.h>

#define MAXN 10

double f( int n, double a[], double x );

int main()
{
    int n, i;
    double a[MAXN], x;
	
    scanf("%d %lf", &n, &x);
    for ( i=0; i<=n; i++ )
        scanf("%lf", &a[i]);
    printf("%.1f\n", f(n, a, x));
    return 0;
}

/* 你的代码将被嵌在这里 */

double f( int n, double a[], double x ){
	int i;
	double sum=0.0;
	for(i=0;i<=n;i++)
		sum+=a[i]*pow((double)x,(double)i);
	return sum;
} 
