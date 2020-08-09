#include <stdio.h>
#include <math.h>
int main(){
	int i, num, len;
	scanf("%d", &num);
	len = log10(num)+1;
	printf("%d\n", len);
	for(i=len-1; i>=0; i--){
		printf("%d", num/(int)pow(10,i)%10);
		if(i!=0)printf(" ");
	}
	printf("\n");
	for(i=0; i<len; i++){
		printf("%d", num/(int)pow(10,i)%10);
		if(i!=len-1)printf(" ");
	}
	return 0;
}
