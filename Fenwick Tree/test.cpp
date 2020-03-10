#include "../util/util.h"

class FenwickTree {
public:
	FenwickTree(const vector<int>& ini) {
		// to do
	}
	void update(size_t pos, int val) {
		// to do
	}
	int query(size_t i, size_t j) {
		// to do
	}
private:
	int getSum(size_t pos) {
		// to do
	}
};

// sum query
int main() {
	vector<int> m = {1,2,3,4,5,6,7,8,9,10};
	FenwickTree f = FenwickTree(m);
	for(int i = 0; i < 1000; ++i) {
		int a = rand() % m.size(), b = rand() % m.size();
		if(a > b) swap(a, b);
		int sum_ = 0;
		for(int i = a; i <= b; ++i) sum_ += m[i];
		assert(f.query(a,b) == sum_);
		size_t pos = rand() % m.size();
		int val = (rand() % 200) - 100;
		m[pos] = val;
		f.update(pos, val);

	}
}
