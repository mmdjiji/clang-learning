#include <stdio.h>
#include <string.h>
int main(){
	char str[100],buff;
	int count=0,i,s1=0,s2=0,s3=0,s4=0;
	while( (buff = getchar()) != '\n')str[count++] = buff;
	for(i=0;i<strlen(str);i++)
	if(str[i] == ' ')s3++;
	else if(str[i] >= '0' && str[i] <= '9')s2++;
	else if( (str[i]>='a' && str[i]<'z') || str[i]>='A' && str[i]<='Z' )s1++;
	else s4++;
	printf("%d %d %d %d",s1,s2,s3,s4);
	return 0;
}
