#ifndef QUEUE
#define QUEUE
#define MAXSIZE 100
#include<bits/stdc++.h>
using namespace std ;
typedef struct person
{
     char name[100];
     char sex[20];
}pe;
typedef struct queueNode
{   pe*data ;
     int head;
     int rear;
}QN;
void queueInit(QN* que );
bool queueEmpty(QN*que);
bool queueFull(QN*que);
int queueSize(QN*que);
void  queuePush(QN*que,pe e);
void queuePop(QN*que);
pe queueTop(QN*que);
#endif //QUEUE