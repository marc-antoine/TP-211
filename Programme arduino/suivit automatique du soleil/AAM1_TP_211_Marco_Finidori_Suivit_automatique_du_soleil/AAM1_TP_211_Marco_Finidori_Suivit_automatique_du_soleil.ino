//!/usr/bin/C++
//   -*- coding: utf-8 -*-
// Date: Sunday 6 June 2021 09h02:01 CEST
// Author: Fabio Malerba
// Last updated by: Marco Finidori
// Last updated time: Sunday 6 June 2021 10:20:20 CEST
// Description: Suivre le soleil

/* 
 Ce programme permet en faisant la moyenne des capteurs
d'adapter la position des servos et donc de la cellule
photovolvatique pour suivre le soleil 
*/

#include <Servo.h>

Servo servoh;
Servo servov; 

int horizontal = 0;
int vertical = 0;

int top_left;
int top_right;
int bottom_left;
int bottom_right;

int moyenne_1;
int moyenne_2;
int moyenne_3;
int moyenne_4;

int difference_horizontale;
int difference_veticale;
const int limite = 30 ;


void setup() 
{
  servoh.attach(10);
  servov.attach(9);
  
  Serial.begin(9600);
}
void loop() {
  
  top_left = analogRead(A2); //lecture de la donnée des capteurs
  top_right = analogRead(A3);
  bottom_left = analogRead(A0);
  bottom_right = analogRead(A1);
  vertical = servov.read();
  horizontal = servoh.read();

  Serial.println(horizontal);

  

  moyenne_2 = ( bottom_left + bottom_right )/2; //moyenne des capteurs du bas 
  moyenne_1 = (top_left + top_right)/2;            //moyenne des capteurs du haut
  moyenne_3 = ( top_left + bottom_left) / 2;      //moyenne des capteurs de gauche
  moyenne_4 = ( top_right + bottom_right) / 2;   //moyenne des capteurs de droite
  
  difference_horizontale= abs(moyenne_2 - moyenne_1); //On regarde l'écart 
  difference_veticale = abs(moyenne_3 - moyenne_4);
  
  if ((moyenne_1 > moyenne_2) && (difference_horizontale > limite))
    {
     if (vertical > 0) 
       {
       vertical = vertical - 1;
       servov.write(vertical);
       delay(5);
       }
    }
    
  if((moyenne_2 > moyenne_1) && (difference_horizontale > limite))
    {
    if (vertical < 180) 
      {
       vertical = vertical + 1;
       servov.write(vertical);
       delay(5);
      }
    }
    
  if ((moyenne_4 < moyenne_3) && (difference_veticale > limite))
    {
     if (horizontal > 0) 
       {
       horizontal = horizontal - 1;
       servoh.write(horizontal);
       delay(5);
       }
    }
    
  if((moyenne_3 < moyenne_4) && (difference_veticale > limite))
    {
    if (horizontal < 180)
      {
       horizontal = horizontal + 1;
       servoh.write(horizontal);
       delay(5);
      }
    }
    delay(10);
}
