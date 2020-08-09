#include <stdio.h>

int Count_Digit ( const int N, const int D );

int main()
{
    int N, D;
	
    scanf("%d %d", &N, &D);
    printf("%d\n", Count_Digit(N, D));
    return 0;
}

/* 你的代码将被嵌在这里 */
#include <math.h>
int Count_Digit ( const int N, const int D ){
	int i,len,sum=0,num;
	if(N<0) num = -N; else num = N;
	if(num > 0)
		len = log10(num)+1;
	else if(num == 0)
		len = 1;
	
	for(i=0;i<len;i++)
		if( num/(int)pow(10,i)%10 == D )
			sum++;
	return sum;
}
