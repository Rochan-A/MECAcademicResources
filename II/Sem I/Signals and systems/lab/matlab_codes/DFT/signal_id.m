function [id] = signal_id(f,m)

N=length(f)

n=[0:N-1]

g=exp(j*((2*pi)/N)*m*n)

id=(sum(f.*g))/length(f)

end


