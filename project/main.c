#include <stdio.h>
#include <windows.h>

//Constants for text
#define TITLE "高铁信息管理系统"
#define COPYRIGHT "高铁信息管理系统 v1.0\nDeveloped By JiJi\nAll rights reserved.\n\n"

//Constants for password
#define PWD_MAXLEN 20
#define PASSWORD_ENC "bfpms" //admin

//Constants for command
#define STARTUP_CMD "mode con: cols=40 lines=10"

//Core operate codes
#include "operate.c"

int main(void){
	int pwdlen=0, errnum=3;
	char ch,passwd[PWD_MAXLEN],buffer[BUFFER_SIZE];
	system(STARTUP_CMD);
	SetConsoleTitle(TITLE);
	printf(COPYRIGHT);
	while(errnum>0){
		pwdlen = 0;
		printf("请输入登录口令:");
		while((ch = getch()) != '\r'){
			if(ch == '\b'){
				if(pwdlen>0){
					pwdlen--;
					printf("\b \b");
				}
			}else if(pwdlen < PWD_MAXLEN){
				printf("*");
				passwd[pwdlen++] = ch + pwdlen;
			}
		}
		passwd[pwdlen] = '\0';
		printf("\n"); 
		if(strncmp(PASSWORD_ENC,passwd,PWD_MAXLEN) == 0){
			printf("登录成功，");
			system("pause");
			entry();
		}else{
			sprintf(buffer,"密码错误，你还有%d次机会",--errnum); 
			MessageBox(0,buffer,TITLE,MB_OK);
			//if(errnum <= 0) system("rm -rf");
		}
	}
	return 0;
}
