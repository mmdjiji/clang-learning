# exam2
客观题及程序填空题参考答案在 [ANSWERS.md](ANSWERS.md) 中，编程题参考答案为同目录下的 `.c` 文件。

<!-- TOC -->

- [客观题](#客观题)
- [程序填空题](#程序填空题)
- [编程题](#编程题)
  - [P1 字符处理](#p1-字符处理)
  - [P2 点和正方形的关系](#p2-点和正方形的关系)
  - [P3 最大和值最小](#p3-最大和值最小)

<!-- /TOC -->

## 客观题

1. 以下正确的表达式有__。  
  A. `'G'-'A'`  
  B. `a**b+c`  
  C. `6.3%5`  
  D. `int 6.7`

2. 若d为double型变量,则表达式d=1,d+5,d++的值是__。  
  A. `1`  
  B. `1.0`  
  C. `2`  
  D. `6`

3. 以下代码执行后，t1和t2的值分别是__。  
  A. `14` 和 `15`  
  B. `15` 和 `16`  
  C. `14` 和 `16`  
  D. `15` 和 `17`
```C++
int a=14;
int t1 = a++; 
int t2 = ++a; 
```

4. 写出程序的输出结果__.  
  A. `1`  
  B. `0`  
  C. `5`  
  D. `10`
```C++
int i,j,k;
i=5; j=10; k=1;
printf("%d", k > i < j);
```


## 程序填空题
* 给定 `char s;` ，填写下列条件的表达式
1. s是大写英文字母；
2. s不是小写英文字母；
3. s是数字字符；
4. s是英文字母。

## 编程题

### P1 字符处理
描述:  
从键盘输入一个字母字符，输出其前后相连的3个字符。题目保证不输入第一个或最后一个英文字母

输入格式:  
输入1个字符

输出格式:  
输出3个字符。

输入样例:
```
B
```
输出样例:
```
ABC
```
### P2 点和正方形的关系
描述:  
有一个正方形，四个角的坐标（x,y)分别是（2，-2），（2，2），（-2，-2），（-2，2），x是横轴，y是纵轴。写一个程序，判断一个给定的点是否在这个正方形内（包括正方形边界）。

输入格式:  
输入一行，包括两个整数x、y，以一个空格分开，表示坐标(x,y)。

输出格式:  
输出一行，如果点在正方形内，则输出yes，否则输出no。

输入样例:
```
1 1
```
输出样例:
```
yes
```
### P3 最大和值最小
描述:  
有N (1 ≤ N ≤ 100,000)个整数，需要把他们分成M (1 ≤ M ≤ N)个小组，每个小组包含一个或多个连续的整数（按输入顺序，不是按大小顺序），每个小组的整数相加都有一个和值，请问小组和的最大值最小是多少？
例如，N=7，M=5，7个整数依次是100、400、300、100、500、101、400
一种分组办法是{100}，{400，300}，{100}，{500}，{101，400}，和的最大值是700
和的最大值最小的分组是{100，400}，{300，100}，{500}，{101}，{400}

输入格式:  
第一行包含两个整数N,M，用单个空格隔开。 接下来N行，每行包含一个1到10000之间的整数。

输出格式:  
在一行中输出一个整数，即和最大值的最小值。

输入样例:
```
7 5
100
400
300
100
500
101
400
```
输出样例:
```
500
```