#include <Adafruit_SSD1306.h>

#define LEFT_BUTTON 6
#define RIGHT_BUTTON 7

void key_press(void (*pressfunc)(), int button);

void key_mode(Adafruit_SSD1306& display);

void copy_mode(Adafruit_SSD1306& display);

void mouse_mode(Adafruit_SSD1306& display);

void mode_change(Adafruit_SSD1306& display);

int8_t& get_current_mode();