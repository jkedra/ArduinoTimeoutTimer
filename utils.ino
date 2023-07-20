#include <math.h>

void pumpOn() {
  digitalWrite(PUMP_OUTPUT, HIGH);
#ifdef SERIALDBG
  char buf[80];
  sprintf(buf, "pumpOn() %i mins\n", round(millis()/60/1000));
  Serial.print(buf);
#endif
}

void pumpOff() {
  digitalWrite(PUMP_OUTPUT, LOW);
#ifdef SERIALDBG
  char buf[80];
  sprintf(buf, "pumpOff() %i mins\n", round(millis()/60/1000));
  Serial.print(buf);
#endif
}

void flipPin(uint8_t pin) {
  digitalWrite(pin, !digitalRead(pin));
}
