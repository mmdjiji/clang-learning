#include <stdio.h>
//����PTA��BUG ����time.h�ͻ������һ�����Ե��ϳ�ʱ 
#include <time.h>
int main(){
	int N,i,sum=0;
	scanf("%d",&N);
	for(i=1;i<N;i++)
		if(N%i == 0)
			sum+=i;
	if(N == sum) printf("Yes"); else printf("No");
	return 0;
}
