//!/usr/bin/C++
//   -*- coding: utf-8 -*-
// Date: Sunday 6 June 2021 09h02:01 CEST
// Author: Fabio Malerba
// Last updated by: Marco Finidori
// Last updated time: Sunday 17 June 2021 10:20:20 CEST
// Description: Récupération de données



/*
Writing Sensor Data to an SD card
//
This example shows how to write data
to an SD card using the SD library.
//
The circuit:
* SD card attached to SPI bus as follows:
** MOSI - pin 11
** MISO - pin 12
** CLK - pin 13
** CS - pin 10 Uno 
*/
//
#include "SD.h"
#include"SPI.h"
//
//the hardware CS pin (10 on most Arduino boards,
// 53 on the Mega) must be left as an output or the SD
// library functions will not work.
const int CSpin = 10;
String dataString =""; // holds the data to be written to the SD card
float sensorReading1 = 0.00; // value read from your first sensor
float sensorReading2 = 0.00; // value read from your second sensor
float sensorReading3 = 0.00; // value read from your third sensor
File sensorData;
//
//
void setup()
{
// Open serial communications
Serial.begin(9600);
Serial.print("Initializing SD card...");
pinMode(CSpin, OUTPUT);
//
// see if the card is present and can be initialized:
if (!SD.begin(CSpin)) {
Serial.println("Card failed, or not present");
// don't do anything more:
return;
}
Serial.println("card initialized.");
}
//
void loop(){
// build the data string
dataString = String(sensorReading1) + "," + String(sensorReading2) + "," + String(sensorReading3); // convert to CSV
saveData(); // save to SD card
delay(60000); // delay before next write to SD Card, adjust as required
}
//
void saveData(){
if(SD.exists("data.csv")){ // check the card is still there
// now append new data file
sensorData = SD.open("data.csv", FILE_WRITE);
if (sensorData){
sensorData.println(dataString);
sensorData.close(); // close the file
}
}
else{
Serial.println("Error writing to file !");
}
}
