#include <stdio.h>
char grade(int n){
	if(n<60) return 'E'; 
	else if(n<75) return 'D';
	else if(n<85) return 'C';
	else if(n<95) return 'B';
	else return 'A';
}
int main(){
	int n;
	scanf("%d",&n);
	printf("%c",grade(n));
	return 0;
} 
