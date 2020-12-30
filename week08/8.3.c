#include <stdio.h>
#include <string.h>
int main(){
	int i,j,N,K;
	char strs[100][11],temp[11];
	scanf("%d %d",&N,&K);
	for(i=0;i<N;i++)scanf("%s",strs[i]);
	for(i=0;i<K;i++)for(j=0;j<N-i-1;j++)
	if(strcmp(strs[j],strs[j+1]) > 0){
		strcpy(temp,strs[j]);
	    strcpy(strs[j],strs[j+1]);
	    strcpy(strs[j+1],temp);
	}
	for(i=0;i<N;i++)printf("%s\n",strs[i]);
	return 0;
}
