#ifndef _MENU_H_
#define _MENU_H_

/***************************************
 *              menu.h                 *
 *                                     *
 *           Author: JiJi              *
 *                                     *
 * Function: Create a menu in console  *
 * conveniently and flexibly.          *
 *                                     *
 *         All rights reserved         *
 ***************************************/

//Constants for size
#define PATH_SIZE 20
#define MENUTXT_SIZE 30
#define CHILD_SIZE 10

//Constants for command
#define ZOOMIN_CMD "mode con: cols=180 lines=40"
#define ZOOMOUT_CMD "mode con: cols=60 lines=20"

//Constants for text
#define WELCOME_USE_TEXT "欢迎使用高铁乘客管理系统"


#ifdef __cpluscplus
extern "C" {
#endif

//Core data structure
//This node is based on the tree in the data structure
//Every node can be root,child or back(means father)
typedef struct menudef{
	char text[MENUTXT_SIZE];
	int (*onCall)();
	int childNum;
	struct menudef *back;
	struct menudef *child[CHILD_SIZE];
}menu;


menu *root, *current;						//For the default menu is root, and for the current menu is current

int zoomIn();								//Zoom in the console to display more

int zoomOut();								//Zoom out the console for enough

int menuInit();								//Make sure the root is created

menu *createNode(char *src);				//Create a menu node and it's universal

int menuBind(menu *src, int (*func)());		//Bind menu node with a function

int addChild(menu *src, menu *dst);			//Add a child for menu father

int choose(char c);							//When user choose an option, this will judge what to do

int printMenu(menu *src);					//Print the menu Console_GUI to user

#ifdef __cpluscplus
}
#endif

#endif
