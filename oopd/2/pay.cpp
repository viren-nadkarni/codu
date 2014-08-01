#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#define FILE "paylist.txt"
#define ENTRIES 4

using namespace std;

class Pay
{
	private:
		char name[32];
		float base, grade, gross, net, hra, da, cca, it, pf;
		
	public:
		void read(int);
		void calc();
		void disp();
};

void Pay::read(int line)
{
	ifstream ifile;
	
	ifile.open(FILE);

	for(int i=0;i<line;++i)
		ifile.ignore(32,'\n');

	ifile >> name >> base >> grade;
	
}

void Pay::calc()
{
	da=0.2*base;
	hra=0.2*base;
	cca=0.04*base;
	gross=da+cca+hra+base+grade;
	pf=0.06*base;
	it=0.1*base;
	net=gross-it-pf;
}

void Pay::disp()
{
	cout << endl << name << "\t" << fixed << setw(6) << setprecision(1) << base << "\t" << setw(6) 
		<< grade << "\t" << setw(6) << da << "\t" << setw(6) << hra << "\t" << setw(6) 
		<< cca << "\t" << setw(6) << pf << "\t" << setw(6) << it << "\t" << setw(6) 
		<< gross << "\t" << setw(6) << net;
}

int main()
{
	Pay a;
	int n=ENTRIES;

	cout << "\nName\tBase\tGrade\tDA\tHRA\tCCA\tPF\tIT\tGross\tNet";
	
	for(int i=0;i<n;++i)
	{
		a.read(i);
		a.calc();
		a.disp();
	}

	cin.get();
	return 0;
}
