# week2 - 主观题参考答案

## Answer 1
```C++
#include <stdio.h>
int main(){
  int n, a, b;
  scanf("%d", &n);
  a = n/1000%10*10+n/100%10;
  b = n/10%10*10+n%10;
  if(b != 0)
    printf("a=%d,b=%d\na+b=%d\na-b=%d\na*b=%d\na/b=%.2lf\na%%b=%d", a, b, a+b, a-b, a*b, (double)a/b, a%b);
  else
    printf("Error");
  return 0;
}
```
## Answer 2
```C++
#include <stdio.h>
int main(){
  int n;
  scanf("%d", &n);
  if(n%3 == 0 && n%2 == 0)
    printf("yes");
  else
    printf("no");
  return 0;
}
```