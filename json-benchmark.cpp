
#include <string>
#include <fstream>
#include <boost/property_tree/json_parser.hpp>
#include <celero/Celero.h>

using namespace std;

class NullJson {
public:
	void parse(const string &) {}
};

class BoostPTree {
public:
	void parse(const string &json) {
		istringstream jfile(json);
		boost::property_tree::read_json(jfile, root);
	}

private:
	boost::property_tree::ptree root;
};

template<typename Impl>
class ParseFixture : public celero::TestFixture, public Impl {
public:
	virtual void setUp(int64_t) {
		ifstream t("data.json");
		json.assign(istreambuf_iterator<char>(t), istreambuf_iterator<char>());
	}

	string json;
};

BASELINE_F(Parsing, NullJson, ParseFixture<NullJson>, 3, 1)
{
	parse(json);
}

BENCHMARK_F(Parsing, BoostPTree, ParseFixture<BoostPTree>, 3, 1)
{
	parse(json);
}

CELERO_MAIN

