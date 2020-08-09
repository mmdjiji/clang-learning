# week4 - 主观题参考答案

### Answer 1
```C++
#include <stdio.h>
int main(){
  int i, n, left=2, right=1;
  double sum=0.0;
  scanf("%d", &n);
  for(i=0;i<n;i++){
    sum+=(double)left/right;
    left+=right;
    right=left-right;
  }
  printf("%.3lf", sum);
  return 0;
}
```
### Answer 2
```C++
#include <stdio.h>
#include <math.h>
int main(){
  double a, left=0, right=0;
  scanf("%lf", &a);
  left = a;
  if(a>0)
    while(1){
      right = (left+a/left)/2;
      if(fabs(left-right) < 1e-5){
        printf("%lf", right);
        break;
      }
      left = (right+a/right)/2;
      if(fabs(left-right) < 1e-5){
        printf("%lf", left);
        break;
      }
    }
  else if(a==0)
    printf("0");
  else
    printf("Error");
  return 0;
}
```