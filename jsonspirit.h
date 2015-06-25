
#pragma once
#include <string>
#include "json_spirit/ciere/json/io.hpp"
#include "json_spirit/libs/json/src/io.cpp"
#include "json_spirit/libs/json/src/value.cpp"

class jsonspirit {
public:
	void parse(const std::string &json) {
		root = ciere::json::construct(json);
	}

	std::string generate() const {
		std::ostringstream os;
		os << root;
		return os.str();
	}

protected:
	ciere::json::value root;
};
