#include <core.h>
#include <stdio.h>
#include <string.h>
#include <linux/input.h>
#include <fcntl.h>
#include <sys/time.h>
#include <unistd.h>

int InData1 = 0;
int InData2 = 0;
int InData3 = 0;
int InData4 = 0;
int InData5 = 0;

int TouchSensitivity = 800; 
int num = 38;

void simulate_key(int fd, int kval)
{

         struct input_event event;
         gettimeofday(&event.time, 0);

         event.type = EV_KEY;
         event.value = 1;
         event.code = kval;
         write(fd, &event, sizeof(event));

         event.type = EV_SYN;
         event.value = 0;
         event.code = SYN_REPORT;
         write(fd, &event, sizeof(event));
         memset(&event, 0, sizeof(event));
         gettimeofday(&event.time, 0);
        
	     event.type = EV_KEY;
         event.value = 0;
         event.code = kval;
         write(fd, &event, sizeof(event));

       event.type = EV_SYN;
       event.value = 0;
       event.code = SYN_REPORT;
       write(fd, &event, sizeof(event));
}

 

void simulate_mouse(int fd, int rel_x, int rel_y)
{

    struct input_event event;

    gettimeofday(&event.time, 0);

    event.type = EV_REL;

    event.value = rel_x;

    event.code = REL_X;

    write(fd, &event, sizeof(event));

    event.type = EV_REL;

    event.value = rel_y;

    event.code = REL_Y;

    write(fd, &event, sizeof(event));

    event.type = EV_SYN;

    event.value = 0;

    event.code = SYN_REPORT;

    write(fd, &event, sizeof(event));

}

 void setup()
{
  for(int i = 6; i <= 12; i++)
    {
      pinMode(i, OUTPUT);                    
    }
}

void loop()
{
	 int fd_mouse ;
         int fd_kbd ;
         int i = 0;
         fd_kbd = open("/dev/input/event1", O_RDWR);
         if(fd_kbd <= 0)
         {
                   printf("Can not open keyboard input file\n");
                   while(1);
         }

	while(1)
	{           
  	InData1 = analogRead(A1);
  	InData2 = analogRead(A2);
  	InData3 = analogRead(A3);
  	InData4 = analogRead(A4);
  	InData5 = analogRead(A5);

  if(InData1 <= num)
   {
    	digitalWrite(7, HIGH); 
	simulate_key(fd_kbd, KEY_S);
	delay(500);
	InData1 = 2000;
	InData2 = 2000;
	InData3 = 2000;
	InData4 = 2000;
	InData5 = 2000;
   }
     else digitalWrite(7, LOW);
     
  if(InData2 <= TouchSensitivity)
   {
   	 digitalWrite(8, HIGH); 
	 simulate_key(fd_kbd, KEY_D);
	delay(500);
	InData1 = 2000;
	InData2 = 2000;
	InData3 = 2000;
	InData4 = 2000;
	InData5 = 2000;
   }
   else digitalWrite(8, LOW);
     
  if(InData3 <= TouchSensitivity)
   {
    	digitalWrite(9, HIGH); 
	 simulate_key(fd_kbd, KEY_F);
	delay(500);
	InData1 = 2000;
	InData2 = 2000;
	InData3 = 2000;
	InData4 = 2000;
	InData5 = 2000;
   }
   else digitalWrite(9, LOW);
     
  if(InData4 <= TouchSensitivity)
   {
    	digitalWrite(10, HIGH); 
	simulate_key(fd_kbd, KEY_G);
	delay(500);
	InData1 = 2000;
	InData2 = 2000;
	InData3 = 2000;
	InData4 = 2000;
	InData5 = 2000;
   }
   else digitalWrite(10, LOW);
      
  if(InData5 <= TouchSensitivity)
   {
    	digitalWrite(11, HIGH); 
	simulate_key(fd_kbd, KEY_H);
	delay(500);
	InData1 = 2000;
	InData2 = 2000;
	InData3 = 2000;
	InData4 = 2000;
	InData5 = 2000;
   }
   else digitalWrite(11, LOW);
	delay(100);
	}
}
