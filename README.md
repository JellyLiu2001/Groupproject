# Groupproject
ab20328-Jelly Jinzhe Liu
## Abstract

This report is based on a group project of selecting and configuring motor and processor, designing a circuit, writing code, and discussing its feasibility.	
The part of this report on the group project is to discuss the feasibility of the motor and processor, using the result to choose the motor and integrated it into the maze. The processor needs to choose the model, design the circuits, and write the code. Also, when the image processing is finished, it must use the same port the processor provided. 

## Introduction
In the hardware part, the main function is using the motor to drive two knobs in the maze, which can control the pitch and roll. This function is leading the ball running in the guided route in case of not dropping the hole and to the destination. It uses two servo motors to drive the maze by connecting to Arduino Mega. when the system turns on, Arduino will do a self-check to make sure every component is connected and working well. Table 1 shows its component for users. 
After self-check, the user can choose two modes: auto mode and manual mode. It also includes auto trim, connect to pc and degree in auto mode. 
The benefit of this plan is to keep the original appearance and function of the maze, so people can still use it like the product itself. 

## Direction
Machines should always serve humans. A useful product not only has perfect hardware but also has good practicality. It is important to choose how to use it. 
In our design, the first task or main function is the connection to the PC and the use of two servos to drive the maze. Every part should give a visualization to the user to let them know what the system is doing, and easy to check errors. One of the problems is that the user will place the maze on different planes, therefore, the angle of the maze will change concerning the horizontal plane. In our design, we want it can be auto trim, which is to design a system that the user does not need to trim and still can get horizon. 
Config.h
Library	It is a set of pre-written code files designed to solve specific problems or provide specific functions, and developers can import them into their own code for use. A library can contain functions, variables, objects, etc., along with their associated header files, source code, and other resources.
adaFruint_sensor	Many small embedded systems exist to collect data from sensors, analyse the data, and either take an appropriate action or send that sensor data to another system for processing. (Adafruit, 2023)


![image](https://user-images.githubusercontent.com/79320181/232819094-1ec531b8-2147-4fbb-b929-514b6ea764fc.png)
<img width="823" alt="image" src="https://user-images.githubusercontent.com/79320181/232819489-edfe8199-d218-4cd4-b9a9-83cdd3f576a3.png">
