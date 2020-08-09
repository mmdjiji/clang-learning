# exam6 - 客观题、填空题、程序填空题及函数题参考答案

## 客观题  
1. C
2. D
3. C
4. B
5. A
6. C
7. A
8. D
9. D
10. A
11. D
12. C
13. B
14. A
15. B
16. D
17. A
18. C
19. A
20. B

## 填空题
1. `1`
2. `8`
3. `10,64`
4. `25`
5. `10532`
6. `1212`
7. `youme`
8. `22`
9. `1100`
10. `5`

## 程序填空题
1. 1. `n/10%10`
   2. `n%10`
   3. `i*i*i+j*j*j+k*k*k == n`
2. 1. `for(len=0;s[len]!='\0';len++)`
   2. `len/2`
   3. `s[i]=s[len-i-1]; s[len-i-1]=t;`
3. 1. `a>0 && b>0 && c>0 && a+b>c && a+c>b && b+c>a`
   2. `a==b && b==c`
   3. `a*a+b*b == c*c || a*a+c*c==b*b || b*b+c*c==a*a`
4. 1. `num<k && p!=NULL`
   2. `p=p->next`
   3. `p->c`
5. 1. `a[i].name, &a[i].bir.year, &a[i].bir.month, &a[i].bir.day, a[i].telephone`
   2. `t=a[i]`
   3. `t.name`

## 函数题
```C++
int bch(char *p){
	int sum=0;
	while(*p!='\0'){
		if(*p>='A' && *p<='Z')sum++;
		p++;
	}
	return sum;
}
```