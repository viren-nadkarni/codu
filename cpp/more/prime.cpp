#include <iostream>

using namespace std;

bool prime(int a);

int main()
{
	int max;
	bool t,flag;
	
	cout << "Enter max number: ";
	cin >> max;
	
	for(int i=0;i<max;++i)
	{
		flag=false;
		t=prime(i);
		if(i==0||i==1)
			flag=true;
		if(i==2)
		{
			cout <<endl <<  i << endl;
			flag=true;
		}
		if(!flag&&t&&!flag)
			cout << endl << i << endl;
	}
	
	return 0;
}

bool prime (int a)
{
	int i;
	bool tag=true;
	for(i=2;i<a;i++)
	{
		if(a%i==0)
		{
			tag=false;
			break;
			
		}
	}
	return tag;
}
