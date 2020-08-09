#include <stdio.h>
#include <string.h>
int main(){
	char str[1000];
	int i;
	gets(str);
	if(str[0]>='a'&&str[0]<='z') printf("%c",str[0] + 'A'-'a');
	else printf("%c",str[0]);
	for(i=1;i<strlen(str);i++){
		if(str[i-1] == ' ' && str[i]>='a' && str[i]<='z')
			printf("%c",str[i] + 'A'-'a');
		else
			printf("%c",str[i]);
	}
	return 0;
}
