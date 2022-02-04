//load library
#include <phoenix_IV_functions.h>
#include <stdio.h>


//data arrays
double data[7000][3];
int i = 0;





//necessary variables
// double state[2] = {data[0][1], data[0][2]};
// double p_cov[2][2] = {{25, 0}, {0, 25}};
// int i = 1;


 void setup() {
  FILE *fp = fopen("test.txt", "r");
char line[256];
while (fgets(line, sizeof(line), fp)) {
  sscanf(line, "%lf,%lf,%lf", &data[i][0], &data[i][1], &data[i][2]);
  i++;
}
fclose;
 Serial.begin(9600);


  

    
}

void loop(){
  while(i<100){
    //resource next measurement
    //double measurement[2] = {alt[i], vel[i]};
    //calculate time step
    //double dt = time_stamp[i] - time_stamp[i-1];
    //run kalman filter
    //kalman_update(state, p_cov, measurement, dt, false, state, p_cov);

    //print data for plotting
    //Serial.print(vel[i]);
    //Serial.print(" ");
    //Serial.println(state[1]);


    Serial.print(data[i][1]);
    Serial.print(" ");
    Serial.println(data[i][2]);

    //increment counter
    i++;
    delay(100);
  }
}