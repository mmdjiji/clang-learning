#include <stdio.h>
char place[8] = {0}, flag[8] = {0}, d1[15] = {0}, d2[15] = {0}, strings[92][9], counts=0;
void findnext(int n){
	int i;
	for(i=0;i<8;i++)
		if(!flag[i] && !d1[n-i+7] && !d2[n+i]){
			place[n] = i;
			flag[i] = d1[n-i+7] = d2[n+i] = 1;
			if(n<7)
				findnext(n+1);
			else
				sprintf(strings[counts++],"%d%d%d%d%d%d%d%d",place[0]+1,place[1]+1,place[2]+1,place[3]+1,place[4]+1,place[5]+1,place[6]+1,place[7]+1);
			flag[i] = d1[n-i+7] = d2[n+i] = 0;
		}
}
int main(){
	int n;
	findnext(0);
	scanf("%d",&n);
	while(scanf("%d",&n) != EOF)
		printf("%s\n",strings[n-1]);
	return 0;
}
