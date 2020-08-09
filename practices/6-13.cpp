#include <iostream>
using namespace std;

#define MAXSIZE 50
typedef int KeyType;

typedef  struct                     
{ KeyType  key;                                             
} ElemType;  

typedef  struct
{ ElemType  *R; 
  int  length;
} SSTable;                      

void  Create(SSTable &T)
{ int i;
  T.R=new ElemType[MAXSIZE+1];
  cin>>T.length;
  for(i=1;i<=T.length;i++)
     cin>>T.R[i].key;   
}

int  Search_Bin(SSTable T, KeyType k);

int main () 
{  SSTable T;  KeyType k;
   Create(T);
   cin>>k;
   int pos=Search_Bin(T,k);
   if(pos==0) cout<<"NOT FOUND"<<endl;
   else cout<<pos<<endl;
   return 0;
}

/* 请在这里填写答案 */

int  Search_Bin(SSTable T, KeyType k){
	int down=0,up=T.length-1,todo;
	while(up - down > 1){
		if(T.R[up].key == k) return up;
		if(T.R[down].key == k)return down;
		todo = (up+down)/2;
		if(T.R[todo].key < k)
			down = todo;
		else if(T.R[todo].key > k){
			up = todo;
		}else if(T.R[todo].key == k){
			return todo;
		}
	}
	return 0;
}
