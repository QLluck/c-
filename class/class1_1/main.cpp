#include"shiyan1.h"

using namespace std ;
void solve()
{
    int arr[1000][2];
    int n;
    //测试数组，全部使用随机数生成
    n=rand()%10+1 ;//多项式1的长度
    List l1 = new LinkList; 
    
    inputArray(arr,n);
    ListInit(l1,arr,n);
    cout<<"第一个多项式为\n";
    PrintList(l1);
    
    n=rand()%10+1;  //多项式2的长度
    List l2 = new LinkList;
    inputArray(arr,n);
    ListInit(l2,arr,n);
    cout<<"第二个多项式为\n";
    PrintList(l2);
   List l3 = ListAdd(l1,l2);
   cout<<"两个多项式的结果为"<<'\n' ;
   PrintList(l3);
    deleteList(l1);
    deleteList(l2);
    deleteList(l3);


}
int main()
{
    


    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t,it=0;
    cin>>t;//测试数据组数
    while(t--)
   {  it++;
    cout<<"第"<<it<<"次测试"<<'\n';
    solve();
   }
    return 0;


}
