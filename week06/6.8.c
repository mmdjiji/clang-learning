#include <stdio.h>
int main(){
	int a,b,m,n,tmp;
	scanf("%d %d",&a,&b);
	m=(a>b)?a:b;
	n=(a<b)?a:b;
	//m>n
	while(m%n != 0){
		tmp = n;
		n = m % n;
		m = tmp;
	}
	printf("%d %d",n,a*b/n);
	return 0;
}
