
clc;clear all;close all

array = input('enter the array:')
x1=array(1)
x2=array(2)
m=0
n=2

y=signal_f(x1,x2,m,n)

subplot(3,1,1),  stem(array) , xlim([-2,3])

subplot(3,1,2), stem(y) , xlim([-2,3])

subplot(3,1,3), stem(fft(array)) , xlim([-2,3])

