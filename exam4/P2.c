#include <stdio.h>
#include <math.h>
int main(){
	int a,b,c,d,e,f,i;
	scanf("%d/%d%d/%d",&a,&b,&c,&d);
	e=a*d+b*c;
	f=b*d;
	if(e%f == 0){
		printf("%d",e/f);
	}else{
		for(i=2;i<=sqrt(f);i++){
			while(e%i == 0 && f%i == 0){
				e/=i;
				f/=i;
			}
		}
		printf("%d/%d",e,f);
	}
	return 0;
}
