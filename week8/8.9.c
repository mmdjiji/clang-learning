#include <stdio.h>
#include <string.h>
int main(){
	char tmp[11];
	int i,j,N,nums[10],ifmax[10],max;
	for(i=0;i<10;i++)ifmax[i]=nums[i]=0;
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%s",tmp);
		for(j=0;j<strlen(tmp);j++)
			nums[tmp[j]-'0']++;
	}
	max=nums[0];
	ifmax[0]=1;
	for(i=1;i<10;i++){
		if(nums[i] > max){
			max = nums[i];
			for(j=0;j<10;j++)ifmax[j]=0;
			ifmax[i] = 1;
		}else if(nums[i] == max) ifmax[i] = 1;
	}
	printf("%d:",max);
	for(i=0;i<10;i++)
		if(ifmax[i])printf(" %d",i);
	return 0;
}
