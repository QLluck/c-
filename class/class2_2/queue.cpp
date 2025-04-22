#include"queue.h"
void queueInit(QN* que )
{
     que->data = (pe*)malloc(MAXSIZE*sizeof(pe));
     que->head = 0 ; 
     que->rear = 0 ; 
}
bool queueEmpty(QN*que)
{
     return que->head==que->rear;
}
bool queueFull(QN*que)
{
     return MAXSIZE==(que->rear-que->head+MAXSIZE)%MAXSIZE;
}
int queueSize(QN*que)
{
     return (que->rear-que->head+MAXSIZE)%MAXSIZE;
}
void  queuePush(QN*que,pe e)
{   if(queueFull(que))
    {
         cout<<"队列满了"<<endl;
         return ;
    }
    que->data[que->rear]=e;
    que->rear = (que->rear+1)%MAXSIZE ;

}
void queuePop(QN*que)
{
     if(queueEmpty(que))
     {
         cout<<"队空"<<endl;
         return ;
     }
     que->head = (que->head+1)%MAXSIZE;
}
pe queueTop(QN*que)
{  if(queueEmpty(que))
    {
        cout<<"队空"<<endl;
        return que->data[que->head] ;
    }
     return que->data[que->head];
}