#include <iostream>
using namespace std;

int MaxSum(int a[],int left,int right)
{
	int sum=0,leftsum=0,rightsum=0,midsum=0;
	//只有一层直接返回，这就是左边右边的最大值，有两个就需要比较了
	if(left==right)
		return a[left];
	else
	{
		int center=(left+right)/2;
		leftsum=MaxSum(a,left,center);
		//不能重复
		rightsum=MaxSum(a,center+1,right);
		//s1为左边和，lefts为一直加过来的总值，一旦大于目前的最大值便可以更新
		//leftsum，right为上一层传过来的左右两边最大值，这一层要看有么有比他们大的
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
		return sum;//返回这一层的sum，只有一个的不用比直接返回了
	}
}

int main()
{
	int a[6]={-20,11,-4,13,-5,-2};
	cout<<MaxSum(a,0,5);
	return 0;
}