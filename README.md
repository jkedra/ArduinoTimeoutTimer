# ArduinoTimeoutTimer

Ultra Simple Timeout Timer

Well - surprise, it is not an Ultra Simple Timeout Timer yet.
It has been created as a protection for water pump against prolonged run.

Here is the scenario:

The water comes to the well in a slow ratio. The pump can empty the well
after some time so it needs to poweroff and wait a few minutes before
the water fills up the well so the pump could be powered on again.

Initally the well is topped up so the initial pump runtime can be a little
longer (constant `PUMP_OPEN_INITIAL_MINUTES`),
but subsequent pump runtime should be somehow shorter
(`PUMP_OPEN_SUBSEQUENT_MINUTES`).

The `PUMP_BREAK_MINUTES` adjusts the time required for the water
to fill up the well.

Two other constants `PUMP_OPEN_LED_DELAY_MS` and `PUMP_BREAK_LED_DELAY_MS`
are used for cycling LED indicator which is blinking quickly when the
pump is active and slowly when it waits for well to be refilled.

The `PUMP_OUTPUT` defines a pin for the the pump switch.

## Cycle example

1. Pump starts up for `PUMP_OPEN_INITIAL_MINUTES`. Then...
2. Pump is powered off for `PUMP_BREAK_MINUTES`. Then...
3. Pump is turned on for `PUMP_OPEN_SUBSEQUENT_MINUTES`. Then
4. Got to (2)

# Possible usage

I need it for the pump but it is an another example of a simple timer using
Arduino. Feel free to use it for your own purpose.






