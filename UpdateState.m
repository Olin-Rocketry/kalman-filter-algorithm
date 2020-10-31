% One Dimensional Update State Equation
% Alex Butler (@lxbtlr)

%Since there are quite a few new variables at play we're going
% to use the same data, but with different levels of confidence
% in the "radar" readings; specifically, Alpha & Beta

%Assumptions: 
% Readings every .5 s, Target is moving in one dimension,
% Target will start at 2000m away, with a predicted speed of 40m/s
starting_pos = 2000 + (rand(1)-.5)*1000;


Real_position = [starting_pos];
velocity = 0;
for i = 2:2000 
    velocity = [velocity (rand(1)+.5)*40];
    Real_position = [Real_position Real_position(1,i-1)+velocity(i)*.5];
    %since we are reading in terms of .5s, velocity (m/s) needs to be cut
    %in half
    
end
%%
figure(1);
hold on
grid on
t = linspace(1,2000,2000);
yyaxis left;
plot(t, velocity);
ylabel('Velocity (m/s)')
yyaxis right;
plot(t, Real_position);
ylabel('Position (m)')
xlabel('time (s)')
%%
% In this regime: alpha = .2, beta = .1
alpha = .2;
beta = .1;

for k = 1:2000
    
    
    
    
end

