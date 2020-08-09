#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *createlist();
struct ListNode *deleteeven( struct ListNode *head );
void printlist( struct ListNode *head )
{
     struct ListNode *p = head;
     while (p) {
           printf("%d ", p->data);
           p = p->next;
     }
     printf("\n");
}

int main()
{
    struct ListNode *head;

    head = createlist();
    head = deleteeven(head);
    printlist(head);

    return 0;
}

/* 你的代码将被嵌在这里 */

struct ListNode *createlist(){
	int tmp;
	struct ListNode *head=(struct ListNode *)malloc(sizeof(struct ListNode)),*now=head;
	head->next = NULL;
	while(scanf("%d",&tmp)!=EOF && tmp!=-1){
		now->next = (struct ListNode *)malloc(sizeof(struct ListNode));
		now = now->next;
		now->data = tmp;
		now->next = NULL;
	}
	return head->next;
}

struct ListNode *deleteeven( struct ListNode *L ){
	struct ListNode *head=(struct ListNode *)malloc(sizeof(struct ListNode)),*now=head,*tmp;
	head->next = L;
	while(now->next != NULL){
		if(now->next->data%2 == 0){
			tmp = now->next;
			now->next = tmp->next;
			free(tmp);
		}else{
			now=now->next;
		}
	}
	return head->next;
}
