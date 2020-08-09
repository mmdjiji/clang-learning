#ifndef _USERLIB_H_
#define _USERLIB_H_

/***************************************
 *             userlib.h               *
 *                                     *
 *           Author: JiJi              *
 *                                     *
 *    Function: Manage users' data.    *
 *                                     *
 *         All rights reserved         *
 ***************************************/

#include <string.h>
#include <time.h>
#include <limits.h>


//Constants for size
#define USERNAME_SIZE 20
#define IDTYPE_SIZE 20
#define IDCARD_SIZE 20
#define TRAINNUM_SIZE 10
#define STATION_SIZE 10

#define PAGE_SIZE 10
#define MALLOC_SIZE 10
#define BUFFER_SIZE 30

//Database table path (Maybe we need dynamic changes in the future)
#define DATABASE_PATH "user.dat"


#ifdef __cpluscplus
extern "C" {
#endif


//**Data structure for user**

struct usrdef{
	unsigned long long uid;				//Unique user id (normal 0 ~ LLONG_MAX)
	char deleted;						//Whether the account available or unavailable
	char name[USERNAME_SIZE];			//Name
	char idType[IDTYPE_SIZE];			//ID card type
	char idCard[IDCARD_SIZE];			//ID card value
	char trainNum[TRAINNUM_SIZE];		//Train number
	char depStation[STATION_SIZE];		//Departure station
	char dstStation[STATION_SIZE];		//Destination station
	double price;						//Ticket price
	struct tm depTime;					//Departure time
	struct tm dstTime;					//Destination time
	unsigned long long phonenum;		//Phone number
	int verifyCode;						//Verify whether the user data has been changed illegally
};
typedef struct usrdef USER;


//**auxiliary function**

int _eof_(FILE *fp);					//In order to avoid a bug from feof() when reading null file and not return eof

int swap(USER *p,USER *q);				//For sorting, we need to swap two users' pointer 


//**global variable table**

unsigned long long user_amount = 0;		//The amount of user
USER *usr,*usr_sort;					//Users from database (contain deleted)
USER *result = NULL; int found = 0;		//Temporary query result


//**Database systemcall**

int initDatabase();						//[Auto call]Make sure program can operate database (will be call by under function)

int initAllUser();						//Initialize user table


//**Output**
int fshowHeader(FILE *fp);				//Output the header to FILE *fp

int showHeader();						//Output the header to stdout

int fprintUser(FILE *fp,USER *src);		//Output the USER *src info to FILE *fp

int printUser(USER *src);				//Output the USER *src info to stdout


//**Time operation** (extern <time.h>)

//Set time from 6 elements and return a `struct tm` for time storage
struct tm setTime(int year, int month, int day, int hour, int minute, int second);

//Convert `struct tm` to string give to *timebuf
int getTime(char *timebuf, struct tm src);


//**Basic operation for database**

int addUser(USER src);								//Add a user to database

int queryVerify(USER *src);							//Query verify

int writeVerify(USER *src);							//Write the right verify code to src

int checkVerify(USER *src);							//Check whether verify code is true

int listUser(USER *src,int start,int len,int num);	//List confirmed amounts of user

int updateUser(unsigned long long uid, USER src);	//Update the information of a user

int delUser(unsigned long long uid);				//Delete a user but not destroy it


#ifdef __cpluscplus
}
#endif

#endif
