
#include "Skeleton.h"

using namespace std;

class NullImplementation : public Skeleton<int>
{
	virtual string name() const override {
		return "null";
	}
	virtual int prepare(size_t) const override {
		return 0;
	}
	virtual string jsonify(const int &) const override {
		return {};
	}
	virtual int parse(const string &) const override {
		return 0;
	}

	virtual bool isEqual(const int &, const int &) const override {
		return true;
	}
};

int main(int, char **)
{
	const size_t size = 1000000;
	NullImplementation().run(size);
	return 0;
}

