#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int conv(int, int);
int conv(int a, int p)
{
	int b;

	if(p==0)			//if 0, octal->bin else if 1, bin->oct
	{
		switch(a)
		{
			case 0:
				b=000;
				break;
			case 1:
				b=001;
				break;
			case 2:
				b=010;
				break;
			case 3:
				b=011;
				break;
			case 4:
				b=100;
				break;
			case 5:
				b=101;
				break;
			case 6:
				b=110;
				break;
			case 7:
				b=111;
				break;
		}	
	}
	else if(p==1)
	{
		switch(a)
		{
			case 000:
				b=0;
				break;			
			case 001:
				b=1;
				break;			
			case 010:
				b=2;
				break;			
			case 011:
				b=3;
				break;			
			case 100:
				b=4;
				break;
			case 101:
				b=5;
				break;			
			case 110:
				b=6;
				break;			
			case 111:
				b=7;
				break;
		}
	}
	return (b);
}
		

class BinOct
{
	public:
		long int inp, out;
		char type;
	
		void getnum();
		void putnum();
		void stage();
			
};

void BinOct::getnum()
{
	cout << "\nEnter the ";
	if(type=='b')
		cout << "binary value: ";
	else 
		cout << "octal value: ";
	cin.ignore();
	cin >> inp;
}

void BinOct::putnum()
{
	cout << "\nThe output in ";
	if(type=='b')
		cout << "octal is: ";
	else 
		cout << "binary is: ";

	cout << out << endl;
}

void BinOct::stage()
{
	if(type=='b')
	{
		int tmp,i=0;
		out=0;
		
		while(inp!=0)
		{
			tmp=conv(inp%1000,1);
			out+=pow(10,i)*tmp;
			inp/=1000;
			++i;
		}
	
	}
	
	else 
	{
		int tmp,i=0;
		out=0;
		
		while(inp!=0)
		{
			tmp=conv(inp%10,0);
			out+=pow(10,i)*tmp;
			inp/=10;
			i+=3;
		}	
	}
	
}


int main()
{
	int menu;
	BinOct x;

	do
	{
		cout << "\n1: Convert binary to octal"
			<< "\n2: Convert octal to binary"
			<< "\n3: Exit\n=> ";
		cin >> menu;

		switch(menu)
		{
			case 1:
				x.type='b';
				x.getnum();
				x.stage();
				x.putnum();
				break;

			case 2:
				x.type='o';
				x.getnum();
				x.stage();
				x.putnum();
				break;

			case 3:
				cout << "Exiting program...\n";
				break;

			default:
				cout << "_Invalid selection\n";
				break;
		}

	} while(menu!=3);

	cin.get();
	return 0;
}
