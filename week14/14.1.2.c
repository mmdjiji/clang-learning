#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *createlist(); /*裁判实现，细节不表*/
struct ListNode *reverse( struct ListNode *head );
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
    struct ListNode  *head;

    head = createlist();
    head = reverse(head);
    printlist(head);
	
    return 0;
}

struct ListNode *createlist(){ //为了测试我写了一个创建链表的函数 
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

/* 你的代码将被嵌在这里 */

struct ListNode *reverse( struct ListNode *head ){
	struct ListNode *n2xt, *n3xt;
	if(head == NULL) return NULL;
	if(head->next != NULL){
		n2xt = head->next;
		head->next = NULL;
		if(n2xt->next != NULL){
			n3xt = n2xt->next;
			while(n3xt->next != NULL){
				n2xt->next = head;
				head=n2xt;
				n2xt=n3xt;
				n3xt=n3xt->next;
			}
			n2xt->next = head;
			n3xt->next = n2xt;
			return n3xt;
		}
		n2xt->next = head;
		return n2xt; 
	}
	return head;
}
