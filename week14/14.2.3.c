#include <stdio.h>
#include <stdlib.h>
struct node{
	int n;
	struct node *next;
};
int main(){
	int amount,k,i;
	struct node *head = (struct node*)malloc(sizeof(struct node)),*now = head,*del;
	scanf("%d %d",&amount,&k);
	if(k==1){
		printf("%d",amount);
		return 0;
	}
	if(amount <= 0) return 0;
	if(amount == 1) {
		printf("1");
		return 0;
	}
	head->n = 1;
	for(i=2;i<=amount;i++){
		now->next = (struct node*)malloc(sizeof(struct node));
		now = now->next;
		now->n = i;
	}
	now->next = head;
	now = head;
	while(now->next != now){
		del = now;
		for(i=0;i<k-2;i++){
			now = now->next;
		}
		del = now->next;
		now->next = del->next;
		now = del->next;
		free(del);
	} 
	printf("%d",now->n);
	return 0;
} 
