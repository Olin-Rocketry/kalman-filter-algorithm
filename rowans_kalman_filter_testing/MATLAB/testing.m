data = readtable("altimeterfiles\flight131 austin.csv");
acc_us = timeseries(data.acc, data.time_acc);
alt_us = timeseries(data.alt(~isnan(data.alt)), data.time(~isnan(data.time)));
[acc_s, alt_s] = synchronize(acc_us, alt_us, "Uniform", "Interval", 0.05);
time = acc_s.Time;
alt = alt_s.Data / 3.2808;
acc = (acc_s.Data - 0.8) * 9.8;


dt = 0.05;
vel = 164;
pos = zeros(length(time), 1);
pos(1) = alt(1);
for i=2:length(time)
    vel = vel + dt * acc(i);
    pos(i) = pos(i-1) + vel * dt;
end


figure()
clf
plot(time, pos)