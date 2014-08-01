#include <iostream>
#include <cstdlib>

using namespace std;

class Complex
{
     public:
        float x,y;
        
        Complex(int a,int b)
        {
            x=(float)a;
            y=(float)b;
        };
        
        Complex(float a,float b)
        {
        	x=a;
        	y=b;
		};
		
		Complex(int a)
        {
        	x=(float)a;
        	y=0;
		};
		
		Complex(float a)
        {
        	x=a;
        	y=0;
		};
		void display();
		Complex operator+(Complex);
};

Complex Complex::operator+(Complex b)
{
	Complex tmp(0,0);
	
	tmp.x=x+b.x;
	tmp.y=y+b.y;
	
	return tmp;
}

void Complex::display()
{
	cout << x << " + " << y << "i\n";
}

int main()
{
	cout << "Init first complex number: 2+4i\n";
	Complex a(2,4);
	
	cout << "Init second complex number: 5+0i\n";
	Complex b(5);
	
	cout << "Init third complex number: 6.8+0.9i\n";
	Complex c((float)6.8,(float)0.9);
	
	cout << "(2+4i) + (5+0i) = ";
	Complex ans(0,0);
	ans=a+b;
	ans.display();
	
	cout << "(2+4i) + (6.8+0.9i) = ";
	Complex bns(0,0);
	bns=a+c;
	bns.display();
	
	return 0;
}
/*
Init first complex number: 2+4i
Init second complex number: 5+0i
Init third complex number: 6.8+0.9i
(2+4i) + (5+0i) = 7 + 4i
(2+4i) + (6.8+0.9i) = 8.8 + 4.9i

*/
