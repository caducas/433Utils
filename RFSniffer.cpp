/*
  RF_Sniffer
  
  Hacked from http://code.google.com/p/rc-switch/
  
  by @justy to provide a handy RF code sniffer
*/

#include "RCSwitch.h"
#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#include <iostream>
     
using namespace std;
     
RCSwitch mySwitch;
 


int main(int argc, char *argv[]) {
  
     // This pin is not the first pin on the RPi GPIO header!
     // Consult https://projects.drogon.net/raspberry-pi/wiringpi/pins/
     // for more information.
    int pin_in = 2;
    int opt = 0;
     
     if(wiringPiSetup() == -1)
       return 0;

      while((opt = getopt(argc, argv, "p:dc")) != -1) {
        if(opt == 'p') {
            pin_in = atoi(optarg);
            printf("pin is set now\n");
        }
      }
     mySwitch = RCSwitch();
     mySwitch.enableReceive(pin_in);  // Receiver on inerrupt 0 => that is pin #2
     
    
     while(1) {
  
      if (mySwitch.available()) {
    
        int value = mySwitch.getReceivedValue();
    
        if (value == 0) {
          printf("Unknown encoding");
        } else {    
   
          // printf("Received %i\n", mySwitch.getReceivedValue() );
          // printf("event%i\n",mySwitch.getReceivedValue());
          printf("event");
          cout << mySwitch.getReceivedValue() << endl;
        }
    
        mySwitch.resetAvailable();
    
      }
      
  
  }

  exit(0);


}

