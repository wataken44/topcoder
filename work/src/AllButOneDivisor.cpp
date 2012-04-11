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
#define DUMP(x) std::cerr << #x << " = " << x << std::endl;

using namespace std;

class AllButOneDivisor {
 public:
  int getMinimum(vector <int> divisors) {
    // -- main code --

    sort(divisors.begin(), divisors.end());

    vector<int> cand;
    
    TIMES(m, divisors.size()) {
      int lcm = 1;

      TIMES(n, divisors.size()) {
        if(m != n) {
          lcm = lcm * divisors[n] / gcd(lcm, divisors[n]); 
        }
      }
      //DUMP(lcm);
      //DUMP(divisors[m]);
      if(lcm % divisors[m] != 0) {
        cand.push_back(lcm);
      }
    }

    sort(cand.begin(), cand.end());
    
    return cand.size() == 0 ? -1 : cand[0];
  }

  int gcd(int a, int b) {
    if(a > b) swap(a, b);
    return a == 0 ? b : gcd(b % a, a);
  }
  

  

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
