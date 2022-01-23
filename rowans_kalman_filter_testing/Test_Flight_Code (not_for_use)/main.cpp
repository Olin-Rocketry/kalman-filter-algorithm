#include "Include/phoenix_IV_functions.h"
#include <stdio.h>

int main(){

double dt = 0.05;

double state[2] = {9.0000,  180.0000};
double measurement[2] = {12, 60};
double p_cov[2][2] = {{25, 0}, {0, 25}};

double adjusted_state[2], adjusted_p_cov[2][2];


kalman_update(state, p_cov, measurement, dt, true, adjusted_state, adjusted_p_cov);



printf("[%f \n %f] \n", adjusted_state[0], adjusted_state[1]);
printf("[%f %f \n %f %f] \n", adjusted_p_cov[0][0], adjusted_p_cov[0][1], adjusted_p_cov[1][0], adjusted_p_cov[1][1]);

return 0;
}