#ifndef _OPERATE_C_
#define _OPERATE_C_

#include "userlib.c"
#include "menu.c"

#ifdef __cpluscplus
extern "C" {
#endif

//Display user with a Console_GUI and have many functions
int disUser(USER *src,int num){
	char path[30],buffer[30];
	FILE *fp;
	int success=0;
	int i, j=0, key, pages = num / PAGE_SIZE + 1;
	if(num != 0){
		zoomIn();
		for(i=0;i<pages;i++){
			system("cls");
			if(current->back != NULL)
				printf("%s-",current->back->text);
			printf("%s: ",current->text);
			printf("按[TAB]键翻页，按[Enter]键返回菜单，按[Space]键导出到文件\n");
			showHeader();
			
			listUser(src,PAGE_SIZE*i,PAGE_SIZE,num);
			if(i==pages-1)printf("到此为止辣 :)\n");
			while(key = _getch()){
				if(key == 9){
					break;
				}else if(key == 13){
					zoomOut();
					return 1;
				}else if(key == 32){
					system("cls");
					zoomOut();
					printf("请输入保存的路径: ");
					scanf("%s",path);
					fp = fopen(path,"w");
					fshowHeader(fp);
					if(fp!=NULL){
						for(j=0;j<num;j++)
							success += fprintUser(fp,src+j);
						
						sprintf(buffer,"共导出%d位用户",success);
						MessageBox(0,buffer,TITLE,MB_OK);
						fclose(fp);
					}else{
						MessageBox(0,"导出失败: 文件无法创建",TITLE,MB_OK);
					}
					return 1;
				}
			}
		}
		zoomOut();
	}else{
		MessageBox(0,"没有用户可被列出",TITLE,MB_OK);
	}
	return 1;
}

//**Sorting Algorithms for all kinds of way (use Bubble Sort)**

int sortByTrainNum(USER *src, int num){
	int i,j;
	for(i=0;i<num;i++){
		for(j=0;j<num-i-1;j++){
			if(strncmp(src[j+1].trainNum,src[j].trainNum,TRAINNUM_SIZE) < 0){
				swap(&src[j+1],&src[j]);
			}
		}
	}
	return 1;
}

int sortByStation(USER *src, int num){
	int i,j;
	for(i=0;i<num;i++){
		for(j=0;j<num-i-1;j++){
			if(strncmp(src[j+1].depStation,src[j].depStation,TRAINNUM_SIZE) < 0){
				swap(&src[j+1],&src[j]);
			}else if(strncmp(src[j+1].depStation,src[j].depStation,TRAINNUM_SIZE) == 0){
				if(strncmp(src[j+1].dstStation,src[j].dstStation,TRAINNUM_SIZE) < 0)
					swap(&src[j+1],&src[j]);
			}
		}
	}
	return 1;
}

int sortByName(USER *src,int num){
	int i,j;
	for(i=0;i<num;i++){
		for(j=0;j<num-i-1;j++){
			if(strncmp(src[j+1].name,src[j].name,TRAINNUM_SIZE) < 0){
				swap(&src[j+1],&src[j]);
			}
		}
	}
	return 1;
}

int displayUserWithoutSort(){
	return disUser(usr,user_amount);
}

int displayUserSortByTrainNum(){
	return sortByTrainNum(usr_sort,user_amount) && disUser(usr_sort,user_amount);
}

int displayUserSortByStation(){
	return sortByStation(usr_sort,user_amount) && disUser(usr_sort,user_amount);
}

int displayUserSortByName(){
	return sortByName(usr_sort,user_amount) && disUser(usr_sort,user_amount);
}

//**Add user**

int addUserByInput(){
	USER src;
	int year,month,day,hour,minute,second;
	
	zoomIn();
	system("cls"); 
	printf("%s: ",current->text);
	printf("请按提示输入新用户的信息\n");
	
	printf("姓名:");
	scanf("%s",src.name);
	
	printf("证件类型:");
	scanf("%s",src.idType);
	
	printf("证件号码:");
	scanf("%s",src.idCard);
	
	printf("车次:");
	scanf("%s",src.trainNum);
	
	printf("始发地:");
	scanf("%s",src.depStation);
	
	printf("目的地:");
	scanf("%s",src.dstStation);
	
	printf("出发时间(格式为2020-01-01 08:00:30):");
	scanf("%d-%d-%d %d:%d:%d",&year,&month,&day,&hour,&minute,&second);
	src.depTime=setTime(year,month,day,hour,minute,second);
	
	printf("预计到达时间(格式同上):");
	scanf("%d-%d-%d %d:%d:%d",&year,&month,&day,&hour,&minute,&second);
	src.dstTime=setTime(year,month,day,hour,minute,second);
	
	printf("票价:");
	scanf("%lf",&src.price);
	
	printf("手机号:");
	scanf("%lld",&src.phonenum);
	
	printf("添加中... ;>");
	
	if(addUser(src)){
		MessageBox(0,"添加成功",TITLE,MB_OK);
	}else{
		MessageBox(0,"添加失败",TITLE,MB_OK);
	}
	zoomOut();
	
	initAllUser();
	return 1;
}

int addUserByFile(){
	int key,success=0;
	char path[PATH_SIZE];
	char buffer[30];
	FILE *fp;
	USER src;
	int year,month,day,hour,minute,second;
	
	system("cls");
	printf("%s: ",current->text);
	printf("\n请输入文件路径:");
	scanf("%s",path);
	
	fp = fopen(path,"r");
	if(fp!=NULL){
		while(!_eof_(fp)){
			fscanf(fp,"%s %s %s %s %s %s",src.name,src.idType,src.idCard,src.trainNum,src.depStation,src.dstStation);
			fscanf(fp,"%d-%d-%d %d:%d:%d",&year,&month,&day,&hour,&minute,&second);
			src.depTime=setTime(year,month,day,hour,minute,second);
			fscanf(fp,"%d-%d-%d %d:%d:%d",&year,&month,&day,&hour,&minute,&second);
			src.dstTime=setTime(year,month,day,hour,minute,second);
			fscanf(fp,"%lf %lld",&src.price,&src.phonenum);
			success += addUser(src);
		}
		initAllUser();
		sprintf(buffer,"共成功添加%d位用户",success);
		MessageBox(0,buffer,TITLE,MB_OK);
		fclose(fp);
	}else{
		MessageBox(0,"添加失败: 文件无法打开",TITLE,MB_OK);
	}
	
	return 1;
}


//**Check user**

int checkUserByIdCard(){
	int i;
	char src[IDCARD_SIZE];
	if(result == NULL)
		result = (USER*)malloc(sizeof(USER)*MALLOC_SIZE);
	system("cls");
	printf("请输入查询的证件号码:");
	scanf("%s",src);
	found = 0;
	
	for(i=0;i<user_amount;i++){
		if(strncmp(usr[i].idCard,src,IDCARD_SIZE) == 0){
			if(found%MALLOC_SIZE == 0)
				result = (USER*)realloc(result,sizeof(USER)*MALLOC_SIZE*(i/MALLOC_SIZE+1));
			result[found++] = usr[i];
		}
	}
	return 1;
}

int checkUserByIdCardArrange0(){
	return checkUserByIdCard() && disUser(result,found);
}

int checkUserByIdCardArrange1(){
	return checkUserByIdCard() && sortByTrainNum(result,found) && disUser(result,found);
}

int checkUserByIdCardArrange2(){
	return checkUserByIdCard() && sortByStation(result,found) && disUser(result,found);
}

int checkUserByIdCardArrange3(){
	return checkUserByIdCard() && sortByName(result,found) && disUser(result,found);
}

int checkUserByName(){
	int i;
	char src[USERNAME_SIZE];
	if(result == NULL)
		result = (USER*)malloc(sizeof(USER)*MALLOC_SIZE);
	system("cls");
	printf("请输入查询的姓名:");
	scanf("%s",src);
	found = 0;
	
	for(i=0;i<user_amount;i++){
		if(strncmp(usr[i].name,src,USERNAME_SIZE) == 0){
			if(found%MALLOC_SIZE == 0)
				result = (USER*)realloc(result,sizeof(USER)*MALLOC_SIZE*(i/MALLOC_SIZE+1));
			result[found++] = usr[i];
		}
	}
	return 1;
}

int checkUserByNameArrange0(){
	return checkUserByName() && disUser(result,found);
}

int checkUserByNameArrange1(){
	return checkUserByName() && sortByTrainNum(result,found) && disUser(result,found);
}

int checkUserByNameArrange2(){
	return checkUserByName() && sortByStation(result,found) && disUser(result,found);
}

int checkUserByNameArrange3(){
	return checkUserByName() && sortByName(result,found) && disUser(result,found);
}

int checkUserByDepStation(){
	int i;
	char src[STATION_SIZE];
	if(result == NULL)
		result = (USER*)malloc(sizeof(USER)*MALLOC_SIZE);
	system("cls");
	printf("请输入查询的起始站:");
	scanf("%s",src);
	found = 0;
	
	for(i=0;i<user_amount;i++){
		if(strncmp(usr[i].depStation,src,STATION_SIZE) == 0){
			if(found%MALLOC_SIZE == 0)
				result = (USER*)realloc(result,sizeof(USER)*MALLOC_SIZE*(i/MALLOC_SIZE+1));
			result[found++] = usr[i];
		}
	}
	return 1;
}

int checkUserByDepStationArrange0(){
	return checkUserByDepStation() && disUser(result,found);
}

int checkUserByDepStationArrange1(){
	return checkUserByDepStation() && sortByTrainNum(result,found) && disUser(result,found);
}

int checkUserByDepStationArrange2(){
	return checkUserByDepStation() && sortByStation(result,found) && disUser(result,found);
}

int checkUserByDepStationArrange3(){
	return checkUserByDepStation() && sortByName(result,found) && disUser(result,found);
}

int checkUserByDstStation(){
	int i;
	char src[STATION_SIZE];
	result = (USER*)malloc(sizeof(USER)*MALLOC_SIZE);
	system("cls");
	printf("请输入查询的终点站:");
	scanf("%s",src);
	found = 0;
	
	for(i=0;i<user_amount;i++){
		if(strncmp(usr[i].dstStation,src,STATION_SIZE) == 0){
			if(found%MALLOC_SIZE == 0)
				result = (USER*)realloc(result,sizeof(USER)*MALLOC_SIZE*(i/MALLOC_SIZE+1));
			result[found++] = usr[i];
		}
	}
	return 1;
}

int checkUserByDstStationArrange0(){
	return checkUserByDstStation() && disUser(result,found);
}

int checkUserByDstStationArrange1(){
	return checkUserByDstStation() && sortByTrainNum(result,found) && disUser(result,found);
}

int checkUserByDstStationArrange2(){
	return checkUserByDstStation() && sortByStation(result,found) && disUser(result,found);
}

int checkUserByDstStationArrange3(){
	return checkUserByDstStation() && sortByName(result,found) && disUser(result,found);
}

int checkUserByDepTime(){
	int i,year,month,day;
	result = (USER*)malloc(sizeof(USER)*MALLOC_SIZE);
	system("cls");
	printf("请输入查询的发车时间(格式2020-01-01):");
	scanf("%d-%d-%d",&year,&month,&day);
	found = 0;
	
	for(i=0;i<user_amount;i++){
		if(usr[i].depTime.tm_year+1900 == year && usr[i].depTime.tm_mon+1 == month && usr[i].depTime.tm_mday == day){
			if(found%MALLOC_SIZE == 0)
				result = (USER*)realloc(result,sizeof(USER)*MALLOC_SIZE*(i/MALLOC_SIZE+1));
			result[found++] = usr[i];
		}
	}
	return 1;
}

int checkUserByDepTimeArrange0(){
	return checkUserByDepTime() && disUser(result,found);
}

int checkUserByDepTimeArrange1(){
	return checkUserByDepTime() && sortByTrainNum(result,found) && disUser(result,found);
}

int checkUserByDepTimeArrange2(){
	return checkUserByDepTime() && sortByStation(result,found) && disUser(result,found);
}

int checkUserByDepTimeArrange3(){
	return checkUserByDepTime() && sortByName(result,found) && disUser(result,found);
}

int checkUserByDstTime(){
	int i,year,month,day;
	result = (USER*)malloc(sizeof(USER)*MALLOC_SIZE);
	system("cls");
	printf("请输入查询的到达时间(格式2020-01-01):");
	scanf("%d-%d-%d",&year,&month,&day);
	found = 0;
	
	for(i=0;i<user_amount;i++){
		if(usr[i].dstTime.tm_year+1900 == year && usr[i].dstTime.tm_mon+1 == month && usr[i].dstTime.tm_mday == day){
			if(found%MALLOC_SIZE == 0)
				result = (USER*)realloc(result,sizeof(USER)*MALLOC_SIZE*(i/MALLOC_SIZE+1));
			result[found++] = usr[i];
		}
	}
	return 1;
}

int checkUserByDstTimeArrange0(){
	return checkUserByDstTime() && disUser(result,found);
}

int checkUserByDstTimeArrange1(){
	return checkUserByDstTime() && sortByTrainNum(result,found) && disUser(result,found);
}

int checkUserByDstTimeArrange2(){
	return checkUserByDstTime() && sortByStation(result,found) && disUser(result,found);
}

int checkUserByDstTimeArrange3(){
	return checkUserByDstTime() && sortByName(result,found) && disUser(result,found);
}

int checkUserByPhonenum(){
	int i;
	unsigned long long src;
	result = (USER*)malloc(sizeof(USER)*MALLOC_SIZE);
	system("cls");
	printf("请输入查询的手机号:");
	scanf("%lld",&src);
	found = 0;
	
	for(i=0;i<user_amount;i++){
		if(usr[i].phonenum == src){
			if(found%MALLOC_SIZE == 0)
				result = (USER*)realloc(result,sizeof(USER)*MALLOC_SIZE*(i/MALLOC_SIZE+1));
			result[found++] = usr[i];
		}
	}
	return 1;
}

int checkUserByPhonenumArrange0(){
	return checkUserByPhonenum() && disUser(result,found);
}

int checkUserByPhonenumArrange1(){
	return checkUserByPhonenum() && sortByTrainNum(result,found) && disUser(result,found);
}

int checkUserByPhonenumArrange2(){
	return checkUserByPhonenum() && sortByStation(result,found) && disUser(result,found);
}

int checkUserByPhonenumArrange3(){
	return checkUserByPhonenum() && sortByName(result,found) && disUser(result,found);
}

//**Change user info**

int changeUserInfo(){
	int i,uid,year,month,day,hour,minute,second,tmpd;
	double tmplf;
	unsigned long long tmpull;
	char buffer[20];
	USER src;
	zoomIn();
	system("cls");
	printf("请输入要修改信息用户的UID:"); 
	scanf("%lld",&uid);
	showHeader();
	for(i=0;i<user_amount;i++){
		if(usr[i].uid == uid){
			printUser(&usr[i]);
			src = usr[i];
			break;
		}
	}
	printf("请按提示输入用户的新信息(如不需要修改填0)\n");
	
	printf("姓名:");
	scanf("%s",buffer);
	if(!(buffer[0] == '0' && buffer[1] == '\0'))
		strncpy(src.name,buffer,USERNAME_SIZE);
	
	printf("证件类型:");
	scanf("%s",buffer);
	if(!(buffer[0] == '0' && buffer[1] == '\0'))
		strncpy(src.idType,buffer,IDTYPE_SIZE);
	
	printf("证件号码:");
	scanf("%s",buffer);
	if(!(buffer[0] == '0' && buffer[1] == '\0'))
		strncpy(src.idCard,buffer,IDCARD_SIZE);
	
	printf("车次:");
	scanf("%s",buffer);
	if(!(buffer[0] == '0' && buffer[1] == '\0'))
		strncpy(src.trainNum,buffer,TRAINNUM_SIZE);
	
	printf("始发地:");
	scanf("%s",buffer);
	if(!(buffer[0] == '0' && buffer[1] == '\0'))
		strncpy(src.depStation,buffer,STATION_SIZE);
	
	printf("目的地:");
	scanf("%s",buffer);
	if(!(buffer[0] == '0' && buffer[1] == '\0'))
		strncpy(src.dstStation,buffer,STATION_SIZE);
	
	printf("出发时间(格式为2020-01-01 08:00:30):");
	scanf("%d",&tmpd);
	if(tmpd != 0){
		year = tmpd;
		scanf("-%d-%d %d:%d:%d",&month,&day,&hour,&minute,&second);
		src.depTime=setTime(year,month,day,hour,minute,second);
	}
	printf("预计到达时间(格式同上):");
	scanf("%d",&tmpd);
	if(tmpd != 0){
		year = tmpd;
		scanf("-%d-%d %d:%d:%d",&month,&day,&hour,&minute,&second);
		src.dstTime=setTime(year,month,day,hour,minute,second);
	}
	
	
	printf("票价:");
	scanf("%lf",&tmplf);
	if(tmplf != 0)src.price = tmplf;
	
	printf("手机号:");
	scanf("%lld",&tmpull);
	if(tmpull != 0)src.phonenum = tmpull;
	
	printf("修改中... ;>");
	
	if(updateUser(uid,src)){
		initAllUser();
		MessageBox(0,"修改用户信息成功",TITLE,MB_OK);
	}else{
		MessageBox(0,"修改用户信息失败",TITLE,MB_OK);
	}
	
	zoomOut();
	return 1;
}

//**Delete user with stoped train**

int stopTrain(){
	int i,success=0;
	char src[TRAINNUM_SIZE];
	char buffer[30];
	system("cls");
	printf("请输入要停开的列车号:"); 
	scanf("%s",src);
	for(i=0;i<user_amount;i++){
		if(strncmp(usr[i].trainNum,src,TRAINNUM_SIZE) == 0){
			//Release information to user (For example use Message API)
			success += delUser(i);
		}
	}
	initAllUser();
	sprintf(buffer,"共成功删除%d位用户",success);
	MessageBox(0,buffer,TITLE,MB_OK);
	
	return 1;
}

//**Menu with parameters**

int makeMenu(){
	menu *tmp,*child,*cchild;
	tmp = createNode("显示所有乘客");
	addChild(root,tmp);
		
		child = createNode("按UID排序");
		addChild(tmp,child);
		menuBind(child,displayUserWithoutSort);
		
		child = createNode("按车次排序");
		addChild(tmp,child);
		menuBind(child,displayUserSortByTrainNum);
		
		child = createNode("按起点站+终点站排序");
		addChild(tmp,child);
		menuBind(child,displayUserSortByStation);
		
		child = createNode("按姓名排序");
		addChild(tmp,child);
		menuBind(child,displayUserSortByName);
	
	
	tmp = createNode("查询乘客");
	addChild(root,tmp);
		
		child = createNode("根据证件号查询");
		addChild(tmp,child);
			
			cchild = createNode("按UID排序");
			addChild(child,cchild);
			menuBind(cchild,checkUserByIdCardArrange0);
			
			cchild = createNode("按车次排序");
			addChild(child,cchild);
			menuBind(cchild,checkUserByIdCardArrange1);
			
			cchild = createNode("按起点站+终点站排序");
			addChild(child,cchild);
			menuBind(cchild,checkUserByIdCardArrange2);
			
			cchild = createNode("按姓名排序");
			addChild(child,cchild);
			menuBind(cchild,checkUserByIdCardArrange3);
		
		child = createNode("根据姓名查询");
		addChild(tmp,child);
		
			cchild = createNode("按UID排序");
			addChild(child,cchild);
			menuBind(cchild,checkUserByNameArrange0);
			
			cchild = createNode("按车次排序");
			addChild(child,cchild);
			menuBind(cchild,checkUserByNameArrange1);
			
			cchild = createNode("按起点站+终点站排序");
			addChild(child,cchild);
			menuBind(cchild,checkUserByNameArrange2);
			
			cchild = createNode("按姓名排序");
			addChild(child,cchild);
			menuBind(cchild,checkUserByNameArrange3);
		
		child = createNode("根据起始站查询");
		addChild(tmp,child);
		
			cchild = createNode("按UID排序");
			addChild(child,cchild);
			menuBind(cchild,checkUserByDepStationArrange0);
			
			cchild = createNode("按车次排序");
			addChild(child,cchild);
			menuBind(cchild,checkUserByDepStationArrange1);
			
			cchild = createNode("按起点站+终点站排序");
			addChild(child,cchild);
			menuBind(cchild,checkUserByDepStationArrange2);
			
			cchild = createNode("按姓名排序");
			addChild(child,cchild);
			menuBind(cchild,checkUserByDepStationArrange3);
		
		child = createNode("根据终点站查询");
		addChild(tmp,child);
		
			cchild = createNode("按UID排序");
			addChild(child,cchild);
			menuBind(cchild,checkUserByDstStationArrange0);
			
			cchild = createNode("按车次排序");
			addChild(child,cchild);
			menuBind(cchild,checkUserByDstStationArrange1);
			
			cchild = createNode("按起点站+终点站排序");
			addChild(child,cchild);
			menuBind(cchild,checkUserByDstStationArrange2);
			
			cchild = createNode("按姓名排序");
			addChild(child,cchild);
			menuBind(cchild,checkUserByDstStationArrange3);
		
		child = createNode("根据发车时间查询");
		addChild(tmp,child);
		
			cchild = createNode("按UID排序");
			addChild(child,cchild);
			menuBind(cchild,checkUserByDepTimeArrange0);
			
			cchild = createNode("按车次排序");
			addChild(child,cchild);
			menuBind(cchild,checkUserByDepTimeArrange1);
			
			cchild = createNode("按起点站+终点站排序");
			addChild(child,cchild);
			menuBind(cchild,checkUserByDepTimeArrange2);
			
			cchild = createNode("按姓名排序");
			addChild(child,cchild);
			menuBind(cchild,checkUserByDepTimeArrange3);
		
		child = createNode("根据到达时间查询");
		addChild(tmp,child);
		menuBind(child,checkUserByDstTime);
		
			cchild = createNode("按UID排序");
			addChild(child,cchild);
			menuBind(cchild,checkUserByDstTimeArrange0);
			
			cchild = createNode("按车次排序");
			addChild(child,cchild);
			menuBind(cchild,checkUserByDstTimeArrange1);
			
			cchild = createNode("按起点站+终点站排序");
			addChild(child,cchild);
			menuBind(cchild,checkUserByDstTimeArrange2);
			
			cchild = createNode("按姓名排序");
			addChild(child,cchild);
			menuBind(cchild,checkUserByDstTimeArrange3);
		
		child = createNode("根据联系电话查询");
		addChild(tmp,child);
		
			cchild = createNode("按UID排序");
			addChild(child,cchild);
			menuBind(cchild,checkUserByPhonenumArrange0);
			
			cchild = createNode("按车次排序");
			addChild(child,cchild);
			menuBind(cchild,checkUserByPhonenumArrange1);
			
			cchild = createNode("按起点站+终点站排序");
			addChild(child,cchild);
			menuBind(cchild,checkUserByPhonenumArrange2);
			
			cchild = createNode("按姓名排序");
			addChild(child,cchild);
			menuBind(cchild,checkUserByPhonenumArrange3);
	
	tmp = createNode("添加乘客");
	addChild(root,tmp);
	
		child = createNode("从输入信息添加乘客");
		addChild(tmp,child);
		menuBind(child,addUserByInput);
		
		child = createNode("从文件添加乘客");
		addChild(tmp,child);
		menuBind(child,addUserByFile);
	
	tmp = createNode("修改乘客信息");
	addChild(root,tmp);
	menuBind(tmp,changeUserInfo);
	
	tmp = createNode("停开列车");
	addChild(root,tmp);
	menuBind(tmp,stopTrain);
	
	return 1;
}

int entry(){
	char ch,buffer[BUFFER_SIZE];
	int status, pointer=0;
	
	zoomOut();
	
	//Start user database
	if(!initAllUser()){
		printf("Exception: database failed.\n");
		system("pause");
		return 0;
	}
	
	//Start Menu
	menuInit();
	makeMenu();
	printMenu(root);
	
	//Died cycle for input
	while(1){
		pointer = 0;
		while((ch = getchar()) != '\n')
			if(ch != ' ')
				buffer[pointer++] = ch;
		if(pointer == 0){
			status = 1;
			printMenu(current);
		}else if(pointer <=1){
			ch = buffer[0];
			status = choose(ch);
		}else{
			status = 0;
		}
		if(!status){
			MessageBox(0,"操作有误，请重新输入",TITLE,MB_OK);
			printMenu(current);
		}
	}
	
	return 1;
}

#ifdef __cpluscplus
}
#endif

#endif
