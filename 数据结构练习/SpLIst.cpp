//顺序表
#include<bits/stdc++.h>
#define MaxSpSize 10 
#define InitSize 10
typedef struct 
{
   int  date[MaxSpSize] ;//静态数组
   int length ;
}SpList ;
typedef struct //动态数组
{ 
   int *date ;
    int MaxSeqSize ;
   int length ;
}SeqList ;
//初始化
void IniSepList(SeqList &L)
{
     L.date = (int *)malloc(sizeof(int ) * InitSize) ;
     L.length = 0 ;
     L.MaxSeqSize = InitSize ; 
}
void InitSpList(SpList &L)
{
      for(int i = 0;  i< MaxSpSize ;i++)
      {
          L.date[i] = 0 ;
          L.length = 0 ;
      }

}
//插入e 
bool ListInsert(SpList &L,int i,int e )
{
     if(i<1||i>L.length+1||L.length>=MaxSpSize) return false ; 
       for(int j = L.length ; j>= i ; j--) L.date[j]  = L.date[j-1] ;
       L.date[i-1] = e ;
       L.length++ ; 
       return true ;
}
//删除元素
bool ListDelete(SpList &L , int i  , int &e)
{
     if(1<i||i>L.length) return false ;
     e = L.date[i-1] ;
     for(int j =  i;  j <L.length ; j++) L.date[j-1] = L.date[j] ;
     L.length-- ;
     return true ;

}
//增加动态数组的长度
void IncreaseSize(SeqList &L,int len)
{
 int *p = L.date ;
 L.date=(int *)malloc((L.MaxSeqSize+len)*sizeof(int) );
 for(int i = 0 ; i<L.length; i++) L.date[i] = p[i] ;  //增加空间需要开辟新的空间
 L.MaxSeqSize+=len ;
 free(p) ;
}
//查找
int GetInt(SpList L , int i)
{
       return L.date[i-1] ;
}
//按值查找
int LocateInt (SpList L , int e )
{
       for(int i = 0 ; i<L.length ; i++)
        if(L.date[i]==e) return i+1 ;//相等放回位序
        return 0 ;
}

int main()
{
     SpList L ;
     InitSpList(L) ;
     
     return 0 ;
}