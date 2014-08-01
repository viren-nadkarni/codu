clc;clear all;
num=[1];
den=[1,-0.091,-1.4299,0.2789,0.4048,-0.1823,0.0316];
[K,c]=tf2latc(num,den)
