clc ; clear all ; close all

y_0=randn(1,100000);



for i = 1:99000
    y_0_mean(i) = mean(y_0(1,i:1000+i));
end
for i = -49:50
    y_0_autocorelation(50+i) = mean((y_0(1,1000:2000)).*(y_0(1,1000+i:2000+i)));
end



[B,A]=butter(6,0.1);
y_1=filter(B,A,y_0);



for i = 1:99000
    y_1_mean(i) = mean(y_0(1,i:1000+i));
end
for i = -49:50
    y_1_autocorelation(50+i) = mean((y_1(1,1000:2000)).*(y_1(1,1000+i:2000+i)));
end



figure(1)
subplot(2,1,1) , stem(y_0_mean)
subplot(2,1,2) , stem(y_1_mean)


figure(2)
subplot(2,1,1) , stem(y_0_autocorelation)
subplot(2,1,2) , stem(y_1_autocorelation)

figure(3)
subplot(2,1,1) , histogram(y_0,50)
subplot(2,1,2) , histogram(y_1,50)


