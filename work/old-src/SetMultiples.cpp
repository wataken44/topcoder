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

// -- utility --
#define FOR(x, a, b) for(int x = static_cast<int>(a); x < static_cast<int>(b); ++x)
#define TIMES(x,n) FOR(x, 0, n)
#define UPTO(x, a, b) for(int x = static_cast<int>(a); x <= static_cast<int>(b); ++x)
#define DOWNTO(x, a, b) for(int x = static_cast<int>(a); x >= static_cast<int>(b); --x)
#define DUMP(x) std::cerr << #x << " = " << x << std::endl;

using namespace std;

class SetMultiples {
// BEGIN CUT HERE
/*
// PROBLEM STATEMENTlist<pll>::iterator
// Suppose that S1 and S2 are sets of integer numbers. Let's call S2 a multiple of S1 if for each integer x from S1 there exist an integer y from S2 such that y is an integer multiple of x, i.e., y = k * x, where k is an integer.

You are given long longs A, B, C, D. Consider a set S consisting of integers x such that A <= x <= B or C <= x <= D. Return the number of elements in the smallest subset of S that is a multiple of S.

DEFINITION
Class:SetMultiples
Method:smallestSubset
Parameters:long long, long long, long long, long long
Returns:long long
Method signature:long long smallestSubset(long long A, long long B, long long C, long long D)


NOTES
-Since S is a subset of S and S is a multiple of S, the answer exists for any test case.


CONSTRAINTS
-A will be between 1 and 10,000,000,000, inclusive.
-B will be between A and 10,000,000,000, inclusive.
-C will be between B + 1 and 10,000,000,000, inclusive.
-D will be between C and 10,000,000,000, inclusive.


EXAMPLES

0)
1
1
2
2

Returns: 1

Here S = {1, 2}. The subset {2} is a multiple of S because 2 is a multiple of both 1 and 2.

1)
1
2
3
4

Returns: 2

This time, S = {1, 2, 3, 4}. The subset {3, 4} is a multiple of S because 4 is a multiple of 1, 2 and 4, and 3 is a multiple of 3.


2)
2
3
5
7

Returns: 3

S = {2, 3, 5, 6, 7}. The solution is {5, 6, 7}.

3)
1
10
100
1000

Returns: 500



4)
1000000000
2000000000
9000000000
10000000000

Returns: 1254365078



*/
// END CUT HERE

 public:
  typedef long long ll;
  typedef pair<ll, ll> pll; // from, to, inclusive
  typedef typename list<pll>::iterator pit;
  
  list<pll> s1;
  list<pll> s2; 

  class sflt {
   public:
    sflt() {};
    virtual ~sflt() {};

    bool operator()(const pll& lhs, const pll& rhs) {
      return lhs.first < rhs.first;
    }
  };

  class sfgt {
   public:
    sfgt() {};
    virtual ~sfgt() {};

    bool operator()(const pll& lhs, const pll& rhs) {
      return lhs.first > rhs.first;
    }
  };
  
