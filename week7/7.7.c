#include <stdio.h>
#include <math.h>
int main(){
	char A[9],B[9],C[9],D[9];
	int i,ad1=0,ad2=0,ad3=0,ad4=0;
	scanf("%8s%8s%8s%8s",A,B,C,D);
	for(i=0;i<8;i++){
		if(A[i]=='1')ad1+=(int)pow(2,7-i);
		if(B[i]=='1')ad2+=(int)pow(2,7-i);
		if(C[i]=='1')ad3+=(int)pow(2,7-i);
		if(D[i]=='1')ad4+=(int)pow(2,7-i);
	}
	printf("%d.%d.%d.%d",ad1,ad2,ad3,ad4);
	return 0;
}
