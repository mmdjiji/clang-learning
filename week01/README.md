# week1
主观题参考答案在 [ANSWERS.md](ANSWERS.md) 中，编程题参考答案为同目录下的 `.c` 文件。

<!-- TOC -->

- [主观题](#主观题)
  - [Problem 1](#problem-1)
  - [Problem 2](#problem-2)
  - [Problem 3](#problem-3)
- [编程题](#编程题)
  - [1.1 找出两个数中的大者](#11-找出两个数中的大者)
  - [1.2 Hello World!](#12-hello-world)
  - [1.3 输出两行短句](#13-输出两行短句)
  - [1.4 简单最值](#14-简单最值)

<!-- /TOC -->

## 主观题

### Problem 1
如果用16位二进制数表示以下数据，请写出内存中数据的二进制形式。

示例:

正整数 `4`:  `00000000 00000100` ; 负整数 `-1`:  `11111111 11111111`

请写出: 正整数 `32765` , 负整数 `-7` , 无符号整数 `65531` .

### Problem 2
写出以下三个字符的内存存储二进制形式: `a` , 空格 , `8` .

示例:  
字符A的内存存储二进制形式是 `01000001` .

### Problem 3
给出下列程序的执行结果  
```C++
main()
{ int i,j,k;
k=10;
i=k++;  j=++i;
printf("%d,%d\n",i,j);
printf("%d\n",k);
i=(k=6,k*5,k+8);
j=k=6,k*5,k+8;
printf("%d,%d\n",i,j);
return 0;
}
```

## 编程题

### 1.1 找出两个数中的大者
描述:  
输入两个整数，输出这两个数中的大者。

输入格式:  
用逗号格开的两个整数

输出格式:  
max=较大的整数

输入样例:
```
5,6
```
输出样例:
```
max=6
```

### 1.2 Hello World!
描述:  
本题要求编写程序，输出一个短句“Hello World!”。

输入格式:  
本题目没有输入。

输出格式:  
在一行中输出短句“Hello World!”。  

### 1.3 输出两行短句
描述:  
本题要求编写程序，在屏幕上显示两个短句“Programming is fun.”和“And Programming in C is even more fun!”，每行显示一句。

输入格式:  
本题目没有输入。

输出格式:  
输出两个短句，每行显示一句。注意除了每行的回车不能有任何多余字符。

输出样例:
```
Programming is fun.
And Programming in C is even more fun!
```

### 1.4 简单最值
描述:  
求3个整数中的最大者。

输入格式:  
输入3个整数a,b,c。

输出格式:  
输出内容为a,b,c中的最大者。

输入样例:
```
1 2 3
```
输出样例:
```
3
```