#include "../util/util.h"

class FenwickTree {
public:
	FenwickTree(const vector<int>& ini) {
		size = ini.size()+1;
		treeVec = vector<int>(size, 0);
		dataVec = vector<int>(size, 0);
		for(size_t i = 0; i < size; ++i) update(i, ini[i]);
	}
	void update(size_t pos, int val) {
		++pos;
		if(pos >= size) return;
		int dif = val - dataVec[pos];
		dataVec[pos] = val;
		while(pos <= size) {
			treeVec[pos] += dif;
			pos += pos&-pos;
		}
	}
	int query(size_t i, size_t j) {
		if(i > j) return 0;
		return getSum(j) - getSum(i-1);
	}
private:
	int getSum(size_t pos) {
		++pos;
		if(pos < 1) return 0;
		int sum = 0;
		while(pos >= 1) {
			sum += treeVec[pos];
			pos -= pos&-pos;
		}
		return sum;
	}
	size_t size;
	vector<int> dataVec;
	vector<int> treeVec;
};

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
