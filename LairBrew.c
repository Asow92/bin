/*
Lair_Brew ~ Caffeine ~
Version 0.3
*/

#include <wiringPi.h>
#include <stdio.h>

void loopback(void)
{
    char ch;
    ch = getchar();
    while( ch != '\n' ) ch = getchar();
}

int main (void)
{
    int pin = 7;
    char ch;
    int exit_flag = 0;
    printf("welcome to Lair Brew\n");

  if (wiringPiSetup() == -1) return(1);

    pinMode(pin, OUTPUT);
    printf("Brew on\n");
    digitalWrite(pin, 1);

 while( exit_flag  == 0 ) {
    printf("Wish to exit? (Y)\n");
    scanf(" %c", &ch );
    ch = toupper( ch );
 if((ch == 'Y')){
    printf("\nBrew Off\n");
    digitalWrite(pin, 0);
    delay(250);
    printf("\nEnjoy Your Coffee, Sir!\n");
  }
  else {
    printf("\nType (y) to exit.\n");
    loopback();
  }

  if( ch == 'Y' ) exit_flag = 1;


  }

  return 0;
}