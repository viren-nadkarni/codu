clc;clear all;
num=[1,-1.4,0.26,1.544,-0.576,-0.414];
den=[1];
[K,c]=tf2latc(den,num)
