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
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>

// -- utility --
// C-style loop
#define FOR(x, a, b) for(int x = static_cast<int>(a); x < static_cast<int>(b); ++x)
#define FORN(x, n) FOR(x, 0, n)
// Ruby-style loop
#define UPTO(x, a, b) for(int x = static_cast<int>(a); x <= static_cast<int>(b); ++x)
#define DOWNTO(x, a, b) for(int x = static_cast<int>(a); x >= static_cast<int>(b); --x)

using namespace std;

class $CLASSNAME$ {
$BEGINCUT$
/*
$PROBLEMDESC$
*/
$ENDCUT$

 public:
  $RC$ $METHODNAME$($METHODPARMS$) {
    $RC$ result;
    // -- main code --
    
    return result;	
  }

  $TESTCODE$
};

$BEGINCUT$

int main()
{
  $CLASSNAME$ test;
  test.run_test(-1);
  
  return 0;
}

$ENDCUT$
