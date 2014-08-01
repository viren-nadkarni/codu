#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#define FILE "eleclist.txt"
#define ENTRIES 4

using namespace std;

class Elec
{
	private:
		int units;
		float amt;
		string name;
		bool surcharge;

	public:
		void getdata(int line);
		void putdata();
		void calc();

};

void Elec::getdata(int line)
{
	ifstream ifile;

	ifile.open(FILE);
	
	for(int i=0;i<line;++i)
		ifile.ignore(32,'\n');
		
	ifile >> name >> units;

}

void Elec::putdata()
{
	cout << endl << name << "\t\t" << setw(5) << units << "\t\t";
	if(surcharge)
		cout << "15%\t\t";
	else
		cout << " 0%\t\t";
	cout << setw(6) << fixed << setprecision(2) << amt;
}

void Elec::calc()
{
	surcharge=false;
	
	if(units>=0 && units<100)
		amt=units*1.5;
	else if(units>=100 && units<200)
		amt=150+(units*1.8);
	else if(units>=200)
		amt=330+(units*1.8);

	if(amt<50)
		amt=50;

	if(amt>=300)
	{
		amt+=(amt*0.15);
		surcharge=true;
	}
}

int main()
{
	Elec a;
	int n=ENTRIES;

	cout << "\nName\t\tUnits\t  Surcharge\t\tAmount";
	
	for(int i=0;i<n;++i)
	{
		a.getdata(i);
		a.calc();
		a.putdata();
	}

	cin.get();
	return 0;
}
