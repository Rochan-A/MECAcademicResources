clc ; close all ; clear all

f = input('enter the first sequence: ')
n = input('enter the first index sequence: ')

g = input('enter the second sequence: ')
m = input('enter the second index sequence: ')

N=[min(n)+min(m):max(n)+max(m)]

convolution_by_function = conv(f,g)

f_1 = [zeros(1,length(g)),f,zeros(1,length(g))]

g_1 = fliplr(g)

for i = 1:length(f_1)-length(g)-1
    
    convolution_by_program(i) = sum((f_1).*([zeros(1,i),g_1,zeros(1,length(f_1)-length(g)-i)]))
    
end

clc

convolution_by_program

convolution_by_function

N

figure(1)
subplot(2,1,1) , stem(N,convolution_by_program)
subplot(2,1,2) , stem(N,convolution_by_function)

figure(2)
subplot(2,1,1) , stem(n,f)
subplot(2,1,2) , stem(m,g)


