
#pragma once
#include <string>
#include "Skeleton.h"

class PtreeImplementation : public Skeleton<boost::ptree>
{
	virtual std::string name() const override {
		return "boost ptree";
	}
	virtual type prepare(size_t size) const override {
		// { "name": "element", "enable": true, "size": 123456, "data": [] }
		type value;
		for (int i = 0; i < size; i++) {
			type element;
			element.put("name", "element");
			element.put("enable", true);
			element.put("size", 123456);
			element.put("data", type());
			value.push_back(element);
		}
		return value;
	}
	virtual string jsonify(const int &) const override {
		std::ostringstream out;
		write_json
		return {};
	}
	virtual int parse(const string &) const override {
		return 0;
	}

	virtual bool isEqual(const int &, const int &) const override {
		return true;
	}
};
