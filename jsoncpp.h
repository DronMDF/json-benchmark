
#pragma once
#include <string>
#include "json/json.h"

class jsoncpp {
public:
	void parse(const std::string &json) {
		Json::Reader reader;
		reader.parse(json, root);
	}

	std::string generate() const {
		Json::FastWriter writer;
		return writer.write(root);
	}

protected:
	Json::Value root;
};

class jsoncpp_styled : public jsoncpp {
public:
	std::string generate() const {
		Json::StyledWriter writer;
		return writer.write(root);
	}
};
