
#pragma once
#include <string>
#include <sstream>
#include <boost/property_tree/json_parser.hpp>

class boost_property_tree {
public:
	void parse(const std::string &json) {
		std::istringstream jfile(json);
		boost::property_tree::read_json(jfile, root);
	}

private:
	boost::property_tree::ptree root;
};
