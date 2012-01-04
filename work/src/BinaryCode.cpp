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


using namespace std;

class BinaryCode {

 public:
  vector <string> decode(string message) {
    vector <string> result;
    // -- main code --
    for(int p0 = 0; p0 <= 1; ++p0) {
      result.push_back( "" );
      int g1 = p0;
      int g0 = 0;
      for(int i = 0; i < static_cast<int>(message.size()); ++i) {
        int cur = to_i(message[i]);
        int guess = cur - g0 - g1;
        
        if(guess < 2 && guess >= 0) {
          result[p0] += to_c(g1);
          g0 = g1;
          g1 = guess;
        }else {
          result[p0] = "NONE";
          break;
        }
      }
    }
    
    return result;	
  }

  int to_i(const char& c) {
    return c - '0';
  }

  char to_c(const int& i) {
    return static_cast<char>(i) + '0';
  }
  

};




// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
