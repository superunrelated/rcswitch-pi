#include "RCSwitch.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
    int PIN = 1; //BCM 18, GPIO1
    if (wiringPiSetup () == -1) return 1; 
    RCSwitch mySwitch = RCSwitch();

    //Serial.begin(9600) kann IMHO weggelassen werden, weil wir keine Serielle Terminalsitzung benÃ¶en
    printf("starting");
    mySwitch.enableReceive(PIN); // Receiver on inerrupt PIN
    printf("enabled");
    /*do {
        piLock(0);
        if (mySwitch.available()) {
            printf("available");
            //output(mySwitch.getReceivedValue(), mySwitch.getReceivedBitlength(), mySwitch.getReceivedDelay(), mySwitch.getReceivedRawdata());
            //Versuch mit printf.
            printf("%s",mySwitch.getReceivedValue());
            printf("%i",mySwitch.getReceivedBitlength());
            printf("%i",mySwitch.getReceivedDelay());
            printf("%s",mySwitch.getReceivedRawdata());
            mySwitch.resetAvailable();
        }
        piUnlock(0);
    } while(true);*/
    while(true) {
        if (mySwitch.available()) {
            printf("available\n");
            printf("%lu\n", mySwitch.getReceivedValue());
            mySwitch.resetAvailable();
        }
    }

    return(0);
}
