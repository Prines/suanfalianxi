#include<iostream>
using namespace std;

//max��Ϊ��ͨʱ��·��ֵ
#define MAX 1000;
 //����洢·�����ȵ�����
int arc[13][13];
void BackPath(int n);

int main()
{
     int weight;
    //��ʼ��·��Ȩ��ֵ
    for(int i=0;i<13;i++)
        for(int j=0;j<13;j++)
        {
            arc[i][j]=MAX;
        }
        int i=0;int j=0;
    //ͼ�Ĵ��۾���
    for(int k=0;k<24;k++)
    {
     cout<<"�����붥���Ȩ��ֵ";
     cin>>i>>j>>weight;
     arc[i][j]=weight;
    }
    BackPath(13);
    return 0;
}

void BackPath(int n)
{
    //���Ϊÿ�������ǰһ�������ֵ
    int path[13];
    //���Ϊ��0����ÿ��������С����
    int cost[13];
    //��ʼ��
    for(int i=1;i<13;i++)
    {
        path[i]=-1;
        cost[i]=MAX;
    }
    cost[0]=0;
    path[0]=-1;
    //����ѭ�����ܴ������ñȽ϶࣬���Ǳ���������ÿ�����㶼��ѭ��
    for(int i=1;i<13;i++)
        for(int j=0;j<i;j++)
        if(arc[j][i]+cost[j]<cost[i])
        {
            path[i]=j;
            cost[i]=arc[j][i]+cost[j];
        }
    cout<<n-1;
    int i=n-1;
    //���·��
    while(path[i]!=-1)
    {
        cout<<"<-"<<path[i];
        i=path[i];
    }

}
