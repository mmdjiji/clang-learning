#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void swop(char **str1, char **str2) {char *tmp = NULL;tmp = *str1;*str1 = *str2;*str2 = tmp;}
void sort(char **str){
	int i,j;
	char *tmp;
	for(i=0;i<8;i++)
		for(j=0;j<7-i;j++)
			if(strcmp(str[j],str[j+1])>0)
				swop(str[j],str[j+1]);
}
int main(){
	int i;
	char *index[8];
	for(i=0;i<8;i++){
		index[i] = (char*)malloc(sizeof(char)*10);
		scanf("%s",index[i]);
	}
	sort(index);
	for(i=0;i<8;i++)
		printf("%s\n",index[i]);
	return 0;
}
