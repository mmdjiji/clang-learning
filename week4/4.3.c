#include <stdio.h>
int main(){
	int grade;
	char comment;
	scanf("%d", &grade);
	if(grade>=90) comment = 'A';
	else if(grade>=80) comment = 'B';
	else if(grade>=70) comment = 'C';
	else if(grade>=60) comment = 'D';
	else comment = 'E';
	printf("%c", comment);
	return 0;
}
