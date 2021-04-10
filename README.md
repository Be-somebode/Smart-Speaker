# team13_RTEP: Smart music lights 
Lighting is an important part of a party. The lighting at a party needs to change with the music, however, it usually requires a staff member to control it manually.
The purpose of this project is to design an intelligent control of the color and quantity of light with the spectrum of music, without manual operation.
![image](https://github.com/Be-somebode/Smart-Speaker/blob/main/image/2.jpg)
## Table of Contents
[Smart music lights](#smart_music_lights)
  * [About](#about)
  * [Function](#function)
  * [Hardware](#hardware)
  * [How it work?](#how_it_work)
 
# Smart music lights <a name="smart_music_lights"></a>
![image](https://github.com/Be-somebode/Smart-Speaker/blob/main/image/1.png)
# About <a name="about"></a>
Smart music lights, which can change lights in real time as music sounds, are a great helper for improving the party and bar atmosphere.
# Function <a name="function"></a>
1. Collect audio data through ADS1115 in real time.
2. Through the internal FFT audio processing of raspberry pie, and then through the LED lattice display the corresponding spectrum.
# Hardware <a name="hardware"></a>
Raspberry Pi(3b+)  
The power cord  
SD card	(16g)  
Heat sink  
LED	(3mm red)  
LED (3mm green)  
LED	(3mm yellow)  
LED	(3mm blue)  
Audio capture module (ADS1115）  
Power amplifier  	 
Dupont Line  	
Speaker  	 
# How it work? <a name="how_it_work"></a>
![image](https://github.com/Be-somebode/Smart-Speaker/blob/main/image/3.png)
1. Use ADS1115 to collect data of the audio in real time.(Connect the ADS1115 to the Raspberry Pi as the picture above).
2. Process audio through the internal fft of the Raspberry Pi.
3. Display the corresponding frequency spectrum through the LED dot matrix.
# Contributors
👤 **Shengbo Huang**  
👤 **Yikang Li**  
👤 **Xinkai Zhou**  
