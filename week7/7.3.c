#include <stdio.h>
int main(){
	int N,i,arr[10],max,location;
	scanf("%d",&N);
	for(i=0;i<N;i++) scanf("%d",&arr[i]);
	max = arr[N-1];
	location = N-1;
	for(i=N-2;i>=0;i--)if(arr[i]>=max){
		max=arr[i];
		location = i;
	}
	printf("%d %d",max,location);
	return 0;
}
