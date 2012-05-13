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

class AttendanceShort {

 public:
  vector <string> shortList(vector <string> names, vector <string> attendance)
  {
    vector <string> result;
    // -- main code --

    TIMES(i, names.size()) {
      string& n = names[i];
      string& a = attendance[i];

      int da = 0;
      int dp = 0;

      TIMES(k, a.size()) {
        if(a[k] == 'P') {
          da += 1;
          dp += 1;
        }else if(a[k] == 'A') {
          da += 1;
        }
      }

      if(da == 0) continue;
      if(dp * 4 < da * 3) result.push_back(n);
    }
    
    return result;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// The students at your university have lately picked up the annoying habit of missing classes. To fix this problem your board has decided to only allow students with 75% or higher attendance to sit for the exams. Given a vector <string> names containing the students' names and a vector <string> attendance containing their attendance records, return the list of students who have less than 75% attendance.

The ith student's name is given as the ith element of names and his attendance record as the ith element of attendance. The attendance record corresponding to each student is specified as a string of 'A's, 'P's and 'M's. An 'A' indicates the students was absent for a class, whereas a 'P' means he was present and a 'M' means he was absent but he submitted a doctor's note for that class. If a student was absent for a class but submitted a doctor's note then that class is not counted when calculating his attendance percentage. Return a vector <string> containing the names of all the students who do not meet the attendance requirements. The names in the returned vector <string> should be in the same relative order as names.

DEFINITION
Class:AttendanceShort
Method:shortList
Parameters:vector <string>, vector <string>
Returns:vector <string>
Method signature:vector <string> shortList(vector <string> names, vector <string> attendance)


CONSTRAINTS
-names will contain between 0 and 50 elements, inclusive.   
-attendance will contain the same number of elements as names.
-Each element of names will contain between 1 and 50 characters, inclusive.
-Each element of attendance will contain between 1 and 50 characters, inclusive.
-Each element of names will contain only letters ('A' - 'Z' and 'a' - 'z').
-Each element of attendance will contain only 'A', 'P' and 'M' characters.
-Each element of attendance will contain at least one 'A' or 'P' character.


EXAMPLES

0)
{"Justin"}
{"PAAPP"}

Returns: {"Justin" }

Justin has attended 3 of his 5 classes which gives him 3/5 * 100 = 60% attendance. Since this is lower than 75% his name should be returned.

1)
{"Justin","Chris"}
{"PAAPP","PPPPA"}

Returns: {"Justin" }

Chris has attended 4 out of his 5 classes and thus has 80% attendance. Justin has 60% so only Justin's name should be returned.

2)
{"Sunny"}
{"PPPAM"}

Returns: { }

Sunny's attendance is effectively calculated from "PPPA" as classes which have a doctor's note are ignored. This results in a 75% attendance and so his name is not included in the returned list.

3)
{"Mansi", "Arjun", "Nikhil", "Taneja"}
{"PPPPMPPAPP", "AAMAAPP", "PPPPAAP", "PPPAAAMPP"}

Returns: {"Arjun", "Nikhil", "Taneja" }



4)
{}
{}

Returns: { }

Take care of the empty case.

*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"Justin"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"PAAPP"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"Justin" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, shortList(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"Justin","Chris"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"PAAPP","PPPPA"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"Justin" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, shortList(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"Sunny"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"PPPAM"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, shortList(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"Mansi", "Arjun", "Nikhil", "Taneja"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"PPPPMPPAPP", "AAMAAPP", "PPPPAAP", "PPPAAAMPP"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"Arjun", "Nikhil", "Taneja" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, shortList(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, shortList(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  AttendanceShort test;

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
