function [T, D] = altitude_model(dt)

    p_0 = 1000;
    v_0 = 300;
    
    t_range = 0:dt:60;
    
    T = t_range;

    D = zeros(length(t_range), 3);
    D(1,:) = [p_0, v_0, -9.8];
    
    
    for i=2:length(t_range)
        acc = acceleration(D(i-1,2));
        vel = D(i-1,2) + acc * dt;
        pos = D(i-1,1) + vel * dt;
        D(i,:) = [pos, vel, acc];
    end


    function res = acceleration(v)
        rho = 1.255;
        C = 0.1;
        A = 0.15^2*pi;
        m_rocket = 22;
        f_drag = -1 * 0.5 * rho * norm(v)^2 * C * A;
        a_drag = (v / norm(v)) * (f_drag / m_rocket);
        a_grav = -9.8;
        res = a_grav + a_drag;

    end

end