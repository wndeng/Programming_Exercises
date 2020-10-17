#include "../util/util.h"

class my_priority_queue {
public:
	my_priority_queue() {}
	
	// decrease top key freq by 1, return key val
	int remove() {
		auto &[v, _]{data[0]};
		decreaseKey(0);	
		return v;
	}
	// increase frequence of val by 1.
	void add(int val, int i) {
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
	bool greaterThan(int i, int j) {
		return data[i].second.size() == data[j].second.size() ? data[i].second.back() > data[].second.back() : data[i].second.size() > data[j].second.size();
	}
	void increaseKey(int i) {
		while(i && greaterThan(i, parent(i))) {
			std::swap(data[i], data[j]);
			i = parent(i);
		}
	}

	void decreaseKey(int i) {
		auto [_, l]{data[i]};
		if(l.size() == 1) {
			std::swap(data[i], data[data.size()-1]);
			data.pop_back();
		}
		l.pop_back();	
		auto [l, r]{children(i)};
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

	static inline int parent(int i) {
		return i == 0 ? 0 : (i-1)>>1;	
	}

	std::unordered_map<int,int> index;	
	std::vector<std::pair<int,std::list<int>>> data;
};

int main() {
	int i{0};
	my_priority_queue pq();
	pq.add(1, i++);
	pq.add(2, i++);
	pq.add(3, i++);
	std::cout << pq.remove() << endl;
}
