#include <wiringPi.h>
#include <ads1115.h>
#include <stdio.h>
#include <stdint.h>



int main(int argc, char *argv[]) 
{
  
	int16_t value;
  
	double voltage;
	
	int16_t i=0;
	double dat1=0;
	double dat2=0;
	double dat3=0;
	double dat4=0;

	ads1115Setup(100,0x48);
	
	wiringPiSetup() ;
	pinMode(0, OUTPUT) ;
	pinMode(2, OUTPUT) ;
	pinMode(3, OUTPUT) ;
	
	pinMode(12, OUTPUT) ;
	pinMode(13, OUTPUT) ;
	pinMode(14, OUTPUT) ;
	
	pinMode(29, OUTPUT) ;
	pinMode(21, OUTPUT) ;
	pinMode(22, OUTPUT) ;
	
	pinMode(23, OUTPUT) ;
	pinMode(24, OUTPUT) ;
	pinMode(25, OUTPUT) ;

	for (;;) 
	{
    
		value = (int16_t) analogRead(100);
    
		voltage = value * (4.096 / 32768);
		
		printf("ADS1115 Reading: %d\n\r",value);
    
		printf("ADS1115 Voltage: %g\n\r",voltage);
		
                
		dat4=dat3;
		dat3=dat2;
		dat2=dat1;
                if(value>0)
                {
                        dat1=value;
                }
                else
                {
                        dat1=-value;
                }
		

                if(i==0)   //1 row
		{
			if(dat1<500)
			{
				digitalWrite(0, HIGH);
				digitalWrite(2, HIGH);
				digitalWrite(3, HIGH); 	
			}
			else if(dat1<1000)
			{
				digitalWrite(0, LOW);
				digitalWrite(2, HIGH);
				digitalWrite(3, HIGH); 	
			}
			else if(dat1<1500)
			{
				digitalWrite(0, LOW);
				digitalWrite(2, LOW);
				digitalWrite(3, HIGH); 	
			}
			else 
			{
				digitalWrite(0, LOW);
				digitalWrite(2, LOW);
				digitalWrite(3, LOW); 	
			}
			i++;			
		}
                if(i==1)  //2 row
		{
			if(dat2<500)
			{
				digitalWrite(12, HIGH);
				digitalWrite(13, HIGH);
				digitalWrite(14, HIGH); 	
			}
			else if(dat2<1000)
			{
				digitalWrite(12, LOW);
				digitalWrite(13, HIGH);
				digitalWrite(14, HIGH); 	
			}
			else if(dat2<1500)
			{
				digitalWrite(12, LOW);
				digitalWrite(13, LOW);
				digitalWrite(14, HIGH); 	
			}
			else 
			{
				digitalWrite(12, LOW);
				digitalWrite(13, LOW);
				digitalWrite(14, LOW); 	
			}
			i++;			
		}
		if(i==2)   //3 row
		{
			if(dat3<500)
			{
				digitalWrite(29, HIGH);
				digitalWrite(21, HIGH);
				digitalWrite(22, HIGH); 	
			}
			else if(dat3<1000)
			{
				digitalWrite(29, LOW);
				digitalWrite(21, HIGH);
				digitalWrite(22, HIGH); 	
			}
			else if(dat3<1500)
			{
				digitalWrite(29, LOW);
				digitalWrite(21, LOW);
				digitalWrite(22, HIGH); 	
			}
			else 
			{
				digitalWrite(29, LOW);
				digitalWrite(21, LOW);
				digitalWrite(22, LOW); 	
			}
			i++;			
		}
		if(i==3)   //4 row
		{
			if(dat4<500)
			{
				digitalWrite(23, HIGH);
				digitalWrite(24, HIGH);
				digitalWrite(25, HIGH); 	
			}
			else if(dat4<1000)
			{
				digitalWrite(23, LOW);
				digitalWrite(24, HIGH);
				digitalWrite(25, HIGH); 	
			}
			else if(dat4<1500)
			{
				digitalWrite(23, LOW);
				digitalWrite(24, LOW);
				digitalWrite(25, HIGH); 	
			}
			else 
			{
				digitalWrite(23, LOW);
				digitalWrite(24, LOW);
				digitalWrite(25, LOW); 	
			}
			i=0;			
		}
		delay(1000);
	} 
	return 0;
}

