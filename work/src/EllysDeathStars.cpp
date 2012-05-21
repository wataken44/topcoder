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

class EllysDeathStars {

 public:
  struct Star {
    int x;
    int y;
    Star(int x_, int y_) : x(x_), y(y_) {};
  };

  struct Ship {
    int sx;
    int sy;
    int ex;
    int ey;
    int s;
    int r;
    int e;
    Ship(int sx_, int sy_, int ex_, int ey_, int s_, int r_, int e_) :
        sx(sx_), sy(sy_), ex(ex_), ey(ey), s(s_), r(r_), e(e_) {};
  };

  double getMax(vector <string> stars, vector <string> ships)
  {
    int stsz = stars.size();
    int shsz = ships.size();

    vector<Star> st;
    vector<Ship> sh;
    
    TIMES(i, shsz) {
      int sx;
      int sy;
      int ex;
      int ey;
      int s;
      int r;
      int e;
      istringstream iss(ships[i]);
      iss >> sx >> sy >> ex >> ey >> s >> r >> e;
      sh.push_back(Ship(sx, sy, ex, ey, s, r, e));
    }

    TIMES(i, stsz) {
      int x;
      int y;
      istringstream iss(stars[i]);
      iss >> x >> y;
      st.push_back(Star(x, y));
    }

    
    double result;
    // -- main code --
    
    return result;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// Princess Elly recently discovered secret plans for building a whole bunch of new death stars. Now she and the rebels are desperately trying to destroy them before they are fully operational.

They are sending several ships to destroy the death stars. For simplicity, in this problem the battle will take place in a 2D plane. The distances are so large that we will view all death stars and all ships as points in this plane. All death stars are stationary. All ships appear at their starting positions at the same time. Each ship is a point moving at some constant speed along some line segment, however the speeds for different ships may be different. As soon as a ship reaches the end of its segment, it disappears from the battlefield. (This does not necessarily happen at the same time for all the ships.) The rebels know the locations of all death stars. Also, for each ship they know its planned trajectory, its speed, the range of its lasers, and the amount of energy available for shooting them.
A ship can shoot at a death star if:

The death star is within its range
The ship still has energy for its lasers

Unfortunately, some defenses of the death stars are already active and prevent multiple ships from attacking the same death star at the same time. Thus, there is one additional rule:

No other ship is currently attacking the death star

On the other hand, all ships are able to shoot at multiple targets at the same time. Whenever a ship shoots at X targets at the same time, it consumes energy at the rate of X units per second. The ship can start and stop shooting at any target at any time. (The time spent shooting at a particular set of targets does not have to be an integer.)

You are given a vector <string> stars whose elements are formatted as "X Y", where (X, Y) corresponds to the position of one death star on the map. You are also given a vector <string> ships describing the ships. The i-th element of ships will be formated as "SX SY EX EY S R E", where (SX, SY) and (EX, EY) give the starting and ending point of the i-th ship, respectively, S is its speed, R is the range of its lasers, and E is its energy.

The rebels came up with a simple plan: They will shoot the death stars in such a way that the total amount of energy spent on shooting them is maximized. (It is possible that a different amount of energy will be spent on different death stars.) Compute and return the maximum total amount of energy spent by the ships' lasers if the rebels use an optimal shooting strategy.

DEFINITION
Class:EllysDeathStars
Method:getMax
Parameters:vector <string>, vector <string>
Returns:double
Method signature:double getMax(vector <string> stars, vector <string> ships)


NOTES
-Your return value must have a relative or an absolute error of less than 1e-9.
-The range of a ship's lasers is given in distance units (the same ones as all coordinates).
-The speed of a ship is given in distance units per second.
-A ship can have the same starting and ending point. Such ship disappears immediately after appearing on the battlefield.
-Multiple death stars can be located at the exact same place. They are still considered to be distinct death stars.
-Multiple ships can be located at the exact same place at some moment of time. A ship and a death star can be located at the exact same place at some moment of time. In both cases, no collision happens and each ship just proceeds moving along its defined trajectory.


CONSTRAINTS
-stars will contain between 1 and 20 elements, inclusive.
-Each element of stars will contain between 3 and 9 characters, inclusive.
-Each element of stars will be formated as "X Y" - two space-separated integers between 1 and 1000, inclusive.
-ships will contain between 1 and 20 elements, inclusive.
-Each element of ships will contain between 13 and 34 characters, inclusive.
-Each element of ships will be formated as "SX SY EX EY S R E" - seven space-separated integers between 1 and 1000, inclusive.


EXAMPLES

0)
{"2 2"}
{"1 1 5 3 2 1 2"}

Returns: 0.894427190999916

Just a single ship and a single star. The ship has plenty of energy, so it might shoot at the death star the whole time it is in range.

1)
{"12 10", "7 5"}
{"10 10 12 10 1 1 3", "6 1 8 10 1 2 3", "3 6 8 2 5 3 1", "42 42 42 42 6 6 6"}

Returns: 4.983770744659944

Although the first ship has remaining energy, it disappears before it can shoot it all. The last ship disappears right after the beginning.

2)
{"5 77", "60 50", "10 46", "22 97", "87 69"}
{"42 17 66 11 5 7 13", "10 10 20 20 3 3 3", "13 15 18 9 4 1 2",
 "99 71 63 81 19 4 60", "27 34 56 43 11 3 12"}

Returns: 0.0

Plenty of ships and stars, but no action whatsoever.

3)
{"141 393", "834 847", "568 43", "18 228", "515 794",
 "167 283", "849 333", "719 738", "434 261", "613 800",
 "127 340", "466 938", "598 601"}
{"410 951 472 100 337 226 210", "713 352 677 908 731 687 300",
 "191 41 337 92 446 716 213", "598 889 446 907 148 650 203",
 "168 556 470 924 344 369 198", "300 182 350 936 737 533 45",
 "410 871 488 703 746 631 80", "270 777 636 539 172 103 56",
 "466 906 522 98 693 77 309", "768 698 846 110 14 643 14",
 "755 724 664 465 263 759 120"}

Returns: 31.965770956316362

Random testcase.

*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"2 2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1 1 5 3 2 1 2"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.894427190999916; verify_case(0, Arg2, getMax(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"12 10", "7 5"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"10 10 12 10 1 1 3", "6 1 8 10 1 2 3", "3 6 8 2 5 3 1", "42 42 42 42 6 6 6"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 4.983770744659944; verify_case(1, Arg2, getMax(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"5 77", "60 50", "10 46", "22 97", "87 69"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"42 17 66 11 5 7 13", "10 10 20 20 3 3 3", "13 15 18 9 4 1 2",
 "99 71 63 81 19 4 60", "27 34 56 43 11 3 12"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.0; verify_case(2, Arg2, getMax(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"141 393", "834 847", "568 43", "18 228", "515 794",
 "167 283", "849 333", "719 738", "434 261", "613 800",
 "127 340", "466 938", "598 601"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"410 951 472 100 337 226 210", "713 352 677 908 731 687 300",
 "191 41 337 92 446 716 213", "598 889 446 907 148 650 203",
 "168 556 470 924 344 369 198", "300 182 350 936 737 533 45",
 "410 871 488 703 746 631 80", "270 777 636 539 172 103 56",
 "466 906 522 98 693 77 309", "768 698 846 110 14 643 14",
 "755 724 664 465 263 759 120"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 31.965770956316362; verify_case(3, Arg2, getMax(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  EllysDeathStars test;

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
