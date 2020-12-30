#include <stdio.h>
int main(){
	int input, output;
	scanf("%d", &input);
	output = (input%10)*100 + (input/10%10)*10 + input/100%10;
	printf("%d", output);
	return 0;
}
