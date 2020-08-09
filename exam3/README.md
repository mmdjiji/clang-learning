# exam3

客观题及程序填空题参考答案在 [ANSWERS.md](ANSWERS.md) 中，本次考试仅有客观题。

## 客观题

1. 读程序：写出下面程序段的输出结果
```C++
main()  
  {  int i;  
    for(i=0;i<6;i++)  
    switch(i)  
    { case 1: printf("%d",i);  
      case 2: printf("%d",i);  
      default: printf("%d",i);  
    }  
  }  
```

2. 读程序：以下程序运行时，如果从键盘输入`1234`，则输出结果为
```C++
main()
{ int n1,n2;
  scanf("%d",&n2);
  while(n2!=0)
    {n1=n2%10;
    n2=n2/10;
    printf("%d", n1);
    }
}
```

3. 读程序：定义`int a=9`，下列循环的输出结果是
```C++
while(a>7)
{a--;printf("%d",a);}
```

4. 读程序：下面程序的输出结果是
```C++
main ()
{int x=100,a=10,b=20,ok1=5,ok2=0;
if (a<b)
    if (b!=15)
      if (ok1!=5)
          x=1;
else
        if (ok2) x=10;
x=-1;
printf("%d\n",x);
}
```

5. 读程序：写出下面程序的输出结果
```C++
main()
{ int x=2;
  while(x--);
  printf("%d",x);
}
```

6. 读程序：下面的程序段运行后x的值是
```C++
a=b=c=0; x=35;
if (!a) x--;
else if (b);
if (!c) x=4;
else x=5;
```

7. 读程序：下面程序的输出结果是
```C++
main() 
{int i;
  for (i=0;i<8;i++);
      printf ("%d",i);
}
```

8. 读程序：下面程序段的运行结果为
```C++
for (i=1; ++i<6;);
printf("%d\n",i);
```

9. 读程序：在执行以下程序时，如果从键盘上输入`ABCdef`后回车，则输出
```C++
main()
{char ch;
while((ch=getchar())!='\n')
  { if (ch>='A' && ch<='Z')  ch=ch+32;
    if (ch>='a' && ch<='z')  ch=ch-32;
    printf("%c",ch);
  }
  printf("\n");
}
```

10. 读程序：输入`2 3`，以下程序的输出结果是
```C++
main()
{ int s,t,a,b;
scanf("%d%d",&a,&b);
s=1,t=1;
if (a>0)  s=s+1;
if (a>b)  t=s+t;
else   if (a==b)  t=5;
            else  t=2*s;
printf("t=%d\n",t);
}
```