
//!/usr/bin/C++
//   -*- coding: utf-8 -*-
// Date: Sunday 6 June 2021 09h02:01 CEST
// Author: Fabio Malerba
// Last updated by: Marco Finidori
// Last updated time: Sunday 6 June 2021 10:20:20 CEST
// Description: Calcul de puissance

/* 
 Ce programme permet grace à la relation P=U*2/R de 
 trouver la valeur de le puissance issue du panneau
 solaire en fonction de l'exposition au soleil
 grace aux photoresistences
*/

int volt;
float resistance = 12.5;
float puissance;

void setup() 
{
  
  Serial.begin(9600);
}

void loop() {

  volt = analogRead(A0);
  volt = map(volt,0,1023,0,5);
   
  puissance = (volt*volt)/resistance;
  Serial.println(puissance);
}
