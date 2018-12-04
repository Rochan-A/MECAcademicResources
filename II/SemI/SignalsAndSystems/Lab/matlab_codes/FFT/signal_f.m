function [y] = signal_f(x,m,n)

Wn=exp((j*2*pi)*(m/n))

y1=x(1)+Wn*x(2)

y2=x(1)-Wn*x(2)

y=[y1,y2]

end
