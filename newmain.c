/*
 * File:   newmain.c
 * Author: MOHAMED
 *
 * Created on 19 ??????, 2021, 07:39 ?
 */


#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

void InitPWM()
{
   TCCR0|=(1<<WGM00)|(1<<WGM01)|(1<<COM01)|(1<<CS00);
   DDRB|=(1<<PB3);
}

void SetPWMOutput(uint8_t duty)
{
   OCR0=duty;
}

void Wait()
{
 _delay_loop_2(3200);
}

int main(void)
{
   uint8_t brightness=0;
   InitPWM();

   while(1)
   {
      //Now Loop with increasing brightness
      for(brightness=0;brightness<255;brightness++)
      {
         SetPWMOutput(brightness);
         Wait();
      }

      //Now Loop with decreasing brightness
      for(brightness=255;brightness>0;brightness--)
      {
         SetPWMOutput(brightness);
         Wait();
      }
   }
}