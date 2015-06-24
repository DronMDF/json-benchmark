
#pragma once
#include <string>
#include "rapidjson/include/rapidjson/document.h"
#include "rapidjson/include/rapidjson/writer.h"
#include "rapidjson/include/rapidjson/stringbuffer.h"

class rapidjson_bench {
public:
	void parse(const std::string &json) {
		root.Parse(json.c_str());
	}

	std::string generate() const {
		rapidjson::StringBuffer buffer;
		rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
		root.Accept(writer);
		return buffer.GetString();
	}

protected:
	rapidjson::Document root;
};
