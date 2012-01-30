#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>

typedef int int_type;

// -- utility --
// C-style loop
#define FOR(x, a, b) for(int_type x = static_cast<int_type>(a); x < static_cast<int_type>(b); ++x)
#define FORN(x, n) FOR(x, 0, n)
// Ruby-style loop
#define TIMES(x, n) FOR(x, 0, n)
#define STEP(x, a, b, s) for(int_type x = static_cast<int_type>(a); s > 0 ? x <= static_cast<int_type>(b) : x >= static_cast<int_type>(b); x += static_cast<int_type>(s) )
#define UPTO(x, a, b) for(int_type x = static_cast<int_type>(a); x <= static_cast<int_type>(b); ++x)
#define DOWNTO(x, a, b) for(int_type x = static_cast<int_type>(a); x >= static_cast<int_type>(b); --x)
// debug
#define DUMP(x) std::cout << #x << " = " << x << std::endl;

using namespace std;

class TheLotteryBothDivs {
 public:
  double find(vector <string> goodSuffixes) {
    // -- main code --

    unsigned long long counts = 0;

    vector<string> suffixes;

    TIMES(i, goodSuffixes.size() - 1) {
      FOR(j, i + 1, goodSuffixes.size()) {
        if(goodSuffixes[i].size() > goodSuffixes[j].size()) {
          swap(goodSuffixes[i], goodSuffixes[j]);
        }
      }
    }

    TIMES(i, goodSuffixes.size()) {
      bool add = true;
      TIMES(j, suffixes.size()) {
        if(suffixes[j] == goodSuffixes[i].substr(goodSuffixes[i].size() - suffixes[j].size(),suffixes[j].size())) {
          add = false;
        }
      }
      if(add) suffixes.push_back(goodSuffixes[i]);
      
    }
    
    TIMES(i, suffixes.size()) {
      counts += p(10, 9 - suffixes[i].size());
    }
    
    return (double)counts / 1000000000.0;	
  }

  long long p(int b, int n) {
    long long r = 1;
    TIMES(i, n) {
      r *= b;
    }
    return r;
  }


  

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
