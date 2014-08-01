#include <iostream>
#include <string>
#include <cstring>

using namespace std;

struct NameList
{
	char a[30];
};

int main()
{
	int num;
	NameList m[30];
	
	cout << "Enter no. of names to be entered: ";
	cin >> num;
	
	cout << "Enter the names:\n";
	for(int i=0;i<num;++i)
	{
		cout << "(" << i+1 << "):\t";
		cin >> m[i].a;
	}
	
	cout << "\nSorting in ascending order:\n";
	for(int j='a';j<'z';++j)
	{
		for(int i=0;i<num;++i)
		{
			if(m[i].a[0]==j)
				cout << "\n> " << m[i].a;
		}
	}
	cout << endl;
	
	return 0;
}
	
