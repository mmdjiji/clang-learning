#include <stdio.h>
int main(){
	int tmp,min,max;
	scanf("%*d%d",&tmp);
	min=max=tmp;
	while(scanf("%d",&tmp) != EOF){
		if(tmp>max) max=tmp;
		if(tmp<min) min=tmp;
	}
	printf("%d",max-min);
	return 0;
}
