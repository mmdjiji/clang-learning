# exam5 - 客观题、填空题、程序填空题及函数题参考答案

## 客观题  
1. C
2. D
3. C
4. B
5. A
6. D
7. D
8. B
9. A
10. A
11. B
12. D
13. B
14. D
15. A
16. C
17. C
18. B
19. A
20. A

## 填空题
1. `18`
2. `0650`
3. `CDGHKL`
4. `v1=5,v2=8,v3=6,v4=1`
5. `7,11`
6. `CDE`
7. `  3 56  6  5  8 12 14 32  2 24 19  7`
8. `135`
9. `15,31`
10. `7`

## 程序填空题
1. 1. `a[i][0] = a[i][i] = 1;`
   2. `a[i-1][j]+a[i-1][j-1]`
   3. `j<=i`
2. 1. `s3[i] = s1[i]`
   2. `s2[j] !='\0'`
   3. `s3[i++] = s2[j]`
   4. `s3[i] = '\0'`
3. 1. `return y`
   2. `gongyinzi(y,x%y)`
4. 1. `i=-1`
   2. `score[k]/10`
   3. `count++`
5. 1. `p>=0;p--`
   2. `continue`
   3. `for(p++;p<=a+k;p++)*p+=x,x=*p-x,*p-=x;*p = x`

## 函数题
```C++
void find(int a[][N],int x){
	int i,j,classes[N]={0};
	for(i=0;i<N;i++)
		for(j=0;j<M;j++)
			if(a[j][i]<x){
				classes[i] = 1;
				break;
			}
	for(i=0;i<N;i++)
		if(!classes[i])printf("%d\n",i+1);
}
```