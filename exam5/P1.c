#include <stdio.h>
#include <string.h>
int main(){
	char a[100],b[100];
	int counts1[128] = {0}, counts2[128] = {0};
	int i,j;
	gets(a);
	gets(b);
	for(i=0;i<strlen(a);i++)
		counts1[a[i]]++;
	for(i=0;i<strlen(b);i++)
		counts2[b[i]]++;
	for(i=0;i<128;i++){
		if(counts1[i]!=counts2[i]){
			printf("no");
			return 0;
		}
	}
	printf("yes");
	return 0;
}
