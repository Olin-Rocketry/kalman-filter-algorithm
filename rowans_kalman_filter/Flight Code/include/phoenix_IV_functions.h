#ifndef phoenix_IV_functions_h
#define phoenix_IV_functions_h



#include <math.h>

const double MU = -9.8; //m/s

//double current_state[2], A[2][2], B[2], Q[2][2], predict_sate[2];

void mat_mat_prod(double A[2][2], double B[2][2], double res[2][2]);
void mat_vec_prod(double A[2][2], double *V, double *res);
void mat_transpose(double A[2][2], double res[2][2]);
void mat_inverse(double A[2][2], double res[2][2]);

void predict_state(double *current_state, double A[2][2], double *B, double *predicted_state, bool drag_term);

void predict_p_cov(double *current_p_cov, double A[2][2], double *Q, double *predicted_p_cov);

void update_gain(double *predicted_p_cov, double *H, double *R, double *kalman_gain);

void adjust_state(double *predicted_state, double *measurement, double *H, double *kalman_gain, double *adjusted_state);

void adjust_p_cov(double *predicted_p_cov, double *kalman_gain, double *H, double *adjusted_p_cov);

void kalman_update(double *state, double *p_cov);

#endif
