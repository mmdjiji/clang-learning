# week11 - 主观题参考答案

### Answer 1
```C++
#include <stdio.h>
typedef struct{
	int day,month,year;
}date;
date input(){
	date retval;
	scanf("%d/%d/%d",&retval.year,&retval.month,&retval.day);
	return retval;
}
int judge(date checking){
	char dayList[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	if(checking.year > 0 && checking.month >= 1 && checking.month <= 12 && checking.day >= 1){
		if(checking.year%4==0 && checking.year%100 !=0 || checking.year%400 == 0)
			dayList[1] = 29;
		if(checking.day <= dayList[checking.month-1])
			return 1;
	}
	return 0;
}
void output(date putting){ 
	char enMonthList[12][10] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
	printf("%s %d,%d",enMonthList[putting.month-1],putting.day,putting.year);
}
int main(){
	date today = input();
	if(judge(today)){
		output(today);
	}else{
		printf("invalid date");
	}
	return 0;
}
```