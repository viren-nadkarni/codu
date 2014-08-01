clc;clear all;close all;
x = input('Enter the 1st sequence : ');  
h = input('Enter the 2nd  sequence : ');   
y =conv(x,h);
subplot(2,3,1);stem(x);
ylabel('(x) ------>');
xlabel('(a)n ------>');
subplot(2,3,2);stem(h);
ylabel('(h) ------>');
xlabel('(b)n ------>');
title('Discrete Convolution');
subplot(2,3,3);stem(y);
ylabel('(y) ------>');
xlabel('(c)n ------>');
disp(' The resultant Signal is :');y

