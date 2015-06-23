
#pragma once
#include <string>

namespace json11_impl {
	#include "json11/json11.hpp"
	#include "json11/json11.cpp"
}

class json11 {
public:
	void parse(const std::string &json) {
		std::string err;
		root = json11_impl::json11::Json::parse(json, err);
	}

	std::string generate() const {
		return root.dump();
	}

protected:
	json11_impl::json11::Json root;
};
