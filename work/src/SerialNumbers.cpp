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
// BEGIN CUT HERE
#define DUMP(x) std::cerr << #x << " = " << to_s(x) << std::endl;
template<typename T> string to_s(const T& v);
template<> string to_s(const string& v);
template<> string to_s(const bool& v);
template<typename T> string to_s(const vector<T>& v);
template<typename T> string to_s(const list<T>& v);
template<typename T> string to_s(const set<T>& v);
template<typename F, typename S> string to_s(const pair<F,S>& v);
template<typename K, typename V> string to_s(const map<K,V>& v);
// END CUT HERE
#ifndef DUMP
#define DUMP(x) 
#endif

class SerialNumbers {

 public:
  int count(string& s)
  {
    int r = 0;

    TIMES(i, s.size()) {
      if(s[i] >= '0' && s[i] <= '9') r += s[i] - '0';
    }
    return r;
  }
  
  vector <string> sortSerials(vector <string> sN)
  {
    
    FOR(i, 0, sN.size()) {
      FOR(k, i+1, sN.size()) {

        if(sN[i].size() > sN[k].size()) {
          swap(sN[i], sN[k]);
        }else if(sN[i].size() == sN[k].size() && count(sN[i]) > count(sN[k])) {
          swap(sN[i], sN[k]);
        }else if(sN[i].size() == sN[k].size() && count(sN[i]) == count(sN[k]) && sN[i] > sN[k]) {
          swap(sN[i], sN[k]);
        }
      }
    }

    return sN;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// You own a lot of guitars, and each guitar has a unique serial number.  You want to be able to  look up serial numbers quickly, so you decide to sort the entire list as follows.

Each serial number consists of uppercase letters ('A' - 'Z') and digits ('0' - '9'). To see if serial number A comes before serial number B, use the following steps:

   If A and B have a different length, the one with the shortest length comes first.
   Else if sum_of_digits(A) differs from sum_of_digits(B) (where sum_of_digits(X) returns the sum of all digits in string X), the one with the lowest sum comes first.
   Else compare them alphabetically, where digits come before letters.

Given a vector <string> serialNumbers, return a vector <string> with the ordered list of serial numbers in increasing order.

DEFINITION
Class:SerialNumbers
Method:sortSerials
Parameters:vector <string>
Returns:vector <string>
Method signature:vector <string> sortSerials(vector <string> serialNumbers)


CONSTRAINTS
-serialNumbers will contain between 1 and 50 elements, inclusive.
-Each element of serialNumbers will contain between 1 and 50 characters, inclusive.
-serialNumbers will only contain uppercase letters ('A' - 'Z') and digits ('0' - '9').
-All elements of serialNumbers will be distinct.


EXAMPLES

0)
{"ABCD","145C","A","A910","Z321"}

Returns: {"A", "ABCD", "Z321", "145C", "A910" }

The first serial is "A" because it has the shortest length. All others have length 4, but "ABCD" has the lowest sum. Next lowest is "Z321", and finally "A910" comes before "145C" because "A" comes before the "1" (they both have sum = 10)

1)
{"Z19", "Z20"}

Returns: {"Z20", "Z19" }

1+9 > 2+0, so "Z20" comes first.

2)
{"34H2BJS6N","PIM12MD7RCOLWW09","PYF1J14TF","FIPJOTEA5"}

Returns: {"FIPJOTEA5", "PYF1J14TF", "34H2BJS6N", "PIM12MD7RCOLWW09" }



3)
{"ABCDE", "BCDEF", "ABCDA", "BAAAA", "ACAAA"}

Returns: {"ABCDA", "ABCDE", "ACAAA", "BAAAA", "BCDEF" }



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"ABCD","145C","A","A910","Z321"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"A", "ABCD", "Z321", "145C", "A910" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, sortSerials(Arg0)); }
	void test_case_1() { string Arr0[] = {"Z19", "Z20"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"Z20", "Z19" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, sortSerials(Arg0)); }
	void test_case_2() { string Arr0[] = {"34H2BJS6N","PIM12MD7RCOLWW09","PYF1J14TF","FIPJOTEA5"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"FIPJOTEA5", "PYF1J14TF", "34H2BJS6N", "PIM12MD7RCOLWW09" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, sortSerials(Arg0)); }
	void test_case_3() { string Arr0[] = {"ABCDE", "BCDEF", "ABCDA", "BAAAA", "ACAAA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"ABCDA", "ABCDE", "ACAAA", "BAAAA", "BCDEF" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, sortSerials(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  SerialNumbers test;

  if(argc == 1) {
    test.run_test(-1);
  }else {
    std::string arg(argv[1]);
    if(arg[0] != '-') {
      test.run_test(arg[0] - '0');
    }else {
      test.debug();
    }
  }
  
  return 0;
}

template<typename T> string to_s(const T& v) { ostringstream oss; oss << v; return oss.str(); }
template<> string to_s(const string& v) { ostringstream oss; oss << '"' << v << '"'; return oss.str(); }
template<> string to_s(const bool& v) { ostringstream oss; oss << ( v ? "true" : "false") ; return oss.str(); } 
template<typename T> string to_s(const vector<T>& v) { ostringstream oss; oss << "["; EACH(v,i) oss << to_s(*i) << ","; oss << "]"; return oss.str(); }
template<typename T> string to_s(const list<T>& v) { ostringstream oss; oss << "("; EACH(v,i) oss << to_s(*i) << ","; oss << ")"; return oss.str(); }
template<typename T> string to_s(const set<T>& v) { ostringstream oss; oss << "{"; EACH(v,i) oss << to_s(*i) << ","; oss << "}"; return oss.str(); }
template<typename F, typename S> string to_s(const pair<F,S>& v) { ostringstream oss; oss << "<" << to_s(v.first) << " " << to_s(v.second) << ">"; return oss.str(); }
template<typename K, typename V> string to_s(const map<K,V>& v) { ostringstream oss; oss << "{"; EACH(v,i) oss << to_s(i->first) << " => " << to_s(i->second) << ","; oss << "}"; return oss.str(); }

// END CUT HERE
