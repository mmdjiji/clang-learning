#include <stdio.h>
int prime(int x);
int main( )	                              
{ int d;  
 scanf("%d",&d);      
 if(prime(d)==1)
     printf("%d is a prime number",d);             
 else 
     printf("%d is not a prime number",d);   
  return 0;
}

/* 你的程序将被嵌在这里 */

int prime(int num){
	int i;
	if(num == 1)return 0;
	if(num<0)num=-num;
	for(i=2;i<=sqrt(num);i++){
		if(num%i==0)return 0;
	}
	return 1;
}
