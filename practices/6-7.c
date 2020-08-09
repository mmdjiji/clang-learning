#include <stdio.h>
#include <math.h>

int IsTheNumber ( const int N );

int main()
{
    int n1, n2, i, cnt;
	
    scanf("%d %d", &n1, &n2);
    cnt = 0;
    for ( i=n1; i<=n2; i++ ) {
        if ( IsTheNumber(i) )
            cnt++;
    }
    printf("cnt = %d\n", cnt);

    return 0;
}

/* 你的代码将被嵌在这里 */

int IsTheNumber ( const int N ){
	int i,len,nums[10] = {0},flag=0;
	len=log10(N)+1;
	for(i=0;i<len;i++){
		if(++nums[N/(int)pow(10,i)%10]>=2){
			flag = 1;
			break;
		}
	}
	if((double)sqrt(N) == (double)((int)sqrt(N)) && flag){
		return 1;
	}else{
		return 0;
	}
}
