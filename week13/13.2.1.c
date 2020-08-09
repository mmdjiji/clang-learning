#include <stdio.h>
typedef struct{
	int id;
	char name[20];
	int grades[3];
}Student;
int main(){
	int i,sum=0,max,whomax=0,tmp;
	Student stu[10];
	for(i=0;i<10;i++)
		scanf("%d%s%d%d%d",&stu[i].id,stu[i].name,&stu[i].grades[0],&stu[i].grades[1],&stu[i].grades[2]);
	sum += max = tmp= stu[0].grades[0] + stu[0].grades[1] + stu[0].grades[2];
	for(i=1;i<10;i++){
		sum += tmp = stu[i].grades[0] + stu[i].grades[1] + stu[i].grades[2];
		if(tmp>max){max=tmp;whomax=i;}
	}
	printf("average score is %.2f\nthe max score is:\n%5d%10s%4d%4d%4d\nthe max average is %.2f\n",(float)sum/30,stu[whomax].id,stu[whomax].name,stu[whomax].grades[0],stu[whomax].grades[1],stu[whomax].grades[2],(float)(stu[whomax].grades[0]+stu[whomax].grades[1]+stu[whomax].grades[2])/3);
	return 0;
}
