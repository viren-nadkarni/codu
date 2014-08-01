//operations on matrices
#include<iostream>

using namespace std;

int main()
{
	int mat1[10][10],mat2[10][10],mat3[10][10],elem,i=0,j=0,menu,divd,quitp,k=0;

	cout << "*** OPERATIONS ON MATRICES ***\n\nEnter number of rows/columns: ";
	cin >> elem;

	cout << "\nEnter elements for matrix 1:\n";
	for(i=0;i<elem;++i)
	{
		for(j=0;j<elem;++j)
		{
			cout << "Row " << i+1 << " Column " << j+1 << ": ";
			cin >> mat1[i][j];
		}
	}

	cout << "\n\nEnter elements for matrix 2:\n";
	for(i=0;i<elem;++i)
	{
		for(j=0;j<elem;++j)
		{
			cout << "Row " << i+1 << " Column " << j+1 << ": ";
			cin >> mat2[i][j];
		}
	}

	cout << "\n\nEntered matrices are: \n\n";
	for(i=0;i<elem;++i)
	{
		for(j=0;j<elem;++j)
			cout << mat1[i][j] << " ";
		cout << "\t";

		for(j=0;j<elem;++j)
			cout << mat2[i][j] << " ";
		cout << endl;
	}

	do{
		cout << "\n-------------------------\nPlease select an option:\n"
			<< "1::Add the two matrices\n"
			<< "2::Multiply the two matrices\n"
			<< "3::Divide the first matrix by a dividend\n"
			<< "4::Subtract first matrix from second\n"
			<< "5::Exit the program\n==>";
		cin >> menu;

		switch(menu)
		{
			case 1:
				for(i=0;i<elem;++i)
				{
					for(j=0;j<elem;++j)
						mat3[i][j]=mat1[i][j]+mat2[i][j];
				}
				cout << "\nSum of the matrices is:\n\n";
				for(i=0;i<elem;++i)
				{
					for(j=0;j<elem;++j)
						cout << mat3[i][j] << " ";
					cout << endl;
				}
				break;

			case 2:
				for(i=0;i<elem;++i)
				{
					for(j=0;j<elem;++j)
					{
						mat3[i][j]=0;
						for(k=0;k<elem;++k)
							mat3[i][j]+=mat1[i][k]*mat2[k][j];
					}
				}
				cout << "\nProduct of the matrices is:\n\n";
				for(i=0;i<elem;++i)
				{
					for(j=0;j<elem;++j)
						cout << mat3[i][j] << " ";
					cout << endl;
				}
				break;

			case 3:
				cout << "\nEnter the dividend by which first matrix is to be divided: ";
				cin >> divd;
				for(i=0;i<elem;++i)
				{
					for(j=0;j<elem;++j)
						mat3[i][j]=mat1[i][j]/divd;
				}
				cout << "\nResult of first matrix divided by " << divd << " is:\n\n";
				for(i=0;i<elem;++i)
				{
					for(j=0;j<elem;++j)
						cout << mat3[i][j] << " ";
					cout << endl;
				}
				break;

			case 4:
				for(i=0;i<elem;++i)
				{
					for(j=0;j<elem;++j)
						mat3[i][j]=mat2[i][j]-mat1[i][j];
				}
				cout << "\nThe difference is:\n\n";
				for(i=0;i<elem;++i)
				{
					for(j=0;j<elem;++j)
						cout << mat3[i][j] << " ";
					cout << endl;
				}
				break;

			case 5:
				quitp=1;
				break;

			default:
				cout << "\nInvalid option, try again...\n";
		}
	}while(quitp!=1);
	
	cin.get();
	return 0;
}

/*
OUTPUT

*** OPERATIONS ON MATRICES ***

Enter number of rows/columns: 3

Enter elements for matrix 1:
Row 1 Column 1: 5
Row 1 Column 2: 1
Row 1 Column 3: 2
Row 2 Column 1: 1
Row 2 Column 2: 4
Row 2 Column 3: 6
Row 3 Column 1: 2
Row 3 Column 2: 4
Row 3 Column 3: 3


Enter elements for matrix 2:
Row 1 Column 1: 4
Row 1 Column 2: 2
Row 1 Column 3: 3
Row 2 Column 1: 1
Row 2 Column 2: 5
Row 2 Column 3: 3
Row 3 Column 1: 4
Row 3 Column 2: 2
Row 3 Column 3: 5


Entered matrices are:

5 1 2   4 2 3
1 4 6   1 5 3
2 4 3   4 2 5

-------------------------
Please select an option:
1::Add the two matrices
2::Multiply the two matrices
3::Divide the first matrix by a dividend
4::Subtract first matrix from second
5::Exit the program
==>1

Sum of the matrices is:

9 3 5
2 9 9
6 6 8

-------------------------
Please select an option:
1::Add the two matrices
2::Multiply the two matrices
3::Divide the first matrix by a dividend
4::Subtract first matrix from second
5::Exit the program
==>2

Product of the matrices is:

29 19 28
32 34 45
24 30 33

-------------------------
Please select an option:
1::Add the two matrices
2::Multiply the two matrices
3::Divide the first matrix by a dividend
4::Subtract first matrix from second
5::Exit the program
==>3

Enter the dividend by which first matrix is to be divided: 2

Result of first matrix divided by 2 is:

2 0 1
0 2 3
1 2 1

-------------------------
Please select an option:
1::Add the two matrices
2::Multiply the two matrices
3::Divide the first matrix by a dividend
4::Subtract first matrix from second
5::Exit the program
==>4

The difference is:

-1 1 1
0 1 -3
2 -2 2

-------------------------
Please select an option:
1::Add the two matrices
2::Multiply the two matrices
3::Divide the first matrix by a dividend
4::Subtract first matrix from second
5::Exit the program
==>5

*/