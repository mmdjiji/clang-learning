#include <stdio.h>
int findmax(int *s){
	int i,max=s[0];
	for(i=1;i<10;i++)
		if(s[i]>max) max=s[i];
	return max;
}
int main(){
	int i,arr[10];
	for(i=0;i<10;i++)
		scanf("%d",&arr[i]);
	printf("%d",findmax(arr));
	return 0;
}
