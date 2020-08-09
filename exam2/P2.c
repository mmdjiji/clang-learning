#include <stdio.h>
int main(){
	int x,y;
	scanf("%d %d",&x,&y);
	if(x>=-2 && x<=2 && y>=-2 && y<=2) printf("yes"); else printf("no");
	return 0;
}
