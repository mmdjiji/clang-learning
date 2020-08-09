#include <stdio.h>
int main(){
	int yyyy, mm, dd;
	scanf("%d/%d/%d", &yyyy, &mm, &dd);
	if(mm == 2){ //28 or 29
		if(yyyy%400==0 || (yyyy%4==0 && yyyy%100!=0)){ //29
			if(dd == 29){
				dd = 1;
				mm++;
			}else{
				dd++;
			}
		}else{ //28
			if(dd == 28){
				dd = 1;
				mm++;
			}else{
				dd++;
			}
		}
	}else if(mm == 1 || mm== 3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12){ //31
		if(dd == 31 && mm == 12){
			yyyy++;
			mm = 1;
			dd = 1;
		}else if(dd ==31){
			dd = 1;
			mm++;
		}else{
			dd++;
		}
	}else{ //30
		if(dd == 30){
			dd = 1;
			mm++;
		}
	}
	printf("%d/%d/%d", yyyy, mm, dd);
	return 0;
}
