//Standard Edition
#include <stdio.h>
#include <math.h>
int power(int a, int ae){
    int powret;
    if (a == 0 || a == 1) powret = a;
    else{
        powret = 1;
        while (ae > 0){
            powret = powret * a;
            ae--;
        }
    }
    return powret;
}
int flower(int num){
	int i,sum=0,len=log10(num)+1;
	for(i=0;i<len;i++) sum+=power(num/power(10,i)%10,len);
	if(sum == num) return 1;else return 0;
}
int main(){
	int N,i;
	scanf("%d",&N);
	for(i=power(10,N-1);i<power(10,N);i++)
		if(flower(i))printf("%d\n",i);
	return 0;
}
//Faster Edition
/*
#include <stdio.h>
int main(){
	int N;
	scanf("%d",&N);
	switch(N){
		case 3:
			printf("153\n370\n371\n407\n");
			break;
		case 4:
			printf("1634\n8208\n9474\n");
			break;
		case 5:
			printf("54748\n92727\n93084\n");
			break;
		case 6:
			printf("548834\n");
			break;
		case 7:
			printf("1741725\n4210818\n9800817\n9926315\n");
			break;	
	}
	return 0;
}
*/
