#ifndef BLLIST
#define BLLIST
#include<bits/stdc++.h>
using namespace std;
typedef struct BLNode
{
    char data;
    struct BLNode *lc;
    struct BLNode *rc;

} BLN;
BLN *createBL();
void xianDFS(BLN *t);
void zhonDFS(BLN *t);
void houDFS(BLN *t);
int tNum(BLN*t);
#endif //bLLIST