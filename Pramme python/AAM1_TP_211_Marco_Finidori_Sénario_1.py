#!/usr/bin/python3.9
#  -*- coding: utf-8 -*-

# Date: Thu Jun 1 12:02:28 2021
# Author: Marc-Antoine Finidori Borg AAM1
# Last updated date: Thu Jun 1 13:00:32 2021
# Description: sénario 1 solarius

import time
import board
import pwmio
from adafruit_motor import servo

# create a PWMOut object on Pin A1 (Rotation of panel)
pwm1 = pwmio.PWMOut(board.A1, duty_cycle=2 ** 15, frequency=50)
# create a PWMOut object on Pin A4 (Tilt of panel)
pwm2 = pwmio.PWMOut(board.A3, duty_cycle=2 ** 15, frequency=50)

# Create a servo object, my_servo.
my_servo1 = servo.Servo(pwm1)
my_servo2 = servo.Servo(pwm2)


while True:
    for angle_1 in range(0, 89,99837, 0.00163):
        my_servo1.angle = angle_1
        time.sleep(0.05)
    while True:
        for angle_1 in range(90, 0, -0.00163): 
        my_servo1.angle = angle_1
        time.sleep(0.05)
    for angle_2 in range(0, 252, 0.00223):
        my_servo2.angle = angle_2
        time.sleep(0.05)

