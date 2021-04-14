# Team13_RTEP: Smart music lights 
 
 <p align="center">
    <a href=""><img height=40 src="images/youtube.svg"></img></a>&nbsp;&nbsp;&nbsp;&nbsp;
    <a href=""><img height=40 src="images/facebook.svg"></img></a>&nbsp;&nbsp;&nbsp;&nbsp;
    <a href=""><img height=40 src="images/twitter.svg"></img></a>&nbsp;&nbsp;&nbsp;&nbsp;
    <a href=""><img height=40 src="images/instagram.svg"></img></a>&nbsp;&nbsp;&nbsp;&nbsp;
    <a href=""><img height=40 src="images/linkedin.svg"></img></a>&nbsp;&nbsp;&nbsp;&nbsp;
    <br />
    <br />
    <a href="">View Demo</a>
  </p>
</div>

Lighting is an important part of a party. The lighting at a party needs to change with the music, however, it usually requires a staff member to control it manually.
The purpose of this project is to design an intelligent control of the color and quantity of light with the spectrum of music, without manual operation.
![image](https://github.com/Be-somebode/Smart-Speaker/blob/main/image/2.jpg)
## Table of Contents
[Smart music lights](#smart_music_lights)
  * [About](#about)
  * [Function](#function)
  * [Hardware](#hardware)
  * [How it work?](#how_it_work)
  * [Contributors](#contributors)
 
# Smart music lights <a name="smart_music_lights"></a>
![image](https://github.com/Be-somebode/Smart-Speaker/blob/main/image/1.png)
# About <a name="about"></a>
Smart music lights, which can change lights in real time as music sounds, are a great helper for improving the party and bar atmosphere.
# Function <a name="function"></a>
1. Collect audio data through ADS1115 in real time.
2. Through the internal FFT audio processing of raspberry pie, and then through the LED lattice display the corresponding spectrum.
3. By using the app on the mobile phone, you can play, pause the music and cut to the next song/previous song. 
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
1. Use ADS1115 to collect data of the audio in real time and translate the signal to digital signal.(Connect the ADS1115 to the Raspberry Pi as the picture above).
2. Display the corresponding frequency spectrum through the LED dot matrix.When the signal is stronger, the more LEDs will turn on (simulating the effect of lighting changes in the bar according to the music).
# Contributors <a name="contributors"></a>
👤 **Shengbo Huang**  
👤 **Yikang Li**  
👤 **Xinkai Zhou**  
