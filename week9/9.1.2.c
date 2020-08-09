#include<stdio.h>
int half(int a[10], int x);
int main( )	                              
{ int a[10],x,i,pos;  
  for(i=0; i<10; i++)
      scanf("%d",&a[i]);
  scanf("%d",&x);
  pos=half(a,x);
  printf("%d",pos);             
  return 0;
}
/* 你写的函数将嵌在这里 */

int half(int a[10], int x){
	int left=0,right=9,todo;
	while(left <= right){
		todo = (left + right)/2;
		if(a[todo] < x) left = todo + 1;
		else if(a[todo] > x) right = todo - 1;
		else return todo;
	}
	return -1;
}
