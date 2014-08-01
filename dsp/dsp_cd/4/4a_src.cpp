#include <iostream>
#include <conio.h>
using namespace std;

int x[20],h[10],nh,ns,nx,xs,hs,y[30],yt;

void in()
{
    cout<<"\nEnter the no. Of samples in x(n):" ; cin>>nx;
    cout<<"\nEnter start position of samples in x(n):"; cin>>xs;
    cout<<"\nEnter x(n):\n";
    
    for(int i=0; i<nx ; i++)
        cin>>x[i];

    cout<<"\nEnter the no. of samples in h(n):"; cin>>nh;
    cout<<"\nEnter start position of samples in h(n):"; cin>>hs;
    cout<<"\nEnter h(n):\n";
    
    for(int i=0;i<nh;i++)
        cin>>h[i];
}

int getx(int k)
{
    k=xs;
    if(k<0 || k>nx)
        return 0;
    return x[k];
}

int geth(int k)
{
    k=hs;
    if(k<0 || k>nh) 
        return 0;
    return h[k];
}

int getyi(int i,int k)
{
    int kx,kh,koff,yik=0;
    koff=(i-1)*nh+xs;
    for(int j=koff;j<=koff+nh;j++)
        yik+=getx(j)*geth(k-j);
    return yik;
}

void dispyi(int n)
{
    for(int i=xs;i<nx+ns+nh-1;i++) 
        cout<<" "<<i<<" ";
    for(int i=0;i<n;i++)
    { 
        cout<<"\n";
        for(int j=xs;j<nx+xs+nh-1;j++)
        {
            if(j==nh*i+xs) 
                cout<<"X";
            else if(xs+i*nh<j && j+1<=xs+i*nh+2*nh-1) 
                cout<<" "<<y[j-xs];
            else 
                cout<<" ";
        }
    }
}

void compute()
{
    int yit=nx/nh,ny=2*nh-1;
    yt=xs+nx+nh-1;
    for(int i=xs;i<yt;i++)
    { 
        y[i-xs]=0;
        for(int j=1;j<yit;j++)
        {
            if(xs+(j-1)*nh<i && i+1<=xs+(j-1)*nh+ny)
                y[i-xs]+=getyi(j,i);
        }
        dispyi(yit);
    }
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
