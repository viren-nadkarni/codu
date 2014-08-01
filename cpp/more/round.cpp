#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
   double num;
   int x;
   cout << "Enter number: ";
   cin >> num;
   cout << "\nRound to? ";
   cin >> x;
   cout << setprecision(x) << fixed <<  num << endl;
   
   return 0;
}
