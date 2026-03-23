#include <Keyboard.h>
#include <Mouse.h>

#include <modes.h>

#if defined(_USING_HID)
#include <key_layouts.h>
#endif

int8_t current_mode = 0;
bool left_pressed = false;
bool right_pressed = false;
bool released = false;

void key_press(void (*pressfunc)(), int button) {
    bool left = button == LEFT_BUTTON;
    bool right = button == RIGHT_BUTTON;

    if (digitalRead(button) == LOW) {
        if (left && !left_pressed) {
            pressfunc();
            left_pressed = true;
        }
        if (right && !right_pressed) {
            pressfunc();
            right_pressed = true;
        }
        released = false;
    } else {
        if (!released) {
            Keyboard.releaseAll();
            released = true;
        }
        if (left) left_pressed = false;
        if (right) right_pressed = false;
    }
}

int8_t key_index = 0;
void key_mode(Adafruit_SSD1306& display)
{
    display.setCursor(0, 0);
    display.print(F("Current:         Keys"));
    display.drawLine(0,10,128,10,1);

    display.setCursor(0, 32);
#if defined(_USING_HID)
    display.print(keys_arr[key_index].name);
#else
    display.print(F("Nothing"));
#endif
    display.display();

#if defined(_USING_HID)
    // Next key
    if (digitalRead(LEFT_BUTTON) == LOW) {
        if (!left_pressed) key_index++;
        left_pressed = true;
    } else left_pressed = false;

    // Key press
    key_press([](){
        Keyboard.press(keys_arr[key_index].key);
    }, RIGHT_BUTTON);

    if (key_index > KEYS) key_index = 0;
    if (key_index < 0) key_index = KEYS;
#endif
}


int8_t state = 0;
void copy_mode(Adafruit_SSD1306& display)
{
    display.setCursor(0, 0);
    display.print(F("Current:         Copy"));
    display.drawLine(0,10,128,10,1);

    display.setCursor(46, 32);
    switch (state) {
        case 0: display.print(F("Nothing")); break;
        case 1: display.print(F("Copied")); break;
        case 2: display.print(F("Pasted")); break;
    }

#if defined(_USING_HID)
    // ctrl+c
    key_press([]() {
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.write('c');
        state = 1;
    }, LEFT_BUTTON);

    // ctrl+v
    key_press([]() {
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.write('v');
        state = 2;
    }, RIGHT_BUTTON);
#endif
}

void mouse_mode(Adafruit_SSD1306& display)
{
    display.setCursor(0, 0);
    display.print(F("Current:        Mouse"));
    display.drawLine(0,10,128,10,1);

    display.setCursor(38, 32);
    display.print(F("Cute Mice"));

#if defined(_USING_HID)
    // Left mouse
    if (digitalRead(LEFT_BUTTON) == LOW)
        Mouse.click(MOUSE_LEFT);

    // Right mouse
    if (digitalRead(RIGHT_BUTTON) == LOW)
        Mouse.click(MOUSE_RIGHT);
#endif
}

bool mode_changed = false;
void mode_change(Adafruit_SSD1306& display) {
    if (digitalRead(LEFT_BUTTON) == LOW && digitalRead(RIGHT_BUTTON) == LOW) {
        if (!mode_changed) { 
            current_mode++;
            if (current_mode > 2) current_mode = 0;
            
            display.clearDisplay();
            display.setCursor(0, 20);
            display.print(F("Switching mode..."));
            display.display();

            Keyboard.releaseAll();
            Mouse.release();

            mode_changed = true; 
            delay(300);
        }
    } else {
        mode_changed = false;
    }
}

int8_t& get_current_mode() {
    return current_mode;
}