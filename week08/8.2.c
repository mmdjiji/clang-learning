#include <stdio.h>
#include <string.h>
#define MAXLEN 100
int maxi(int a,int b) {return (a>b)?a:b;}
int main(){
	int i;
	char str1[MAXLEN],str2[MAXLEN];
	scanf("%s%s",str1,str2);
	for(i=0;i<maxi(strlen(str1),strlen(str2));i++)
	if(str1[i] != str2[i]){
		printf("%d",str1[i]-str2[i]);
		return 0;
	}
	printf("0");
	return 0;
}
