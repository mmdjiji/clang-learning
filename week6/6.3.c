#include <stdio.h>
int main(){
	int i,j,repeat,tmp,max,n;
	scanf("%d",&repeat);
	for(i=0;i<repeat;i++){
		scanf("%d",&n);
		scanf("%d",&max);
		for(j=1;j<n;j++){
			scanf("%d",&tmp);
			if(tmp>max)max=tmp;
		}
		printf("%d\n",max);
	}
	return 0;
}
