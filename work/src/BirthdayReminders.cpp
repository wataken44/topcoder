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

class BirthdayReminders {

 public:
  vector <string> remind(vector <string> friendNames, vector <int> birthDates, int currentDate, vector <string> occasions, vector <int> days, int k)
  {

    map<int, vector<string> > celebrate;

    int sz = friendNames.size();
    int cd = currentDate;
    int osz = occasions.size();
    
    TIMES(m, osz) {
      TIMES(i, sz) {
        int bd = birthDates[i];
        int d = days[m];
        int start = max((cd - bd) / d,  0);


        FOR(a, start - 1, start + k + 3) {
          int dd = d * a + bd;
          if(cd > dd) continue;

          if(celebrate.find(dd) == celebrate.end()) {
            celebrate[dd] = vector<string>();
          }

          ostringstream oss;
          oss << friendNames[i] + " " + occasions[m] + " (";
          oss << a << ")";
          celebrate[dd].push_back(oss.str());
        }

      }
    }

    //DUMP(celebrate);
    
    int c = 0;
    vector <string> result;
    // -- main code --
    
    EACH(celebrate, it) {
      int d = it->first;
      vector<string> v = it->second;

      TIMES(i, v.size()) {
        ostringstream oss;
        string os = v[i];

        // DATE. FRIEND OCCASION (NUMBER)
        oss << d << ". ";
        oss << os << "";
        result.push_back(string(oss.str()));

        ++c;
        if(c == k) break;

      }
      if(c == k) break;
    }
    
    return result;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// You are a geek with so many geeky friends that you sometimes forget about their birthdays.  So, you've decided to write a program that will remind you about such recurring events.  Since your friends are geeks, they may celebrate occasions other than their actual birthdays.  For example, they might celebrate whenever their age in days becomes divisible by 1000.

You are given a vector <string> friendNames and a vector <int> birthDates.  Your i-th friend is named friendNames[i] and was born on birthDates[i].  All dates in this problem are non-negative integers representing the number of days that have elapsed since day 0.

The occasions celebrated by all your friends are given in the vector <string> occasions and vector <int> days.  Occasion i is named occasions[i]. Each of your friends celebrates that occasion on each date b+n*day[i], where b is that friend's birth date and n is an integer greater than or equal to 1.  For example, if a friend was born on day 10, and there's an occasion that is celebrated every 4 days, that friend would celebrate it on day 14, day 18, day 22, etc.

Today's date is given as an int currentDate.  Your task is to generate the next k occasions that will be celebrated by your friends (starting from today).  Return these occasions in a vector <string> where each element represents a single occasion formatted as "DATE. FRIEND OCCASION (NUMBER)" (quotes for clarity).  Each DATE is the date of the occasion with no extra leading zeroes, FRIEND is the name of the friend, OCCASION is the name of the occasion, and NUMBER is the number of the occasion (1 is the first time the occasion has happened since that person's birth date, 2 is the second time, etc.).  The String[] should be sorted in chronological order from earliest to latest.  If multiple occasions happen on the same day, order them by occasion (occasions that appear earlier in occasions and days should be listed earlier), breaking ties by friend (friends that appear earlier in friendNames and birthDates should be listed earlier).

DEFINITION
Class:BirthdayReminders
Method:remind
Parameters:vector <string>, vector <int>, int, vector <string>, vector <int>, int
Returns:vector <string>
Method signature:vector <string> remind(vector <string> friendNames, vector <int> birthDates, int currentDate, vector <string> occasions, vector <int> days, int k)


CONSTRAINTS
-currentDate will be between 1 and 1000000, inclusive.
-friendNames will contain the same number of elements as birthDates.
-friendNames and birthDates will contain between 1 and 50 elements, inclusive.
-Each element of birthDates will be between 0 and currentDate-1, inclusive.
-occasions will contain the same number of elements as days.
-occasions and days will contain between 1 and 50 elements, inclusive.
-Each element of days will be between 1 and 1000000, inclusive.
-k will be between 1 and 100, inclusive.
-Each element of friendNames will contain only uppercase letters ('A' - 'Z'), lowercase letters ('a' - 'z'), and spaces.
-Each element of occasions will contain only uppercase letters ('A' - 'Z'), lowercase letters ('a' - 'z'), and spaces.


EXAMPLES

0)
{"John", "Jack", "Bill"}
{50, 100, 150}
500
{"birthday", "decimal birthday", "binary birthday"}
{365, 1000, 512}
10

