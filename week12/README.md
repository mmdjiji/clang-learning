# week12
主观题参考答案在 [ANSWERS.md](ANSWERS.md) 中，函数题及编程题参考答案为同目录下的 `.c` 文件。

<!-- TOC -->

- [主观题](#主观题)
  - [Problem 1](#problem-1)
- [函数题](#函数题)
  - [12.1.1 字符串排序(用行指针实现)](#1211-字符串排序用行指针实现)
  - [12.1.2 字符串排序(用指针数组实现)](#1212-字符串排序用指针数组实现)
  - [12.1.3 整数排序](#1213-整数排序)
  - [12.1.4 输出月份英文名](#1214-输出月份英文名)
  - [12.1.5 计算最长的字符串长度](#1215-计算最长的字符串长度)
  - [12.1.6 字符串的连接](#1216-字符串的连接)
- [编程题](#编程题)
  - [12.2.1 字符串排序(用指向指针的指针实现)](#1221-字符串排序用指向指针的指针实现)
  - [12.2.2 竞赛排名](#1222-竞赛排名)

<!-- /TOC -->

## 主观题

### Problem 1
建立链表(输入格式自定)，每个结点有姓名、性别、成绩，然后输出链表中所有大于90分的张姓同学的数据。

## 函数题

### 12.1.1 字符串排序(用行指针实现)
描述:  
在主函数中输入10个字符串。用另一函数对它们排序。然后在主函数输出这10个已排好序的字符串。要求用行指针实现。

函数接口定义:
```C++
void sort(char (*p)[20]) ;
```
裁判测试程序样例:
```C++
#include<stdio.h>
#include "string.h"
#define N 10
void sort(char (*p)[20]) ;
int main()
{char ch[N][20]; int i;
 for (i=0; i<N; i++)        //输入10个串
   scanf("%s",ch[i]);
 sort(ch);                  //利用行指针排序
 for(i=0; i<N; i++)         //输出
    printf("%s\n",ch[i]);
  return 0;
}
/* 你的程序将被嵌在这里 */
```
输入样例:
```
qwe
asd
zxc
hg
up
cctv
are
not
goto
head
```
输出样例:
```
are
asd
cctv
goto
head
hg
not
qwe
up
zxc
```

### 12.1.2 字符串排序(用指针数组实现)
描述:  
在主函数中输入10个字符串。用另一函数对它们排序。然后在主函数输出这10个已排好序的字符串（从大到小）。要求用指针数组实现。

函数接口定义:
```C++
void sort(char  *p[N]);
```
裁判测试程序样例:
```C++
#include<stdio.h>
#include "string.h"
#define N 10
void sort(char  *p[N]);
int main()
{char ch[N][20]; int i,j;
 char *t[N];                 //定义指针数组
 for (i=0; i<N; i++)        //输入10个串
  { scanf("%s",ch[i]);
    t[i]=ch[i];            //建立联系   
  }
 sort(t);                   //利用指针数组排序
 for(i=0; i<N; i++)         //输出
  printf("%s\n",t[i]);
  return 0;
}
/* 你写的函数将被嵌在这里 */
```
输入样例:
```
qwe
asd
zxc
hg
up
cctv
are
not
goto
head
```
输出样例:
```
are
asd
cctv
goto
head
hg
not
qwe
up
zxc
```

### 12.1.3 整数排序
描述:  
用指向指针的指针的方法对n个整数排序并输出。要求将排序单独写成一个函数。n个整数在主函数中输入，最后在主函数中输出。 输入分两行，第一行是整数n，第二行是用空格隔开的n个整数。 输出只有一行，n个排好序的整数，每个整数后面有个空格（最后一个数后面也有一个空格）

函数接口定义:
```C++
void sort(int **p,int N);
```
裁判测试程序样例:
```C++
#include "stdio.h"
void sort(int **p,int N);
int main()
{int i,j;
 int N,**k;
 scanf("%d",&N);
 k=(int **)malloc(N*sizeof(int *));
 for (i=0; i<N; i++) 
 { k[i]=(int*)malloc(sizeof(int));
   scanf("%d",k[i]);   //输入N个整数
 }
 sort(k,N);   //利用指向指针的指针排序
 for(i=0; i<N; i++) 
      printf("%d ",*(*(k+i)));
 printf("\n");
 for(i=0; i<N; i++)
     free(k[i]);
 free(k);
 return 0;
}
/*你的程序将嵌在这里 */
```
输入样例:
```
12
5 4 3 6 7 9 12 19 32 13 29 10
```
输出样例:
```
3 4 5 6 7 9 10 12 13 19 29 32 
```

### 12.1.4 输出月份英文名
描述:  
本题要求实现函数，可以返回一个给定月份的英文名称。

函数接口定义:
```C++
char *getmonth( int n );
//函数getmonth应返回存储了n对应的月份英文名称的字符串头指针。如果传入的参数n不是一个代表月份的数字，则返回空指针NULL。
```
裁判测试程序样例:
```C++
#include <stdio.h>
char *getmonth( int n );
int main()
{
    int n;
    char *s;
    scanf("%d", &n);
    s = getmonth(n);
    if ( s==NULL ) printf("wrong input!\n");
    else printf("%s\n", s);
    return 0;
}
/* 你的代码将被嵌在这里 */
```
输入样例1:
```
5
```
输出样例1:
```
May
```
输入样例2:
```
15
```
输出样例2:
```
wrong input!
```

### 12.1.5 计算最长的字符串长度
描述:  
本题要求实现一个函数，用于计算有n个元素的指针数组s中最长的字符串的长度。

函数接口定义:
```C++
int max_len( char *s[], int n );
//其中n个字符串存储在s[]中，函数max_len应返回其中最长字符串的长度。
```

裁判测试程序样例:
```C++
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXN 10
#define MAXS 20
int max_len( char *s[], int n );
int main()
{
    int i, n;
    char *string[MAXN] = {NULL};
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        string[i] = (char *)malloc(sizeof(char)*MAXS);
        scanf("%s", string[i]);
    }
    printf("%d\n", max_len(string, n));
    return 0;
}
/* 你的代码将被嵌在这里 */
```
输入样例:
```
4
blue
yellow
red
green
```
输出样例:
```
6
```

### 12.1.6 字符串的连接
描述:  
本题要求实现一个函数，将两个字符串连接起来。

函数接口定义:
```C++
char *str_cat( char *s, char *t );
//函数str_cat应将字符串t复制到字符串s的末端，并且返回字符串s的首地址。
```
裁判测试程序样例:
```C++
#include <stdio.h>
#include <string.h>
#define MAXS 10
char *str_cat( char *s, char *t );
int main()
{
    char *p;
    char str1[MAXS+MAXS] = {'\0'}, str2[MAXS] = {'\0'};
    scanf("%s%s", str1, str2);
    p = str_cat(str1, str2);
    printf("%s\n%s\n", p, str1);
    return 0;
}
/* 你的代码将被嵌在这里 */
```
输入样例:
```
abc
def
```
输出样例:
```
abcdef
abcdef
```

## 编程题

### 12.2.1 字符串排序(用指向指针的指针实现)
描述:  
在主函数中输入8个字符串。用另一函数对它们排序。然后在主函数输出这8个已排好序的字符串。要求用指向指针的指针实现。

输入格式:  
输入共8行，表示8个字符串。

输出格式:  
输出也是8行，表示8个排好序的字符串。

输入样例:
```
qwe
asd
zxc
up
cctv
not
goto
head
```
输出样例:
```
asd
cctv
goto
head
not
qwe
up
zxc
```

### 12.2.2 竞赛排名
描述:  
有m个选手n个评委，每个评委给所有选手打分。最后得分的计算规则为去掉一个最高分，去掉一个最低分后取平均分为最后得分。要求按得分从高到低排出名次，公布获奖名单。本题要求用行指针实现。1≤m,n≤10。

输入格式:  
输入共m+1行，第一行是m和n两个整数，其他行是m×n个整数。

输出格式:  
输出一行，表示选手编号的一种排列（用%3d格式），这种排列代表得分从高到低的选手顺序。

输入样例:
```
8 5
7 8 9 7 8
8 9 7 9 8
8 9 8 8 7
8 9 9 9 8
7 6 8 9 7
6 7 8 9 9
6 7 8 7 8
7 8 7 6 7
```
输出样例:
```
  4  2  3  6  1  5  7  8
```