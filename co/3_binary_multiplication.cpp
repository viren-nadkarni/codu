#include <iostream>
#include <conio.h>
#include <math.h>

using namespace std;

int binmultip(int,int,int);
int binadd(int,int,int);
int binsub(int,int,int);

int binsub(int a,int b,int bit)
{
        int bor=0,ans=0,tmp,i,m,n;

        for(i=0;i<bit;++i)
        {
                m=(int)(a/pow(10.0,i))%10;
                n=(int)(b/pow(10.0,i))%10;

                if(bor==0)
                {
                        tmp=m-n;
                        if(tmp==1)
                        {
                                tmp=1;
                                bor=0;
                        }
                }
                else if(bor==1)
                {
                        tmp=m-n-bor;
                        if(tmp==0)
                                bor=0;
                        else if(tmp==-1)
                        {
                                bor=1;
                                tmp=1;
                        }
                        else if(tmp==-2)
                        {
                                bor=1;
                                tmp=1;
                        }
                }
                ans+=tmp*pow(10.0,i);
        }
        return (ans);

}

int binmultip(int a,int b,int bit)
{
	int ans=0,i,m;

	for(i=0;i<bit;++i)
	{
		m=(int)(b/pow(10.0,i))%10;
		ans=binadd(ans,a*m*pow(10.0,i),8);
	}
	return (ans);
}


int binadd(int a,int b,int bit)
{
	int car=0,ans=0,tmp,i,m,n;

	for(i=0;i<bit;++i)
	{
		m=(int)(a/pow(10.0,i))%10;
		n=(int)(b/pow(10.0,i))%10;

		if(car==0)
		{
			tmp=m+n;
			if(tmp==2)
			{
				tmp=0;
				car=1;
			}
		}
		else if(car==1)
		{
			tmp=m+n+car;
			if(tmp==1)
				car=0;
			else if(tmp==2)
			{
				car=1;
				tmp=0;
			}
			else if(tmp==3)
			{
				car=1;
				tmp=1;
			}
		}
		ans+=tmp*pow(10.0,i);
	}
	return (ans);
}


int main()
{
	int a,b,c;
//	clrscr();

	cout << "a  b\n";
	cin >> a >> b;
	c=binsub(a,b,8);
	cout << endl << c;

	getch();
	return 0;
}