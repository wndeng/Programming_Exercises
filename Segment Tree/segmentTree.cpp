#include "../util/util.h"

class SegmentTree {
public:
	SegmentTree(vector<int> v) {
		data = vector<int>(v);
		size = v.size();
		vector<int> tmp(v.size(), 0);
		data.insert(data.begin(), tmp.begin(), tmp.end());
		for(int i = 0, size = v.size(); i < size; ++i) update(i, v[i]); 
		print(data);
	}
	int query(size_t i, size_t j) {
		i += size; j += size;
		int min_ = INT32_MAX;
		while(i <= j) {
			if(i % 2 == 1) min_ = min(min_, data[i++]);
			if(j % 2 == 0) min_ = min(min_, data[j--]);
			i >>= 1; j >>= 1;
		}
		return min_;
	}
	void update(size_t i, int val) {
		i += size;
		data[i] = val;
		for(i>>=1; i >= 1; i>>=1) data[i] = min(data[2*i], data[2*i+1]);
	}
private:
	vector<int> data;
	size_t size;

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
