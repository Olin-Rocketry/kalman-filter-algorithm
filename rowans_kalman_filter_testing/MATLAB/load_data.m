%%==============real data with acc==================
data = readtable("altimeterfiles\flight131 austin.csv")
acc_us = timeseries(data.acc, data.time_acc);
alt_us = timeseries(data.alt(~isnan(data.alt)), data.time(~isnan(data.time)));
[acc_s, alt_s] = synchronize(acc_us, alt_us, "Uniform", "Interval", 0.05);
time = acc_s.Time;
alt = alt_s.Data / 3.2808;
acc = (acc_s.Data - 0.8) * 9.8;

figure()
clf
hold on
yyaxis right
plot(time, alt);
yyaxis left
plot(time, acc);



A  = [time, alt, acc];
writematrix(A,'C:\Users\rjansens\OneDrive - Olin College of Engineering\Documents\GitHub\kalman-filter-algorithm\phoenix_IV_functions\cpp_testing\test.txt','Delimiter',',');