#include"graph.h"
using namespace std;

GP* init(int num)//初始化图
{
    GP *g = new GP;
    g->head = 1;
    g->num = num;
    for (int i = 1; i <= num ;i++)
        init_v(i, g);//北京为1 , 上海为2 台北为3 香港为4
    add_e(1,2,1463,g);
    add_e(2,1,1463,g);
    add_e(1,3,1680,g);
    add_e(3,1,1680,g);
    add_e(1,4,2160,g);
    add_e(4,1,2160,g);
    add_e(2,3,700,g);
    add_e(3,2,700,g);
    add_e(2,4,1200,g);
    add_e(4,2,1200,g);
    add_e(3,4,808,g);
    add_e(4,3,808,g);
    return g;
}
int main()
{
  GP*g=init(4);
   dfs(1,1, g,0);
   GP *g2 = prim(1, g);
   printf("mini Tree\n");
   dfs(1, 1, g2,0);
   int a;
   cin >> a;
}