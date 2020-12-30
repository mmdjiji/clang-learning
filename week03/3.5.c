#include <stdio.h>
int main(){
	int A,B;
	scanf("%d %d",&A,&B);
	printf("%d/",A);
	if(B < 0) printf("(%d)=",B);
	else printf("%d=",B);
	if(B != 0) printf("%.02lf",(double)A/B);
	else printf("Error");
	return 0;
}
