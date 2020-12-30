#include <stdio.h>
int main(){
	int i, tmp, max;
	scanf("%d", &max);
	for(i=1; i<3; i++){
		scanf("%d", &tmp);
		if(tmp > max)
			max = tmp;
	}
	printf("%d", max);
	return 0;
}
