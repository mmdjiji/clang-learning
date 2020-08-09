# week12 - 主观题参考答案

### Answer 1

```C++
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student{
	char name[20];
	char gender;
	int grade;
}student;
typedef struct node{
	student data;
	struct node *next;
}list;
int main(){
	list *head = (list*)malloc(sizeof(list)), *tmp = head;
	student stu;

	while(scanf("%s %c %d", stu.name, &(stu.gender), &(stu.grade)) != EOF){
		tmp->next = (list*)malloc(sizeof(list));
		tmp = tmp->next;
		tmp->data = stu;
		tmp->next = NULL;
	}
	tmp = head->next;
	while(tmp != NULL){
		if(tmp->data.grade > 90 && strncmp(tmp->data.name, "张", 2)==0){
			printf("%s %c %d\n", tmp->data.name, tmp->data.gender, tmp->data.grade);
		}
		if(tmp->next != NULL)
			tmp = tmp->next;
		else
			break;
	}
	return 0;
}
```
另附测试数据:
```
张华 m 90
张路阳 f 91
吴老师 m 87
李老师 f 60
张嘤嘤 f 99
李明 m 98
孙力 f 97
刘明 m 87
张蛋笨 f 93
```