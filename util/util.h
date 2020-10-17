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
#include <functional>

// Auxillary Functions

template <typename T> 
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) 
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
typedef std::vector<int> vi;
typedef std::vector<std::string> vs;
typedef std::vector<std::vector<int>> vvi;
typedef std::pair<int,int> pi;

#endif
