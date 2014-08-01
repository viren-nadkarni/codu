#include <iostream.h>

int main()
{
	int stck[30],num=0,menu,quitp=0;

	do
	{
		cout << "\n--- Menu ---\n"
			<< "1::View stack\n2::Push element\n3::Pop element\n4::Show the top element\n5::Exit\n==>";
		cin >> menu;

		switch(menu)
		{
			case 1:
			{
				for(int i=num-1;i>=0;--i)
				{
					cout << "\n(" << i << ") " << stck[i] << endl;
				}
				break;
			}
			case 2:
			{
				cout << "\nEnter element: ";
				cin >> stck[num];
				num++;
				break;
			}
			case 3:
			{
				stck[num]=0;
				num--;
				break;
			}
			case 4:
			{
				cout << "\n(" << num-1 << ") " << stck[num-1] << endl;
				break;
			}
			case 5:
			{
				quitp=1;
				break;
			}
		}
	}while(quitp!=1);

	return 0;
}