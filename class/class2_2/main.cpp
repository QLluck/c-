#include"queue.h"
void init(QN*queNa,QN*queNv,pe arr[],int n)
{
     for(int i=0 ; i<n ; i++)
     { 
        if(strcmp(arr[i].sex,"男")==0)
        {
             queuePush(queNa,arr[i]);
        }
        else if(strcmp(arr[i].sex,"女")==0)
        {
             queuePush(queNv,arr[i]);
        }
     }
}
void main()
{
     //给定一个列表
     pe arr[]={{"林小悠","女"},{"陈逸尘","男"},{"周泽楷","男"},{"苏瑶光","女"},{"秦宇晨","男"},{"叶雨晴","女"},{"林逸风","男"},{"周子墨","男"},{"沈清歌","女"},{"张子涵","男"}};
     int n = sizeof(arr)/sizeof(pe);
     int t;
     cout<<"输入组合的次数"<<endl;
     cin>>t;
     QN * queNa = new QN ;
     QN * queNv = new QN ;
     queueInit(queNa);
     queueInit(queNv);
     init(queNa,queNv,arr,10);

     for(int i=1; i<=t ;i++)
     {
          cout<<"第"<<i<<"次"<<endl;
          pe nan = queueTop(queNa);
          pe nv = queueTop(queNv);
          queuePop(queNa);
          queuePop(queNv);
          queuePush(queNa,nan);
          queuePush(queNv,nv);


          cout<<nan.name<<' '<<nv.name<<endl;

     }
}
