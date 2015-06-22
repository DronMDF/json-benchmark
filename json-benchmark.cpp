
#include <celero/Celero.h>

using namespace std;

class NullJson {
public:
	void parse() {}
};

template<typename Impl>
class ParseFixture : public celero::TestFixture, public Impl {
};

BASELINE_F(Abstract, NullJson, ParseFixture<NullJson>, 10, 1)
{
	parse();
}

CELERO_MAIN

