#include <Arduino.h>
#include <Wire.h>
#include <BlueDot_BMA400.h>
BlueDot_BMA400 bma400 = BlueDot_BMA400();

float x=0,y=0,z=0;
String myStatus;

void setup()
{
  Serial.begin(115200);
    
  bma400.parameter.I2CAddress = 0x14;                  //Choose I2C Address
  bma400.parameter.powerMode = 0x02;                   //Choose power mode
  bma400.parameter.measurementRange = 0x00;             //Choose measurement range
  bma400.parameter.outputDataRate = 0x05;             //Choose measurement range
  bma400.parameter.oversamplingRate = 0x03;             //Choose measurement samplingrate

  //CHECK THE CHIP ID
  Serial.print(F("Communication with BMA400:\t"));
  if (bma400.init()==0x90)
  {
    Serial.println("Successful");   
  }
  
  else
  {
    Serial.println("Failed");
  }
  delay(1000);

   //There is no need to change anything here
  Serial.print(F("Reading Power Mode:\t\t"));
  uint8_t powerMode;
  powerMode = bma400.readPowerMode();
  
  if (powerMode == 0)
  Serial.println(F("Sleep Mode"));

  if (powerMode == 1)
  Serial.println(F("Low Power Mode"));
  
  if (powerMode == 2)
  Serial.println(F("Normal Power Mode"));
  delay(1000);
  
 
  Serial.print(F("Reading Measurement Range:\t"));
  uint8_t measurementRange;
  measurementRange = bma400.readMeasurementRange();
  
  if (measurementRange == 0)
  Serial.println(F("2g"));

  if (measurementRange == 1)
  Serial.println(F("4g"));
  
  if (measurementRange == 2)
  Serial.println(F("8g")); 

  if (measurementRange == 3)
  Serial.println(F("16g")); 
  delay(1000);
  
 
  //There is no need to change anything here
  
  Serial.print(F("Reading Output Data Rate:\t"));
  uint8_t outputDataRate;
  outputDataRate = bma400.readOutputDataRate();

  if (outputDataRate == 5)
  Serial.println(F("12.5Hz"));

  else if (outputDataRate == 6)
  Serial.println(F("25Hz"));
  
  else if (outputDataRate == 7)
  Serial.println(F("50Hz")); 

  else if (outputDataRate == 8)
  Serial.println(F("100Hz")); 

  else if (outputDataRate == 9)
  Serial.println(F("200Hz")); 

  else if (outputDataRate == 10)
  Serial.println(F("400Hz")); 

  else if (outputDataRate == 11)
  Serial.println(F("800Hz")); 

  else
  Serial.println(outputDataRate);
  
  delay(1000);

 
  //There is no need to change anything here
  
  Serial.print(F("Reading Oversampling Range:\t"));
  uint8_t oversamplingRate;
  oversamplingRate = bma400.readOversamplingRate();
  
  if (oversamplingRate == 0)
  Serial.println(F("OSR 0"));

  if (oversamplingRate == 1)
  Serial.println(F("OSR 1"));
  
  if (oversamplingRate == 2)
  Serial.println(F("OSR 2")); 

  if (oversamplingRate == 3)
  Serial.println(F("OSR 3")); 
  delay(1000);
  
  Serial.println();  

}

void loop()
{
  bma400.readData();
  x = bma400.parameter.acc_x;
  y = bma400.parameter.acc_y;
  z = bma400.parameter.acc_z;

  Serial.printf("%f \t %f \t %f \t\n",x,y,z);
  // Serial.printf("/t %s /t %s /t",db_date,db_time);
 
  // if((x >= 500) && (z <= 700)) 
  //   {
  //     Serial.print('\t');
  //     Serial.println("sitting straight \n");
  //     myStatus = "sitting straight";
  //   }
  // if((x < 0) && (z <= 700) ) 
  //   {
  //     Serial.print('\t');
  //     Serial.println("Right \n");
  //     myStatus = "right";      
  //   }
  // if((x>=700) && (z<700) ) 
  //   {
  //     Serial.print('\t');
  //     Serial.println("Left \n");
  //     myStatus = "left";
  //   }

}