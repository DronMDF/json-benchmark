
#include <string>
#include <fstream>
#include <celero/Celero.h>

#include "boost_property_tree.h"
#include "jsoncpp.h"
#include "json11.h"

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

BENCHMARK_F(Parsing, ptree, ParseFixture<boost_property_tree>, 10, 1)
{
	parse();
}

BENCHMARK_F(Parsing, json11, ParseFixture<json11>, 10, 1)
{
	parse();
}

template<typename Impl>
class GenerateFixture : public celero::TestFixture {
private:
	Impl impl;
public:
	virtual void setUp(int64_t) {
		ifstream t("data.json");
		const string json{istreambuf_iterator<char>(t), istreambuf_iterator<char>()};
		impl.parse(json);
	}

	string generate() const {
		return impl.generate();
	}
};

BASELINE_F(Generating, jsoncpp, GenerateFixture<jsoncpp>, 10, 1)
{
	celero::DoNotOptimizeAway(generate());
}

BENCHMARK_F(Generating, jsoncpp_styled, GenerateFixture<jsoncpp_styled>, 10, 1)
{
	celero::DoNotOptimizeAway(generate());
}

BENCHMARK_F(Generating, ptree, GenerateFixture<boost_property_tree>, 10, 1)
{
	celero::DoNotOptimizeAway(generate());
}

BENCHMARK_F(Generating, ptree_styled, GenerateFixture<boost_property_tree_styled>, 10, 1)
{
	celero::DoNotOptimizeAway(generate());
}

BENCHMARK_F(Generating, json11, GenerateFixture<json11>, 10, 1)
{
	celero::DoNotOptimizeAway(generate());
}

CELERO_MAIN

