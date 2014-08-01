%dft(xn,N)
clc;clear all;close all;
xn=[1 1 1 1 0 0 0 0];
N=8;
L=length(xn);
if(N<L)
error(' N must be >=L')
end
x1=[xn zeros(1,N-L)];
for k=0:1:N-1;
for n=0:1:N-1;
        p=exp(-i*2*pi*n*k/N);
x2(k+1,n+1)=p;
end
end
Xk=x1*x2.';
%xn=[1 1 1];
%N=50;
%Xk=dft(xn,N);
magXk=abs(Xk);Xk

k=0:N-1;
plot(k,magXk);
grid
ylabel('mag|X(k)| ------>');
xlabel('n values------>');
