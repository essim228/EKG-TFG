# EKG-TFG
A github repository for an electrocardiogram based in Arduino.

Each branch of the project represents a different device where we upload a different code.
The goal of the project is to represent a EKG chart in smart phone device, using a NODEMCU 1.0, OLIMEXINO AND EKG SHIELD from OLIMEX :

<img src="https://user-images.githubusercontent.com/106173055/221409371-6660340b-2d4c-47f5-ad16-3645e1ec97a0.png" width="30%"></img> <img src="https://user-images.githubusercontent.com/106173055/221409380-3dac1a86-6fff-4129-a5ce-cbe01d0636a1.png" width="27%"></img> <img src="https://user-images.githubusercontent.com/106173055/221409417-152cad90-0679-406b-af4e-85f1801f9fc7.png" width="24%"></img> 


The structre of the projects conections is:

<img src="https://user-images.githubusercontent.com/106173055/221410575-82795b21-d5a7-4704-b455-d0a3cd1009b6.png" width="35%"></img>

Both connections are used in order to decrease the power consumption BLE is more power consumming than MQTT 5.0 protocol. We would disable one connection or the other of the information we request, whether is the complete EKG signal or just the BPM and another small signal packages.
The MQTT conection is using the ThingsSpeak MQTT channels.
