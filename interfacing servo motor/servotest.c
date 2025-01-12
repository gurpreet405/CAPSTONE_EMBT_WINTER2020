#include <iobb.h>   // A header library to control GPIOs of Beaglebone
#include <stdio.h>   //Standard C input Output Library 
#include <time.h>  //Time Library  
#include <unistd.h> //defines miscellaneous symbolic constants and types, and declares miscellaneous functions
#include <sys/types.h> //definitions for types like size_t , ssize_t

void servo_move(int angle); //Defining a function

int pin = 10;

int  main(void)  

{  

  iolib_init();   //Initializing the iobb library
  iolib_setdir(8, pin, DigitalOut);   //Setting Pin direction of a specific pin of a specific port 
  printf("Program Started\n"); // A simple print message 
  
  while(1)  //Infinite Loop

    {  

      for(int i=0;i<180;i = i+10) // A for loop to servo_angle function repeatedly with value 0 - 180
      {
        servo_move(i);  // Calling the Function to move servo at specific angle
        iolib_delay_ms(50);
      }

      for(int i=180;i>0;i= i-10) // A for loop to servo_angle function repeatedly with value 180 - 0
      {
      	servo_move(i); // Calling the Function to move servo at specific angle
      	iolib_delay_ms(50);
      }

  }


  iolib_free();  // Free the GPIos

  return(0);  

}  


void servo_move(int angle) // Function for moving servo to angle
{

int delay = 0; // An integer to store delays

delay =( (5.55 * angle)+1000); // A formula to calculate delay for Servo motor
// We got the delay and other details from Servo motor (SG90) datasheet

printf("Delay %d \n",delay); // Print the calculated delay

for(int i=0;i<50;i++) // A for loop running 50 times for setting angle of Servo
{
pin_high(8,pin); // Making the servo connected pin high
usleep(delay); //Delay in microseconds which we calculated above
pin_low(8,pin); // Making the servo connected pin low
usleep(20000-delay); //Delay in microseconds which we calculated above subtracted by 20000

}

iolib_delay_ms(10); // Small delay


}
