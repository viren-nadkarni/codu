#include <iostream>
using namespace std;

int main()
{
	//declarations
	string name1, name2, book;
	int roll, ret_d, ret_m, ret_y, iss_d, iss_m, iss_y;
	int duration, iss_fig, ret_fig;
	char flag_loop, x_iss, x_ret;
	
	//input
	do
	{
		//data reset
		/*roll=0;
		ret_d=0;
		ret_m=0;
		ret_y=0;
		iss_d=0;
		iss_m=0;
		iss_y=0;
		flag_loop='n';
		x_iss='n';
		x_ret='n';*/

		//main algorithm
		cout << "Enter the name of the student (FIRST LAST):" << endl;
		cin >> name1 >> name2;
		cout << "Enter the roll number of the student:" << endl;
		cin >> roll;
		cout << "Enter the name of the book:" << endl;
		cin >> book;
		do
		{
			cout << "Enter the issue date (DAY MONTH YEAR):" << endl;
			cin >> iss_d >> iss_m >> iss_y;
			if (iss_d>31||iss_d<1||iss_m>12||iss_m<1||iss_y<2011)
			{
				cout << "Invalid date. Please try again..." << endl;
				x_iss='y';
			}
			else
			{
				x_iss='n';
			}
		}while(x_iss=='y');


		do
		{
			cout << "Enter the return date (DAY MONTH YEAR):" << endl;
			cin >> ret_d >> ret_m >> ret_y;
			if (ret_d>31||ret_d<1||ret_m>12||ret_m<1||ret_y<2011)
			{
				cout << "Invalid date. Please try again..." << endl;
				x_ret='y';
			}
			
			
			else
			{
				x_ret='n';
			}

			//can you time travel?			
			iss_fig=iss_d+(30*iss_m)+((iss_y-2011)*365);
			ret_fig=ret_d+(30*ret_m)+((ret_y-2011)*365);
			duration=ret_fig-iss_fig;

			if (duration<0)
			{
				cout << "Time machines havn't been invented yet!" << endl << "Please enter a date after " << iss_d << "/" << iss_m << "/" << iss_y << endl;
				x_ret='y';
			}

		}while(x_ret=='y');
		
		//calculates the no of days the book was borrowed for
		iss_fig=iss_d+(30*iss_m)+((iss_y-2011)*365);
		ret_fig=ret_d+(30*ret_m)+((ret_y-2011)*365);
		duration=ret_fig-iss_fig;

		//output
		cout << endl << "STUDENT: " << name1 << " " << name2 << endl << "ROLL NO: " << roll << endl;
		cout << "BOOK: " << book << endl << "ISSUE DATE: " << iss_d << "/" << iss_m << "/" << iss_y << endl;
		cout << "RETURN DATE: " << ret_d << "/" << ret_m << "/" << ret_y << endl;
		cout << "BORROWED " << book << " FOR " << duration << " DAYS" << endl << endl;
		
		//loop confirmtion
		cout << "Press 'y' to display another set" << endl;
		cin >> flag_loop;
		cout << endl << endl;
	}while(flag_loop=='y');
	
	return 0;
}
