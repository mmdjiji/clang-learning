#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *readlist();
struct ListNode *deletem( struct ListNode *L, int m );
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
    int m;
    struct ListNode *L = readlist();
    scanf("%d", &m);
    L = deletem(L, m);
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
struct ListNode *deletem( struct ListNode *L, int m ){
	struct ListNode *head=(struct ListNode *)malloc(sizeof(struct ListNode)),*now=head,*tmp;
	head->next = L;
	while(now->next != NULL){
		if(now->next->data == m){
			tmp = now->next;
			now->next = tmp->next;
			free(tmp);
		}else{
			now=now->next;
		}
	}
	return head->next;
}
