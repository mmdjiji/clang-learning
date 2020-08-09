#include<stdio.h>
#include<string.h>
void tongji(char s[],int leibie[4]);
int main()
{char a[50];
 int leibie[4]={0};
 gets(a);
 tongji(a,leibie);
 printf("%d %d %d %d",leibie[0],leibie[1],leibie[2],leibie[3]);
 return 0;
}
/* 你写的函数将被嵌在这里 */

void tongji(char s[],int leibie[4]){
	char i=0,ch;
	while((ch = s[i++]) != '\0'){
		if((ch >='a' && ch <='z') || (ch >='A' && ch <='Z')) leibie[0]++;
		else if(ch >= '0' && ch <= '9') leibie[1]++;
		else if(ch == ' ') leibie[2]++;
		else leibie[3]++;
	}
}
