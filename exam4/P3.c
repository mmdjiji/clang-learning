#include <stdio.h>
int main(){
	long long a=1,b=2,c=4,d,i,n;
	scanf("%lld",&n);
	if(n==1||n==2)printf("%lld",n);
	else if(n==3)printf("4");
	else{
	for(i=0;i<n-3;i++){
		d=a+b+c;
		a=b;
		b=c;
		c=d;
	}
	printf("%lld",d);
	}
	return 0;
}
