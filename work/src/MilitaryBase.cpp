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

class MilitaryBase {

 public:
  int getSchoolBuildingCount(vector <string> photo, int k)
  {
    int result;
    // -- main code --
    
    return result;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// 
You are given vector <string> photo, representing a satellite photo of a military base. Photo contains two types of characters - '.' characters represent an empty area, and '*' characters represent parts of buildings.
Two non-empty squares A and B on photo belong to the same building if and only if there exist a chain of squares where the first square is A, 
the last square is B, and each pair of consecutive squares in the chain shares a common side or angle.


There are some school buildings on the photo. The distinguishing feature of the school buildings is the shape. 
Each such building is a rectangular frame (in other words, it is the result of subtracting non-empty solid rectangle A from solid rectange B, and rectangle A lies completely inside B without touching by borders).
Each side of the frame must be k cells thick and must be parallel to an edge of the photo (see examples for clarification). 
Note that a school building can't contain any other buidings inside its internal part (see example 2 for clarification).


Return the number of school buildings on the photo.



DEFINITION
Class:MilitaryBase
Method:getSchoolBuildingCount
Parameters:vector <string>, int
Returns:int
Method signature:int getSchoolBuildingCount(vector <string> photo, int k)


CONSTRAINTS
-photo will contain between 1 and 50 elements, inclusive.
-Each element of photo will contain between 1 and 50 characters, inclusive.
-Each element of photo will contain the same number of characters.
-k will be between 1 and 24, inclusive.
-Each element of photo will contain only '.' or '*' characters.


EXAMPLES

0)
{"***......",
 "*.*......",
 "***.*****",
 "....*****",
 "....**.**",
 "....**.**",
 "....**.**",
 "....*****",
 "....*****"}
1

Returns: 1

The topleft building at the photo is a school. The other one looks similar to a school, but its sides are too thick.

1)
{"*****.*****",
 "*****.*****",
 "**.**.**.**",
 "*****.*****",
 "*****.*****",
 "...........",
 "*****.*****",
 "**.**.*****",
 "*****.**.**",
 "...........",
 "****.......",
 "****.......",
 "**.........",
 "**........."}
2

Returns: 2

Two top buildings are schools. The left building in the middle row is a rectangle frame, but its top and bottom sides are of incorrect thickness. The two remaining buildings are not rectangle frames at all.

2)
{"*********",
 "*.......*",
 "*.*****.*",
 "*.*...*.*",
 "*.*...*.*",
 "*.*****.*",
 "*.......*",
 "*********"}
1

Returns: 1

Only the inner building is a school.

3)
{"..........",
 ".****.....",
 ".*..*.....",
 ".****.....",
 ".....****.",
 ".....*..*.",
 ".....****.",
 ".........."}
1

Returns: 0

Here we have only one building and it's not a school (remember that two squares sharing a commong angle belong to the same building). 

4)
{"*********.",
 "*.......*.",
 "*.***...*.",
 "*.*.*.*.*.",
 "*.***...*.",
 "*.......*.",
 "*********.",
 "*********."}
1

Returns: 1

This photo contains one school building and two buildings which are not a school.


5)
{"*******",
 "*.....*",
 "*.**..*",
 "*..**.*",
 "*.....*",
 "*******"}
1

Returns: 0



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"***......",
 "*.*......",
 "***.*****",
 "....*****",
 "....**.**",
 "....**.**",
 "....**.**",
 "....*****",
 "....*****"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 1; verify_case(0, Arg2, getSchoolBuildingCount(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"*****.*****",
 "*****.*****",
 "**.**.**.**",
 "*****.*****",
 "*****.*****",
 "...........",
 "*****.*****",
 "**.**.*****",
 "*****.**.**",
 "...........",
 "****.......",
 "****.......",
 "**.........",
 "**........."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 2; verify_case(1, Arg2, getSchoolBuildingCount(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"*********",
 "*.......*",
 "*.*****.*",
 "*.*...*.*",
 "*.*...*.*",
 "*.*****.*",
 "*.......*",
 "*********"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 1; verify_case(2, Arg2, getSchoolBuildingCount(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"..........",
 ".****.....",
 ".*..*.....",
 ".****.....",
 ".....****.",
 ".....*..*.",
 ".....****.",
 ".........."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 0; verify_case(3, Arg2, getSchoolBuildingCount(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"*********.",
 "*.......*.",
 "*.***...*.",
 "*.*.*.*.*.",
 "*.***...*.",
 "*.......*.",
 "*********.",
 "*********."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 1; verify_case(4, Arg2, getSchoolBuildingCount(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"*******",
 "*.....*",
 "*.**..*",
 "*..**.*",
 "*.....*",
 "*******"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 0; verify_case(5, Arg2, getSchoolBuildingCount(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  MilitaryBase test;

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
