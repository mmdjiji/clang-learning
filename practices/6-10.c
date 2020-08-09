#include <stdio.h>

void Print_Factorial ( const int N );

int main()
{
    int N;
	
    scanf("%d", &N);
    Print_Factorial(N);
    return 0;
}

/* 你的代码将被嵌在这里 */
#define MAXLEN 10000
void Print_Factorial ( const int N ){
	int i,j,tmp,up=0;
	char arr[MAXLEN+1] = {0};
	arr[0] = 1;
	if(N>=0){
		for(i=2;i<=N;i++){
			up = 0;
			for(j=0;j<=MAXLEN;j++){
				tmp = arr[j] * i + up;
				arr[j] = tmp % 10;
				up = tmp / 10;
			}
		}
	
	for(i=MAXLEN;i>=0;i--)
		if(arr[i] != 0)
			for(i;i>=0;i--)
				printf("%d",arr[i]);
	}else{
		printf("Invalid input");
	}
}
