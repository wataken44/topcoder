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

class StrongPrimePower {

 public:
  typedef unsigned long long ull;

  bool isPower(ull n, ull p, ull q)
  {
    ull c = 0;
    while(n > 1) {
      if(n % p != 0) return false;
      n /= p;
      ++c;
    }
    return c == q;
  }
  
  vector <int> baseAndExponent(string n)
  {
    istringstream iss(n);
    ull nn ;
    iss >> nn;

    int maxq = static_cast<int>(ceil(log(nn) / log(2)));

    DUMP(maxq);

    double eps = 1e-8;
    
    DOWNTO(q, maxq, 2) {
      ull p = static_cast<ull>(floor(pow(nn, 1.0 / q)));
      if(p == 1) p = 2;

      cout << p << " " << q << endl;
      
      bool ok = false;
      while(true) {
        cout << log(nn) << " " << log(p) << " " << log(nn) / log(p)  << " " << q << " " << (log(nn) / log(p) >= q) << endl;
        if((eps + log(nn) / log(p)) >= q) {
          cout << isPower(nn, p, q) << endl;
          if(isPower(nn, p, q)) {
            ok = true;
            break;
          }
          ++p;
        }else {
          break;
        }
      }

      if(!ok) continue;
      
      bool isPrime = true;
      for(int k = 2; 1ULL* k * k <= p; ++k) {
        if(p % k == 0) {
          isPrime = false;
          break;
        }
      }

      if(isPrime) {
        vector<int> result;
        result.push_back(p);
        result.push_back(q);

        return result;
      }
    }
        
    vector <int> empty;
    return empty;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// 

NOTE: This problem statement contains superscripts that may not display properly if viewed outside of the applet.



A number which can be represented as pq, where p is a prime number and q is an integer greater than 0, is called a prime power. If q is larger than 1, we call the number a strong prime power. You are given an integer n.  If n is a strong prime power, return an vector <int> containing exactly two elements.  The first element is p and the second element is q.  If n is not a strong prime power, return an empty vector <int>.


DEFINITION
Class:StrongPrimePower
Method:baseAndExponent
Parameters:string
Returns:vector <int>
Method signature:vector <int> baseAndExponent(string n)


CONSTRAINTS
-n will contain digits ('0' - '9') only.
-n will represent an integer between 2 and 10^18, inclusive.
-n will have no leading zeros.


EXAMPLES

0)
"27"

Returns: {3, 3 }

27 = 33. This is a strong prime power.

1)
"10"

Returns: { }

10 = 2 * 5. This is not a strong prime power.

2)
"7"

Returns: { }

A prime number is not a strong prime power.

3)
"1296"

Returns: { }



4)
"576460752303423488"

Returns: {2, 59 }



5)
"999999874000003969"

Returns: {999999937, 2 }



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arg0 = "27"; int Arr1[] = {3, 3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, baseAndExponent(Arg0)); }
	void test_case_1() { string Arg0 = "10"; int Arr1[] = { }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, baseAndExponent(Arg0)); }
	void test_case_2() { string Arg0 = "7"; int Arr1[] = { }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, baseAndExponent(Arg0)); }
	void test_case_3() { string Arg0 = "1296"; int Arr1[] = { }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, baseAndExponent(Arg0)); }
	void test_case_4() { string Arg0 = "576460752303423488"; int Arr1[] = {2, 59 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, baseAndExponent(Arg0)); }
	void test_case_5() { string Arg0 = "999999874000003969"; int Arr1[] = {999999937, 2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, baseAndExponent(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  StrongPrimePower test;

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
