///////////////////////////////////////////////////////////////////////////
//
//  Description:  
//      Flight controll library for Phoenix IV
//
//  Comments:
//
//  Rowan Jansens
//  Olin College of Engineering
//  1/23/2022
///////////////////////////////////////////////////////////////////////////    


#ifndef phoenix_IV_functions_h
#define phoenix_IV_functions_h


#include <math.h>
#include <stdio.h>

//constans
const double MU = -9.8; //m/s

//vector/matrix opperation macros
#define vec_sum(v1, v2, res) res[0] = v1[0]+v2[0]; res[1] = v1[1]+v2[1];
#define vec_scale(v, scale, res) res[0] = v[0]*scale; res[1] = v[1]*scale;

#define mat_sum(m1, m2, res) \
res[0][0] = m1[0][0]+m2[0][0]; \
res[0][1] = m1[0][1]+m2[0][1]; \
res[1][0] = m1[1][0]+m2[1][0]; \
res[1][1] = m1[1][1]+m2[1][1];

#define mat_scale(m1, scale, res) \
res[0][0] = m1[0][0]*scale; \
res[0][1] = m1[0][1]*scale; \
res[1][0] = m1[1][0]*scale; \
res[1][1] = m1[1][1]*scale;


#define mat_vec_prod(m, v, res) \
res[0] = (m[0][0]*v[0])+(m[0][1]*v[1]); \
res[1] = (m[1][0]*v[0])+(m[1][1]*v[1]);

#define mat_transpose(m, res) res[0][0] = m[0][0]; res[0][1] = m[1][0]; res[1][0] = m[0][1], res[1][1] = m[1][1];

#define mat_mat_prod(m1, m2, res) \
res[0][0] = (m1[0][0]*m2[0][0])+(m1[0][1]*m2[1][0]); \
res[0][1] = (m1[0][0]*m2[0][1])+(m1[0][1]*m2[1][1]); \
res[1][0] = (m1[1][0]*m2[0][0])+(m1[1][1]*m2[1][0]); \
res[1][1] = (m1[1][0]*m2[0][1])+(m1[1][1]*m2[1][1]);

#define mat_inverse(m, res) \
double det = (m[0][0] * m[1][1]) - (m[1][0] * m[0][1]); \
res[0][0] = m[1][1] / det; \
res[0][1] = -1 * m[0][1] / det; \
res[1][0] = -1 * m[1][0] / det; \
res[1][1] = m[0][0] / det;


//kalman function declerations
void predict_state(double *current_state, double A[2][2], double *B, double *predicted_state, bool drag_term);
void predict_p_cov(double current_p_cov[2][2], double A[2][2], double Q[2][2], double predicted_p_cov[2][2]);
void update_gain(double predicted_p_cov[2][2], double H[2][2], double R[2][2], double kalman_gain[2][2]);
void adjust_state(double *predicted_state, double *measurement, double H[2][2], double kalman_gain[2][2], double *adjusted_state);
void adjust_p_cov(double predicted_p_cov[2][2], double kalman_gain[2][2], double H[2][2], double adjusted_p_cov[2][2]);
void kalman_update(double *state, double p_cov[2][2], double *measurement, double dt, bool drag_term, double *adjusted_state, double adjusted_p_cov[2][2]);


#endif
