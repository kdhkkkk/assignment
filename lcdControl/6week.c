

#include <wiringPi.h>
#include <stdio.h>
#include <lcd.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <signal.h>

#define LCD_RS 11
#define LCD_E 10
#define LCD_D4 6
#define LCD_D5 5
#define LCD_D6 4
#define LCD_D7 1
#define LED1 28
#define LED2 29
#define SW1 27
#define DHT 7
#define ECHO 0
#define TRIGGER 2
#define MAXTIMINGS 85

volatile int count = 0;

void setLED(int ,int);
void setLCD(char*,int);
int* getTemp();
float getDistance(float);
void swInterrupt();
void ctrl_c_handler(int);

int main(int argc , char **argv)
{
		int lcd;
		char s1[20];
		float distance;
		
		wiringPiSetup();
		wiringPiISR(SW1, INT_EDGE_RISING, &swInterrupt);
		pinMode(LED1,OUTPUT);
		pinMode(LED2,OUTPUT);
		signal(SIGINT,ctrl_c_handler);
		
		if(lcd = lcdInit(2,16,4,LCD_RS,LCD_E,LCD_D4,LCD_D5,LCD_D6,LCD_D7,0,0,0,0))
		{
				printf("lcd init failed!\n");
				return -1;
		}
		
		while(1)
		{
				if(count ==0)
				{		char msg[20] = "Press the switch";
						setLCD(msg,lcd);
						setLED(0,0);
				}
				
				else if(count==1)
				{								
						int* temp = getTemp();
						sprintf(s1, "TEMP :     %d.%dC",temp[0],temp[1]);
						setLCD(s1,lcd);
					//	lcdPosition(lcd, 0, 0);
						//lcdPrintf(lcd,"Temp :     %d.%dC",temp[0],temp[1]);
						
						setLED(1,0);					
				}
				
				else if (count ==2)
				{		
					
						distance = getDistance(distance);
						sprintf(s1, "Distance:%.2fcm",distance);
						setLCD(s1,lcd);
						setLED(1,1);	
				}
		}
		
		
		return 0;
}

void setLED(int led1, int led2)
{
	digitalWrite(LED1,led1);
	digitalWrite(LED2,led2);
}

void setLCD(char msg[20], int lcd)
{
	lcdPosition(lcd,0,0);
	lcdPuts(lcd,msg);
	
}

int* getTemp()
{
	int dht11_dat[5] = { 0, 0, 0, 0, 0 };

	while(1)
	{
			uint8_t laststate = HIGH;
			uint8_t counter = 0;
			uint8_t j = 0, i;
			float f; 
			static int arr[2];
			dht11_dat[0] = dht11_dat[1] = dht11_dat[2] = dht11_dat[3] = dht11_dat[4] = 0;
		 
			pinMode(DHT, OUTPUT);
			digitalWrite(DHT, LOW);
			delay(18);
				
			digitalWrite(DHT, HIGH);
			delayMicroseconds(40);
				
			pinMode(DHT, INPUT);
		 
			for (i = 0; i < MAXTIMINGS; i++)
			{
				counter = 0;
				while (digitalRead(DHT) == laststate)
				{
					counter++;
					delayMicroseconds(1);
					if (counter == 255)
					{
						break;
					}
				}
				laststate = digitalRead(DHT);
		 
				if (counter == 255)
					break;
				if ((i >= 4) && (i % 2 == 0))
				{
					dht11_dat[j / 8] <<= 1;
					if (counter > 16)
						dht11_dat[j / 8] |= 1;
					j++;
				}
			}
		 
			if ((j >= 40) && (dht11_dat[4] == ((dht11_dat[0] + dht11_dat[1] + dht11_dat[2] + dht11_dat[3]) & 0xFF)))
			{
				arr[0] = dht11_dat[2];
				arr[1] = dht11_dat[3];
				
			}	
			else
				delay(1);
			delay(1000);
				
			return (int*) arr;
			
	}
}

float getDistance(float distance)
{	char s1[20];
	wiringPiSetup();
	while(1)
	{
		 int start_time, end_time;
		 if (wiringPiSetup() == -1) exit(1) ;

		 pinMode(TRIGGER, OUTPUT) ;

		 pinMode(ECHO , INPUT) ;

		 digitalWrite(TRIGGER, LOW) ;

		 delay(500) ;

		 digitalWrite(TRIGGER, HIGH) ;

		 delayMicroseconds(10) ;

		 digitalWrite(TRIGGER, LOW) ;

		 while (digitalRead(ECHO) == 0) ;

		 start_time = micros() ;

		 while (digitalRead(ECHO) == 1) ;

		 end_time = micros() ;

		 distance = (end_time - start_time) / 29. / 2. ;
		 
		 return distance;
	}

					
}

void swInterrupt()
{
	count ++;
	if(count ==3)
		count =0;
	delay(120);
}

void ctrl_c_handler(int signal)
{
		lcdClear(0);
		setLED(0,0);
		exit(1);
}






















































