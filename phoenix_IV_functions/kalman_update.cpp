#include "phoenix_IV_functions.h"

void kalman_update(double *state, double p_cov[3][3], double *measurement, double dt, double *adjusted_state, double adjusted_p_cov[3][3]){

    double A[3][3] = {{1, dt, dt*dt / 2}, {0, 1, dt}, {0, 0, 1}};     //state transition matrix for position
    double Q[3][3] = {{3, 0, 0}, {0, 2, 0}, {0, 0, 1}};    //model noise covariance
    double H[2][3] = {{1, 0, 0}, {0, 0, 1}};     //measurement jacobian (to transforms the system state into the measurement)
    double R[2][2] = {{100, 0}, {0, 10}};  //measurement noise covariance
    double kalman_gain[3][2];


    predict_state(state, A, state);
    predict_p_cov(p_cov, A, Q, p_cov);
    update_gain(p_cov, H, R, kalman_gain);
    printf("%f %f \n %f%f \n %f %f \n", kalman_gain[0][0], kalman_gain[0][1], kalman_gain[1][0], kalman_gain[1][1], kalman_gain[2][0], kalman_gain[2][1]);
    adjust_state(state, measurement, H, kalman_gain, adjusted_state);
    adjust_p_cov(p_cov, kalman_gain, H, adjusted_p_cov);
}
