#include <stdio.h>
#include <math.h>
int main(){
	int a,b,c;
	double p,s;
	scanf("%d %d %d",&a,&b,&c);
	if(a+b>c && a+c>b && b+c>a){
		p = (double)(a+b+c)/2;
		s = sqrt(p*(p-a)*(p-b)*(p-c));
		printf("area = %.2lf; perimeter = %.2lf",s,(double)(a+b+c));
	}else printf("These sides do not correspond to a valid triangle");
	return 0;
}
