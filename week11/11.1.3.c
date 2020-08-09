#include <stdio.h>
#define MAXS 30

char *search(char *s, char *t);
void ReadString( char s[] ){gets(s);} /* 裁判提供，细节不表 */ /* 但是为了调试我给加上了 */

int main()
{
    char s[MAXS], t[MAXS], *pos;

    ReadString(s);
    ReadString(t);
    pos = search(s, t);
    if ( pos != NULL )
        printf("%d\n", pos - s);
    else
        printf("-1\n");

    return 0;
}

/* 你的代码将被嵌在这里 */
char *search(char *s, char *t){
	int i,index=0,len=strlen(t),flag;
	while(s[index]!='\0'){
		flag = 1;
		for(i=0;i<len;i++){
			if(t[i] != s[index+i]){ 
				flag=0;
				break;
			}
		}
		if(flag){
			return s+index;
		}else{
			flag=1; 
			for(i=0;i<len;i++){
				if(t[i] == s[index+len]){
					index+=len-i;
					flag=0;
					break; 
				}
			}
			if(flag) index+=len+1;
		}
	}
	return NULL; 
}
