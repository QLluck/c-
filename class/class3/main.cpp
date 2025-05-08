#include"BLlist.h"
int main()
{
    BLN *t = new BLN;
    t=createBL();
    xianDFS(t);
    cout << '\n';
    zhonDFS(t);
    cout << '\n';
    houDFS(t);
   cout<<"叶节点个数为"<<tNum(t)<<'\n';
}