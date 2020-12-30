# week3 - 主观题参考答案

### Answer 1
```C++
#include <stdio.h>
int main(){
  char a, grade=-1;
  scanf("%c", &a);
  if(a>='a' && a<= 'e') a-=32;
  switch(a){
    case 'A': grade = 90; break;
    case 'B': grade = 80; break;
    case 'C': grade = 70; break;
    case 'D': grade = 60; break;
    case 'E': grade = 59; break;
  }
  if(grade != -1)
    printf("%d",grade);
  else
    printf("Data Error!");
  return 0;
} 
```
### Answer 2
```C++
#include <stdio.h>
typedef struct{int year,month,day;} Date;
Date *minimum, d1, d2;
void min(int ai,int bi) {minimum = (ai>bi)?&d2:&d1;}
int main(){
  scanf("%d/%d/%d%d/%d/%d",&d1.year,&d1.month,&d1.day,&d2.year,&d2.month,&d2.day);
  if(d1.year != d2.year) min(d1.year,d2.year);
  else if(d1.month != d2.month) min(d1.month,d2.month);
  else min(d1.day,d2.day);
  printf("%d/%02d/%02d",(*minimum).year,(*minimum).month,(*minimum).day);
  return 0;
} 
```