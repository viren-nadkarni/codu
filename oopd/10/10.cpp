#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
	ifstream f1("f1"),f2("f2"),f4;	
	ofstream f3("f3");

	char ch;
	cout << "\"f1\" contents: \n";
	while(1)
	{
		ch=f1.get();
		if(ch==EOF)
			break;
		f3 << (ch);
		cout << ch;
	}
	f1.close();
	
	cout << "\n\"f2\" contents: \n";
	while(1)
	{
		ch=f2.get();		
		if(ch==EOF)
			break;
		f3 << ch;
		cout << ch;
	}
	f2.close();
	f3.close();
	
	f4.open("f3");
	cout << "\n\"f3\" contents: \n";
	while(1)
	{
		ch=f4.get();
		if(ch==EOF)
			break;
		cout << ch;
	}
	f4.close();
	
	return 0;
}
