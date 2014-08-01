#include <iostream>
#include <cstdlib>
#include <cstring>
#define ARRSIZE 2

using namespace std;

class Queue
{
	private:
		int front,rear;
		int items[ARRSIZE];
	public:
		Queue(){front=0;rear=-1;};
		void enq(int);
		int deq(void);
};

void Queue::enq(int tmp)
{
	try
	{
		if(rear>ARRSIZE)
			throw (1);
		else
			items[++rear]=tmp;
	}
	
	catch(int exp)
	{
		cout << "_queue overflow\n";
		cin.get();
		exit(1);
	}
}

int Queue::deq(void)
{
	int x;
	try
	{
		if(rear<front)
			throw (1);
		else
			x=items[front--];	
	}	
	catch(int exp)
	{
		cout << "_queue underflow\n";
		cin.get();
		exit(1);
	}
	return (x);
}

int main()
{
	Queue q;
	char stat[11];
	int integer;
	
	cout << "Array size is " << ARRSIZE+1;
	cout << "\nTo enqueue, type: enqueue <int>\nTo dequeue, type: dequeue\n$ ";
	
	while(1)
	{
		cin >> stat;
		if(stat [0]=='e' && stat[1]=='n')
		{
			cin >> integer;
			q.enq(integer);
			cout << "$ ";
		}
		else if(stat [0]=='d' && stat[1]=='e')
		{
			cout << (integer=q.deq());
			cout << "\n$ ";
		}
		else 
			cout << "\n$ ";
	}	
	return 0;
}
