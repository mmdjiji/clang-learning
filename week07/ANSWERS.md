# week7 - 主观题及程序填空题参考答案

## 主观题
### Answer 1
```C++
#include <stdio.h>
#include <string.h>
int palindrome(char *s){
	int i,len=strlen(s);
	for(i=0;i<len/2;i++)
		if(s[i] != s[len-i-1])
			return 0;
	return 1;
}
int main(){
	char str[100];
	scanf("%s",str);
	if(palindrome(str))
		printf("palindrome");
	else
		printf("not palindrome");
	return 0;
}
```
### Answer 2
```C++
#include <stdio.h>
#include <string.h>
#define ARR_LEN 6
int arr_equals(int *p, int *q){
	int i;
	for(i=0;i<ARR_LEN;i++)
		if(*(p++) != *(q++))
			return 0;
	return 1;
}
int main(){
	int i,arr1[ARR_LEN],arr2[ARR_LEN];
	for(i=0;i<ARR_LEN;i++) scanf("%d",&arr1[i]);
	for(i=0;i<ARR_LEN;i++) scanf("%d",&arr2[i]);
	if(arr_equals(arr1,arr2))
		printf("equals");
	else
		printf("not equals");
	return 0;
}
```

## 程序填空题
1. 1. `&a[k]`
   2. `N`
   3. `N-j-1`
   4. `a[k+1]<a[k]`
   5. `t=a[k];a[k]=a[k+1];a[k+1]=t;`
   6. `a[N-1]`
2. 1. `&a[k]`
   2. `N`
   3. `t=a[k=j]`
   4. `a[s]<t`
   5. `t=a[k=s]`
   6. `t=a[k];a[k]=a[j];a[j]=t;`
   7. `a[N-1]`