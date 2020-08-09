# week13
程序填空题参考答案在 [ANSWERS.md](ANSWERS.md) 中，函数题及编程题参考答案为同目录下的 `.c` 文件。

<!-- TOC -->

- [程序填空题](#程序填空题)
  - [Problem 1](#problem-1)
  - [Problem 2](#problem-2)
- [函数题](#函数题)
  - [13.1.1 日子计算](#1311-日子计算)
- [编程题](#编程题)
  - [13.2.1 成绩计算1](#1321-成绩计算1)
  - [13.2.2 成绩计算2](#1322-成绩计算2)
  - [13.2.3 通讯录排序](#1323-通讯录排序)

<!-- /TOC -->

## 程序填空题

### Problem 1
本题目要求统计候选人的得票数。设有3个候选人 `zhang, li, wang` ，10个选民，选民每次输入一个得票的候选人的名字，若选民输错候选人姓名，则按废票处理。选民投票结束后程序自动显示各候选人的得票结果和废票信息。要求用结构体数组 `candidate` 表示3个候选人的姓名和得票结果。
```C++
#include<stdio.h>
#include<string.h>
#define NUM_ELECTORATE 10
#define NUM_CANDIDATE 3
struct candidate 
{ char name[20]; 
  int count;
}c[3] = {"li",0, "zhang",0, "wang",0};
int main()
{  int i, j, flag , wrong = 0;   
   char name[20];
   for (i=0; i<NUM_ELECTORATE; i++)
    {   scanf("%s", name);  
        flag = 1;
        for (j=0; j<NUM_CANDIDATE; j++)
            if (____1____) 
                { ____2____;   flag = 0;  }
        if (flag)
            wrong++; /* 废票计数 */
    }
    printf("Election results:\n");
    for (i=0; i<NUM_CANDIDATE; i++)
       printf("%s:%d\n", ____3____);
    printf("Wrong election:%d\n", wrong);
   return 0;
}
```

### Problem 2
本题目要求用指向一维数组的指针变量即二维数组的行指针作函数参数，编程计算任意m×n阶矩阵的转置矩阵。
```C++
#include<stdio.h>
void Transpose(int (*a)[4], int (*at)[3], int row, int col)
{ int i, j;
for (i=0; i<row;i++)
  for (j=0; j<col; j++)
     ____1____;
}
void InputMatrix(int (*s)[4], int row, int col)   //输入矩阵元素
{ int i, j;
  for (i=0; i<row; i++)
    for (j=0; j<col; j++)
     scanf("%d", ____2____ );
}
void PrintMatrix(int (*s)[3], int row, int col)  //输出矩阵元素
{ int i, j;
  for (i= 0; i<row; i++)
    { for (j=0; j<col; j++)
        printf("%3d",  ____3____); 
      printf("\n");
    }
}
int main()
{  int in[3][4],out[4][3];
   InputMatrix(in, 3, 4);
   Transpose(in, out, 3,4);
   PrintMatrix(out,4,3);
   return 0;
}
```

## 函数题

### 13.1.1 日子计算
描述:  
写一个函数days, 用结构体变量（包括年、月、日）做参数，计算该日在本年中是第几天？主函数将年、月、日传递给days函数，计算后将日子数传回主函数输出。

函数接口定义:
```C++
int count(struct oneday one);
//其中 one 是用户传入的参数。
```
裁判测试程序样例:
```C++
#include<stdio.h>
struct oneday
{int day,month,year;};
main()
{struct oneday day1;
 int allday;
scanf("%d,%d,%d",&day1.year,&day1.month,&day1.day);
 printf("%d\n",count(day1));
}
/* 你的程序将被嵌在这里*/
```
输入样例:
```
2008,3,2 
```
输出样例:
```
62
```

## 编程题

### 13.2.1 成绩计算1
描述:  
有10个学生，每个学生的数据包括学号、姓名、3门课程的成绩，从键盘输入10个学生数据，要求输出3门课程总平均成绩，以及最高分的学生的数据（包括学号、姓名、3门课程成绩、平均分数）。

输入格式:  
输入共10行，每行依次输入每个学生数据，包括学号、姓名、3门课程的成绩。

输出格式:  
输出共三行，第一行是3门课的总平均分（格式为average score is %.2f）  
第2至4行是最高分的学生的数据  
（格式为 the max score is:\n %5d%10s后面三个%4d \nthe max average is %.2f\n）

输入样例:
```
101 ejhgrje 67 78 96
104 jghjg 65 78 98
107 hkhjk 77 88 99
102 jghgui 87 88 89
103 57jhg 76 95 67
105 gutiutyi 77 98 90
109 fyyfryu 88 99 98
106 jhtguytiu 89 74 62
108 iiuyiw 73 82 63
110 yieiur 68 83 90
```
输出样例:
```
average score is 82.73
the max score is:
  109   fyyfryu  88  99  98
the max average is 95.00
```

### 13.2.2 成绩计算2
描述:  
有10个学生，每个学生的数据包括学号、姓名、性别，若为男生，还有1500米成绩、标枪成绩、跳高成绩和100米成绩，若为女生，还有800米成绩、立定跳远成绩和100米成绩。从键盘输入10个学生数据，要求输出每个学生的平均成绩（包括学号、姓名、性别，平均成绩）。

输入格式:  
输入共10行，表示10个学生数据，性别分别为m（男生）和f（女生）。

输出格式:  
输出也是10行，输出每个学生的学号、姓名、性别，平均成绩 (格式：%5d%10s%3c%4d)。

输入样例:
```
101 zhsngsan m 67 78 96 65
104 lisi f 65 78 98
107 dong m 77 88 99 78
102 xixi m 87 88 89 77
103 kaikai f 76 95 67
105 ting m 77 98 90 87 
109 youxi f 88 99 98
106 ruihgf f 89 74 62
108 iiuyiw m 73 82 63 78
110 yieiur f 68 83 90
```
输出样例:
```
  101  zhsngsan  m  76
  104      lisi  f  80
  107      dong  m  85
  102      xixi  m  85
  103    kaikai  f  79
  105      ting  m  88
  109     youxi  f  95
  106    ruihgf  f  75
  108    iiuyiw  m  74
  110    yieiur  f  80
```

### 13.2.3 通讯录排序
描述:  
输入n个朋友的信息，包括姓名、生日、电话号码，本题要求编写程序，按照年龄从大到小的顺序依次输出通讯录。题目保证所有人的生日均不相同。

输入格式:  
输入第一行给出正整数n（<10）。随后n行，每行按照“姓名 生日 电话号码”的格式给出一位朋友的信息，其中“姓名”是长度不超过10的英文字母组成的字符串，“生日”是yyyymmdd格式的日期，“电话号码”是不超过17位的数字及+、-组成的字符串。

输出格式:  
按照年龄从大到小输出朋友的信息，格式同输出。

输入样例:
```
3
zhang 19850403 13912345678
wang 19821020 +86-0571-88018448
qian 19840619 13609876543
```
输出样例:
```
wang 19821020 +86-0571-88018448
qian 19840619 13609876543
zhang 19850403 13912345678
```