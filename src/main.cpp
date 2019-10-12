/*
 * main.cpp
 *
 *  Created on: 16.08.2019
 *      Author: ian
 */

#include <Arduino.h>
#include <Homie.hpp>

#include <LoggerNode.h>
#include <OnOffNode.h>

LoggerNode LN;

/* Pinout for usage on LedCtrlV3 Default PCB (5xMOSFET)
 *
 *     I2C available on defaults (4,5)
 *     GPIO12, GPIO13 available on J1 Pin 1 and 2
 *     ADC available on J1 Pin 4 (J1-3 = GND)
 *
 *     LED Connectors (J4, J5, J6): Pin1 =  Supply +24V
 *
 */
//TODO: Read names from config
OnOffNode heater1("heater1", "Heizung 1", 0, true);	//Q1: LED W1
OnOffNode heater2("heater2", "Heizung 2", 2, true);	//Q2: LED W2
OnOffNode heater3("heater3", "Heizung 3", 15, true);	//Q3: LED RGB2
OnOffNode heater4("heater4", "Heizung 4", 14, true);  //Q4: LED RGB3
//							              16	//Q5: LED RGB4

#define FW_NAME "fln-heat_4x"
#define FW_VERSION "1.0.0"

void setup() {
	//74880 is quite unusual, but it is the Baud-Rate of the ESP8266 boot loader. So by using 74880 as baudrate, you can see boot loader messages and your messages.
	Serial.begin(74880);
	Serial.println("\nSetup");
	Serial.flush();
	Homie_setFirmware(FW_NAME, FW_VERSION);
	Homie.disableResetTrigger();
	Homie.disableLedFeedback();
	Homie.setup();
}

void loop() {
	Homie.loop();
}




