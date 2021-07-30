# week11
主观题参考答案在 [ANSWERS.md](ANSWERS.md) 中，函数题及编程题参考答案为同目录下的 `.c` 文件。

<!-- TOC -->

- [主观题](#主观题)
  - [Problem 1](#problem-1)
- [函数题](#函数题)
  - [11.1.1 整数有序输出](#1111-整数有序输出)
  - [11.1.2 字符串部分复制](#1112-字符串部分复制)
  - [11.1.3 查找子串](#1113-查找子串)
  - [11.1.4 成绩计算](#1114-成绩计算)
  - [11.1.5 数据转换](#1115-数据转换)
- [编程题](#编程题)
  - [11.2.1 移位](#1121-移位)
  - [11.2.2 位置调整](#1122-位置调整)

<!-- /TOC -->

## 主观题

### Problem 1
定义一个结构体，包含3个成员：day、month、year。  
(1)写一个函数，将键盘读入的日期赋值给结构体变量；  
(2)写一个函数验证日期是否合法(日期作为参数)；  
(3)写一个函数用以下格式输出日期: `April 25,2002`。  
在主函数中调用以上函数。

## 函数题

### 11.1.1 整数有序输出
描述:  
本题要求利用函数和指针输入3个整数，按由小到大的顺序输出。

函数接口定义:
```C++
void swap(int *p1,int *p2);
void exchange(int *q1,int *q2,int *q3);
//其中 函数swap交换p1和p2指向的数据。函数exchange让指针q1指向最小值，q3指向最大值，q2指向中间值。
```
裁判测试程序样例:
```C++
#include <stdio.h>
void swap(int *p1,int *p2);
void exchange(int *q1,int *q2,int *q3);
int  main()
{ int a,b,c,*p1,*p2,*p3;
  scanf("%d%d%d",&a,&b,&c);
  p1=&a; p2=&b; p3=&c;
  exchange(p1,p2,p3);
  printf("%d %d %d\n",a,b,c);
  return 0;
}
/* 请在这里填写答案 */
```
输入样例:
```
7 5 3
```
输出样例:
```
3 5 7
```
### 11.1.2 字符串部分复制
描述:  
本题要求编写函数，将输入字符串t中从第m个字符开始的全部字符复制到字符串s中。

函数接口定义:
```C++
void strmcpy( char *t, int m, char *s );
//函数strmcpy将输入字符串char *t中从第m个字符开始的全部字符复制到字符串char *s中。若m超过输入字符串的长度，则结果字符串应为空串。
```
裁判测试程序样例:
```C++
#include <stdio.h>
#define MAXN 20
void strmcpy( char *t, int m, char *s );
void ReadString( char s[] ); /* 由裁判实现，略去不表 */
int main()
{
    char t[MAXN], s[MAXN];
    int m;
    scanf("%d\n", &m);
    ReadString(t);
    strmcpy( t, m, s );
    printf("%s\n", s);

    return 0;
}
/* 你的代码将被嵌在这里 */
```
输入样例:
```
7
happy new year
```
输出样例:
```
new year
```

### 11.1.3 查找子串
描述:  
本题要求实现一个字符串查找的简单函数。

函数接口定义:
```C++
char *search( char *s, char *t );
//函数search在字符串s中查找子串t，返回子串t在s中的首地址。若未找到，则返回NULL。
```
裁判测试程序样例:
```C++
#include <stdio.h>
#define MAXS 30
char *search(char *s, char *t);
void ReadString( char s[] ); /* 裁判提供，细节不表 */
int main()
{
    char s[MAXS], t[MAXS], *pos;
    ReadString(s);
    ReadString(t);
    pos = search(s, t);
    if ( pos != NULL )
        printf("%d\n", pos - s);
    else
        printf("-1\n");
    return 0;
}
/* 你的代码将被嵌在这里 */
```
输入样例1:
```
The C Programming Language
ram
```    
输出样例1:
```
10
```
输入样例2:
```
The C Programming Language
bored
```
输出样例2:
```
-1
```

### 11.1.4 成绩计算
描述:  
有一个班4个学生，5门课程。①求第一门课程的平均分；②找出有2门(含)以上课程不及格的学生，输出他们的学号（1-4）和全部课程成绩及平均成绩；③找出平均成绩在90分以上或全部课程成绩在85分以上的学生。分别编3个函数实现以上3个要求。

输出数:  
第一行输出第一门课程的平均分；  
接下来输出有2门以上课程不及格的学生，每个学生占3行；  
接下来输出平均成绩在90分以上或全部课程成绩在85分以上的学生，每个学生占3行；  
整数用%4d，实数用%.2f输出。

函数接口定义:
```C++
void average1(int (*p)[5],int n);
void average2(int *p, float *a);
void find1(int (*p)[5],float *a);
void find2(int *p,float *a);
//其中函数 average1 输出第一门课的平均分，average2 计算每个学生的平均分放在数组a[ ]中, find1 输出有两门以上不及格的学生， find2 输出平均分在90分以上或每门课85分以上的学生。
```
裁判测试程序样例:
```C++
#include <stdio.h>
void average1(int (*p)[5],int n);
void average2(int *p, float *a);
void find1(int (*p)[5],float *a);
void find2(int *p,float *a);
int main()
{int score[4][5];
 int i,j;
 float aver[4];
 for (i=0; i<4; i++) //输入4个学生5门课的成绩
  for (j=0; j<5; j++)
   scanf("%d",*(score+i)+j);
 average1(score,4); //计算第一门课的平均分
 average2(*score,aver); //计算每个学生的平均分放在数组aver中
 find1(score,aver); //输出有两门以上不及格的学生
 find2(*score,aver); //输出平均分在90分以上或每门课85分以上的学生
 return 0;
}
/* 你的程序将嵌在这里 */
```
输入样例:
```
96 82 88 99 97
78 89 96 76 65
67 55 87 34 44
87 88 89 87 93
```
输出样例:
```
average of score 1 is 82.00
number 3 failed with 3
his score is  67  55  87  34  44
average score is 57.40
number 1 is very good
his score is  96  82  88  99  97
average score is 92.40
number 4 is very good
his score is  87  88  89  87  93
average score is 88.80
```

### 11.1.5 数据转换
描述:  
输入10个整数，将其中最小的数与第一个数对换，把最大的数与最后一个数对换。要求写3个函数: ①输入10个数；②进行处理；③输出10个数。

函数接口定义:
```C++
void input(int *p);
void proc(int *p);
void output(int *p);
//其中函数 input 实现输入10个整数，函数proc 实现将最小的数与第一个数对换，把最大的数与最后一个数对换，函数output 实现输出10个整数，每个整数用%3d格式输出。
```
裁判测试程序样例:
```C++
#include <stdio.h>
void input(int *p);
void proc(int *p);
void output(int *p);
main()
{int a[10];
 input(a);     //输入10个整数
 proc(a);      //调换
 output(a);    //输出
 return 0;
}
/* 请在这里填写答案 */
```
输入样例:
```
10 9 7 3 2 6 5 4 8 1
```
输出样例:
```
  1  9  7  3  2  6  5  4  8 10
```

## 编程题

### 11.2.1 移位
描述:  
一个数组A中存有N(>0)个整数，在不允许使用另外数组的前提下，将每个整数循环向右移M(≥0)个位置，即将A中的数据由 (A<sub>0</sub>A<sub>1</sub>A<sub>2</sub>...A<sub>N-1</sub>) 变换为 (A<sub>N-M</sub>...A<sub>N-1</sub>A<sub>0</sub>A<sub>1</sub>A<sub>2</sub>...A<sub>N-M-1</sub>)(最后M个数循环移至最前面的M个位置)。本题要求用指针实现。

输入格式:  
第1行输入N(1≤N≤100)和M(≥0)；第2行输入N个整数，之间用空格分隔。

输出格式:  
输出一行，用%3d格式输出N个整数。

输入样例:
```
10 3
1 2 3 4 5 6 7 8 9 10
```
输出样例:
```
  8  9 10  1  2  3  4  5  6  7
```

### 11.2.2 位置调整
描述:  
将一个5×5的矩阵中最大的元素放在中心，4个角分别放4个最小的元素（顺序从左到右，从上到下顺序依次从小到大存放），写一函数实现之。用main函数调用。本题要求用行指针实现。

输入格式:  
输入一共5行，表示一个5×5的矩阵

输出格式:  
输出也是5行，表示一个5×5的矩阵，每个元素用%3d格式输出

输入样例:
```
 6  7 18  9 14
 5 24  2  9 10
22  8  5  1  8
 4 12  5  7  2
13 33  8  7  9
```
输出样例:
```
  1  7 18  9  2
  5 24 14  9 10
 22  8 33  6  8
  9 12  5  7 13
  2  5  8  7  4
```