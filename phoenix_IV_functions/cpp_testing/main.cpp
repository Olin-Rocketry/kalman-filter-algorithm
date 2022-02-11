#include "../phoenix_IV_functions.h"
#include <stdio.h>




int main(){

//     FILE *fp = fopen("test.txt", "r");
// char line[256];
// while (fgets(line, sizeof(line), fp)) {
//   sscanf(line, "%lf,%lf,%lf", &data[i][0], &data[i][1], &data[i][2]);
//   i++;
// }
// fclose;


double dt = 0.05;

double state[3] = {29.8102,  0, 53.5571};

printf("%f %f %f \n", state[0], state[1], state[2]);

double measurement[2] = {31.1948, 56.3991};

double p_cov[3][3] = {{3, 0, 0}, {0, 2, 0}, {0, 0, 1}};

double adjusted_state[3], adjusted_p_cov[3][3];


kalman_update(state, p_cov, measurement, dt, adjusted_state, adjusted_p_cov);

printf("%f %f %f \n", state[0], state[1], state[2]);
printf("%f %f %f \n %f %f %f \n %f %f %f \n", p_cov[0][0], p_cov[0][1], p_cov[0][2], p_cov[1][0], p_cov[1][1], p_cov[1][2], p_cov[2][0], p_cov[2][1], p_cov[2][2]);
printf("%f %f \n", measurement[0], measurement[1]);
printf("%f %f %f \n", adjusted_state[0], adjusted_state[1], adjusted_state[2]);
printf("%f %f %f \n %f %f %f \n %f %f %f \n", adjusted_p_cov[0][0], adjusted_p_cov[0][1], adjusted_p_cov[0][2], adjusted_p_cov[1][0], adjusted_p_cov[1][1], adjusted_p_cov[1][2], adjusted_p_cov[2][0], adjusted_p_cov[2][1], adjusted_p_cov[2][2]);


printf("[%f \n %f] \n", adjusted_state[0], adjusted_state[1]);
printf("[%f %f \n %f %f] \n", adjusted_p_cov[0][0], adjusted_p_cov[0][1], adjusted_p_cov[1][0], adjusted_p_cov[1][1]);

return 0;
}