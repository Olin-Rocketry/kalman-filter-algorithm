function res = plot_res(T, true_state, noise_state, kalman_state)

    noise_error = abs(true_state - noise_state);
    kalman_error = abs(true_state - kalman_state);
    
    str1 = string(mean(kalman_error));
    str2 = string(mean(noise_error));
    disp("Mean Kalman position error: " + str1{1} + "m")
    disp("Mean Sensor position error: " + str2{1} + "m")
    disp("Mean Kalman velocity error: " + str1{2} + "m/s")
    disp("Mean Sensor velocity error: " + str2{2} + "m/s")
 

    figure(2)
    set(figure(2), "Position", [0 0 1200 600])
    clf
    
    
    
    subplot(1,2,1)

    yyaxis right
    hold on
    %plot(T, kalman_error(:,1), "b:", "Linewidth", 1)
    %plot(T, noise_error(:,1), "r:", "Linewidth", 1)
    hold off
    ylim([0 100])
    ylabel("Error (m)")

    yyaxis left
    hold on
    plot(T, true_state(:,1), "black", "Linewidth", 1)
    plot(T, noise_state(:,1), "r.", "Markersize", 10)
    plot(T, kalman_state(:,1), "b-", "Linewidth", 1)
    hold off
    xlabel("Time (s)")
    ylabel("Height (m)")

    
    
    subplot(1,2,2)
    
    yyaxis right
    hold on
    %plot(T, kalman_error(:,2), "b:", "Linewidth", 1)
    %plot(T, noise_error(:,2), "r:", "Linewidth", 1)
    hold off
    ylim([0 100])
    ylabel("Error (m/s)")

    yyaxis left
    hold on
    plot(T, true_state(:,2), "black", "Linewidth", 1)
    plot(T, noise_state(:,2), "r.", "Markersize", 10)
    plot(T, kalman_state(:,2), "b-", "Linewidth", 1)
    hold off
    xlabel("Time (s)")
    ylabel("Velocity (m/s)")


    

    legend("True Value", "Simulated Measurement", "Kalman Estimation", "Kalman Error", "Sensor Error" )