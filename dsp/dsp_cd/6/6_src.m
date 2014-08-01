%given the transfer function as 
%H(Z)=(1 -1.6180z^-1 +z^-2)/(1-1.5161z^-1+0.878z^-2) i.e H(Z)=b/a

b = [1 -1.6180 1];b
a = [1 -1.5161 0.878];a
zk=roots(b);zk
poles=roots(a);poles
zplane(b,a);
grid on

% we have obtained the zeros (zk) and the poles (poles) from above
% poly converts the poles and roots to a transfer function

B=poly(zk);B
A=poly(poles);A