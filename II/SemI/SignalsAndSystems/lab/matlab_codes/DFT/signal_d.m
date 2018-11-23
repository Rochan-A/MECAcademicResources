function [d] = signal_d(f,m)
N=length(f)
n=[0:N-1]
g=exp(-j*((2*pi)/N)*m*n)
%d=[zeros(1,N)]
%i = 1:N 
d=sum(f.*g)
end