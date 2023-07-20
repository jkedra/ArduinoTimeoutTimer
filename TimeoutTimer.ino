#define SERIALDBG 1
#define PUMP_OUTPUT 4

/*
// marginal emergency mode values
word PUMP_OPEN_INITIAL_MINUTES=12;
word PUMP_OPEN_SUBSEQUENT_MINUTES=5;
word PUMP_BREAK_MINUTES=120;
*/

/*
// values for testing
word PUMP_OPEN_INITIAL_MINUTES=5;
word PUMP_OPEN_SUBSEQUENT_MINUTES=1;
word PUMP_BREAK_MINUTES=10;
*/

// values for standalone mode
word PUMP_OPEN_INITIAL_MINUTES=5;
word PUMP_OPEN_SUBSEQUENT_MINUTES=4;
word PUMP_BREAK_MINUTES=60;

word PUMP_OPEN_LED_DELAY_MS=50;
word PUMP_BREAK_LED_DELAY_MS=1000;

unsigned long startMillis = millis();
unsigned long currentMillis;


void setup() {

#ifdef SERIALDBG
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB
  }
#endif
  
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(PUMP_OUTPUT, OUTPUT);
  pumpOn();
  unsigned long initialWaitUntil = millis() + (PUMP_OPEN_INITIAL_MINUTES*60*1000L);
  while(millis() < initialWaitUntil) {
    flipPin(LED_BUILTIN);
    delay(PUMP_OPEN_LED_DELAY_MS);
  }
  digitalWrite(LED_BUILTIN, LOW);
  pumpOff();
}

void loop() {
  unsigned long subseqWaitOffUntil = millis() + (PUMP_BREAK_MINUTES*60*1000L);
  pumpOff();
  while(millis() < subseqWaitOffUntil) {
    flipPin(LED_BUILTIN);
    delay(PUMP_BREAK_LED_DELAY_MS);
  }

  unsigned long subseqWaitOnUntil = millis() + (PUMP_OPEN_SUBSEQUENT_MINUTES*60*1000L);
  pumpOn();
  while(millis() < subseqWaitOnUntil) {
    flipPin(LED_BUILTIN);
    delay(PUMP_OPEN_LED_DELAY_MS);
  }
}
