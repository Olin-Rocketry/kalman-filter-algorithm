#include "phoenix_IV_functions.h"

void kalman_update(double *state, double p_cov[2][2], double *measurement, double dt, bool drag_term, double *adjusted_state, double adjusted_p_cov[2][2]){

    double A[2][2] = {{1, dt}, {0, 1}};
    double B[2] = {0.5 * dt * dt, dt};
    double Q[2][2] = {{25, 0}, {0, 25}};
    double H[2][2] = {{1, 0 }, {0, 1}};
    double R[2][2] = {{100, 0}, {0, 100}};
    double kalman_gain[2][2];


    predict_state(state, A, B, state, false);
    predict_p_cov(p_cov, A, Q, p_cov);
    update_gain(p_cov, H, R, kalman_gain);
    adjust_state(state, measurement, H, kalman_gain, adjusted_state);
    adjust_p_cov(p_cov, kalman_gain, H, adjusted_p_cov);
}
