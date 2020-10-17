#include "../util/util.h"

template<class T>
class my_priority_queue {
public:
	my_priority_queue() {}
	
	// decrease top key freq by 1, return key val
	static int remove(int val) {
		auto &[v, l]{data[0]};
		decreaseKey(0);	

			
	}
	// increase frequence of val by 1.
	static void add(int val, int i) {
		if(!index.count(val)) {
			index[val] = data.size();
			data.emplace_back(val, {i});
		} else {
			int idx{index[val]};
			auto &[_, l]{data[idx]};
			l.emplace_back(i);
			increaseKey(idx);
		}
	}

private:
	void increaseKey(int i) {
		while(i && greaterThan(i, parent(i))) {
			std::swap(data[i], data[j]);
			i = parent(i);
		}
	}

	void decreaseKey(int i) {
		int idx{index[val]};
		std::swap(i, data[data.size()-1]);
		data.pop_back();
		int [l, r]{children(i)};
		while(l || r) {
			int max_{l == 0 ? r : r == 0 ? l : greaterThan(l, r) ? l : r};
			if(greaterThan(i, max_)) return;
			else {
				std::swap(data[i], data[max_]);
				i = max_i;
			}
		}
		
	}

	std::pair<int,int> children(int i) {
		int a{2*i+1 < data.size() ? 0 : 2*i+1}, b{2*i+2 < data.size() ? 0 : 2*i+2};
		return {a, b};
	}

	static inline int parent(i) {
		return i == 0 ? 0 : (i-1)>>1;	
	}

	std::unordered_map<int,int> index;	
	std::vector<std::pair<int,std::list<int>> data;
};

int main() {
	auto f = [](const auto& a, const auto& b) {return a < b;};
	test<int> t(f);
	std::cout << t.run(2, 3) << std::endl;
}
