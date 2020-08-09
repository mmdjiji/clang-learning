#include <stdio.h>
int main(){
	int a[100000]={0};
	int i,down=0,up,tmp=0,counts=0,n,m,todo;
	scanf("%d %d",&n,&m);
	scanf("%d",&a[i]);
	up = down = a[i];
	for(i=1;i<n;i++){
		scanf("%d",&a[i]);
		if(a[i]>up)up=a[i];
		if(a[i]<down)down=a[i];
	}
	if(m == n){
		printf("%d",up);
	} else{
		up *= n;
		while(up - down > 1){
			todo = (up+down)/2;
			tmp=0;counts=0;
			for(i=0;i<n-1;i++){
				if(a[i] >= todo){
					if(tmp == 0)
						counts++;
					else{
						counts+=2;
						tmp=0;
					}
				}else if(tmp + a[i] < todo){
					tmp += a[i];
				}else if(a[i]+a[i+1] < todo){
					counts++;
					tmp = a[i];
				}else{
					counts+=2;
					tmp=0;
				}
			}
			if(tmp == 0){
				counts++;
			}else if(a[n-1] >= todo)
				counts+=2;
			else if(tmp + a[n-1] < todo)
				counts++;
			else
				counts+=2;
			if(counts<=m)
				up = todo;
			else
				down = todo;
		}
		printf("%d",(up+down)/2);
	}
	return 0;
}
