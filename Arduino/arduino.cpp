#include <Arduino_FreeRTOS.h>
#include "pitches.h"
#include <LiquidCrystal_I2C.h>
#define SPEAKER_PIN A3
const uint8_t buttonPins[] = { 13, 12, 11, 10, 9, 8, 7, 6, 5, 4,
  3, 2, 1 };
const int buttonTones[] = {
  NOTE_C4, NOTE_CS4, NOTE_D4, NOTE_DS4, NOTE_E4, NOTE_F4,
  NOTE_FS4,
  NOTE_G4, NOTE_GS4, NOTE_A4, NOTE_AS4, NOTE_B4, NOTE_C5
};
const int numTones = sizeof(buttonPins) / sizeof(buttonPins[0]);
unsigned long timing;
LiquidCrystal_I2C lcd(0x27, 20, 4);
void LCD_detected();
void LCD_notdetected();
void sound();
TaskHandle_t xHandle;
TaskHandle_t vHandle;
TaskHandle_t zHandle;


void setup() {
  Serial.begin(9600);
  lcd.init();
  xTaskCreate(sound, "sound", 128, NULL, 2, &vHandle);
  xTaskCreate(LCD_detected, "lcd_on", 128, NULL, 3, &xHandle);
  xTaskCreate(LCD_notdetected, "lcd_off", 128, NULL, 1, &zHandle);
  vTaskStartScheduler();
}


void LCD_detected(void){
  for(;;){
    lcd.backlight();
    lcd.display();
    lcd.setCursor(1, 0);
    lcd.print("Button:");
    lcd.setCursor(1, 1);
    lcd.print("Tone:");
    vTaskSuspend(xHandle);
  }
}


void LCD_notdetected(void){
  for(;;){
    lcd.noBacklight();
    lcd.noDisplay();
    for (byte i = 0; i < numTones; i++) {
      byte buttonPin = buttonPins[i];
      if (digitalRead(buttonPin) == LOW) {
        vTaskResume( xHandle );
        vTaskResume( vHandle );
      }
    }
  }
}



void sound(void){
  for (uint8_t i = 0; i < numTones; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }
  pinMode(SPEAKER_PIN, OUTPUT);
  for(;;){
      int pitch = 0;
      for (uint8_t i = 0; i < numTones; i++) {
        if (digitalRead(buttonPins[i]) == LOW) {
          pitch = buttonTones[i];
        lcd.setCursor(9, 0);
        lcd.print(14 - buttonPins[i]);
        lcd.setCursor(9, 1);
        lcd.print(buttonTones[i]);
      }
    }
    if (pitch) {
      tone(SPEAKER_PIN, pitch);
      timing = millis();
    } 
    else {
      noTone(SPEAKER_PIN);
      if (millis() - timing > 5000){
        vTaskSuspend( vHandle );
      }
    }
  } 
}
