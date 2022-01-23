#include "phoenix_IV_functions.h"

void update_gain(double predicted_p_cov[2][2], double H[2][2], double R[2][2], double kalman_gain[2][2]){

    //target equation: pH' / (HpH' + R)

    //temp variables
    double HT[2][2], temp1[2][2], temp2[2][2], temp3[2][2], temp4[2][2], temp5[2][2];

    //H'
    mat_transpose(H, HT);

    //pH'
    mat_mat_prod(predicted_p_cov, HT, temp1);
    //Hp
    mat_mat_prod(H, predicted_p_cov, temp2);
    //(Hp)H'
    mat_mat_prod(temp2, HT, temp3);
    //(HpH') + R
    mat_sum(temp3, R, temp4);
    //(HpH' + R)^-1
    mat_inverse(temp4, temp5);
    //pH' * (HpH' + R)^-1
    mat_mat_prod(temp1, temp5, kalman_gain);
}
