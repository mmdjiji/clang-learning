#include <stdio.h>
typedef struct{
	char name[20];
	int birthday;
	char phonenum[20];
}User;
int main(){
	int i,j,n;
	User users[10],tmp;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%s %d %s",users[i].name,&users[i].birthday,users[i].phonenum);
	for(i=0;i<n;i++)
		for(j=0;j<n-i-1;j++)
			if(users[j+1].birthday < users[j].birthday){tmp=users[j+1];users[j+1]=users[j];users[j]=tmp;}
	for(i=0;i<n;i++)
		printf("%s %d %s\n",users[i].name,users[i].birthday,users[i].phonenum);
	return 0;
}
