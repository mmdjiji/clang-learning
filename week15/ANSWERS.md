# week15 - 程序填空题参考答案

1. 1. `j==0 || j==i || j==n-1`
   2. `putchar('*')`
   3. `putchar('\n')`
2. 1. `{m^=n;n^=m;m^=n;}`
   2. `m`
   3. `n`
   4. `r%m`
   5. `s/m`
3. 1. `&score[i][j]`
   2. `maxhang=0,maxlie=0;`
   3. `maxhang=i,maxlie=j,max=score[i][j];`
4. 1. `*hang=0,*lie=0;`
   2. `score[0][0]`
   3. `*hang=i;*lie=j;`
   4. `&score[i][j]`
   5. `score,&maxhang,&maxlie`
5. 1. `score[0]`
   2. `max<score[4*i+j]`
   3. `max=score[4*i+j]`
   4. `score,&maxhang,&maxlie`
6. 1. `*(p[0])`
   2. `max<*(p[i]+j)`
   3. `max=*(p[i]+j)`
   4. `score,&maxhang,&maxlie`
7. 1. `*s == *t && *s!='\0'`
   2. `*s - *t`
   3. `*t!='\0'`
   4. `*s = *t`
   5. `*s='\0'`
   6. `*s!='\0'`
   7. `*t!='\0'`
   8. `*s = *t`
   9. `*s='\0'`
8. 1. `i<len`
   2. `word=0;k=0;`
   3. `word=1;k++;`
9. 1. `string[i]`
   2. `i+1`
   3. `strcmp(string[i],string[j])>0`
   4. `strcpy(t,string[i]);strcpy(string[i],string[j]);strcpy(string[j],t);`
   5. `string[i]`
10. 1. `strcmp(s[i],s[j])>0`
    2. `strcpy(t,s[i]);strcpy(s[i],s[j]);strcpy(s[j],t);`
    3. `string`
11. 1. `strcmp(s+20*i,s+20*j)>0`
    2. `strcpy(t,s+20*i);strcpy(s+20*i,s+20*j);strcpy(s+20*j,t);`
    3. `*string`
12. 1. `strcmp(s[i],s[j])>0`
    2. `strcpy(t,s[i]);strcpy(s[i],s[j]);strcpy(s[j],t);`
    3. `string`
13. 1. `char **s`
    2. `strcmp(s[i],s[j])>0`
    3. `strcpy(t,s[i]);strcpy(s[i],s[j]);strcpy(s[j],t);`
    4. `p[i]=string[i]`
    5. `p`
14. 1. `s[j]>s[j+1]`
    2. `w=s[j];s[j]=s[j+1];s[j+1]=w;`
    3. `&a[i]`
    4. `a`
    5. `a[i]`
15. 1. `int **s`
    2. `*s[j]>*s[j+1]`
    3. `w=s[j];s[j]=s[j+1];s[j+1]=w;`
    4. `p[i]=&a[i]`
    5. `p[i]`
    6. `p`
    7. `*p[i]`