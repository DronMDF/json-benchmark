
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

	std::string generate() const {
		std::ostringstream os;
		boost::property_tree::write_json(os, root, false);
		return os.str();
	}

protected:
	boost::property_tree::ptree root;
};

class boost_property_tree_styled : public boost_property_tree {
public:
	std::string generate() const {
		std::ostringstream os;
		boost::property_tree::write_json(os, root);
		return os.str();
	}
};
