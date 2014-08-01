#include <iostream>
#include <conio.h>
using namespace std;

int x[20],h[10],nh,nx,xs,hs,y[30],yt,s[11][11],a[11];

void in()
{
    cout<<"Enter the no of samples in x(n) : ";
    cin>>nx;
    cout<<"Enter start position of samples in x(n) : ";
    cin>>xs;
    cout<<"\nEnter x(n)\n";
    for(int i=0;i<nx;i++)
        cin>>x[i];

    cout<<"Enter the no of samples in h(n) : ";
    cin>>nh;
    cout<<"Enter start position of samples in h(n) : ";
    cin>>hs;
    cout<<"\nEnter h(n)\n";
    for(int i=0;i<nh;i++)
        cin>>h[i];

}

int getx(int k)
{
    k-=xs;
    if(k<0 || k>nx)
        return 0;
    return x[k];
}

int geth(int k)
{
    k-=hs;
    if(k<0 || k>nh)
        return 0;
    return h[k];
}

void matmul()
{
    int j;
    for(int i=0;i<nh+1;i++)
        for(j=0,a[i]=0;j<1;j++)
            for(int k=0;k<nh+1;k++)
                a[i]+=geth(k)*s[i][k];
}

void create(int p)
{
    p=-xs+p*nh;
    int i;
    for(i=0;i<nh+1;i++)
    {
        for(int j=0;j<nh+1;j++)
        {
            s[i][j]=getx(p+(i-j+nh+2)%(nh+1) -1);
        }
    }
}

void dispyi(int n)
{
    for(int i=xs;i<nx+xs+nh-1;i++)
        cout<<" "<<i<<" ";
    for(int i=0;i<n;i++)
    {
        cout<<"\n";
        for(int j=xs;j<nx+xs+nh-1;j++)
        {
            if(j==nh*i+xs+2*nh-2)
                cout<<"  X";
            else if(xs+i*nh<=j && j+1<xs+i*nh+2*nh-1)
                cout<<" "<<y[j-xs];
            else
                cout<<"  ";
        }
    }
}
void compute()
{
    int t=nx/nh;
    yt=xs+nx;
    int i;
    for(i=0;i<t;i++)
    {
        create(i);
        matmul();

        for(int j=0;j<nh;j++)
        {
            y[i*nh-xs+j]=a[j];
        }
    }
    dispyi(t);
}

int main()
{
    in();
    compute();
    cout<<"\n\ny(n)={";
    for(int i=0;i<yt-xs;i++)
        cout<<" "<<y[i];
    cout<<" }";

    cout<<"\nSamples of y start at "<<xs;
    getch();
    return 0;
}
