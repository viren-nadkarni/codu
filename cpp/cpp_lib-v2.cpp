/*library program v.2 - using vector class*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int iday,imon,iyr, rday,rmon,ryr, roll, entry, ifault=0,rfault=0, rfig,ifig, dur;
	char conf='n';
	string name, book;
	
	vector <string> vName;
	vector <string> vBook;
	vector <int> vRoll;
	vector <int> vDur;
	
	vector <int> vIday;
	vector <int> vImon;
	vector <int> vIyr;
	
	vector <int> vRday;
	vector <int> vRmon;
	vector <int> vRyr;
	
	do
	{
		entry=vName.size()+1;
		cout << "ENTRY NO. " << entry;
		
		cout << "\nEnter name of the student: ";
		getline(cin,name);
		vName.push_back(name);
		
		cout << "Enter roll number: ";
		cin >> roll;
		vRoll.push_back(roll);
		cin.ignore();
		
		cout << "Enter book name: ";
		getline (cin,book);
		vBook.push_back(book);
		
		do
		{
			ifault=0;
			cout << "Enter issue date (DD MM YYYY): ";
			cin >> iday >> imon >> iyr;
			
			if (iday>31||iday<1||imon>12||imon<1||iyr<2011)
			{
				cout << "Invalid date. Please try again..." << endl;
				ifault=1;
			}
			else
			{
				vIday.push_back(iday);
				vImon.push_back(imon);
				vIyr.push_back(iyr);
			}
		} while(ifault==1);
		
		do
		{
			rfault=0;
			cout << "Enter return date (DD MM YYYY): ";
			cin >> rday >> rmon >> ryr;
			
			ifig=iday+(30*imon)+((iyr-2011)*365);
			rfig=rday+(30*rmon)+((ryr-2011)*365);
			dur=rfig-ifig;
			
			if (rday>31||rday<1||rmon>12||rmon<1||ryr<2011||dur<0 )
			{
				cout << "Invalid date. Please try again..." << endl;
				rfault=1;
			}
			else
			{
				vRday.push_back(rday);
				vRmon.push_back(rmon);
				vRyr.push_back(ryr);
			}
		} while(rfault==1);
		
		ifig=iday+(30*imon)+((iyr-2011)*365);
		rfig=rday+(30*rmon)+((ryr-2011)*365);
		dur=rfig-ifig;
		
		vDur.push_back(dur);
		
		cout << "\nEnter another entry? (y/n)\n==>";
		cin >> conf;
		cout << "-------------------\n";
		cin.ignore();
	} while(conf=='y');
	
	
	int menu, entry_, tmpa=1,tmpb=0, mem=0, quitp=0, sz=vDur.size(), dura[20],l,m=0,n=0,found=0;
		
	do{
		cout << "Please select an action and enter relevent number\n"
			<< "1: View specific entry details\n"
			<< "2: View the borrower for longest period\n"
			<< "3: Exit the program\n==>";
			
		cin >> menu;
		cin.ignore();
		switch(menu)
		{
			case 1:
				cout << "Enter entry number: ";
				cin >> entry_;
				entry_=entry_-1;
				cout << "\nName: " << vName.at(entry_)
					<< "\nRoll number: " << vRoll.at(entry_)
					<< "\nBook borrowed: " << vBook.at(entry_)
					<< "\nIssued on: " << vIday.at(entry_) << "/" << vImon.at(entry_) << "/" << vIyr.at(entry_)
					<< "\nReturn date: " << vRday.at(entry_) << "/" << vRmon.at(entry_) << "/" << vRyr.at(entry_)
					<< "\nBorrowed for " << vDur.at(entry_) << " days\n-------------------\n";
				break;
			
			case 2:
				for(l=0;l<sz;l++)					//converts vector class to array
				{
					dura[l]=vDur.at(l);
				}
				n=m+1;
				while(n<sz)
				{
					if(dura[m]>dura[n])
						mem=m;
					else if(dura[m]<dura[n])
						mem=n;
					else
						mem=m;
					m=mem;
					n++;
				}
				cout << "\nThe following person borrowed book for longest period\n"
					<< "Name: " << vName.at(mem)
					<< "\nBorrowed for " << vDur.at(mem) << " days\n-------------------\n";
				break;
			
			case 3:
				quitp=1;
				break;
			
			default:
				cout << "Invalid menu option\n\n";
		}
	}while (quitp!=1);
	return 0;
}