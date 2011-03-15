/*
 * main.cpp
 *
 *  Created on: Feb 24, 2011
 *      Author: xum
 */
#include "WProgram.h"
#include "WConstants.h"

void setup();
void loop();
void calibrate();
int main(int argc, char **argv) {
	setup();
	for(;;){
		loop();
	}
}

int tam = 1000;
double mean = 0;
double meanAmpl = 0;
double variancePercent = 10;

void setup() {
  Serial.begin(115200);
  calibrate();
}
void calibrate(){
  mean = 0;
  int sensorValue = 0;
  for(int i = 0; i<tam;i++){
    sensorValue =  analogRead(A0);
    mean += sensorValue/(double) tam;
  }
  for(int j = 0; j<tam;j++){
    sensorValue =  analogRead(A0);
    meanAmpl += abs(mean-sensorValue)/(double) tam;
  }
  Serial.print("Mean:");
  Serial.println(mean,DEC);
  Serial.print("Ampl:");
  Serial.println(meanAmpl,DEC);

}
void loop() {
  //  int sensorValue = 0;
  //  sensorValue =  analogRead(A0);
  //  double ampl = abs(mean-sensorValue);
  //  if(ampl>meanAmpl){
  //    Serial.println("Calla puta!");
  //  }
  calibrate();
  delay(1000);
}

