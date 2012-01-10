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

class FoxPlayingGame {
 public:
  double theMax(int nA, int nB, int paramA, int paramB) {
    // -- main code --

    double a = (double)nA * (double)paramA / 1000.0; 
    //DUMP(a);
    if(paramA < 0) {
      if(-1000 > paramB or paramB > 1000) {
        return a;
      }

      if(paramB < -1000) {
        if(nB % 2 == 1) --nB;
      }
    
      TIMES(i, nB) {
        a = a * ((double)paramB / 1000.0);
      }
      return a;
    }

    // paramA > 0;
    if(-1000<= paramB and paramB <= 1000) {
      return a;
    }

    if(paramB < -1000) {
      if(nB % 2 == 1) --nB;
    }
    
    TIMES(i, nB) {
      a = a * ((double)paramB / 1000.0);
    }

    //cout.flush();
    return a;
  }


  

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
