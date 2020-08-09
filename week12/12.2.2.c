#include <stdio.h>
#define cycle(x,y) for(x=0;x<y;x++)
int get_aver(int *p,int n){
	int i,sum=0,max,min,i_max,i_min;
	max=min=*p;i_max=i_min=0;
	cycle(i,n) {
		if(p[i]>max){max=i[p];i_max=i;}
		if(i[p]<min){min=p[i];i_min=i;}
	}
	i_max[p]=i_min[p]=0;
	cycle(i,n) sum+=i[p];
	return sum;
}
int main(){
	int i,j,m,n,arr[10][10],aver[10],max,i_max,rank[10]={0},counts=0;
	scanf("%d %d",&m,&n);
	cycle(i,m) {
		cycle(j,n) scanf("%d",j+i[arr]);
		aver[i] = get_aver(i[arr],n);
	}
	cycle(i,m) {
		max=aver[0];i_max=0;
		cycle(j,m)
			if(aver[j]>max){max=aver[j];i_max=j;}
		i_max[aver]=0;
		printf("%3d",i_max+1);
	}
	return 0;
}
