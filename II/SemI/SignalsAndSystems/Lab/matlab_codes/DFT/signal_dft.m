clc ; close all ; clear all

f=input('enter the array:')


F=zeros(1,length(f))

for m=1:length(f)

    F(m)=signal_d(f,m-1)
    
end


for m=1:length(F)
   
    f_2(m) = abs(signal_id(F,m-1))
    
end




subplot(6,1,1) , stem(f)
subplot(6,1,3) , stem(abs(F))
subplot(6,1,4) , stem(abs(fft(f)))
subplot(6,1,2) , stem(abs(f_2))
subplot(6,1,5) , stem(angle(F))
subplot(6,1,6) , stem(angle(fft(f)))




