#include "../util/util.h"

class SegmentTree {
public:
	SegmentTree(vector<int> v) {
		// to do
	}
	int query(size_t i, size_t j) {
		// to do
	}
	void update(size_t i, int val) {
		// to do
	}
private:

};

// min range query
int main() {
	vector<int> m = {5,8,6,3,1,7,2,6};
	SegmentTree s(m);
	for(int i = 0; i < 1000; ++i) {
		int a = rand() % m.size(), b = rand() % m.size();
		if(a > b) swap(a, b);
		int min_ = INT32_MAX;
		for(int i = a; i <= b; ++i) min_ = min(min_, m[i]);
		assert(s.query(a,b) == min_);
		size_t pos = rand() % m.size();
		int val = (rand() % 200) - 100;
		m[pos] = val;
		s.update(pos, val);

	}
}
