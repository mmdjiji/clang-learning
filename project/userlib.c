#ifndef _USERLIB_C_
#define _USERLIB_C_

#include "userlib.h"
#include <stdio.h>
#include <stdlib.h>

#ifdef __cpluscplus
extern "C" {
#endif

int _eof_(FILE *fp){
	if(fgetc(fp) != EOF){
		fseek(fp, -1L, SEEK_CUR);
		return 0;
	}else{
		return 1;
	}
}

int swap(USER *p,USER *q){
	USER tmp=*p;
	*p=*q;
	*q=tmp;
	return 1;
}

int initDatabase(){
	FILE *fp;
	usr = NULL;
	if((fp=fopen(DATABASE_PATH,"rb+"))!=NULL){ //Perfect exist!
		fclose(fp);
		return 1;
	}else{
		//Try to create
		if((fp=fopen(DATABASE_PATH,"wb"))!=NULL){ //Create success!
			fclose(fp);
			user_amount = 0;
			return 1;
		}else{ //Exception: cannot create database
			return 0;
		}
	}
}

int initAllUser(){
	unsigned long long i=0,amount = 0;
	USER tmp;
	if(!initDatabase())
		return 0;
	FILE *fp = fopen(DATABASE_PATH,"rb");
	if(fp != NULL){
		while(!_eof_(fp)){
			if(usr == NULL){
				usr = (USER*)malloc(sizeof(USER)*MALLOC_SIZE);
				usr_sort = (USER*)malloc(sizeof(USER)*MALLOC_SIZE);
			}else if(i%MALLOC_SIZE == 0){
				usr = (USER*)realloc(usr,sizeof(USER)*MALLOC_SIZE*(i/MALLOC_SIZE+1));
				usr_sort = (USER*)realloc(usr_sort,sizeof(USER)*MALLOC_SIZE*(i/MALLOC_SIZE+1));
			}
			fread(usr+i,sizeof(USER),1,fp);
			usr_sort[i] = usr[i];
			i++;
		}
		fclose(fp);
	}
	user_amount = i;
	return 1;
}

int fshowHeader(FILE *fp){
	fprintf(fp,"UID\tName\tIdType\t      IdCard      \tTrain\t     Dep¡úDst     \t          Dep Time ¡ú Dst Time          \tPrice\tPhone\n");
	return 1;
}

int showHeader(){
	fshowHeader(stdout);
	return 1;
}

int fprintUser(FILE *fp,USER *src){
	char buffer[BUFFER_SIZE];
	fprintf(fp,"%d\t%s\t%s\t%s\t%s\t   %s¡ú%s   \t",
	src->uid,
	src->name,
	src->idType,
	src->idCard,
	src->trainNum,
	src->depStation,
	src->dstStation);
	getTime(buffer, src->depTime);
	fprintf(fp,"%s¡ú",buffer);
	getTime(buffer, src->dstTime);
	fprintf(fp,"%s\t",buffer);
	fprintf(fp,"%.2lf\t%lld",src->price, src->phonenum);
	fprintf(fp,"\n");
	return 1;
}

int printUser(USER *src){
	return fprintUser(stdout,src);
}

struct tm setTime(int year, int month, int day, int hour, int minute, int second){
	struct tm retval = {second, minute, hour, day, month-1, year-1900};
	return retval;
}

int getTime(char *timebuf, struct tm src){
	strftime(timebuf, 30, "%Y-%m-%d %H:%M:%S", &src);
	return 1;
}

int addUser(USER src){
	FILE *fp;
	if((fp=fopen(DATABASE_PATH,"ab+")) != NULL){
		src.uid = user_amount++;
		src.deleted=0;
		writeVerify(&src);
		fwrite(&src,sizeof(src),1,fp);
		fclose(fp);
		return 1;
	}
	return 0;
}

int queryVerify(USER *src){
	int i, dst = 0;
	dst += (src->uid + src->deleted*USHRT_MAX + (int)src->price + src->phonenum + mktime(&src->depTime) + mktime(&src->dstTime)) % INT_MAX;
	for(i=0;i<strlen(src->name);i++)
		dst += src->name[i];
	for(i=0;i<strlen(src->idType);i++)
		dst += src->idType[i];
	for(i=0;i<18;i++)
		dst += src->idCard[i];
	for(i=0;i<strlen(src->trainNum);i++)
		dst += src->trainNum[i];
	for(i=0;i<strlen(src->depStation);i++)
		dst += src->depStation[i];
	for(i=0;i<strlen(src->dstStation);i++)
		dst += src->dstStation[i];
	return dst;
}

int writeVerify(USER *src){
	src->verifyCode = queryVerify(src);
	return 1;
}

int checkVerify(USER *src){
	return (queryVerify(src) == src->verifyCode);
}

int listUser(USER *src,int start,int len,int num){
	int i,flag=0;
	for(i=0;i<len;i++){
		while(start+flag+i<num && !(src[start+flag+i].deleted==0 && checkVerify(src+start+flag+i)))flag++;
		if(start+flag+i<num)
			printUser(&src[start+flag+i]);
		else break;
	}
	return 1;
}

int updateUser(unsigned long long uid, USER src){
	USER tmp;
	FILE *fp = fopen(DATABASE_PATH,"rb+");
	if(fp != NULL){
		while(!_eof_(fp)){
			fread(&tmp,sizeof(USER),1,fp);
			if(tmp.uid == uid && tmp.deleted == 0 && checkVerify(&tmp)){
				writeVerify(&src);
				fseek(fp, -(long)sizeof(USER), SEEK_CUR);
				fwrite(&src,sizeof(src),1,fp);
				fclose(fp);
				return 1;
			}
		}
		fclose(fp);
	}
	//not found
	return 0;
}

int delUser(unsigned long long uid){
	USER tmp;
	FILE *fp = fopen(DATABASE_PATH,"rb+");
	if(fp != NULL){
		while(!_eof_(fp)){
			fread(&tmp,sizeof(USER),1,fp);
			if(tmp.uid == uid && tmp.deleted == 0 && checkVerify(&tmp)){
				tmp.deleted = 1;
				writeVerify(&tmp);
				fseek(fp, -(long)sizeof(USER), SEEK_CUR);
				fwrite(&tmp,sizeof(tmp),1,fp);
				fclose(fp);
				return 1;
			}
		}
		fclose(fp);
	}
	//not found
	return 0;
}

#ifdef __cpluscplus
}
#endif

#endif
