function [state, p_cov] = kalman_update(state, p_cov, measurement, dt)

    %https://www.bzarg.com/p/how-a-kalman-filter-works-in-pictures/
    
    global R Q MU;
    
    A = [1 dt dt^2 / 2 ; 0 1 dt ; 0 0 1];
    

    H = [1 0 0 ; 0 0 1];

    predicted_state = predict_state(state, A)
    
    predicted_p_cov = predict_p_cov(p_cov, A)
    
    kalman_gain = update_gain(predicted_p_cov, H, R)
    
    state = adjust_state(predicted_state, measurement, H, kalman_gain)
    
    p_cov = adjust_p_cov(predicted_p_cov, kalman_gain, H)
    


    
    function res = predict_state(state, A)
        res = A*state;
       
    end

    function res = predict_p_cov(p_cov, A)
        res = A * p_cov * A' + Q;
    end

    function res = update_gain(predicted_p_cov, H, R)
        kgain = (predicted_p_cov*H') / (H*predicted_p_cov*H' + R);
        res = kgain;
    end

    function res = adjust_state(state, measurement, H, kalman_gain)
        res = state + kalman_gain*(measurement - H*state);
    end

    function res = adjust_p_cov(predicted_p_cov, kalman_gain, H)
        res = predicted_p_cov - kalman_gain*H*predicted_p_cov;
    end
end
