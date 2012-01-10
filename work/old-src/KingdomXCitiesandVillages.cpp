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

typedef int int_type;

// -- utility --
// C-style loop
#define FOR(x, a, b) for(int_type x = static_cast<int_type>(a); x < static_cast<int_type>(b); ++x)
#define FORN(x, n) FOR(x, 0, n)
// Ruby-style loop
#define TIMES(x, n) FOR(x, 0, n)
#define STEP(x, a, b, s) for(int_type x = static_cast<int_type>(a); s > 0 ? x <= static_cast<int_type>(b) : x >= static_cast<int_type>(b); x += static_cast<int_type>(s) )
#define UPTO(x, a, b) for(int_type x = static_cast<int_type>(a); x <= static_cast<int_type>(b); ++x)
#define DOWNTO(x, a, b) for(int_type x = static_cast<int_type>(a); x >= static_cast<int_type>(b); --x)
// debug
#define DUMP(x) std::cout << #x << " = " << x << std::endl;

using namespace std;

class KingdomXCitiesandVillages {
 public:
  double determineLength(vector <int> cx, vector <int> cy, vector <int> vx, vector <int> vy) {
    // -- main code --

    vector< bool > vc(vy.size(), false);

    double s = 0.0;
    
    TIMES(vi, vc.size()) {
      double mcd = dist(cx[0], cy[0], vx[vi], vy[vi]);
      TIMES(ci, cx.size()) {
        mcd = min(mcd, dist(cx[ci], cy[ci], vx[vi], vy[vi]));
      }
      vector<double> vdists(vy.size());
      TIMES(vj, vx.size()) {
        vdists[vj] = min(mcd, dist(vx[vj], vy[vj], vx[vi], vy[vi]));
      }
      sort(vdists.begin(), vdists.end());
      vdists[0] = mcd;
      FOR(i, 0, vdists.size()) {
        DUMP(vdists[i]);
        s += (double)vdists[i] * (double)(fact(vdists.size() - i - 1)) /(double)(fact(vdists.size()));
      }

    }
    
    return s;
  }

  unsigned long long fact(int n) {
    if(n <= 1) {
      return 1;
    }else {
      return fact(n-1) * n;
    }
  }
  
  double dist(int x0, int y0, int x1, int y1) {
    int xd = x0 - x1;
    int yd = y0 - y1;
    return pow(xd * xd +  yd * yd, 0.5);
  }

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// The Grid Kingdom lies on a plane. There are N cities and M villages in the Grid Kingdom, each is a point on the plane. The i-th city is located at coordinates (cityX[i], cityY[i]) and the i-th village is located at coordinates (villageX[i], villageY[i]). Initially, there are no roads in the kingdom, so no village is initially connected to any city.  

To improve this, the king has ordered that each village shall be connected to a city by a system of roads. The scheme for building the roads is as follows: 

While there exists a village that is not connected to any city:

Pick one unconnected village (each has an equal probability of being chosen), call it V.
Select a point, X, which is nearest to V, in terms of Euclidean Distance, and is either a city or a village-that-is-already-connected-to-a-city. If multiple such points are equally near, pick any of the nearest points with equal probability.
Construct a road from V to X. The length of this road is equal to the Euclidean Distance between points V and X. V is now connected to a city.

Return the expected total length of all the roads that will be constructed after all villages are connected to a city.

DEFINITION
Class:KingdomXCitiesandVillages
Method:determineLength
Parameters:vector <int>, vector <int>, vector <int>, vector <int>
Returns:double
Method signature:double determineLength(vector <int> cityX, vector <int> cityY, vector <int> villageX, vector <int> villageY)


NOTES
-The Euclidean distance between two points (X1, Y1) and (X2, Y2) is defined as the square root of ((X1-X2)^2 + (Y1-Y2)^2).
-The returned value must have an absolute or relative error less than 1e-9.


CONSTRAINTS
-cityX will contain between 1 and 50 elements, inclusive.
-cityY will contain the same number of elements as cityX.
-Each element in cityX and cityY will be between 0 and 1,000,000, inclusive.
-villageX will contain between 1 and 50 elements, inclusive.
-villageY will contain the same number of elements as villageX.
-Each element in villageX and villageY will be between 0 and 1,000,000, inclusive.
-The location of all cities will be distinct.
-The location of all villages will be distinct.
-There will be no pair of city and village that is located at the same location.


EXAMPLES

0)
{3}
{0}
{3,3}
{2,1}

Returns: 2.5

If village 0 is chosen first, the total length is 3. Otherwise it's 2. The expected length is their average.

1)
{1,4,7,10}
{5,5,5,5}
{1,4,7,10}
{4,4,4,4}

Returns: 4.0

This time the order doesn't matter, each village will be connected to the city closest to it.

2)
{1,2,3}
{4,4,4}
{4,5,6}
{4,4,4}

Returns: 4.166666666666667



*/
// END CUT HERE

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2,1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 2.5; verify_case(0, Arg4, determineLength(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {1,4,7,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5,5,5,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,4,7,10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {4,4,4,4}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 4.0; verify_case(1, Arg4, determineLength(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4,4,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {4,5,6}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {4,4,4}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 4.166666666666667; verify_case(2, Arg4, determineLength(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  KingdomXCitiesandVillages test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
