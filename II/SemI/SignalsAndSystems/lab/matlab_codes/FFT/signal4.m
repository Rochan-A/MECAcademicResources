clc;clear all; close all

array=input('enter the array:')

x1=array(1)
x2=array(2)
x3=array(3)
x4=array(4)

even=[x1,x3]
odd=[x2,x4]

q1=signal_f(even,0,2)
q2=signal_f(odd,0,2)

Q1=[q1(1),q2(1)]
Q2=[q1(2),q2(2)]

Y=[signal_f(Q1,0,4),signal_f(Q2,1,4)]

F=fft(array)

subplot(3,1,1),  stem(array) , xlim([-2,6])

subplot(3,1,2), stem(Y) , xlim([-2,6])

subplot(3,1,3), stem(F) , xlim([-2,6])


