#include<stdio.h>
#include<string.h>
void turn(char s[]);
int main()
{ char str[81];
  scanf("%s",str);
  turn(str);
  printf("%s",str);
  return 0;
}
/* 你的函数将被嵌在这里 */
void swap(char *a,char *b) {*a^=*b;*b^=*a;*a^=*b;}
void turn ( char str[] ){
	int i,len;
	len = strlen(str);
	for(i=0;i<len/2;i++)
		swap(&str[i],&str[len-i-1]);
}
