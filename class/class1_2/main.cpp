#include "ListNode.h"
#include"menu.h"
using namespace std ;
void solve()
{
     char arr[][MAX_NAME]={"红楼梦","活着","哈利波特","三体","百年孤独","飘","三国演义","小王子","呐喊","杀死一只知更鸟","诡秘之主"};
     //
     List l = new LinkList;
     listInit(l,arr,11);

     listPrint(l);
     
     menuPrint(l);
     
    
     //menuPrint(l);
     listDelete(l);



}
int main()
{
  //ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
  solve();
}