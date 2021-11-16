% One Dimensional Update State Equation
% Alex Butler (@lxbtlr)

%Since there are quite a few new variables at play we're going
% to use the same data, but with different levels of confidence
% in the "radar" readings; specifically, Alpha & Beta

%Assumptions: 
% Readings every .5 s, Target is moving in one dimension,
% Target will start anywhere from 0m to 1000m away
data = table2array(readtable("python_kalman_filter/test_data/dtl1.csv"));

starting_pos = (rand())*1000; %m
expected_velocity = 40; %m/s
alpha = .1;
beta = .1;
gamme = .1;

real_position = [starting_pos];
meas_position = [starting_pos];
calc_position = [starting_pos];
calc_velocity = [expected_velocity];

for i = 2:2000 
    real_position = [real_position real_position(end)+20];
    new_meas_position = (meas_position(end) + (rand()-0.5)*10+20);
    meas_position = [meas_position new_meas_position];
    
    new_calc_position = calc_position(end) + alpha*(new_meas_position - calc_position(end));
    new_calc_velocity = calc_velocity(end) + beta*((new_meas_position - calc_position(end))/0.5);
    
    calc_position = [calc_position new_calc_position];
    calc_velocity = [calc_velocity new_calc_velocity];
    
end
%%
% calculate percent errors
error_meas = (real_position - meas_position) ./ (meas_position) * 100;
error_calc = (real_position - calc_position) ./ (calc_position) * 100;


t = linspace(1,2000,2000);

figure(1);
hold on
grid on
plot(t, calc_velocity, 'g-');
ylabel('Calculated Velocity (m/s)')
xlabel('Time (s)')

figure(2);
hold on
grid on
plot(t, calc_position, 'r.', 'DisplayName', 'calculated');
plot(t, meas_position, 'b.', 'DisplayName', 'measured');
plot(t, real_position, 'g-', 'DisplayName', 'real');
ylabel('Position (m)')
legend();
xlabel('time (s)')

figure(3);
hold on
grid on
plot(t, error_meas, 'DisplayName', 'Measured values')
plot(t, error_calc, 'DisplayName', 'Calculated values')
ylabel('Percent error from actual');
xlabel('Time (s)');
legend();