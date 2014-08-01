//Prints the series
//	f(n) = (f(n-1)*f(n-2)) + 1
//	f(0)=1
//	f(1)=1
//makes use of a for loop
#include <iostream>

using namespace std;

int main()
{
	int terms, series[51];
	
	cout << "Enter the number of terms (max. 10): ";
	cin >> terms;
	
	series[0]=1;
	series[1]=1;
	
	for(int i=2 ; i<terms&&terms>1 ; ++i)
		series[i]=(series[i-1]*series[i-2])+1;
	
	cout << endl;
	for(int j=0; j<terms ;++j)
		cout << series[j] << "  ";
	
	cout << endl;
	return 0;
}
