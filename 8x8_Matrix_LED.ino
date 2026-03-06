#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>
#include <SoftwareSerial.h>

#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 1

#define DATA_PIN 11
#define CLK_PIN 13
#define CS_PIN 10

SoftwareSerial BT(2,3);   // RX, TX

MD_Parola display = MD_Parola(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);

String message = "WELCOME";

void setup()
{
  display.begin();
  display.setIntensity(5);
  display.displayClear();

  BT.begin(9600);
}

void loop()
{
  if (BT.available())
  {
    message = BT.readString();
    display.displayClear();
    display.displayScroll(message.c_str(), PA_LEFT, PA_SCROLL_LEFT, 100);
  }

  if (display.displayAnimate())
  {
    display.displayReset();
  }
}