Returns: {"515. Bill birthday (1)", "562. John binary birthday (1)", "612. Jack binary birthday (1)", "662. Bill binary birthday (1)", "780. John birthday (2)", "830. Jack birthday (2)", "880. Bill birthday (2)", "1050. John decimal birthday (1)", "1074. John binary birthday (2)", "1100. Jack decimal birthday (1)" }



1)
{"Zero", "Two", "Three"}
{0, 2, 3}
24
{"threeday", "twoday"}
{3,2}
10

Returns: {"24. Zero threeday (8)", "24. Three threeday (7)", "24. Zero twoday (12)", "24. Two twoday (11)", "25. Three twoday (11)", "26. Two threeday (8)", "26. Zero twoday (13)", "26. Two twoday (12)", "27. Zero threeday (9)", "27. Three threeday (8)" }

This demonstrates the sorting rules used.

2)
{"Jessica Alba", "Angelina Jolie", "Paris Hilton", "Britney Spears"}
{4135, 1980, 4065, 4353}
14091
{"Venus year", "Earth year", "Mars year", "Jupiter year", "Saturn year"}
{225, 365, 687, 4332, 10760}
20

Returns: {"14130. Angelina Jolie Venus year (54)", "14190. Paris Hilton Venus year (45)", "14208. Britney Spears Earth year (27)", "14253. Britney Spears Venus year (44)", "14260. Jessica Alba Venus year (45)", "14285. Paris Hilton Earth year (28)", "14346. Angelina Jolie Mars year (18)", "14355. Angelina Jolie Venus year (55)", "14355. Jessica Alba Earth year (28)", "14370. Paris Hilton Mars year (15)", "14390. Angelina Jolie Earth year (34)", "14415. Paris Hilton Venus year (46)", "14440. Jessica Alba Mars year (15)", "14478. Britney Spears Venus year (45)", "14485. Jessica Alba Venus year (46)", "14573. Britney Spears Earth year (28)", "14580. Angelina Jolie Venus year (56)", "14640. Paris Hilton Venus year (47)", "14650. Paris Hilton Earth year (29)", "14658. Britney Spears Mars year (15)" }



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"John", "Jack", "Bill"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {50, 100, 150}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 500; string Arr3[] = {"birthday", "decimal birthday", "binary birthday"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {365, 1000, 512}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 10; string Arr6[] = {"515. Bill birthday (1)", "562. John binary birthday (1)", "612. Jack binary birthday (1)", "662. Bill binary birthday (1)", "780. John birthday (2)", "830. Jack birthday (2)", "880. Bill birthday (2)", "1050. John decimal birthday (1)", "1074. John binary birthday (2)", "1100. Jack decimal birthday (1)" }; vector <string> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); verify_case(0, Arg6, remind(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_1() { string Arr0[] = {"Zero", "Two", "Three"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 24; string Arr3[] = {"threeday", "twoday"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {3,2}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 10; string Arr6[] = {"24. Zero threeday (8)", "24. Three threeday (7)", "24. Zero twoday (12)", "24. Two twoday (11)", "25. Three twoday (11)", "26. Two threeday (8)", "26. Zero twoday (13)", "26. Two twoday (12)", "27. Zero threeday (9)", "27. Three threeday (8)" }; vector <string> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); verify_case(1, Arg6, remind(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_2() { string Arr0[] = {"Jessica Alba", "Angelina Jolie", "Paris Hilton", "Britney Spears"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4135, 1980, 4065, 4353}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 14091; string Arr3[] = {"Venus year", "Earth year", "Mars year", "Jupiter year", "Saturn year"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {225, 365, 687, 4332, 10760}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 20; string Arr6[] = {"14130. Angelina Jolie Venus year (54)", "14190. Paris Hilton Venus year (45)", "14208. Britney Spears Earth year (27)", "14253. Britney Spears Venus year (44)", "14260. Jessica Alba Venus year (45)", "14285. Paris Hilton Earth year (28)", "14346. Angelina Jolie Mars year (18)", "14355. Angelina Jolie Venus year (55)", "14355. Jessica Alba Earth year (28)", "14370. Paris Hilton Mars year (15)", "14390. Angelina Jolie Earth year (34)", "14415. Paris Hilton Venus year (46)", "14440. Jessica Alba Mars year (15)", "14478. Britney Spears Venus year (45)", "14485. Jessica Alba Venus year (46)", "14573. Britney Spears Earth year (28)", "14580. Angelina Jolie Venus year (56)", "14640. Paris Hilton Venus year (47)", "14650. Paris Hilton Earth year (29)", "14658. Britney Spears Mars year (15)" }; vector <string> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); verify_case(2, Arg6, remind(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  BirthdayReminders test;

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
