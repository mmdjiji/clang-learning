# week8 - 主观题及程序填空题参考答案

## 主观题
### Answer 1
```C++
#include <stdio.h>
void swap(char *p, char *q) {if(*p!=*q){*p^=*q;*q^=*p;*p^=*q;}}
int main(){
	int i, j;
	char arr[10], *tmp;
	for(i=0;i<10;i++)
		scanf("%c",&arr[i]);
	for(i=0;i<10;i++){
		tmp = arr+i;
		for(j=i;j<10;j++)
			if(*(arr+j) < *tmp) tmp=arr+j;
		swap(arr+i, tmp);
	}
	for(i=0;i<10;i++)
		printf("%c",arr[i]);
	return 0;
}
```

### Answer 2
```C++
#include <stdio.h>
void swap(char *p, char *q) {if(*p!=*q){*p^=*q;*q^=*p;*p^=*q;}}
int main(){
    char str[] = "123456";
    char *l = str, *r = str;
	while(*(++r+1) != '\0');
	if(*r != '\0')
	for(; l <= r; l++,r--)
	    swap(l,r);
    printf("%s",str);
    return 0;
}
```

## 程序填空题
1. 1. `&a[i]`
   2. `pos=-1`
   3. `pos=i`
2. 1. `&a[i]`
   2. `left=0;right=9;`
   3. `left<=right`
   4. `left=mid+1`
   5. `right=mid-1`
   6. `a[mid]==n`
3. 1. `name[i]`
   2. `find=0`
   3. `strcmp(name[i],one) == 0`
   4. `find`