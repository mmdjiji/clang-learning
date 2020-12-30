#include <stdio.h>

int ifrun(int year){
	if(year%4==0 && year%100!=0 || year%400 == 0) return 1; else return 0;
}

int date2day(int year, int month, int day){
	int alldays=0,i,days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
	if(ifrun(year)) days[1] = 29;
	for(i=0;i<month-1;i++)
		alldays += days[i];
	alldays += day;
	return alldays;
}

int main(){
	int year,month,day;
	scanf("%d,%d,%d",&year,&month,&day);
	printf("%d",date2day(year,month,day));
	return 0;
}
