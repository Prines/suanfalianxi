#include <iostream>
using namespace std;

int MaxSum(int a[],int left,int right)
{
	int sum=0,leftsum=0,rightsum=0,midsum=0;
	//ֻ��һ��ֱ�ӷ��أ����������ұߵ����ֵ������������Ҫ�Ƚ���
	if(left==right)
		return a[left];
	else
	{
		int center=(left+right)/2;
		leftsum=MaxSum(a,left,center);
		//�����ظ�
		rightsum=MaxSum(a,center+1,right);
		//s1Ϊ��ߺͣ�leftsΪһֱ�ӹ�������ֵ��һ������Ŀǰ�����ֵ����Ը���
		//leftsum��rightΪ��һ�㴫�����������������ֵ����һ��Ҫ����ô�б����Ǵ��
		int s1=0,lefts=0;
		for(int i=center;i>=left;i--)
		{
			lefts+=a[i];
			if(lefts>s1)
			  s1=lefts;
		}
		int s2=0,rights=0;
		for(int i=center+1;i<=right;i++)
		{
			rights+=a[i];
			if(rights>s2)
				s2=rights;
		}
		midsum=(s1+s2);
		if(midsum<leftsum)
			sum=leftsum;
		else
			sum=midsum;
		if(sum<rightsum)
			sum=rightsum;
		return sum;//������һ���sum��ֻ��һ���Ĳ��ñ�ֱ�ӷ�����
	}
}

int main()
{
	int a[6]={-20,11,-4,13,-5,-2};
	cout<<MaxSum(a,0,5);
	return 0;
}