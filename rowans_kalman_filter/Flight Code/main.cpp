#include "Include/phoenix_IV_functions.h"
#include <stdio.h>

int main(){

double dt = 0.05;
double Q[2][2] = {{25, 0}, {0, 25}};
double R[2][2] = {{100, 0}, {0, 100}};
double A[2][2] = {{1, dt}, {0, 1}};
double B[2] = {0.5 * dt * dt, dt};
double p_cov[2][2] = {{25, 0}, {0, 25}};
double state[2] = {9.0000,  180.0000};

double kalman_state[2][2] = {0, 0};

predict_state(state, A, B, state, false);

printf("<%f, %f>", state[0], state[1]);

return 0;
}
