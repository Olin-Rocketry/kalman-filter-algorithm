//load library
#include <phoenix_IV_functions.h>
#include <stdio.h>
#include <SD.h>
#include <SPI.h>
#include <iostream>
#include <cstring>
const int chipSelect = BUILTIN_SDCARD;

double data[6000][3];

unsigned long t1, t2;

void setup() {

  //open sd============

   Serial.begin(9600);
   while (!Serial) {
    ;// wait for serial port to connect.
  }

  Serial.print("Initializing SD card...");
  
  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    return;
  }
  Serial.println("card initialized.");
  
  // open the file.
  File dataFile = SD.open("test.txt", FILE_READ);


//read first entry=================

if (dataFile) {

  for (int i = 0; i < 6000; i++){
      String line = dataFile.readStringUntil('\n');
      int n = line.length();
 
    // declaring character array
    char char_array[n + 1];
 
    // copying the contents of the
    // string to char array
    strcpy(char_array, line.c_str());
 

      sscanf(char_array, "%lf,%lf,%lf", &data[i][0], &data[i][1], &data[i][2]);

            //Serial.print(data[i][0]);
      //Serial.print(" ");
      
      //Serial.print(data[i][1]);
      //Serial.print(" ");
      //Serial.println(data[i][2]);
}
}
      
 
  
  dataFile.close();  



//========================================================

    double state[3] = {data[0][1], 0, data[0][2]};
  double p_cov[3][3] = {{3, 0, 0}, {0, 2, 0}, {0, 0, 1}};

    //Serial.print(state[0]);
    //Serial.print(" ");
    //Serial.print(state[1]);
    //Serial.print(" ");
    //Serial.println(state[2]);


  for (int j = 1; j <1000 ; j++){

    double dt = data[j][0] - data[j-1][0];
    double measurement[2] = {data[j][1], data[j][2]};
    //double adjusted_state[3], adjusted_p_cov[3][3];
    
    
    //time, altitude, acceleration
    
    kalman_update(state, p_cov, measurement, dt, state, p_cov);
    
    
    Serial.print(state[0]);
    Serial.print(" ");
    Serial.println(data[j][1]);
    delay(10);


}
}


void loop(){
  }