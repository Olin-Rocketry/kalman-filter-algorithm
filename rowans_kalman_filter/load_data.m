test_data = csvread('dtl1.csv', 1);

figure(1)
clf
hold on
plot(test_data(:,1), test_data(:,3))
plot(test_data(:,1), test_data(:,5))
hold off




