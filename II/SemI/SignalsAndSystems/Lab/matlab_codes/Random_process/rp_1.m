clc ; close all ; clear all

y_0 = randn(10000);

for i = 1:10000
    y_0_mean(i) = mean(y_0(:,i));
end

for i = -4999:5000
    y_0_autocorelation(5000+i) = mean((y_0(:,5000)).*(y_0(:,5000+i)));
end

figure(1)
subplot(2,1,1) , stem(y_0_mean)
subplot(2,1,2) , stem(y_0_autocorelation)

figure(2)
subplot(1,1,1) , histogram(y_0,55)

