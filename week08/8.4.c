#include <stdio.h>
#include <string.h>
int main(){
	char tmp[100]={0},longest[100]={0};
	while(scanf("%s",tmp) != EOF)
		if(strlen(tmp) > strlen(longest))
			strcpy(longest,tmp);
	printf("%s",longest);
	return 0;
}
