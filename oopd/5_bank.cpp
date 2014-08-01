#include <iostream>
#include <iomanip>

using namespace std;

class Bank
{
	private:
		char name[16];
		int bal;
	public:
		int ac;
		void read();
		void withdraw();
		void deposit();
		void disp();
};

bool ac_check(Bank *,int,int);          //return true if ac no already exists
bool ac_check(Bank x[],int ac_,int n)
{
	for(int i=0;i<n;++i)
	{
		if(x[i].ac == ac_)
		    return (true);
	}
	return (false);
}

void Bank::disp()
{
	cout << "Name: " << name;
	cout << "\nBalance: Rs." << bal;
}

void Bank::read()
{
	bool flag=false;

	cout << "Name: ";
	cin >> name;
	bal=0;
	cout << "Balance: Rs." << bal;
}

void Bank::withdraw()
{
	int with;
	bool flag;

	do
	{
		flag=false;

		cout << "Amount to be withdrawn: ";
		cin >> with;

		if(bal-with<0)
	    {
			cout << "! No enough balance to carry out transaction\n";
			flag=true;
		}
		else
		    bal-=with;
	} while(flag);
	
	cout << "Balance: Rs." << bal;
}

void Bank::deposit()
{
	int dep;

	cout << "Amount to be deposited: ";
	cin >> dep;
 	bal+=dep;

	cout << "Balance: Rs." << bal;
}


int main()
{
	Bank x[16];
	int n,ac,menu;
	bool flag,quit=false;
	
	cout << "Enter no. of entries: ";
	cin >> n;
	
	cout << "\nEnter the entry details:";
	for(int i=0;i<n;++i)
	{
		cout << "\n\n_Entry no. " << i+1 << endl;
		do
		{
			flag=false;
			cout << "Enter account no: ";
			cin >> ac;
			flag=ac_check(x,ac,n);
			if(flag)
		    	cout << "! Account no already exists, enter a different one\n";
			else
			    x[i].ac=ac;
		} while(flag);
		x[i].read();
	}
	
	do
	{
		cout << "\n\n_Main menu\n1::Deposit\n2::Withdraw\n3::View\n4::Exit\n=> ";
		cin >> menu;
		
		switch(menu)
		{
			case 1:
	        	flag=false;
				cout << "Enter account no: ";
				cin >> ac;
				for(int i=0;i<n;++i)
				{
					flag=ac_check(x,ac,n);
					if(flag)
					{
						x[i].deposit();
						break;
					}
				}
				if(!flag)
				    cout << "! Account no. does not exist\n";
    			break;
			case 2:
				flag=false;
				cout << "Enter account no: ";
				cin >> ac;
				for(int i=0;i<n;++i)
				{
					flag=ac_check(x,ac,n);
					if(flag)
					{
						x[i].withdraw();
						break;
					}
				}
				if(!flag)
				    cout << "! Account no. does not exist\n";
				break;
			case 3:
				flag=false;
				cout << "Enter account no: ";
				cin >> ac;
				for(int i=0;i<n;++i)
				{
					flag=ac_check(x,ac,n);
					if(flag)
					{
						x[i].disp();
						break;
					}
				}
				if(!flag)
				    cout << "! Account no. does not exist\n";
				break;
			case 4:
				quit=true;
		}
				
	} while(!quit);
	
	return 0;
	
}

	
