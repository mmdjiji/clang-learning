#include <stdio.h>
int main(){
	unsigned char buff[100],negative=0,met=0;
	long result=0;
	int i,count=0;
	while((buff[count++] = getchar()) != '#');
	buff[--count] = '\0';
	for(i=0;i<=count;i++){
		if(buff[i]>='0' && buff[i]<='9'){
            met=1;
            result = result*16+buff[i]-'0';
        }else if(buff[i]>='a' && buff[i]<='f'){
            met=1;
            result = result*16+buff[i]-'a'+10;
        }else if(buff[i]>='A' && buff[i]<='F'){
            met=1;
            result = result*16+buff[i]-'A'+10;
        }else if(buff[i]=='-' && met==0){
            negative=1;
        }
	}
	//In order to avoid a bug if met "-0", the program must print "0".
	if(result == 0)printf("0");else{
		if(negative) printf("-");
	    printf("%d",result);
    }
	return 0;
}
