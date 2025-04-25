#include"BLlist.h"
// 采取先序创建链表
BLN * createBL( )
{
    char c;
    cin >>c;
    BLN *t = new BLN;
    if(c=='#')
        return NULL;
    else 
    {
        t->data = c;
        t->lc = createBL();
        t->rc = createBL();
    }
    return t;
}
void xianDFS(BLN*t)
{
    cout << t->data;
    if(t->lc)
        xianDFS(t->lc);
    if(t->rc)
        xianDFS(t->rc);
}
void zhonDFS(BLN*t)
{
    if(t->lc)
        xianDFS(t->lc);
    cout << t->data;
    if(t->rc)
        xianDFS(t->rc);
}
void houDFS(BLN*t)
{
    if(t->lc)
        xianDFS(t->lc);
        if(t->rc)
            xianDFS(t->rc);
    cout << t->data;
}