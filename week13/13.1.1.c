#include<stdio.h>
struct oneday
{int day,month,year;};
main()
{struct oneday day1;
 int allday;
scanf("%d,%d,%d",&day1.year,&day1.month,&day1.day);
 printf("%d\n",count(day1));
}
/* 你的程序将被嵌在这里*/
int count(struct oneday one){
	int i,sum=0,months[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	if(one.year%4 == 0 && one.year%100 != 0 || one.year%400 == 0) months[1] = 29;
	for(i=0;i<one.month-1;i++) sum+=months[i];
	sum+=one.day;
	return sum;
}
