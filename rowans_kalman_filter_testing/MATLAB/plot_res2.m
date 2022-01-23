function res = plot_res2(T, noise_state, old_method, kalman_state)


    
 

    figure(2)
    set(figure(2), "Position", [0 0 1200 600])
    clf
    
    
    
    subplot(1,2,1)



    hold on
    plot(T, old_method(:,1), "k", "Markersize", 10)
    plot(T, noise_state(:,1), "r.", "Markersize", 10)
    plot(T, kalman_state(:,1), "b-", "Linewidth", 1)
    hold off
    xlabel("Time (s)")
    ylabel("Height (m)")

    
    
    subplot(1,2,2)
    

    hold on
    plot(T, old_method(:,2), "k", "Markersize", 10)
    plot(T, noise_state(:,2), "r.", "Markersize", 10)
    plot(T, kalman_state(:,2), "b-", "Linewidth", 1)
    hold off
    xlabel("Time (s)")
    ylabel("Velocity (m/s)")


    

    legend("Old Method", "Flight Data", "Kalman Estimation")