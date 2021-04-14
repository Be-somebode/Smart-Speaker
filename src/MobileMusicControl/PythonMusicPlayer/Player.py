# -*- coding: utf-8 -*-

import time

from PIL import Image
from PIL import ImageDraw
from PIL import ImageFont
import psutil as p
import os, re  
import subprocess
import threading
from pygame import mixer
import wave
import glob
import socket
import ctypes
import inspect



IP="192.168.5.112"  #enter your RaspberryPi IP
Port=23333  #port

if 1==1:   #Main
    Replay=False
    RST = None     
    DC = 23
    SPI_PORT = 0
    SPI_DEVICE = 0

    maindate=time.strftime('%Y-%m-%d',time.localtime(time.time()))
    maintime=time.strftime('%H:%M:%S',time.localtime(time.time()))
    x = 0

    mainroad='Fonts/'#'/home/pi/Documents/Programs/OLEDPrograms/Fonts/'
    retron=mainroad+'Retron2000.ttf'
    hanzi=mainroad+'Dengl.ttf'
    NowTimes=""
    AllTimes=""
    MusicName=""


def Timeupdate():
    print("时钟已加载")
    while True:
        global maindate
        global maintime
        maindate=time.strftime('%Y-%m-%d',time.localtime(time.time()))
        maintime=time.strftime('%H:%M:%S',time.localtime(time.time()))
        
MainNext=False


timeint=-1
def MusicPlay():
    global timeint
    global AllWaveName
    if timeint == len(AllWaveName)-1:
        timeint=-1
    Name=AllWaveName[timeint+1]
    timeint=timeint+1
    f = wave.open(Name)
    secs = int(f.getnframes() / f.getframerate())
    mins=int(secs/60)
    lastsecs=secs-mins*60
    maintime=str(mins)+":"+str(lastsecs)
    frequency=f.getframerate()
    mixer.init(frequency)#,size=-16,channels=0)
    mixer.music.load(Name)
    mixer.music.play()
    costtime=0
    outputmins=0
    global MusicName
    global AllTimes
    MusicName=str(Name[6:-4])
    print(MusicName)
    while True:
        global MainNext
        if costtime<59:
            costtime=costtime+1
        else:
            costtime=0
            outputmins=outputmins+1
        global NowTimes
        global Replay
        NowTimes=str(outputmins)+":"+str(costtime)
        AllTimes=str(maintime)
        if NowTimes==AllTimes:
            time.sleep(1)
            if Replay:
                timeint=timeint-1
            MusicPlay()
            break
        time.sleep(1)
        if MainNext:
            MainNext=False
            break;
        #MusicPlayerScreen(maintime,str(outputmins)+":"+str(costtime),Name)

def MusicStop():
    mixer.music.stop()
    
xiumianle=False
xiumiantime=0
def xiumian():
    while True:
        global xiumianle
        global xiumiantime
        while xiumianle==False:
            xiumiantime=xiumiantime+1
            time.sleep(1)
            
def stop_thread(thread):
    _async_raise(thread.ident, SystemExit)

def Wificl():
    server=socket.socket()
    server.bind((IP,Port)) 
    while True:
        time.sleep(2)
        global xiumianle
        global xiumiantime
        global MainNext
        global timeint
        global Replay
        #socket.setsockopt(socket.SOL_SOCKET,socket.SO_REUSEADDR,1) 
#绑定要监听的端口
        try:
            server.listen() 
            print("Start listening")
            conn,addr=server.accept()
            print(conn,addr)
            print("Connected")
            data=conn.recv(1024)
            maindata=str(data)
            print(maindata)
            conn.send(data.upper())
            if str(data)=="b'next'":
                t_MusicPlay3 = threading.Thread(target=MusicPlay)
                t_MusicPlay3.start()
                xiumianle=False
                xiumiantime=0
                MainNext=True
            elif str(data)=="b'light'":
                xiumianle=False
                xiumiantime=0
            elif str(data)=="b'up'":
                timeint=timeint-2
                t_MusicPlay3 = threading.Thread(target=MusicPlay)
                t_MusicPlay3.start()
                MainNext=True
                xiumianle=False
                xiumiantime=0
            elif str(data)=="b'replay'":
                if Replay:
                    Replay=False
                    print("Replay=False")
                elif Replay==False:
                    Replay=True
                    print("Replay=True")
        except:
            print("error")

AllWaveName=glob.glob(r"Music/*.wav")
print(AllWaveName)
print (len(AllWaveName))
t_MusicPlay = threading.Thread(target=MusicPlay)
t_xiumian = threading.Thread(target=xiumian)
t_Timeupdate = threading.Thread(target=Timeupdate)

t_Wificl = threading.Thread(target=Wificl)
t_MusicPlay.start()
t_xiumian.start()
t_Timeupdate.start()

t_Wificl.start()





