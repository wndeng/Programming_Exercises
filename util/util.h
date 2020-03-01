#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <string>
#include <getopt.h>
#include <assert.h>
#include <iomanip>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <bitset>
#include <time.h>
#include <stack>
#include <list>

using namespace std;


// Auxillary Functions

template <typename T> 
ostream& operator<<(ostream& os, const vector<T>& v) 
{ 
    os << "[ "; 
    for (const auto &n: v) os << n << " "; 
    os << "]"; 
    return os; 
}

#define print(v) cout << #v << ": " << v << endl;

// Macros

typedef long long int ll;
typedef unsigned long long int ull;
typedef uint32_t uint;
typedef long int l;
typedef unsigned long int ul;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef pair<int,int> pi;

// Abbreviations

#define push_back pb;
#define push p;
#define emplace_back eb;
#define first f;
#define second s;
#define for_all(v) for(const auto &e: v)
#define for_ind(i, v) for(int i = 0, size = v.size(); i < size; ++i)


#endif
