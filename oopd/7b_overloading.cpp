#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

class Matrix
{
	private:
		int ** arr;
		int m,n;
	public:
		Matrix(void){};
		Matrix(int,int);
		Matrix(int,int,bool);
		void get();
		void put();
		Matrix operator-(Matrix);
		
	friend int main();
};

Matrix::Matrix(int a,int b,bool flag)
{
	m=a;
	n=b;
	
	arr=new int *[m];
	
	for(int i=0;i<m;++i)
		arr[i]=new int [n];
}

Matrix::Matrix(int a,int b)
{
	m=a;
	n=b;
	
	arr=new int *[m];
	
	for(int i=0;i<m;++i)
		arr[i]=new int [n];
	
	get();
}

void Matrix::get()
{
	cout << "Enter values: \n";
	for(int i=0;i<m;++i)
	{
		for(int j=0;j<n;++j)
			cin >> arr[i][j];
	}
	
}

void Matrix::put()
{
	cout << endl;
	
	for(int i=0;i<m;++i)
	{
		for(int j=0;j<n;++j)
		{
			cout << arr[m][n] << "\t";
		}
		cout << endl;
	}
}

Matrix Matrix::operator-(Matrix x)
{
	Matrix temp;
	
	for(int i=0;i<m;++i)
		for(int j=0;j<n;++j)
			temp.arr[i][j]=arr[i][j]-x.arr[i][j];
	
	return (temp);
}

int main()
{
	int s,q,o,p;
	
	cout << "Matrix A: ";
	cout << "\nEnter size: ";
	cin >> s >> q;
	Matrix a(s,q);
	
	cout << "\nMatrix B: ";
	cout << "\nEnter size: ";
	cin >> o >> p;
	if(o!=s || p!=q)
	{
		cout << "Subtraction not possible";
		exit(1);
	}
	Matrix b(o,p);
	
	Matrix c(o,p,true);
	c=a-b;
	cout << "a-b=";
	c.put();
	
	return 0;
}
