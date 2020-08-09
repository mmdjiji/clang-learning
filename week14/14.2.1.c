#include <stdio.h>
#include <stdlib.h>
typedef struct {
	int a,e; //a为系数 e为指数
}term;
struct node {
	term data;
	struct node *next;
};
void printnode(term t, int flag){
	if(t.a != 0){
		if(flag){
			printf("%d",t.a);
		}else{
			if(t.a == 1)
				printf("+");
			else if(t.a == -1)
				printf("-");
			else
				printf("%+d",t.a);
		}
		if(t.e != 0){
			if(t.e == 1)
				printf("x");
			else
				printf("x^%d",t.e);
		}
	}
}
int main(){
	int i,n;
	struct node *head = (struct node *)malloc(sizeof(struct node)),*tmp = head;
	head->next = NULL;
	scanf("%d",&n);
	if(n == 0) return 0;
	for(i=0;i<n;i++){
		tmp->next = (struct node *)malloc(sizeof(struct node));
		tmp = tmp->next;
		scanf("%d %d",&tmp->data.a,&tmp->data.e);
		tmp->next = NULL;
	}
	tmp = head->next;
	printnode(tmp->data,1);
	while(tmp->next != NULL){
		printnode(tmp->next->data,0);
		tmp = tmp->next;
	}
	return 0;
}
