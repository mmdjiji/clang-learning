#include<stdio.h>
#include<string.h>
void input(char name[10][20],int num[]);
void sort(char name[10][20],int num[]);
//int search(int num[],int one);

int main()
{   int i,one,k;
    char name[10][20];
    int num[10];
    input(name,num);
    sort(name,num);
    for(i=0;i<10; i++)
        printf("%s %d\n",name[i],num[i]);
    scanf("%d",&one);
    k=search(num,one);
    if(k!=-1) puts(name[k]);
		else puts("NO");
    return 0;
}

/* 你的程序将嵌在这里 */
void swap(int *int1,int *int2) {*int1^=*int2;*int2^=*int1;*int1^=*int2;}
void input(char name[10][20],int num[]){
	int i;
	for(i=0;i<10; i++)
        scanf("%s %d",name[i],&num[i]);	
}
void sort(char name[10][20],int num[]){
	int i,j,k;
	char tmp[20];
	for(i=0;i<10;i++)
		for(j=0;j<9-i;j++)
			if(num[j]>num[j+1]){
				strcpy(tmp,name[j]);
				strcpy(name[j],name[j+1]);
				strcpy(name[j+1],tmp);
				swap(&num[j],&num[j+1]);
			}
}
int search(int num[],int one){
	int down=0,up=9,todo;
	while(down<=up){
		todo = (up+down)/2;
		if(num[todo] < one)
			down = todo + 1;
		else if(num[todo] > one)
			up = todo - 1;
		else
			return todo;
	}
	return -1;
}
