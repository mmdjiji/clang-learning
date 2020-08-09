#include <stdio.h>
int hash(char *tmp){
	int sum=0,i=1;
	while(*tmp!='\0') sum += *tmp++ * i++;
	return sum;
}
int main(){
	int hashmap[100] = {0}, rec=0, flag=1, i;
	char tmp[20];
	while(scanf("%s",tmp)!=EOF){
		flag=1;
		for(i=0;i<rec;i++)
		 	if(hashmap[i] == hash(tmp))
		 		flag=0;
		if(flag)
			hashmap[rec++] = hash(tmp);
	}
	printf("%d",rec);
	return 0;
}
