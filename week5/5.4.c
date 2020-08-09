#include <stdio.h>
int main(){
	int N,i,numbers[10],max;
	scanf("%d",&N);
	for(i=0;i<N;i++) scanf("%d",&numbers[i]);
	max = numbers[0];
	for(i=1;i<N;i++)
		if(numbers[i]>max) max = numbers[i];
	printf("%d",max);
	return 0;
}
