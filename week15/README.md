# week15
程序填空题参考答案在 [ANSWERS.md](ANSWERS.md) 中，本周仅有程序填空题。

<!-- TOC -->

- [程序填空题](#程序填空题)
  - [Problem 1](#problem-1)
  - [Problem 2](#problem-2)
  - [Problem 3](#problem-3)
  - [Problem 4](#problem-4)
  - [Problem 5](#problem-5)
  - [Problem 6](#problem-6)
  - [Problem 7](#problem-7)
  - [Problem 8](#problem-8)
  - [Problem 9](#problem-9)
  - [Problem 10](#problem-10)
  - [Problem 11](#problem-11)
  - [Problem 12](#problem-12)
  - [Problem 13](#problem-13)
  - [Problem 14](#problem-14)
  - [Problem 15](#problem-15)

<!-- /TOC -->

## 程序填空题

### Problem 1
本题目要求打印字母N形状的图形。输入是一个整数n，表示图形有n行。例如输入5，输出
```
*   *
**  *
* * *
*  **
*   *
```

```C++
#include <stdio.h>
int main()
{
    int i,j;
    int n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n; j++)
            if(____1____ )
               ____2____;
            else putchar(' ');
        ____3____;
    }
    return 0;
}
```

### Problem 2
本题目要求计算两个正整数的最大公因子和最小公倍数。
```C++
#include <stdio.h>
int main()
{int  m,n,r,s;
  scanf("%d,%d",&m,&n);
  s=m*n;
  if(m<n)
    ____1____
  do
      { r=____2____;
         m=____3____;
         n=____4____;
      }while(n);
   printf("%d %d\n",m,____5____);
  return 0;
}
```

### Problem 3
班上有7个同学，学4门课程。题目要求找出哪个同学哪门课成绩最高。

输入样例:
```
95 99 95 88
89 74 95 100
95 47 87 50
86 78 90 76
51 99 86 71
43 64 73 56
80 86 81 94
```
输出样例:
```
student 1 course 3 is excellent
```

```C++
#include <stdio.h>
int main()
{ float score[7][4],max;
  int maxhang,maxlie,i,j;
  for (i=0; i<7;i++)
     for(j=0; j<4; j++)
        scanf("%d",____1____);
  ____2____
  max=score[0][0];
  for (i=0; i<7;i++)
     for(j=0; j<4; j++)
        if( max<score[i][j])
             ____3____
  printf("student %d course %d is excellent",maxhang, maxlie);
  return 0;
}
```

### Problem 4
班上有7个同学，学4门课程。题目要求找出哪个同学哪门课成绩最高。

输入样例:
```
95 99 95 88
89 74 95 100
95 47 87 50
86 78 90 76
51 99 86 71
43 64 73 56
80 86 81 94
```

输出样例:
```
student 1 course 3 is excellent
```

```C++
#include <stdio.h>
void find(float score[7][4],int *hang,int *lie)
{ int i,j;
  float max;
  ____1____
  max=____2____;
  for (i=0; i<7;i++)
     for(j=0; j<4; j++)
        if( max<score[i][j])
             {max=score[i][j];   ____3____ }
}
int main()
{ float score[7][4],max;
  int maxhang,maxlie,i,j,k;
  for(k=0; k<3; k++) {
  for (i=0; i<7;i++)
     for(j=0; j<4; j++)
        scanf("%d",____4____);
  find(____5____);
  printf("student %d course %d is  excellent\n",  maxhang, maxlie);
 }
  return 0;
}
```

### Problem 5
班上有7个同学，学4门课程。题目要求找出哪个同学哪门课成绩最高。

输入样例:
```
95 99 95 88
89 74 95 100
95 47 87 50
86 78 90 76
51 99 86 71
43 64 73 56
80 86 81 94
```

输出样例:
```
student 1 course 3 is excellent
```

```C++
#include <stdio.h>
void find(float *score,int *hang,int *lie)
{ int i,j;
  float max;
  *hang=0,*lie=0;
  max=____1____;
  for (i=0; i<7;i++)
     for(j=0; j<4; j++)
        if( ____2____)
             {____3____;  *hang=i;   *lie=j;  }
}
int main()
{ float score[7][4],max;
  int maxhang,maxlie,i,j;
  for (i=0; i<7;i++)
     for(j=0; j<4; j++)
        scanf("%d",&score[i][j]);
  find(____4____);
  printf("student %d course %d is  excellent\n",  maxhang, maxlie);
  return 0;
}
```

### Problem 6
班上有7个同学，学4门课程。题目要求找出哪个同学哪门课成绩最高。

输入样例:
```
95 99 95 88
89 74 95 100
95 47 87 50
86 78 90 76
51 99 86 71
43 64 73 56
80 86 81 94
```

输出样例:
```
student 1 course 3 is excellent
```

```C++
#include <stdio.h>
void find(float (*p)[4], int *hang, int *lie)
{ int i,j;
  float max;
   *hang=0;*lie=0;
   max=____1____;
   for (i=0; i<7;i++)
     for(j=0; j<4; j++)
        if( ____2____)
            {____3____;
              *hang=i;
              *lie=j;
           }
}
int main()
{ float score[7][4],max;
  int maxhang,maxlie,i,j;
  for (i=0; i<7;i++)
     for(j=0; j<4; j++)
        scanf("%d",&score[i][j]);
  find(____4____);
  printf("student %d course %d is excellent\n",  maxhang, maxlie);
  return 0;
}
```

### Problem 7
本题目要求完成字符串的比较、复制、连接操作。

输入样例:
```
showed
show
```

输出样例:
```
0
```

```C++
#include <stdio.h>
int strcompare(char *s,char *t)  //串的比较,返回0或不同处ASCII码的差
{  while(____1____)
      s++,t++;
   return ____2____;
}
void strcopy(char *s,char *t)   //串复制，功能与strcpy相同
{
   while(____3____)
   { ____4____; s++; t++;  }
   ____5____;
}
void strconcat(char *s,char *t)  //串的连接，功能与stcat相同
{
    while(____6____) 
        s++;
    while(____7____)
    {
        ____8____;
        s++; t++;
    }
    ____9____;
}
int main()
{ char a[80],b[80],c[80];
  int i;
  gets(a);gets(b);
  strcopy(c,b);
  strconcat(c,"ed");
  printf("%d\n",strcompare(a,c));
  return 0;
}
```

### Problem 8
读入一行文本，其中以空格分隔为若干个单词，以‘.’结束。你要输出这行文本中每个单词的长度。这里的单词与语言无关，可以包括各种符号，比如“it's”算一个单词，长度为4。注意，行中可能出现连续的空格。

输入格式:  
输入在一行中给出一行文本，以‘.’结束，结尾的句号不能计算在最后一个单词的长度内。

输出格式:  
在一行中输出这行文本对应的单词的长度，每个长度之后都有空格。

输入样例:
```
It's great to see you here.
```

输出样例:
```
4 5 2 3 3 4 
```

```C++
#include <stdio.h>
#include<string.h>
int main( )
{ int i, k, word,len;
  char string[81];
  gets(string);
  len=strlen(string);
  word=0; k=0;
  for(i=0; ____1____; i++)
    if (string[i]== ' '||string[i]== '.')
    { if(word==1) printf("%d ",k);
        ____2____
    }
    else  { ____3____ }
  return 0;
}
```

### Problem 9
输入10个字符串，本题目要求排序后输出这些串（从小到大）。

```C++
#include <stdio.h>
#include<string.h>
int main( )
{ char string[10][20],t[20];
  int i,j,k;
  for(i=0; i<10; i++)
     gets(____1____);
  for(i=0; i<9; i++)
    for(j=____2____; j<10; j++)
        if(____3____)
            {   ____4____
            }
  for(i=0; i<10; i++)
    puts(____5____);
  }
  return 0;
}
```

### Problem 10
输入10个字符串，本题目要求利用函数对字符串排序后，输出这些串（从小到大）。

```C++
#include <stdio.h>
#include<string.h>
void sort(char s[ ][20])
{ char t[20];
  int  i,j,k;
  for(i=0; i<9; i++)
    for(j=i+1; j<10; j++)
        if(____1____)
            {   ____2____
            }
}
int main( )
{ char string[10][20],t[20];
  int i,j,k;
  for(i=0; i<10; i++)
     gets(string[i]);
  sort(____3____);
  for(i=0; i<10; i++)
    puts(string[i]);
  return 0;
}
```

### Problem 11
输入10个字符串，本题目要求利用元素指针对字符串排序后，输出这些串（从小到大）。

```C++
#include <stdio.h>
#include<string.h>
void sort(char *s)
{ char t[20];
  int  i,j,k;
  for(i=0; i<9; i++)
    for(j=i+1; j<10; j++)
        if(____1____)
            {   ____2____
            }
}
int main( )
{ char string[10][20],t[20];
  int i,j,k;
  for(i=0; i<10; i++)
     gets(string[i]);
  sort(____3____);
  for(i=0; i<10; i++)
    puts(string[i]);
  return 0;
}
```

### Problem 12
输入10个字符串，本题目要求利用行指针对字符串排序后，输出这些串（从小到大）。

```C++
#include <stdio.h>
#include<string.h>
void sort(char (*s)[20])
{ char t[20];
  int  i,j,k;
  for(i=0; i<9; i++)
    for(j=i+1; j<10; j++)
        if(____1____)
            {   ____1____
            }
}
int main( )
{ char string[10][20],t[20];
  int i,j,k;
  for(i=0; i<10; i++)
     gets(string[i]);
  sort(____1____);
  for(i=0; i<10; i++)
    puts(string[i]);
  return 0;
}
```

### Problem 13
输入10个字符串，本题目要求利用指针数组或指向指针的指针对字符串排序后，输出这些串（从小到大）。

```C++
#include <stdio.h>
#include<string.h>
void sort(____1____)
{ char t[20],*w;
  int  i,j,k;
  for(i=0; i<9; i++)
    for(j=i+1; j<10; j++)
        if(____2____)
            {   ____3____
            }
}
int main( )
{ char string[10][20];
  char *p[10];
  int s,i,j,k;
  for(s=0;s<3; s++){
  for(i=0; i<10; i++)
      ____4____;
  for(i=0; i<10; i++)
     gets(p[i]);
  sort(____5____);
  for(i=0; i<10; i++)
    puts(p[i]);
  }
  return 0;
}
```

### Problem 14
本题目要求利用函数对12个整数从小到大排序。

```C++
#include <stdio.h>
#include<string.h>
void sort(int *s)
{ int w,t;
  int  i,j,k;
  for(i=0; i<11; i++)
    for(j=0; j<11-i; j++)
        if(____1____)
            {  ____2____
            }
}
int main( )
{ int  a[12];
  int i,j,k;
  for(i=0; i<12; i++)
     scanf("%d",____3____);
  sort(____4____);
  for(i=0; i<12; i++)
    printf("%3d",____5____);
  return 0;
}
```

### Problem 15
本题目要求利用指针数组或指向指针的指针对12个整数进行从小到大的排序。

```C++
#include <stdio.h>
#include<string.h>
void sort(____1____)
{ int t,*w;
  int  i,j,k;
  for(i=0; i<11; i++)
    for(j=0; j<11-i; j++)
        if(____2____)
            {  ____3____
            }
}
int main( )
{ int  a[12];
  int *p[12];
  int i,j,k;
  for(i=0; i<12; i++)
      ____4____;
  for(i=0; i<12; i++)
     scanf("%d",____5____);
  sort(____6____);
  for(i=0; i<12; i++)
    printf("%3d",____7____);
  return 0;
}
```