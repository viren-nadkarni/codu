#include <iostream>
#include <iomanip>
//#include <conio.h>

using namespace std;

class Array
{
	private:
		int num[10];
	public:
		int n;
		void read();
		void display();

	friend void swap(Array *,Array *,int,int);
	friend void duplicate(Array *);

};

void swap(Array *,Array *,int,int);
void duplicate(Array *);

void swap(Array * a,Array * b,int m,int n)
{
	int tmp;

	tmp=a->num[m];
	a->num[m]=b->num[n];
	b->num[n]=tmp;
}

void duplicate(Array * a)
{
	for(int i=0 ; i<a->n ; ++i)
	{
		for(int j=i+1 ; j<a->n ; ++j)
		{
			if(a->num[i] == a->num[j])
			{
				for(int k=i ; k<a->n-1 ; ++k)
    				a->num[k] = a->num[k+1];

                a->n--;
			}
		}
	}
}

void Array::read()
{
	cout << "\nEnter the elements: ";
	for(int i=0;i<n;++i)
		cin >> num[i];


}

void Array::display()
{
	cout << endl;
	for(int i=0;i<n;++i)
		cout << num[i] << " ";
}

int main()
{
//	clrscr();

	int m,n;
	Array a,b;

	cout << "\nEnter number of elements: ";
	cin >> a.n;
	b.n=a.n;

	cout << "\nArray A";
	a.read();

	cout << "\nArray B";
	b.read();

	cout << "\nSwap element 'x' in A with 'y' in B. Enter x & y: ";
	cin >> m >> n;
	m--;
	n--;

	swap(&a,&b,m,n);

	cout << "\nArrays after swap() are:\nA: ";
	a.display();
	cout << "\nB: ";
	b.display();

	duplicate(&a);
	duplicate(&b);

	cout << "\n\nThe arrays after duplicate() are: \nA: ";
	a.display();
	cout << "\nB: ";
	b.display();

	cin.get();
//	getch();
	return 0;
}
