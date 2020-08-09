#include <stdio.h>
int main(){
	int grade, flag;
	char comment;
	scanf("%d", &grade);
	flag = grade / 10;
	switch(flag){
		case 10:
		case 9:
			comment = 'A';
			break;
		case 8:
			comment = 'B';
			break;
		case 7:
			comment = 'C';
			break;
		case 6:
			comment = 'D';
			break;
		default:
			comment = 'E';
			break;
			
	}
	printf("%c", comment);
	return 0;
}
