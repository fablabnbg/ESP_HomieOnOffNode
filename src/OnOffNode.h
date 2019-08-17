/*
 * OnOffNode.h
 *
 *  Created on: 16.08.2019
 *      Author: ian
 */

#ifndef SRC_ONOFFNODE_H_
#define SRC_ONOFFNODE_H_

#include <HomieNode.hpp>

class OnOffNode: public HomieNode {
public:
	OnOffNode(const char* _id, const char* _name, uint_fast8_t _pin, bool _invert=false);
	bool handleInput(const HomieRange& range, const String& property, const String& value) override;
	void setup() override;
	void onReadyToOperate() override;
private:
	uint8_t pin;
	bool invert;
};

#endif /* SRC_ONOFFNODE_H_ */