  long long smallestSubset(long long A, long long B, long long C, long long D)
  {
    // -- main code --

    s1.clear();
    s2.clear();

    // initial state
    ll hd = D / 2 + 1;

    if(A >= hd) {
      s1.push_back(make_pair(A,B));
      s1.push_back(make_pair(C,D));
    }else if(B >= hd) {
      s2.push_back(make_pair(A,hd-1));
      s1.push_back(make_pair(hd, B));
      s1.push_back(make_pair(C,D));
    }else if(C >= hd) {
      s2.push_back(make_pair(A,B));
      s1.push_back(make_pair(C,D));
    }else {
      s2.push_back(make_pair(A,B));
      s2.push_back(make_pair(C,hd-1));
      s1.push_back(make_pair(hd,D));      
    }

    s2.sort(sfgt());
    dump(s2, "s2=");
    pit it2 = s2.begin();

    int c = 0;
    while(not s2.empty()) {
      bool updated = false;
        
      s1.sort(sflt());
      merge(s1);


      for(pit it1 = s1.begin(); it1 != s1.end(); ++it1) {
        ll f2 = it2->first;
        ll t2 = it2->second;

        ll f1 = it1->first;
        ll t1 = it1->second;

        ll crf = (ll)(ceil((double)f1 / (double)f2));
        ll ff = f2 * crf;
        ll ft = t2 * crf; 

        DUMP(crf);DUMP(f2);DUMP(t2);DUMP(f1);DUMP(t1);DUMP(ff);DUMP(ft);
        if(f1 <= ff and ff <= t1 and ft <= t1) {
          it2 = s2.erase(it2);
          break;
        }else if(f1 <= ff and ff <= t1 and t1 < ft) {
          ll nt = t1 / crf; 
          // f1 <= ff(=f2*|f1/f2|) <= t1 < ft(=t2*|f1/f2|)
          it2->first = nt + 1;
          updated = true;
        }
      }

      if(it2 == s2.end()) {
        break;
      }
          
      for(pit it1 = s1.begin(); it1 != s1.end(); ++it1) {
        ll f2 = it2->first;
        ll t2 = it2->second;

        ll f1 = it1->first;
        ll t1 = it1->second;

        ll frt = (ll)(floor((double)t1 / (double)t2));
        ll tf = f2 * frt;
        ll tt = t2 * frt; 

        DUMP(frt);DUMP(f2);DUMP(t2);DUMP(f1);DUMP(t1);DUMP(tf);DUMP(tt);
        if(f1 <= tf and tf <= t1 and f1 <= tt and tt <= t1) {
          it2 = s2.erase(it2);
          break;
        }else if(tf < f1 and f1 < tt and tt <= t1) {
          ll nf = f1 / frt; 
          // tf(=f2*|t1/t2|) < t1 
          it2->second = nf;
          updated = true;
        }
      }

      if(it2 == s2.end()) {
        break;
      }

      if(!updated) {
        if(it2->first == it2->second) {
          s1.push_back(make_pair(it2->first, it2->second));
          it2 = s2.erase(it2);
        }else {
        
          ll h = (it2->second - it2->first) / 2 + it2->first;
          ll t = it2->second;
          it2->second = h;
          if(h < t) {
            s2.insert(it2, make_pair(h+1, t));
            --it2;
          }
          ++c;
        }
        //dump(s2, "s2=");
      }

      if(c > 100) {
        break;
      }
    }

    dump(s1, "s1=");
    dump(s2, "s2=");
    long long result = 0;

    for(pit it1 = s1.begin(); it1 != s1.end(); ++it1) result += it1->second - it1->first + 1;
    for(pit it2 = s2.begin(); it2 != s2.end(); ++it2) result += it2->second - it2->first + 1;
    
    return result;
  }

  void dump(list<pll>& s, string msg) {
    cerr << msg;
    for(pit iter = s.begin(); iter != s.end(); ++iter) {
      cerr << "(" << iter->first << "," << iter->second << ") ";
    }
    cerr << endl;
  }
  
  void merge(list<pll>& s) {
    for(pit iter = s.begin(); iter != s.end();) {
      pit next = iter;
      ++next;

      if(next == s.end()) {
        return;
      }

      if(iter->second == next->first - 1) {
        iter->second = next->second;
        s.erase(next);
      }else {
        ++iter;
      }
    }
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 1LL; long long Arg1 = 1LL; long long Arg2 = 2LL; long long Arg3 = 2LL; long long Arg4 = 1LL; verify_case(0, Arg4, smallestSubset(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { long long Arg0 = 1LL; long long Arg1 = 2LL; long long Arg2 = 3LL; long long Arg3 = 4LL; long long Arg4 = 2LL; verify_case(1, Arg4, smallestSubset(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { long long Arg0 = 2LL; long long Arg1 = 3LL; long long Arg2 = 5LL; long long Arg3 = 7LL; long long Arg4 = 3LL; verify_case(2, Arg4, smallestSubset(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { long long Arg0 = 1LL; long long Arg1 = 10LL; long long Arg2 = 100LL; long long Arg3 = 1000LL; long long Arg4 = 500LL; verify_case(3, Arg4, smallestSubset(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { long long Arg0 = 1000000000LL; long long Arg1 = 2000000000LL; long long Arg2 = 9000000000LL; long long Arg3 = 10000000000LL; long long Arg4 = 1254365078LL; verify_case(4, Arg4, smallestSubset(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  SetMultiples test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE

