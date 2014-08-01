clear all;
close all;
f=input('enter the freq');
N=input('enter the number of samples');
w=2*pi*f;
alpha=(N-1)/2;
h=zeros(1,N);
for n=0:1:N-1
    if n~=(N-1)/2
    h(n+1)=sin(w*(n-alpha))/((n-alpha)*pi);
    h(n+1)=1-h(n+1);
    end
end
h(((N-1)/2)+1)=(w/pi);
rectangular_window=boxcar(N);
ham=hamming(N);
han=hanning(N);
black=blackman(N);
h1=h.*rectangular_window';
h2=h.*ham';
h3=h.*han';
h4=h.*black';
w=0:.01:pi;
H1=freqz(h1,1,w);
H2=freqz(h2,1,w);
H3=freqz(h3,1,w);
H4=freqz(h4,1,w);
plot(w/pi,abs(H1),'r',w/pi,abs(H2),'g',w/pi,abs(H3),'y',w/pi,abs(H4));
