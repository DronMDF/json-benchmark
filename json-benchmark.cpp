
#include <string>
#include <fstream>
#include <celero/Celero.h>

#include "boost_property_tree.h"
#include "jsoncpp.h"

using namespace std;

template<typename Impl>
class ParseFixture : public celero::TestFixture {
private:
	Impl impl;
	string json;
public:
	virtual void setUp(int64_t) {
		ifstream t("data.json");
		json.assign(istreambuf_iterator<char>(t), istreambuf_iterator<char>());
	}

	void parse() {
		impl.parse(json);
	}

};

BASELINE_F(Parsing, jsoncpp, ParseFixture<jsoncpp>, 10, 1)
{
	parse();
}

BENCHMARK_F(Parsing, boost_property_tree, ParseFixture<boost_property_tree>, 10, 1)
{
	parse();
}

CELERO_MAIN

