#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include <modes.h>

Adafruit_SSD1306 display = Adafruit_SSD1306(128, 64, &Wire);

void setup() 
{
    delay(500); 

    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        while(1) {
            digitalWrite(LED_BUILTIN, HIGH); delay(100);
            digitalWrite(LED_BUILTIN, LOW); delay(100);
        }
    }

    display.clearDisplay();
    display.setTextColor(SSD1306_WHITE);
    display.setTextSize(1);
    display.setCursor(0,0);
    display.print(F("Booting..."));
    display.display();

#if defined(_USING_HID)
    Keyboard.begin();
    Mouse.begin();
#endif

    pinMode(LEFT_BUTTON, INPUT_PULLUP);
    pinMode(RIGHT_BUTTON, INPUT_PULLUP);
    
    delay(500);
}

void loop() 
{
    mode_change(display);

    display.clearDisplay();
    switch (get_current_mode()) {
        case 0: key_mode(display); break;
        case 1: copy_mode(display); break;
        case 2: mouse_mode(display); break;
    }
    display.display();
}