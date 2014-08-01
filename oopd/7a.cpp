#include <iostream>
#include <cstring>

using namespace std;

class Str
{
    public:
	char * a;
		Str(char x[])
		{
			a=new(char[strlen(x)+1]);
			strcpy(a,x);
		};
		Str(void){};
		Str operator+(Str);
		int operator<=(Str);
};

Str Str::operator+(Str b)
{
	Str temp;
	int i;

	temp=new(char[strlen(a)+strlen(b.a)+1]);
	for(i=0;i<strlen(a);++i)
	{
		temp.a[i]=a[i];
	}
	for(int j=0;j<strlen(b.a);++j)
	{
		temp.a[i++]=(b.a[j]);

	}
	temp.a[i]='\0';
	return (temp);
}

int Str::operator<=(Str b)
{
	int x,y;

	x=strlen(a);
	y=strlen(b.a);

	if(x<=y)
	    return (1);
	else return (0);
}

int main()
{
	char sent[64];

	cout << "String A: ";
	cin.getline(sent,64);
	Str A(sent);

	cout << "String B: ";
	cin.getline(sent,64);
	Str B(sent);

	cout << "\na<=b\t" << (A<=B);
	cout << "\n\na+b\t" << (A+B).a;

	return 0;
}



