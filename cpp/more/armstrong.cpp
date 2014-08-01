//armstrong numbers

#include <iostream>

using namespace std;

bool armst(int);

int main()
{
	int m,n;
	bool tag;
	
	cout << "\n\nEnter range: ";
	cin >> m >> n;
	
	for(int w=m; w<n ; w++)
	{
		tag=armst(w);
		if (tag)
			cout << w << endl;
	}
	
	
	return 0;
}

bool armst(int num)
{
	int sum=0, x=num, p;
	
	while(x>0)
	{
		p=x%10;
		sum+=(p*p*p);
		x/=10;
	}
	
	if(num==sum)
		return (true);
	else 
		return (false);
}
