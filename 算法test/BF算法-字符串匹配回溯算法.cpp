#include <iostream>
using namespace std;

int main()
{
	//c语言 scanf字符串结尾自动添加'\0'
   char a[10]={'a','b','c','a','b','c','a','c','b','\0'};
   char b[6]={'a','b','c','a','c','\0'};
   int index=0; //这个index作为回溯标志
	int i=0;int j=0;
	while(a[i]!='\0'&&b[j]!='\0')
   {
	   if(a[i]==b[j])
	   {
		   i++;j++;
	   }
		else
		{
			index++;//失败的话回溯位置加一
			i=index;//i还原
			j=0;//j变成0
		}
   }
		cout<<index;
	return 0;
}