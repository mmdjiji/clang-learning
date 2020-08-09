#ifndef _MENU_C_
#define _MENU_C_

#include "menu.h"
#include "userlib.c"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#ifdef __cpluscplus
extern "C" {
#endif

int zoomIn(){
	if(system(ZOOMIN_CMD)!=-1)
		return 1;
	return 0;
}

int zoomOut(){
	if(system(ZOOMOUT_CMD)!=-1)
		return 1;
	return 0;
}

int menuInit(){
	root = createNode(WELCOME_USE_TEXT);
	menuBind(root,NULL);
	current = root;
	return 1;
}

menu *createNode(char *src){
	menu *retval = (menu *)malloc(sizeof(menu));
	retval->back = NULL;
	retval->childNum = 0;
	strncpy(retval->text, src, MENUTXT_SIZE);
	return retval;
}

int menuBind(menu *src, int (*func)()){
	src->onCall = func;
	return 1;
}

int addChild(menu *src, menu *dst){
	src->child[src->childNum++] = dst;
	dst->back = src;
	return 1;
}

int choose(char c){
	if(c == 'q'){exit(0);}
	if(c == '*' && current->back != NULL){
		current = current->back;
		printMenu(current);
		return 1;
	}else if(c == '#'){
		current = root;
		printMenu(current);
		return 1;
	}else if(current->childNum > c - '0' && c >= '0' && c <= '9'){
		current = current->child[c-'0'];
		if(current->childNum == 0){
			current->onCall();
			current = current->back;
		}
		printMenu(current);
		return 1;
	}else{
		return 0;
	}
}

int printMenu(menu *src){ //Ugly codes here
	int i,j,len;
	HANDLE hConsole;
	CONSOLE_SCREEN_BUFFER_INFO bufInfo;
	COORD pos = {0,0};
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if(src->childNum != 0){
		system("cls");
		printf("\n ");
		len = 56 - strlen(current->text);
		for(i=0;i<len/2;i++)printf("+");
		printf("%s",current->text);
		for(i=0;i<len/2;i++)printf("+");
		printf("\n +");
		 
		for(i=0;i<54;i++)printf(" ");
		printf("+\n");
		
		for(i=0;i<src->childNum;i++){
			len = 47-strlen(src->child[i]->text);
			printf(" +    ");
			printf("%d. %s",i,src->child[i]->text);
			for(j=0;j<len;j++)printf(" ");
			printf("+\n");
		}
		
		printf(" +");
		for(i=0;i<54;i++)printf(" ");
		printf("+\n");
		
		if(current->back != NULL){
			printf(" +    *. 返回上一级菜单");for(j=0;j<33;j++)printf(" ");printf("+\n");
		}
		if(current != root){
			printf(" +    #. 返回主菜单");for(j=0;j<37;j++)printf(" ");printf("+\n");
		}
		printf(" +    q. 退出程序");for(j=0;j<39;j++)printf(" ");printf("+\n");
		
		printf(" +");
		for(i=0;i<54;i++)printf(" ");
		printf("+\n");
		
		printf(" +    请输入您的选择: ");
		
		GetConsoleScreenBufferInfo(hConsole,&bufInfo);
		pos.X = bufInfo.dwCursorPosition.X;
		pos.Y = bufInfo.dwCursorPosition.Y;
		
		for(j=0;j<34;j++)printf(" ");printf("+\n ");
		
		printf("+");
		for(i=0;i<54;i++)printf(" ");
		printf("+\n ");
		
		for(i=0;i<56;i++)printf("+");
		printf("\n");
		
		SetConsoleCursorPosition(hConsole, pos);
		
		return 1; 
	}else{
		return 0;
	}
}

#ifdef __cpluscplus
}
#endif

#endif
