# week6 - 主观题参考答案

### Answer 1
```C++
#include <stdio.h>
int main(){
	int arr[10],todo,i,flag=0;
	for(i=0;i<10;i++) scanf("%d",&arr[i]);
	scanf("%d",&todo);
	for(i=0;i<10;i++)
		if(arr[i] == todo && (flag=1))
			printf("%d\n",i+1);
	if(!flag) printf("0\n");
	return 0;
}
```

### Answer 2
```C++
#include <stdio.h>
typedef int ElementType;
typedef struct matrix{
	int len_x,len_y;
	ElementType element[10][10];
}matrix;
matrix matmul(matrix m, matrix n){
	int i,j,k;
	matrix retval;
	retval.len_x=retval.len_y=0;
	if(m.len_y != n.len_x)
		return retval;
	retval.len_x = m.len_x;
	retval.len_y = n.len_y;
	for(i=0;i<retval.len_x;i++){
		for(j=0;j<retval.len_y;j++){
			retval.element[i][j]=0;
			for(k=0;k<m.len_y;k++)
				retval.element[i][j] += m.element[i][k] * n.element[k][j];
		}
	}
	return retval;
}
void draw(matrix mat){
	int i,j;
	for(i=0;i<mat.len_x;i++){
		for(j=0;j<mat.len_y;j++)
			printf("%d\t",mat.element[i][j]);
		printf("\n");
	}
}
int main(){
	int i,j;
	matrix A,B,C;
	A.len_x = 5; A.len_y = 6; B.len_x = 6; B.len_y = 4;
	for(i=0;i<A.len_x;i++)
		for(j=0;j<A.len_y;j++)
			scanf("%d",&A.element[i][j]);
	for(i=0;i<B.len_x;i++)
		for(j=0;j<B.len_y;j++)
			scanf("%d",&B.element[i][j]);
	C = matmul(A,B);
	draw(C);
	return 0;
}
```
补充一组测试数据
```
A (5*6)
4 6 4 1 3 5
1 6 4 3 2 0
8 9 3 1 3 4
5 6 3 4 6 9
4 3 6 4 2 6
B (6*4)
5 9 3 4
1 6 4 6
9 1 3 4
4 1 2 3
7 1 3 4
1 3 6 4
A * B (5*4)
92	95	89	103
73	54	51	73
105	145	104	129
125	121	128	140
113	84	92	102
```