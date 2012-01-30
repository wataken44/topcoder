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

class MathContest {
 public:
  int countBlack(string ballSequence, int repetitions) {
    // -- main code --

    int count = 0;

    ostringstream oss;
    TIMES(i, repetitions) {
      oss << ballSequence;
    }
    string sequence = oss.str();
    
    int left = 0;
    int right = sequence.size() - 1;
    bool dir = false;
    bool inverted = false;
    
    while(left <= right) {
      char c = '?';
      if(!dir) {
        c = sequence[left];
        ++left;
      }else {
        c = sequence[right];
        --right;
      }
      char t = c;
      if(inverted) {
        t = c == 'B' ? 'W' : 'B';
      }
      if(t == 'B') {
        ++count;
        inverted = not inverted;
      }
      if(t == 'W') {
        dir = not dir;
      }
    }
    
    return count;	
  }


  

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
