#line $NEXTLINENUMBER$ "$FILENAME$"

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

using namespace std;

#define FOR(val, start, end) for(int val = (start); val < (end); ++val)

class $CLASSNAME$ {
$BEGINCUT$
/*
$PROBLEMDESC$
*/
$ENDCUT$

 public:
  $RC$ $METHODNAME$($METHODPARMS$) {
    $RC$ result;
    // -- 
    
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
