#include "../include/phoenix_IV_functions.h"


void predict_state(double *current_state, double A[2][2], double *B, double *predicted_state, bool drag_term){
    
    //temp variable
    double U[2];

    //if parachute is deployed, factor in drag into the model
    if (drag_term){

        //=====calculate force of drag======
        
        //constants for drag force
        double coefficient_of_drag = 1.5;
        double air_density = 1.225; //kg/m^3
        double chute_cross_section = 0.2; //m^2
        double rocket_mass = 22; //kg

        //F_d = 1/2 pv^2 C_d A
        double drag_force = 0.5 * air_density * (current_state[1] * current_state[1]) * coefficient_of_drag  * chute_cross_section;
        double drag = drag_force / rocket_mass;

        //======update state using model=======
        //Ax + B(grav+drag)
        mat_vec_prod(A, current_state, predicted_state);
        vec_scale(B, MU + drag, U);
        vec_sum(predicted_state, U, predicted_state);
    }

    //otherwise, just use simple model with no drag term
    else{
        //Ax + B(grav)
        mat_vec_prod(A, current_state, predicted_state);
        vec_scale(B, MU, U);
        vec_sum(predicted_state, U, predicted_state);
    }


}