#include <Keyboard.h>
#include <Mouse.h>

#if defined(_USING_HID)
#include <key_layouts.h>
#endif

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define LEFT_BUTTON 6
#define RIGHT_BUTTON 7

Adafruit_SSD1306 display = Adafruit_SSD1306(128, 64, &Wire);

void setup() 
{
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
#if defined(_USING_HID)
    Keyboard.begin();
    Mouse.begin();
#endif

    pinMode(LEFT_BUTTON, INPUT_PULLUP);
    pinMode(RIGHT_BUTTON, INPUT_PULLUP);

    display.clearDisplay();
    display.setTextColor(1);
    display.setTextSize(1);
}

int8_t key_index = 0;
bool pressed = false;
void key_mode()
{
    display.clearDisplay();
    
    display.setCursor(0, 0);
    display.print("Current:         Keys");
    display.drawLine(0,10,128,10,1);

    display.setCursor(0, 32);
#if defined(_USING_HID)
    display.print(keys_arr[key_index].name);
#else
    display.print("Nothing");
#endif
    display.display();

#if defined(_USING_HID)
    // Next key
    if (digitalRead(LEFT_BUTTON) == LOW) {
        if (!pressed) key_index++;
        pressed = true;
    } else pressed = false;

    // Key press
    if (digitalRead(RIGHT_BUTTON) == LOW) {
        Keyboard.press(keys_arr[key_index].key);
    } else Keyboard.releaseAll();

    if (key_index > KEYS) key_index = 0;
    if (key_index < 0) key_index = KEYS;
#endif
}

int8_t state = 0;
void copy_mode()
{
    display.clearDisplay();
    
    display.setCursor(0, 0);
    display.print("Current:         Copy");
    display.drawLine(0,10,128,10,1);

    display.setCursor(46, 32);
    switch (state) {
        case 0: display.print("Nothing"); break;
        case 1: display.print("Copied"); break;
        case 2: display.print("Pasted"); break;
    }

#if defined(_USING_HID)
    // ctrl+c
    if (digitalRead(LEFT_BUTTON) == LOW) {
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.write('c');
        state = 1;
    } else Keyboard.releaseAll();

    // ctrl+v
    if (digitalRead(RIGHT_BUTTON) == LOW) {
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.write('v');
        state = 2;
    } else Keyboard.releaseAll();
#endif

    display.display();
}

void mouse_mode()
{
    display.clearDisplay();
    
    display.setCursor(0, 0);
    display.print("Current:        Mouse");
    display.drawLine(0,10,128,10,1);

    display.setCursor(38, 32);
    display.print("Cute Mice");
    display.display();

#if defined(_USING_HID)
    // Left mouse
    if (digitalRead(LEFT_BUTTON) == LOW)
        Mouse.click(MOUSE_LEFT);

    // Right mouse
    if (digitalRead(RIGHT_BUTTON) == LOW)
        Mouse.click(MOUSE_RIGHT);
#endif
}

int8_t current_mode = 0;
void loop() 
{
    if (digitalRead(LEFT_BUTTON) == LOW && digitalRead(RIGHT_BUTTON) == LOW) {
        current_mode++;
        if (current_mode > 2) current_mode = 0;
        return;
    }

    switch (current_mode) {
        case 0: key_mode(); break;
        // case 1: copy_mode(); break;
        // case 2: mouse_mode(); break;
    }
}