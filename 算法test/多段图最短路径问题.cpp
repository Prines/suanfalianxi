#include<iostream>
using namespace std;

//max作为不通时的路径值
#define MAX 1000;
 //定义存储路径长度的数组
int arc[13][13];
void BackPath(int n);

int main()
{
     int weight;
    //初始化路径权重值
    for(int i=0;i<13;i++)
        for(int j=0;j<13;j++)
        {
            arc[i][j]=MAX;
        }
        int i=0;int j=0;
    //图的代价矩阵
    for(int k=0;k<24;k++)
    {
     cout<<"请输入顶点和权重值";
     cin>>i>>j>>weight;
     arc[i][j]=weight;
    }
    BackPath(13);
    return 0;
}

void BackPath(int n)
{
    //这个为每个顶点的前一个顶点的值
    int path[13];
    //这个为从0到达每个顶点最小消耗
    int cost[13];
    //初始化
    for(int i=1;i<13;i++)
    {
        path[i]=-1;
        cost[i]=MAX;
    }
    cost[0]=0;
    path[0]=-1;
    //这样循环可能次数做得比较多，但是必须这样，每个顶点都得循环
    for(int i=1;i<13;i++)
        for(int j=0;j<i;j++)
        if(arc[j][i]+cost[j]<cost[i])
        {
            path[i]=j;
            cost[i]=arc[j][i]+cost[j];
        }
    cout<<n-1;
    int i=n-1;
    //输出路径
    while(path[i]!=-1)
    {
        cout<<"<-"<<path[i];
        i=path[i];
    }

}
