#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *readlist();
struct ListNode *getodd( struct ListNode **L );
void printlist( struct ListNode *L )
{
     struct ListNode *p = L;
     while (p) {
           printf("%d ", p->data);
           p = p->next;
     }
     printf("\n");
}

int main()
{
    struct ListNode *L, *Odd;
    L = readlist();
    Odd = getodd(&L);
    printlist(Odd);
    printlist(L);

    return 0;
}

/* 你的代码将被嵌在这里 */

struct ListNode *readlist(){
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
struct ListNode *getodd( struct ListNode **L ){
	struct ListNode *head=(struct ListNode *)malloc(sizeof(struct ListNode)),*now=head,*tmp,*newlist=(struct ListNode *)malloc(sizeof(struct ListNode)),*newhead=newlist;
	head->next = *L;
	newlist->next = NULL;
	while(now->next != NULL){
		if(now->next->data%2 != 0){
			tmp = now->next;
			now->next = tmp->next;
			newlist->next = tmp;
			newlist=newlist->next;
			newlist->next = NULL;
		}else{
			now=now->next;
		}
	}
	*L = head->next;
	return newhead->next;
}
