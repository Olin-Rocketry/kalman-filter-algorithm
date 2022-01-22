#include "../include/phoenix_IV_functions.h"


void predict_state(double *current_state, double A[2][2], double *B, double *predicted_state, bool drag_term){

    //constants for drag force
    double coefficient_of_drag = 1.5;
    double air_density = 1.225; //kg/m^3
    double chute_cross_section = 0.2; //m^2
    double rocket_mass = 22; //kg
    

    //F_d = 1/2 pv^2 C_d A
    double drag_force = 0.5 * air_density * (current_state[1] * current_state[1]) * coefficient_of_drag  * chute_cross_section;
    double drag = drag_force / rocket_mass;
    if (drag_term){
        //A*state + B*(MU+drag)
        predicted_state[0] = (A[0][0] * current_state[0]) + (A[0][1] * current_state[1]) + (B[0] * (MU + drag));
        predicted_state[1] = (A[1][0] * current_state[0]) + (A[1][1] * current_state[1]) + (B[1] * (MU + drag));
    }
    else{
        predicted_state[0] = (A[0][0] * current_state[0]) + (A[0][1] * current_state[1]) + (B[0] * MU);
        predicted_state[1] = (A[1][0] * current_state[0]) + (A[1][1] * current_state[1]) + (B[1] * MU);
    }


}