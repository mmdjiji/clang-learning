#include <stdio.h>
int main(){
	int i,a,b,reverse=0;
	scanf("%d/%d",&a,&b);
	if(a>b){
		reverse = 1;
		a+=b;
		b=a-b;
		a-=b;
	}
    for(i=a;i>0;i--)
    if(a%i==0 && b%i==0){
        if(reverse)
		printf("%d/%d",b/i,a/i);
		else
		printf("%d/%d",a/i,b/i);
        break;
    }
	return 0;
}
