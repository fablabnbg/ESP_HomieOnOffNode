/*
 * OnOffNode.cpp
 *
 *  Created on: 16.08.2019
 *      Author: ian
 */

#include <OnOffNode.h>
#include <LoggerNode.h>

OnOffNode::OnOffNode(const char* _id, const char* _name, uint_fast8_t _pin, bool _invert):
	HomieNode(_id, _name, "OnOff", false),
	pin(_pin),
	invert(_invert)
{
	advertise("state").setName("Zustand").setDatatype("bool").settable();
}

bool OnOffNode::handleInput(const HomieRange& range, const String& property, const String& value) {
	LN.logf(__PRETTY_FUNCTION__, LoggerNode::DEBUG, "Received input for property %s, value %s", property.c_str(), value.c_str());
	if (property.equalsIgnoreCase("state")) {
		bool cmd = value.equalsIgnoreCase("ON");
		digitalWrite(pin, invert ^ cmd);
		setProperty("state").setRetained(true).send(String(cmd?"ON":"OFF"));
		return true;
	}
	return false;
}

void OnOffNode::setup() {
	pinMode(pin, OUTPUT);
	digitalWrite(pin, invert);
}

void OnOffNode::onReadyToOperate() {
	setProperty("state").setRetained(true).send(String(digitalRead(pin)^invert ? "ON":"OFF"));
}

