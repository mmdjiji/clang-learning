# week5 - 主观题参考答案

### Answer 1
```C++
#include <stdio.h>
#include <string.h>
#define MAXLEN 100
int main(){
  int i,j,sum=0;
  char str[MAXLEN+1];
  for(i=0;i<5;i++){
    scanf("%s",str);
    for(j=0;j<strlen(str);j++)
      if(str[j] == 'a' || str[j] == 'e' || str[j] == 'i' || str[j] == 'o' || str[j] == 'u')
        sum++;
  }
  printf("%d",sum);
  return 0;
}
```
### Answer 2
```C++
#include <stdio.h>
int main(){
  int n,i,j;
  char chr,tmp; 
  scanf("%d%c",&n,&chr);
  for(i=1;i<=n;i++){
    for(j=0;j<i;j++){
      tmp = chr-j;
      while(tmp < 'A') tmp += 26;
      printf("%c",tmp);
    }
    printf("\n");
  }
  return 0;
}
```