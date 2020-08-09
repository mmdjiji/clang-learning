# week10 - 主观题参考答案

### Answer 1
```C++
#include <stdio.h>
int qshu(int n, int k){
	while(--k>0) n/=10;
	return n%10;
}
int main(){
	printf("%d",qshu(12345, 2));
	return 0;
}
```

### Answer 2
```C++
#include <stdio.h>
const int MAX_ARRAY_LEN = 10;
void faver_min(int a[], int *aver, int *min){
	int i, tmp=a[0], sum=a[0];
	for(i=1;i<MAX_ARRAY_LEN;i++){
		if(a[i]<tmp) tmp=a[i];
		sum += a[i];
	}
	*aver = sum/MAX_ARRAY_LEN;
	*min = tmp;
}
int main(){
	int arr[] = {6,1,2,3,4,5,6,7,8,9};
	int average,minimum;
	faver_min(arr, &average, &minimum);
	printf("average=%d, minimum=%d",average,minimum);
	return 0;
}
```