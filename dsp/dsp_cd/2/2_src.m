% program for generation of unit sample
clc;clear all;close all;
t = -3:1:3;
y = [zeros(1,3),ones(1,1),zeros(1,3)];
subplot(2,2,1);stem(t,y);
ylabel('Amplitude------>');
xlabel('(a)n ------>');
title('Unit Impulse Signal');
% program for genration of unit step of sequence [u(n)- u(n)-N]
t = -4:1:4;
y1 = ones(1,9);
subplot(2,2,2);stem(t,y1);
ylabel('Amplitude------>');
xlabel('(b)n ------>');
title('Unit step');
% program for generation of ramp signal
n1 = input('Enter the value for end of the seqeuence ');   %n1 = <any value>7 %
x = 0:n1;
subplot(2,2,3);stem(x,x);
ylabel('Amplitude------>');
xlabel('(c)n ------>');
title('Ramp sequence');
% program for generation of exponential signal
n2 = input('Enter the length of exponential seqeuence ');   %n2 = <any value>7 %
t = 0:n2;
a = input('Enter the Amplitude');    %a=1%
y2 = exp(a*t);
subplot(2,2,4);stem(t,y2);
ylabel('Amplitude------>');
xlabel('(d)n ------>');
title('Exponential sequence');
disp('Unit impulse signal');y
disp('Unit step signal');y1
disp('Unit Ramp signal');x
disp('Exponential signal');x
