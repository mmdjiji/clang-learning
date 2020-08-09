#include <stdio.h>
void print(int a){
	if(a/10 != 0){
		printf("%d",a%10);
		print(a/10);
	}else{
		printf("%d",a);
	}
}
int main(){
	int a;
	scanf("%d",&a); 
	print(a);
	return 0;
} 
