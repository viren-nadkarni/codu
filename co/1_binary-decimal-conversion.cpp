/* Write a OOP to implement conversion from decimal to signed
 * magnitude binary and vice versa.
 */
#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

class BinDec
{
private:
	long float inp;
	char type, out[20];

public:
	void getnum();
	void putnum();
	void stage();

	friend int main();

};

void BinDec::getnum()
{
	cout << "\nEnter the ";
	if(type=='b')
		cout << "binary value: ";
	else 
		cout << "decimal value: ";
	cin.ignore();
	cin >> inp;
}

void BinDec::putnum()
{
	cout << "\nThe output in ";
	if(type=='b')
		cout << "decimal is: ";
	else 
		cout << "binary is: ";

	cout << out << endl;
}

void BinDec::stage()
{
	if(type=='d')
	{
		bool negative=false, right=false;
		int tmp;
		float r,l;

		//init the output array to 0's
		for(int i=0;i<20;++i)
			out[i]='0';
		out[20]='\0';

		//set sign bit and dot
		if(inp>=0)
			out[0]='0';
		else if(inp<0)
		{
			out[0]='1';
			inp=-inp;
		}
		out[8]='.';

		//split into left and right parts
		tmp=(int)inp;
		r=inp-tmp;
		l=inp-r;
				
		//do the conversion
		{
			int i=0, m, n=(int)l, p=7;
			char xar[20];
			while(n>0)
			{
				m=n%2;
				if(m==0)
					xar[i]='0';
				else if(m==1)
					xar[i]='1';
				n/=2;
				++i;
			}

			for(int j=0;j<i;++j)
			{
				out[p]=xar[j];
				--p;
			}
		}

		//do the conversion after decimal point
		{
			int x, ct=9;
			float temp_r=r, intermed=10;

			while(intermed!=0.0)
			{
				intermed=2*temp_r;
				x=(int)intermed;

				if(x==0)
					out[ct]='0';
				else if(x==1)
				{
					out[ct]='1';
					intermed-=1.0;
				}

				temp_r=intermed;
				++ct;
				
				if(ct==19)
					break;
			}
		}

	}

	else if(type=='b')
	{
		int sign=0,tmp,l,count=0;
		float r;

		//find the sign bit, set sign in output and decimal point
		sign=(int)(inp/10000000);
		if(sign==1)
		{
			out[count]='-';
			count++;
		}

		//split into left and right parts
		l=(int)inp;
		r=inp-l;
		if(sign==1)
			l=l-10000000;

		//convert the left part
		int out_tmp=0, l_tmp=l,x,i=0,j=0;
		char outltmp[10];
		while(l_tmp>0)					//stores converted value as an int
		{
			x=l_tmp%10;
			out_tmp+=x*pow(2.0,i);
			++i;
			l_tmp/=10;
		}
		for(i=0;out_tmp>0;++i)			//converts the int to a reverse array of char
		{
			x=out_tmp%10;
			outltmp[i]=48+x;
			out_tmp/=10;
		}
		
		for(int k=i-1;k>=0;--k)			//corrects the reversed array of char and stores it to final char array out[]
		{
			out[count]=outltmp[k];
			count++;
		}
		out[count]='.';
		count++;
		
		//converts the right part, answer is stored as int
		x=0;
		j=-1;
		float iTemp=0;
		char outrtmp[10];
		while(r!=0.0)
		{
			r*=10;
			x=(int)r;
			iTemp+=x*pow(2.0,j);
			if(x==1)
				r-=1.0;
			--j;
			if(j==-8)
				break;
		}
		
		//converts the int answer to char array
		x=0;
		while(iTemp!=0.0)
		{
			x=(int)(iTemp*10);
			out[count]=48+x;
			++count;
			iTemp*=10;
			if(x>0)
				iTemp-=x;
			if(count==18)
				break;
		}
		out[count]='\0';
	}
}


int main()
{
	int menu;
	BinDec x;

	do
	{
		cout << "\n1: Convert binary to decimal"
			<< "\n2: Convert decimal to binary"
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
				x.type='d';
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
