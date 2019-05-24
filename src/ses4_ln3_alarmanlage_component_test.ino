/*
 * Project ses4_ln3_alarmanlage_component_test
 * Description: Simply tests the correct setup of the board
 * Author: Jose Miguel Rota
 * Date: 24 May 2019
 */

#define ALARM_LED_RED D4
#define ALARM_LED_YELLOW D3
#define ALARM_LED_GREEN D2
#define ALARM_BUTTON_ACTIVATE D1
#define ALARM_BUTTON_RIGHT D6
#define ALARM_BUTTON_LEFT D5
#define ALARM_SPEAKER D0
#define ALARM_DOOR_SENSOR A0

#define STATE_READY 1
#define STATE_ACTIVE 2
#define STATE_DOOR_OPEN 3
#define STATE_CODE_FAILED 4
#define STATE_CODE_SUCCESS 5

void setup() {
  pinMode(ALARM_LED_RED, OUTPUT);
  pinMode(ALARM_LED_YELLOW, OUTPUT);
  pinMode(ALARM_LED_GREEN, OUTPUT);
  pinMode(ALARM_BUTTON_ACTIVATE, INPUT_PULLUP);
  pinMode(ALARM_BUTTON_RIGHT, INPUT_PULLUP);
  pinMode(ALARM_BUTTON_LEFT, INPUT_PULLUP);
  pinMode(ALARM_SPEAKER, OUTPUT);
  pinMode(ALARM_DOOR_SENSOR, INPUT_PULLUP);
}

void loop() {
  
  // Test red button & speaker
  if (digitalRead(ALARM_BUTTON_ACTIVATE) == LOW) {
    digitalWrite(ALARM_LED_RED, HIGH);
    tone(ALARM_SPEAKER, 330, 16);
    delay(16);
  } else {
    digitalWrite(ALARM_LED_RED, LOW);
  }

  // Test green button & speaker
  if (digitalRead(ALARM_BUTTON_RIGHT) == LOW) {
    digitalWrite(ALARM_LED_YELLOW, HIGH);
    tone(ALARM_SPEAKER, 294, 16);
    delay(16);
  } else {
    digitalWrite(ALARM_LED_YELLOW, LOW);
  }

  // Test blue button & speaker
  if (digitalRead(ALARM_BUTTON_LEFT) == LOW) {
    digitalWrite(ALARM_LED_GREEN, HIGH);
    tone(ALARM_SPEAKER, 262, 16);
    delay(16);
  } else {
    digitalWrite(ALARM_LED_GREEN, LOW);
  }

  // Test magnetic sensor & speaker
  if (digitalRead(ALARM_DOOR_SENSOR) == LOW) {
    digitalWrite(ALARM_LED_RED, HIGH);
    tone(ALARM_SPEAKER, 330, 16);
    delay(16);
    // digitalWrite(ALARM_ONBOARD_LED, HIGH);
  } else {
    digitalWrite(ALARM_LED_RED, LOW);
    // digitalWrite(ALARM_ONBOARD_LED, LOW);
  }
}