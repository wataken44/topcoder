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

using namespace std;

class DiskSpace {
 public:
  int minDrives(vector <int> used, vector <int> total) {
    // -- main code --

    sort(total.begin(), total.end(), greater<int>());

    int used_sum = 0;
    TIMES(i , used.size()) {
      used_sum += used[i];
    }

    TIMES(i, total.size()) {
      used_sum -= total[i];
      if(used_sum <= 0) {
        return i+1;
      }
    }
    
    return total.size();	
  }

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// As of late, your usually high-performance computer has been acting rather sluggish.  You come to realize that while you have plenty of free disk space on your machine, it is split up over many hard drives.  You decide that the secret to improving performance is to consolidate all the data on your computer onto as few hard drives as possible.

Given a vector <int> used, representing the amount of disk space used on each drive, and a corresponding vector <int> total, representing the total capacity of each drive mentioned in used, you should attempt to pack the data onto as few hard drives as possible.  You may assume that the data consists of very small files, such that splitting it up and moving parts of it onto different hard drives never presents a problem.  Return the minimum number of hard drives that still contain data after the consolidation is complete.

DEFINITION
Class:DiskSpace
Method:minDrives
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int minDrives(vector <int> used, vector <int> total)


CONSTRAINTS
-used will contain between 1 and 50 elements, inclusive.
-used and total will contain the same number of elements.
-Each element of used will be between 1 and 1000, inclusive.
-Each element of total will be between 1 and 1000, inclusive.
-used[i] will always be less than or equal to total[i], for every valid index i.


EXAMPLES

0)
{300,525,110}
{350,600,115}

Returns: 2

In this example, the computer contains three hard drives:

Hard drive 1: 350 MB total, 300 MB used, 50 MB free
Hard drive 2: 600 MB total, 525 MB used, 75 MB free
Hard drive 3: 115 MB total, 110 MB used, 5 MB free

One way to pack the data onto as few drives as possible is as follows.  First, move 50 MB from hard drive 3 to hard drive 1, completely filling it up.  Next, move the remaining 60 MB from hard drive 3 to hard drive 2.  There are still two hard drives which contain data after this process, so your method should return 2.

1)
{1,200,200,199,200,200}
{1000,200,200,200,200,200}

Returns: 1

One way to consolidate the data would be to move the 1 MB from hard drive 1 to hard drive 4.  However, this is a poor choice, as it results in only one free hard drive and five hard drives which still contain data.  A better decision is to move all the data from the other five hard drives onto hard drive 1.  Now there is only one hard drive which contains data.  Since this is the optimal strategy, the method returns 1.

2)
{750,800,850,900,950}
{800,850,900,950,1000}

Returns: 5

No matter how the files get moved around, all five drives will still contain data at the end.

3)
{49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,
 49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49}
{50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,
 50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50}

Returns: 49

To consolidate this data, you would select one hard drive, and transfer 1 MB of data from it to each other drive.  This results in 49 completely full hard drives and one empty drive.

4)
{331,242,384,366,428,114,145,89,381,170,329,190,482,246,2,38,220,290,402,385}
{992,509,997,946,976,873,771,565,693,714,755,878,897,789,969,727,765,521,961,906}

Returns: 6

*/
// END CUT HERE

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {300,525,110}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {350,600,115}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(0, Arg2, minDrives(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,200,200,199,200,200}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1000,200,200,200,200,200}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(1, Arg2, minDrives(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {750,800,850,900,950}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {800,850,900,950,1000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(2, Arg2, minDrives(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,
 49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,
 50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 49; verify_case(3, Arg2, minDrives(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {331,242,384,366,428,114,145,89,381,170,329,190,482,246,2,38,220,290,402,385}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {992,509,997,946,976,873,771,565,693,714,755,878,897,789,969,727,765,521,961,906}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(4, Arg2, minDrives(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  DiskSpace test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
