#include <stdio.h>
int main(){
	char a;
	scanf("%c",&a);
	if(a>=65 && a<=90) printf("%c",a+'a'-'A');
	else if(a>=97 && a<=122) printf("%c",a+'A'-'a');
	else printf("input error");
	return 0;
}
