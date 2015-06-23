
#pragma once
#include <string>
#include "json/json.h"

class jsoncpp {
public:
	void parse(const std::string &json) {
		Json::Reader reader;
		reader.parse(json, root);
	}

private:
	Json::Value root;
};
