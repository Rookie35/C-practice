/*��Ŀ����������:����һ�������������մ�С�����˳�����������������������
 *����180����������Ϊ2 2 3 3 5 �����һ��������ҲҪ�пո�
 *��������������һ��long������ 
 *������������մ�С�����˳����������������������ӣ��Կո���������һ��������ҲҪ�пո� 
 *ʾ��1�� 
 *����
 *180 
 *��� 
 *2 2 3 3 5 
 *���ߣ�zheng kaifan
 *ʱ�䣺2019/03/31 
 */ 
#include<iostream>

using namespace std;

int main()
{
	long input;
	cin>>input;
	
	for(int i=2;i<=input;)
	{
		if(input%i==0)
		{
			cout<<i<<" ";
			input=input/i;
		}
		else i++;
	}
	return 0;
}  