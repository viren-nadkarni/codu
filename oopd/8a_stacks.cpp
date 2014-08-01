#include <iostream>
#include <cstdlib>
#include <cstring>
#define ARRSIZE 1

using namespace std;

class Stack
{
	private:
		int top;
		int items[ARRSIZE];
	public:
		Stack(){top=-1;};
		void push(int);
		int pop(void);
};

void Stack::push(int tmp)
{
	try
	{
		if(top+1>ARRSIZE)
			throw (1);
		items[++top]=tmp;
	}
	
	catch(int exp)
	{
		if(exp==1)
			cout << "_stack overflow\n";
		else if(exp==-1)
			cout << "_stack underflow\n";
		cin.get();
		exit(1);
	}
}

int Stack::pop(void)
{
	int x;
	try
	{
		if(top-1<-1)
			throw (-1);
		x=items[top--];
	}
	
	catch(int exp)
	{
		if(exp==1)
			cout << "_stack overflow\n";
		else if(exp==-1)
			cout << "_stack underflow\n";
		cin.get();
		exit(1);
	}
	return (x);
}

int main()
{
	Stack s;
	char stat[11];
	int integer;
	
	cout << "Array size is " << ARRSIZE+1;
	cout << "\nTo push, type: push <int>\nTo pop, type pop\n$ ";
	
	while(1)
	{
		cin >> stat;
		if(stat [0]=='p' && stat[1]=='u')
		{
			cin >> integer;
			s.push(integer);
			cout << "$ ";
		}
		else if(stat [0]=='p' && stat[1]=='o')
		{
			cout << (integer=s.pop());
			cout << "\n$ ";
		}
		else 
			cout << "\n$ ";
	}
	
	return 0;
}
/*

Array size is 2
To push, type: push <int>
To pop, type pop
$ push 10
$ push 20
$ push 30
_stack overflow

Fund12@fund12-6ca249f4 /cygdrive/c/Documents and Settings/Fund12/Desktop
$ g++ sharand.cpp && ./a.exe
Array size is 2
To push, type: push <int>
To pop, type pop
$ push 10
$ pop
10
$ pop
_stack underflow
*/
