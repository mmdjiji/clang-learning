#include <stdio.h>
typedef struct{
	int id;
	char name[20];
	char gender;
	int grades[4];
}Student;
int main(){
	int i;
	Student stu[10];
	for(i=0;i<10;i++){
		scanf("%d %s %c",&stu[i].id,stu[i].name,&stu[i].gender);
		if(stu[i].gender == 'm')
			scanf("%d%d%d%d",&stu[i].grades[0],&stu[i].grades[1],&stu[i].grades[2],&stu[i].grades[3]); 
		else
			scanf("%d%d%d",&stu[i].grades[0],&stu[i].grades[1],&stu[i].grades[2]); 
	}
	for(i=0;i<10;i++){
		printf("%5d%10s%3c",stu[i].id,stu[i].name,stu[i].gender);
		if(stu[i].gender == 'm')
			printf("%4d\n",(stu[i].grades[0]+stu[i].grades[1]+stu[i].grades[2]+stu[i].grades[3])/4); 
		else
			printf("%4d\n",(stu[i].grades[0]+stu[i].grades[1]+stu[i].grades[2])/3); 
	}
	return 0;
}
