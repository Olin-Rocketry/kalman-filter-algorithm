#include "../include/phoenix_IV_functions.h"


void predict_p_cov(double current_p_cov[2][2], double A[2][2], double Q[2][2], double predicted_p_cov[2][2]){
    //Target Equation: ApA' + Q

    //temp variables
    double AP[2][2];
    double AT[2][2];

    //Ap
    mat_mat_prod(A, current_p_cov, AP);

    //A'
    mat_transpose(A, AT);

    //(Ap)A'
    mat_mat_prod(AP, AT, predicted_p_cov);
    
    //(ApA') + Q
    mat_sum(predicted_p_cov, Q, predicted_p_cov);
}