
#include <string>
#include <fstream>
#include <celero/Celero.h>

using namespace std;

class NullJson {
public:
	void parse(const string &) {}
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

BASELINE_F(Abstract, NullJson, ParseFixture<NullJson>, 3, 1)
{
	parse(json);
}

CELERO_MAIN

