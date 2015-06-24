
#pragma once
#include <string>
#include "rapidjson/include/rapidjson/rapidjson.h"

class rapidjson {
public:
	void parse(const std::string &json) {
		root.Parse(json);
	}

	std::string generate() const {
		rapidjson::StringBuffer buffer;
		Writer<StringBuffer> writer(buffer);
    d.Accept(writer);
	}

protected:
	rapidjson::Document root;
};
