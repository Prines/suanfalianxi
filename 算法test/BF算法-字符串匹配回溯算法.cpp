#include <iostream>
using namespace std;

int main()
{
	//c���� scanf�ַ�����β�Զ����'\0'
   char a[10]={'a','b','c','a','b','c','a','c','b','\0'};
   char b[6]={'a','b','c','a','c','\0'};
   int index=0; //���index��Ϊ���ݱ�־
	int i=0;int j=0;
	while(a[i]!='\0'&&b[j]!='\0')
   {
	   if(a[i]==b[j])
	   {
		   i++;j++;
	   }
		else
		{
			index++;//ʧ�ܵĻ�����λ�ü�һ
			i=index;//i��ԭ
			j=0;//j���0
		}
   }
		cout<<index;
	return 0;
}