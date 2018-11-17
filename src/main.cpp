#include <Arduino.h>
#include <Adafruit_ILI9481.h>
#include "mgos_timers.h"

#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define WHITE   0xFFFF

Adafruit_ILI9481 *tft = nullptr;

void setup(void) {
  tft = new Adafruit_ILI9481();

  if (tft != nullptr) {
    printf("TFT object created!\r\n");
    tft->reset();
    tft->begin();
    tft->setRotation(3);
    tft->fillScreen(WHITE);

    tft->setTextColor(BLACK, WHITE);
    tft->setTextSize(3);
    tft->setCursor(100, 100);
    tft->print("Hello World!");

    for (int i = 80; i < 95; i++) {
      tft->drawCircle(110, 105, i, BLUE);
    }

    for (int i = 80; i < 95; i++) {
      tft->drawCircle(370, 190, i, RED);
    }
  }
  
}

void loop() {

}
