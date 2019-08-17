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

//HomieSetting<long> settingCT1_WW ("CTLicht1_PIN_WW", "Output Pin Licht 1 warmweiß");
//HomieSetting<long> settingCT1_CW ("CTLicht1_PIN_CW", "Output Pin Licht 1 kaltweiß");


//HomieSetting<long> settingCT_PWMFREQ ("CTLicht_PWM_FREQ", "PWM Frequency");

//TODO: Read names from config
LoggerNode LN;
OnOffNode heater1("heater1", "Heizung 1", 0);
OnOffNode heater2("heater2", "Heizung 2", 2);
OnOffNode heater3("heater3", "Heizung 3", 15);
OnOffNode heater4("heater4", "Heizung 4", 14);

#define FW_NAME "fln-heat_4x"
#define FW_VERSION "0.0.1"

/* Magic sequence for Autodetectable Binary Upload */
const char *__FLAGGED_FW_NAME = "\xbf\x84\xe4\x13\x54" FW_NAME "\x93\x44\x6b\xa7\x75";
const char *__FLAGGED_FW_VERSION = "\x6a\x3f\x3e\x0e\xe1" FW_VERSION "\xb0\x30\x48\xd4\x1a";
/* End of magic sequence for Autodetectable Binary Upload */

void setup() {
        Serial.begin(74880);
        Serial.println("\nSetup");
        Serial.flush();
        Homie_setFirmware(FW_NAME, FW_VERSION);
        Homie.disableResetTrigger();
        //Homie.disableLedFeedback();
        Homie.setup();
}

void loop() {
        Homie.loop();
}




