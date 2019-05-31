#include<iostream>
using namespace std;

//动态规划的核心就是填表
//v[i][j]代表前i个物品装入容量为j的背包的最大价值

int v[6][7];//代表6行7列，从0行开始，0列开始
int w[6]={0,3,2,1,4,5};
int p[6]={0,25,20,15,40,50};

int main()
{
    //初始化表格第一行第一列
    for(int i=0;i<6;i++)
    {
        v[i][0]=0;
    }
    for(int j=0;j<7;j++)
    {
        v[0][j]=0;
    }
    for(int i=1;i<6;i++)
        for(int j=1;j<7;j++)
    {
        //容量放不下这个物品，这个容量j是没有算前面加入物品的，因为后面比较max时会把这个容量去掉
        if(w[i]>j)
        {
            v[i][j]=v[i-1][j];
        }
        else if((v[i-1][j-w[i]]+p[i])>v[i-1][j])
            v[i][j]=v[i-1][j-w[i]]+p[i];
            else
                v[i][j]=v[i-1][j];
    }
    //求放入背包的物品有哪些
    int x[6];
    //i是从五开始，那么得有x[5]定义时即为6，i>0从第一行开始检验，这跟weight，price从一开始对应
    for(int i=5,j=6;i>0;i--)
    {
        //如果大于说明添加进来了,这种最标准，排除了容量不够的情况
        if(v[i][j]>v[i-1][j])
        {
            x[i]=1;
            //这个物品已经放入，说明容量会减少到j-w[i]，下一次直接从这个检查起，其余容量只不过是铺垫而已
            j=j-w[i];
        }
        else x[i]=0;
    }

    int k=5;
    while(k>0)
    {
        if(x[k]==1)
        {
            cout<<v[k][6]<<endl;
            break;
        }
        k--;
    }
    k=1;
    cout<<"装进的物品如下"<<endl;
    while(k<6)
    {
        if(x[k]==1)
          cout<<k;
        k++;
    }

    return 0;
}
