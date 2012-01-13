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

class InternetSecurity {

 public:
  vector <string> determineWebsite(vector <string> address, vector <string> keyword, vector <string> dangerous, int threshold)
  {
    vector <string> result;
    // -- main code --

    int sz = address.size();

    set<string> blacklist;
    FOR(k, 0, dangerous.size()) {
      blacklist.insert(dangerous[k]);
    }

    vector< vector<string> > word(sz);
    FOR(i, 0, sz) {
      istringstream iss(keyword[i]);
      string w;
      while(!iss.eof()) {
        iss >> w;
        word[i].push_back(w);
      }
    }
    
    vector<bool> marked(sz, false);    
    while(true) {
      bool changed = false;

      //DUMP(blacklist);
      
      FOR(i, 0, sz) {
        if(marked[i] == true) continue;

        int count = 0;
        EACH(blacklist, it) {
          string w = *it;
          FOR(m, 0, word[i].size()) {
            if(w == word[i][m]) {
              ++count;
              break;
            }
          }
        }
        //DUMP(count);
        if(count >= threshold) {
          FOR(m, 0, word[i].size()) {
            blacklist.insert(word[i][m]);
          }
          changed = true;
          marked[i] = true;
        }
      }
      
      if(!changed) break;
    }

    //DUMP(marked);

    FOR(i, 0, marked.size()) {
      if(marked[i]) 
        result.push_back(address[i]);
    }
    
    return result;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// TopCoder Security Agency (TSA, established today) is going to search for dangerous content in the internet.


There are N candidate websites numbered 0 through N-1. Each website has an address given as address[i]. It also has one or more keywords associated with it. The i-th element of keyword is a string describing all keywords associated with the i-th website. It is formatted as a single space separated list of keywords without leading or trailing spaces, where each keyword consists only of lowercase letters.


It is known to TSA that some keywords are dangerous. These keywords are given in vector <string> dangerous, where each element is a single dangerous keyword. For all other keywords it is not initially known whether they are dangerous or not.


TSA uses the following algorithm to identify all dangerous websites:


  Initially, all websites are considered to be safe.

  While there exists a website W such that it's considered safe and
        at least threshold of its keywords are known to be dangerous

    Website W becomes dangerous
    All keywords associated with W become dangerous   

  End While


Return a vector <string> containing the addresses of all dangerous websites found by the algorithm described above sorted in increasing order of website numbers. Return an empty vector <string> if no dangerous website is found.

DEFINITION
Class:InternetSecurity
Method:determineWebsite
Parameters:vector <string>, vector <string>, vector <string>, int
Returns:vector <string>
Method signature:vector <string> determineWebsite(vector <string> address, vector <string> keyword, vector <string> dangerous, int threshold)


NOTES
-The address of a website is just a string used to uniquely identify it. It doesn't necessarily adhere to any common format of naming websites.


CONSTRAINTS
-address will contain between 1 and 50 elements, inclusive.
-Each element of address will contain between 1 and 50 characters, inclusive.
-Each character in address will be a '.', '_' or a lowercase letter ('a'-'z').
-All elements of address will be distinct.
-keyword will contain the same number of elements as address.
-Each element of keyword will contain between 1 and 50 characters, inclusive.
-Each character in keyword will be a ' ' or a lowercase letter ('a'-'z').
-Each element in keyword will be formatted as described in the statement above.
-For each website, the keywords associated with it will be distinct.
-dangerous will contain between 1 and 50 elements, inclusive.
-Each element of dangerous will contain between 1 and 50 characters, inclusive.
-Each character in dangerous will be a lowercase letter ('a'-'z').
-All elements of dangerous will be distinct.
-threshold will be between 1 and 25, inclusive.


EXAMPLES

0)
{"www.topcoder.com",
"www.sindicate_of_evil.com",
"www.happy_citizens.com"}
{"hack encryption decryption internet algorithm",
"signal interference evil snake poison algorithm",
"flower baloon topcoder blue sky sea"}
{"hack","encryption","decryption","interference","signal","internet"}
3

Returns: {"www.topcoder.com", "www.sindicate_of_evil.com" }

"www.topcoder.com" is detected as dangerous since it contains four dangerous keywords: "hack", "encryption", "decryption", and "internet". Hence, "algorithm" becomes a dangerous keyword. As a result, "www.sindicate_of_evil.com" is detected as dangerous since it contains three dangerous keywords: "interference", "signal", and "algorithm". Hence, the correct return value is {"www.topcoder.com","www.sindicate_of_evil.com"} since the answer must be sorted in increasing order of website numbers.

1)
{"brokenlink","flowerpower.net","purchasedomain.com"}
{"broken","rose tulips","cheap free domain biggest greatest"}
{"biggest","enemy","hideout"}
2

Returns: { }

No website is dangerous and an empty vector <string> should be returned.

2)
{"a..a.ab.","...aa.b"}
{"a bc def","def ghij klmno"}
{"a","b","c","d","e"}
1

Returns: {"a..a.ab.", "...aa.b" }



3)
{"www.tsa.gov"}
{"information assurance signal intelligence research"}
{"signal","assurance","penguin"}
2

Returns: {"www.tsa.gov" }



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"www.topcoder.com",
"www.sindicate_of_evil.com",
"www.happy_citizens.com"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"hack encryption decryption internet algorithm",
"signal interference evil snake poison algorithm",
"flower baloon topcoder blue sky sea"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"hack","encryption","decryption","interference","signal","internet"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; string Arr4[] = {"www.topcoder.com", "www.sindicate_of_evil.com" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(0, Arg4, determineWebsite(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { string Arr0[] = {"brokenlink","flowerpower.net","purchasedomain.com"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"broken","rose tulips","cheap free domain biggest greatest"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"biggest","enemy","hideout"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; string Arr4[] = { }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(1, Arg4, determineWebsite(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { string Arr0[] = {"a..a.ab.","...aa.b"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"a bc def","def ghij klmno"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"a","b","c","d","e"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; string Arr4[] = {"a..a.ab.", "...aa.b" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(2, Arg4, determineWebsite(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { string Arr0[] = {"www.tsa.gov"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"information assurance signal intelligence research"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"signal","assurance","penguin"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; string Arr4[] = {"www.tsa.gov" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(3, Arg4, determineWebsite(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  InternetSecurity test;

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
