#include "../include/phoenix_IV_functions.h"

void adjust_p_cov(double predicted_p_cov[2][2], double kalman_gain[2][2], double H[2][2], double adjusted_p_cov[2][2]){

    //target equation: I - kHp;
    double I[2][2] = {{1, 0}, {0, 1}};

    //temp variable
    double temp1[2][2];

    //kH
    mat_mat_prod(kalman_gain, H, temp1);
    //(kH)p
    mat_mat_prod(temp1, predicted_p_cov, adjusted_p_cov);
    //-(kHp)
    mat_scale(adjusted_p_cov, -1, adjusted_p_cov);
    //I - kHp
    mat_sum(I, adjusted_p_cov, adjusted_p_cov);
}