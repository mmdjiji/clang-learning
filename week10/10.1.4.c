#include<stdio.h>
#include<string.h>
int change(char a[],int len);
int main()
{ char char16[8];
  int int10;
  scanf("%s",char16);
  int10=change(char16,strlen(char16));
  printf("%d",int10);
  return 0;
}

/* 你的程序将嵌在这里 */
int change(char a[ ],int len){
	int retval  = ( (a[len-1] >= 'a' && a[len-1] <= 'f') ? (a[len-1] - 'a' + 10) : (a[len-1] - '0') ) % 16;
	if(len == 1)
		return retval;
	else
		return 16*change(a,len-1)+retval;
}
