#include <stdio.h>
int main(){
	int i,arr[10],todo,min,location;
	for(i=0;i<10;i++) scanf("%d",&arr[i]);
	scanf("%d",&todo);
	location = todo;
	min = arr[location];
	for(i=todo+1;i<10;i++)
	if(arr[i]<min){
		min=arr[i];
		location = i;
	}
	printf("%d",location);
	return 0;
} 
