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

class NetworkXOneTimePad {

 public:
  int crack(vector <string> plaintexts, vector <string> ciphertexts)
  {
    int result = 0;
    // -- main code --

    set<string> cand;

    TIMES(i, ciphertexts.size()) {
      TIMES(k, plaintexts.size()) {
        cand.insert(exor(ciphertexts[i], plaintexts[k]));
      }
    }

    EACH(cand, it) {
      bool ok = true;
      string key = *it;

      TIMES(k, ciphertexts.size()) {
        string plain = exor(ciphertexts[k], key);
        if(find(plaintexts.begin(), plaintexts.end(), plain) == plaintexts.end()) {
          ok = false;
          break;
        }
      }
      
      if(ok) ++result;
    }
    
    return result;	
  }

  string exor(string a, string b)
  {
    string c;

    TIMES(i, a.size()) {
      c += (a[i] == b[i] ? "0" : "1") ;
    }
    
    return c;
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// One-time pad (patented by Vernam in 1919) is one of the most widely known schemes to encrypt a binary string to achieve confidentiality. This scheme takes a binary string (a string consisting of only the digits 0 and 1) as input and outputs another binary string of the same length. The input is called the plaintext, and the output is called the ciphertext. The scheme uses a key which is another binary string of the same length as the input. The i-th bit of the ciphertext is defined as the XOR of the i-th bit of the plaintext and the key (see the notes for XOR definition). The ciphertext is sent to the receiving party.

In this problem, we will consider several messages, each of length N, encrypted using a single key of length N.


We would like to investigate how strong this cipher is. Suppose an adversary manages to find out the content of all the original messages (i.e., the plaintexts) and some of the encrypted messages (i.e., ciphertexts). These messages are given in the vector <string>s plaintexts and ciphertexts, respectively. Return the number of possible keys that are consistent with this data. The constraints will guarantee that there is at least one such key. A key is consistent if for all members of ciphertexts C, there exists a member of plaintexts P such that when P is encrypted using the specified key, it becomes C.

DEFINITION
Class:NetworkXOneTimePad
Method:crack
Parameters:vector <string>, vector <string>
Returns:int
Method signature:int crack(vector <string> plaintexts, vector <string> ciphertexts)


NOTES
-XOR is a binary operation on bits defined as follows: 0 XOR 0 = 0, 0 XOR 1 = 1, 1 XOR 0 = 1, 1 XOR 1 = 0.


CONSTRAINTS
-plaintexts will contain between 1 and 50 elements, inclusive.
-Each element of plaintexts will contain between 1 and 50 characters, inclusive.
-All the elements of plaintexts will contain the same number of characters.
-All the characters in plaintexts will be either '0' (zero) or '1' (one).
-All the elements of plaintexts will be distinct.
-ciphertexts will contain between 1 and 50 elements, inclusive.
-All the elements of ciphertexts will contain the same number of characters as all the elements of plaintexts.
-All the characters in ciphertexts will be either '0' (zero) or '1' (one).
-All the elements of ciphertexts will be distinct.
-There will exist at least one key that is consistent with the given plaintexts and ciphertexts.


EXAMPLES

0)
{"110", "001"}
{"101", "010"}

Returns: 2

The two possible keys are "011" and "100".

1)
{"00", "01", "10", "11"}
{"00", "01", "10", "11"}

Returns: 4



2)
{"01", "10"}
{"00"}

Returns: 2



3)
{"000", "111", "010", "101", "110", "001"}
{"011", "100"}

Returns: 6



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"110", "001"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"101", "010"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(0, Arg2, crack(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"00", "01", "10", "11"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"00", "01", "10", "11"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(1, Arg2, crack(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"01", "10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"00"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(2, Arg2, crack(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"000", "111", "010", "101", "110", "001"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"011", "100"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(3, Arg2, crack(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  NetworkXOneTimePad test;

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
