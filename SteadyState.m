%Initial work for single state kalman filter
%proof of concept
%Alex Butler (@lxbtlr) & Aydin O'leary (@zbwrm)

%our system is defined as a scale measuring weight of a gold bar. The bar
%is alledgedly the same mass, within a set (hidden) error-bound. 
%Using the metrics of the gold bar (height, length, width, & density) we
%will create an initial guess for the system. The new 'readings' for this
%model will be semi random, and change every timestep.


%metrics of gold bar:
%25 cm x 7 cm x 5 cm, 
%density: 19.32 g/cm^3

guess = 25*7*5 * 19.23;



%Setting up hidden errors for measurements
r1 = rand(1, 100);
r2 = rand(1, 100);

%tucking guess into readings
readings = [guess 17000 + (r1 - .5).*1000 + (r2 - .5).*200];
% alpha = 1/n    %% weight of the measurement

estimates = guess;
ESTIMATE = guess;
for i = 1:length(readings)-1
    temp =  ESTIMATE + (1/i)*(readings(i+1)-readings(i));

    estimates = [estimates temp]

end


hold on;
grid on;

plot(linspace(1,101,101), estimates, '--')
plot(linspace(1,101,101), readings, '.')
plot(linspace(1,101,101), ones(1,101).*estimates(101))
plot(linspace(1,101,101), ones(1,101).*guess)
hold off;
legend('Estimates','Measurements','True Value', 'Calculated Value')
percent_error = abs(estimates(101)-guess)/guess *100