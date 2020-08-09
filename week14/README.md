# week14
程序填空题参考答案在 [ANSWERS.md](ANSWERS.md) 中，函数题及编程题参考答案为同目录下的 `.c` 文件。

<!-- TOC -->

- [程序填空题](#程序填空题)
  - [Problem 1](#problem-1)
  - [Problem 2](#problem-2)
- [函数题](#函数题)
  - [14.1.1 单链表结点删除](#1411-单链表结点删除)
  - [14.1.2 链表逆置](#1412-链表逆置)
  - [14.1.3 删除单链表偶数节点](#1413-删除单链表偶数节点)
  - [14.1.4 奇数值结点链表](#1414-奇数值结点链表)
- [编程题](#编程题)
  - [14.2.1 链表建立练习1](#1421-链表建立练习1)
  - [14.2.2 链表建立练习2](#1422-链表建立练习2)
  - [14.2.3 报数](#1423-报数)

<!-- /TOC -->

## 程序填空题

### Problem 1
本题目建立和显示链表。链表存放若干同学的学号和成绩。
```C++
#include<stdio.h>
#include<stdlib.h>
#define LEN sizeof(struct student)
 struct student
 { int num;
   int score;
   struct student *next;
 };
 struct student *CreateLink( )
 {struct student *head,*p,*pr;
   pr=p=(struct student*)malloc(sizeof(struct student));
   if(NULL==p)
     {printf("No enough memory to allocation!\n"); exit(0); }
   scanf("%d,%d",&p->num,&p->score);
   ____1____;
   while (p->num!=0)
   {
    if (NULL==head)  ____2____;
    else ____3____;
    pr=p;
    p=(struct student *)malloc(LEN);
    scanf("%d,%d",&p->num,&p->score);
   }
   ____4____;
   free(p);
   return head;
 }
void DispLink(struct student *head)
{struct student *p;
 p=head;
 while (____5____)
  {printf("%d %5d\n",____6____);
   ____7____;
  }
}
void DeleteMemory(struct student *head)
{struct student *p,*pr;
 p=head;
 while (p!=NULL)
  { pr=p;
    p=p->next;
    free(pr);
  }
}
int main()
{struct student *head;
  head=CreateLink();
  DispLink(head);
  DeleteMemory(head);
  return 0;
}
```

### Problem 2
已有一个有序链表存放若干同学的学号和成绩，所有数据已经按学号排好序，现在通过一系列指令对链表进行操作:
```
D num 删除学号为num的学生
S num 查找学号为num的学生信息
I num 插入学号为num的学生（假设成绩都是90）
E 0 结束操作，输出链表数据
```
假设链表数据为:
```
101 78
205 88
304 96
402 60
```
输入示例:
```
D 402
I 107
S 205
E 0
```
输出示例:
```
the 205 score is 88
101    78
107    90
205    88
304    96
```

```C++
#include<stdio.h>
#include<stdlib.h>
#define LEN sizeof(struct student)
 struct student
 { int num;
   int score;
   struct student *next;
 };

 void search(struct student *head, int num)
{struct student *p;
  p=head;
  if (p!=NULL)
  {while (____1____)
        p=p->next;
    if (____2____)
        printf("the %ld score is %d\n",num,p->score);
    else printf("%ld not found\n",num);
  }
  else printf("the list null\n");
}
struct student *DeleteNode(struct student * head, int num)
{struct student *p,*pr;
  if (head==NULL)
    {printf("list null \n");
     return head;
    }
  p=head;
  while (p->num!=num && p->next!=NULL)
     {____3____}
  if (p->num==num)
      {if (p==head) ____4____;
       else ____5____;
       free(p);
      }
    else printf("%d not found\n",num);
  ____6____;
}
struct student *InsertNode(struct student *head, int num)
{struct student *p,*pr,*p0;
 p0=(struct student*)malloc(LEN);
 if(NULL==p0)
  {printf("No enough memory to allocation!\n"); exit(0);}
 p0->num=num;  p0->score=90; p0->next=NULL;
 if (head==NULL)
    ____7____;
 else
  { p=head;
     while (____8____)
        {____9____; p=p->next;}
    if(p->num>num)
         if (____10____)   {head=p0; p0->next=p;}
         else  { ____11____ }
    else  {____12____; p0->next=NULL;}
  }
  return(head);
}

int main()
{ struct student *head;
  char choice; int num;
  head=CreateLink();
  scanf(" %c %d",&choice,&num);
  while(choice!='E')
    { if(choice=='I') ____13____;
      else if(choice=='D') head=DeleteNode(head,num);
      else if(choice=='S') search(head,num);
      scanf(" %c %d",&choice,&num);
    }
  DispLink(head);
  DeleteMemory(head);
  return 0;
}
```

## 函数题

### 14.1.1 单链表结点删除
描述:  
本题要求实现两个函数，分别将读入的数据存储为单链表、将链表中所有存储了某给定值的结点删除。链表结点定义如下:
```C++
struct ListNode {
    int data;
    ListNode *next;
};
```
函数接口定义:
```C++
struct ListNode *readlist();
//函数readlist从标准输入读入一系列正整数，按照读入顺序建立单链表。当读到−1时表示输入结束，函数应返回指向单链表头结点的指针。

struct ListNode *deletem( struct ListNode *L, int m );
//函数deletem将单链表L中所有存储了m的结点删除。返回指向结果链表头结点的指针。
```
裁判测试程序样例:
```C++
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
```
输入样例:
```
10 11 10 12 10 -1
10
```
输出样例:
```
11 12 
```

### 14.1.2 链表逆置
描述:  
本题要求实现一个函数，将给定单向链表逆置，即表头置为表尾，表尾置为表头。链表结点定义如下:
```C++
struct ListNode {
    int data;
    struct ListNode *next;
};
```
函数接口定义:
```C++
struct ListNode *reverse( struct ListNode *head );
//其中head是用户传入的链表的头指针；函数reverse将链表head逆置，并返回结果链表的头指针。
```
裁判测试程序样例:
```C++
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
/* 你的代码将被嵌在这里 */
```
输入样例:
```
1 2 3 4 5 6 -1
```
输出样例:
```
6 5 4 3 2 1 
```

### 14.1.3 删除单链表偶数节点
描述:  
本题要求实现两个函数，分别将读入的数据存储为单链表、将链表中偶数值的结点删除。链表结点定义如下：
```C++
struct ListNode {
    int data;
    struct ListNode *next;
};
```
函数接口定义:
```C++
struct ListNode *createlist();
//函数createlist从标准输入读入一系列正整数，按照读入顺序建立单链表。当读到−1时表示输入结束，函数应返回指向单链表头结点的指针。
struct ListNode *deleteeven( struct ListNode *head );
//函数deleteeven将单链表head中偶数值的结点删除，返回结果链表的头指针。
```
裁判测试程序样例:
```C++
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
```
输入样例:
```
1 2 2 3 4 5 6 7 -1
```
输出样例:
```
1 3 5 7 
```

### 14.1.4 奇数值结点链表
描述:  
本题要求实现两个函数，分别将读入的数据存储为单链表、将链表中奇数值的结点重新组成一个新的链表。链表结点定义如下:
```C++
struct ListNode {
    int data;
    ListNode *next;
};
```
函数接口定义:
```C++
struct ListNode *readlist();
//函数readlist从标准输入读入一系列正整数，按照读入顺序建立单链表。当读到−1时表示输入结束，函数应返回指向单链表头结点的指针。
struct ListNode *getodd( struct ListNode **L );
//函数getodd将单链表L中奇数值的结点分离出来，重新组成一个新的链表。返回指向新链表头结点的指针，同时将L中存储的地址改为删除了奇数值结点后的链表的头结点地址（所以要传入L的指针）。
```
裁判测试程序样例:
```C++
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
```
输入样例:
```
1 2 2 3 4 5 6 7 -1
```
输出样例:
```
1 3 5 7 
2 2 4 6 
```

## 编程题

### 14.2.1 链表建立练习1
描述:  
建立链表并输出链表内容。链表每个结点包括一个一元多项式的一项。

输入格式:  
输入共n+1行，第一行是n的值，其余各行分别是每项的系数和指数。

输出格式:  
输出共一行，依次用格式%dx^%d输出一项的值。指数为0的项、指数或系数为1的项与书写习惯相同。

输入样例:
```
5
3 0
2 5
4 1
1 3
8 9
```
输出样例:
```
3+2x^5+4x+x^3+8x^9
```

### 14.2.2 链表建立练习2
描述:  
建立链表并输出链表内容。链表每个结点包括一元多项式的一项。

输入格式:  
输入一行，给出多项式中的每一项，以(0,0)结束。

输出格式:  
输出共一行，依次用格式%dx^%d输出一项的值。指数为0的项、指数或系数为1的项与书写习惯相同。

输入样例:
```
(3,0)(2,5)(4,7)(6,3)(8,9)(0,0)
```
输出样例:
```
3+2x^5+4x^7+6x^3+8x^9
```

### 14.2.3 报数
描述:  
n个人围成一圈，从第1个人开始顺序报号1、2、....k。凡报到k者推出圈子。找出最后留在圈子中的人原来的序号。本题要求用链表实现。n<50,k<50。

输入格式:  
输入在一行中给出整数n和k。

输出格式:  
输出一个整数

输入样例:
```
7 3
```
输出样例:
```
4
```