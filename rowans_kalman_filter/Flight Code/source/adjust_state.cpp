#include "../include/phoenix_IV_functions.h"

void adjust_state(double *predicted_state, double *measurement, double H[2][2], double kalman_gain[2][2], double *adjusted_state){

    //target equation: x + k(m - Hx)

    double temp1[2], temp2[2], temp3[2];

    //Hx
    mat_vec_prod(H, predicted_state, temp1);
    //-Hx
    vec_scale(temp1, -1, temp1);
    //m + (-Hx)
    vec_sum(measurement, temp1, temp2);
    //k*(m-Hx)
    mat_vec_prod(kalman_gain, temp2, temp3);
    //x + k*(m-hx)
    vec_sum(predicted_state, temp3, adjusted_state);
}