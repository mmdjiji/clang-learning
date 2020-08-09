#include <stdio.h>
int if13(int w){ 
	int day=1;
	while(w!=5 && w!=12){
		day++;
		w++;
	}
	if(day == 6) return 1; else	return 0;
}
int main(){
	int w,i;
	int day2month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	scanf("%d",&w);
	for(i=0;i<12;i++){
		if(if13(w)) printf("%d\n",i+1);
		w=(w+day2month[i])%7;
	}
	return 0;
}
