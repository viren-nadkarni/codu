#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Matrix
{
private:
	float **ar;
	int d1,d2;

public:
	Matrix()
	{
		cout << "Rows: ";
		cin >> d1;
		cout << "Columns: ";
		cin >> d2;
		initMatrix();
		getMatrix();
	};
	Matrix(int m,int n)
	{
		d1=m;
		d2=n;
		initMatrix();
	};

	Matrix operator*(Matrix);
	void initMatrix();
	void putMatrix();
	void getMatrix();

	friend int main();
};

void Matrix::initMatrix()
{
	ar=new float *[d1];
	for(int i=0;i<d1;++i)
		ar[i]=new float [d2];
	for(int i=0;i<d1;++i)
		for(int j=0;j<d2;++j)
			ar[i][j]=0;
}

void Matrix::putMatrix()
{
	for(int i=0;i<d1;++i)
	{
		for(int j=0;j<d2;++j)
			cout << setw(3) << ar[i][j] << "\t";
		cout << endl;
	}
}

void Matrix::getMatrix()
{
	for(int i=0;i<d1;++i)
	{
		cout << endl;
		for(int j=0;j<d2;++j)
		{
			cout << "Row " << i+1 << " Column " << j+1 << ": \t";
			cin >> ar[i][j];
		}
	}
}

Matrix Matrix::operator*(Matrix B)
{
	int i,j,k;
	Matrix temp(d1,B.d2);

	if(d2==B.d1)
	{
		for(i=0;i<d1;++i)
			for(j=0;j<B.d2;++j)
			{
				temp.ar[i][j]=0;
				for(k=0;k<B.d1;++k)
					temp.ar[i][j]+=ar[i][k]*B.ar[k][j];
			}
	}
	else
		cout << "\n_Matrix multiplication failed...\n";

	return temp;
}


int main()
{
	cout << "\nMatrix A\n";
	Matrix A;

	cout << "\nMatrix B\n";
	Matrix B;

	Matrix C(A.d1,B.d2);

	C=A*B;

	cout << "\nMatrix C (C=A*B)\n";
	C.putMatrix();

	return 0;
}
