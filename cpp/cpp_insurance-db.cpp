/* insurance database
 * uses class to read details of given number of customers
 * reads name, address, ins. amt., policy date and maturity date
 * list names of customers who are insured before given date for given amount	*/
#include <iostream>
#include <iomanip>

using namespace std;

static int num=0;

class Insurance
{
	private:
		string name[20],address[20];
		float id[20],im[20],iy[20],md[20],mm[20],my[20],iad[20],mad[20];
		float amount[20];
	public:
		void readData(int);
		void printData(int);
		
	friend int main();
};

void Insurance::readData(int i)
{
	bool i_error=false, m_error=false;
	cout << "\n--- Entry no. " << num+1 << " ---";
	cout << "\nName: ";
	cin >>  name[i];
	
	cout << "Address: ";
	cin >> address[i];
			
	do
	{
		if(i_error)
			cout << "_Incorrect date, please try again\n";
		cout << "Insurance date (DD MM YYYY): ";
		cin >>  id[i] >> im[i] >> iy[i];
		i_error=true;
	} while(!(id[i]<31 && id[i]>0 && im[i]<13 && im[i]>0 && iy[i]>1900 && iy[i]<2100));
	
	iad[i]=(1900*iy[i]) + (12*im[i]) + id[i]; 
	
	do
	{
		if(m_error)
			cout << "_Incorrect date, please try again\n";
		cout << "Maturity date (DD MM YYYY): ";
		cin >> md[i] >> mm[i] >> my[i];
		m_error=true;
	} while(!(md[i]<31 && md[i]>0 && mm[i]<13 && mm[i]>0 && my[i]>1900 && my[i]<2100));
	
	mad[i]=(1900*my[i]) + (12*mm[i]) + md[i];
	
	cout << "Amount: Rs. ";
	cin >> amount[i];
	
	num++;
}

void Insurance::printData(int i)
{
	cout << "\n>>>(" << i+1 << ")";
	cout << "\n   Name: " << name[i];
	cout << "\n   Address: " << address[i];
	cout << "\n   Insurance date (DD MM YYYY): " << id[i] << " " << im[i] << " " << iy[i];
	cout << "\n   Maturity date (DD MM YYYY): " <<  md[i] << " " << mm[i] << " " << my[i];
	cout << "\n   Amount: Rs. " << setprecision(10) << amount[i];	
}


int main()
{
	int x,menu, da, ma, ya, sad;
	Insurance db;
	
	cout << "\n*** The Insurance Company ***\nEnter number of entries to be entered: ";
	cin >> x;
		
	for (int i=0;i<x;++i)
		db.readData(i);
	
	do
	{
		cout << "\n--- Menu ---\n1: Add a new entry\n2: List entries with amount greater than Rs. 1,00,000\n3: List entries with maturity date before\n4: Exit\n : ";
		cin >> menu;
		
		switch(menu)
		{
			case 1:
				db.readData(num+1);
				break;
				
			case 2:
				cout << "\nResults";
				for(int j=0;j<num;++j)
				{
					if(db.amount[j]>=100000)
						db.printData(j);
				}
				cout << "\n\t...\n";
				break;
				
			case 3:
				cout << "\nEnter date (MM DD YYYY): ";
				cin >> da >> ma >> ya;
				sad=(ya*1900)+(ma*12)+da;
				for(int k=0;k<num;++k)
				{
					if(sad>db.mad[k])
						db.printData(k);
				}
				break;
				
			default:
				cout << "Invalid selection...\n";
		}
	} while(menu!=4);
	
	return 0;
}
