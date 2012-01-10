#include <algorithm>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

typedef int int_type;

// -- utility --
// C-style loop
#define FOR(x, a, b) for(int_type x = static_cast<int_type>(a); x < static_cast<int_type>(b); ++x)
// Ruby-style loop
#define TIMES(x, n) FOR(x, 0, n)
#define STEP(x, a, b, s) for(int_type x = static_cast<int_type>(a); s > 0 ? x <= static_cast<int_type>(b) : x >= static_cast<int_type>(b); x += static_cast<int_type>(s) )
#define UPTO(x, a, b) for(int_type x = static_cast<int_type>(a); x <= static_cast<int_type>(b); ++x)
#define DOWNTO(x, a, b) for(int_type x = static_cast<int_type>(a); x >= static_cast<int_type>(b); --x)
#define EACH(c, i) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define ALL(cont, it, cond, ret) \
  bool ret = true; EACH(cont, it) { if(!(cond)) {ret=false;break;} }
#define ANY(cont, it, cond, ret) \
  bool ret = false; EACH(cont, it) { if(cond) {ret=true;break;} }

using namespace std;
// debug
#ifndef DUMP
#define DUMP(x) 
#endif

class ChickenOracle {

 public:
  string theTruth(int n, int eggCount, int lieCount, int liarCount)
  {
    // count of answer egg and chicken 
    int ec = eggCount;
    int cc = n - eggCount;

    bool truthEgg = false;
    bool truthChiken = false;

    int lieMax = lieCount + liarCount;
    int lieMin = abs(lieCount - liarCount);
    
    if(lieMin <= ec && ec <= lieMax) truthChiken = true;
    if(lieMin <= cc && cc <= lieMax) truthEgg = true;
    
    if(truthEgg && truthChiken) return "Ambiguous";
    if(!truthEgg && !truthChiken) return "The oracle is a lie";
    if(truthEgg && !truthChiken) return "The egg";
    if(!truthEgg && truthChiken) return "The chicken";
    
    return "There is some bug...";	
  }

  
  

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
