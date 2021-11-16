function [T, D] = altitude_model(dt)
    global A B H R MU;

    p_0 = [0 ; 0 ; 1000];
    v_0 = [1 ; 0.3 ; 300];
    state = [p_0 ; v_0];
    options = odeset('Events', @event_func);

    [T, D] = ode45(@rate_func, [0:dt:60], state, options);
    figure(1)
    clf
    plot3(D(:,1), D(:,2), D(:,3))


    function rate = rate_func(t, state)
        p = state(1:3);
        v = state(4:6);
        dpdt = v;
        dvdt = acceleration(v);
        rate = [dpdt ; dvdt];
    end


    function res = acceleration(v)
        rho = 1.293;
        C = 0.1;
        A = 0.15^2*pi;
        m_rocket = 20;
        f_drag = -0.5 * rho * norm(v)^2 * C * A;
        a_drag = (v / norm(v)) * (f_drag / m_rocket);
        a_grav = [0 ; 0 ; -9.8];
        res = a_grav + a_drag;

    end

    function [value, isterminal, direction] = event_func(t, state)
        value = state(3);
        isterminal = 1;
        direction = -1;
    end

end