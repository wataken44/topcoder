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

class ContestScore {
 public:
  struct group {
    string name;
    vector<double> score;
    vector<int> rank;
  };
  
  vector <string> sortResults(vector <string> data) {
    // -- main code --

    vector<group> groups;

    TIMES(i, data.size()) {
      istringstream iss(data[i]);
      group g;

      iss >> g.name;
      while(!iss.eof()) {
        double d;
        iss >> d;
        g.score.push_back(d);
      }

      g.rank.push_back(i + 1);

      groups.push_back(g);
    }

    int m = g[0].score.size();

    TIMES(i, m) {
      TIMES(y, groups.size()) {
        FOR(x, y+1, groups.size()) {
          if(groups[y].score[i] > groups[x].score[i]) {
            int ry = groups[y].rank[i];
            int rx = groups[x].rank[i];
            groups[y].rank[i] = rx;
            groups[x].rank[i] = ry;
          }
        }
      }
    };
    
    return ;
  }

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Some competitions have judges who score one specific area of a performance.  Unfortunately, bad judges do exist and can individually cause one group's rating to be affected drastically.  In some sports, the highest and lowest scores are dropped.  This works well when all judges are scoring the same thing.  However, when each judge scores only one aspect of a performance, dropping a score is not an option.

One way to minimize the effects of a bad judge is to not use the score each judge gives, but to use the relative ranking the judge gives each group.  The group that places first has a ranking of 1.  The group that places second has a ranking of 2, third has a ranking of 3, and so forth.  When multiple groups are given the same score from one judge, then they will all receive the same ranking.  For example, if the groups A, B, C, D, and E receive the scores 98, 95, 95, 90, and 83 respectively, then they would receive rankings of 1, 2, 2, 4, and 5, respectively.

Each group's rankings from all of the judges are then added together to find the group's total ranking.  The group with the lowest total ranking places first.  The group with the second lowest total ranking places second and so forth.  Ties are broken using the sum of all scores the group receives from the judges to find the group's total score.  The group with the highest total score wins the tiebreaker.  If multiple groups have the same total ranking and the same total score, then the group whose name comes first alphabetically wins.

Create a class ContestScore with a method sortResults that is given a vector <string> data and will return a vector <string> containing the group names and scores sorted from first to last place.  Every string in data will be formatted as: ("<GROUPNAME> NN.N NN.N NN.N") (quotes for clarity) where <GROUPNAME> will be between 1 and 10 characters in length, inclusive, and NN.N is a decimal number.  It will have leading zeros if necessary to follow the above format.  Each string in the returned vector <string> will be formatted as "<GROUPNAME> <TOTALRANK> <TOTALSCORE>" (quotes for clarity) where <TOTALRANK> is the group's total ranking and is an integer.  <TOTALSCORE> is the sum of the scores received from all judges and will always have exactly one decimal place and no extra leading 0's.  For example, if a group's <TOTALRANK> is 7 and <TOTALSCORE> is 271, then the string would be "<GROUPNAME> 7 271.0" (quotes for clarity).

For example, we have three groups.  Group A scored a 90.7, a 92.9, and an 87.4.  Group B scored a 90.5, a 96.6, and an 88.0.  Group C scored a 92.2, a 91.0, and a 95.3.  Here is how you would receive the data (quotes for clarity).

  {"A 90.7 92.9 87.4",
   "B 90.5 96.6 88.0",
   "C 92.2 91.0 95.3"}
From judge 1, group C got 1st, group A got 2nd, and group B got 3rd.  From judge 2, group B got 1st, group A got 2nd, and group C got 3rd.  From judge 3, group C got 1st, group B got 2nd, and group A got 3rd.

   A  2 2 3
   B  3 1 2
   C  1 3 1
So A has a total ranking of 7, B has a total ranking of 6, and C has a total ranking of 5.  Since C has the lowest total ranking, they place first.  B places second, and A places third.  You would return:

  {"C 5 278.5",
   "B 6 275.1",
   "A 7 271.0"}

DEFINITION
Class:ContestScore
Method:sortResults
Parameters:vector <string>
Returns:vector <string>
Method signature:vector <string> sortResults(vector <string> data)


NOTES
-It is possible for a group to receive 00.0 for a score.  Remember that leading and trailing zeros will be present if necessary in order to maintain formatting.
-Remember that if a group's total score is an exact integer to display it with one decimal place.  Also, if the total score is between 0.0 and 0.9, inclusive, display one zero to the left of the decimal point.  The last example shows this.


CONSTRAINTS
-data will contain between 0 and 50 elements, inclusive.
-Each element of data will contain the exact same number of scores.
-Each element of data will contain between 6 and 50 characters, inclusive.
-There will be at least one judge.
-Each element of data will be formatted as a group name followed by a single space, followed by a single space delimited list of scores.
-Group names will be between 1 and 10 characters in length, and will consist of only of uppercase letters ('A'-'Z').
-No two groups will have the same name.
-The score from each judge will be formatted as NN.N where N is a digit ('0'-'9').
-There will be no leading or trailing spaces in each string of data.


EXAMPLES

0)
{"A 90.7 92.9 87.4",
 "B 90.5 96.6 88.0",
 "C 92.2 91.0 95.3"}

Returns: { "C 5 278.5",  "B 6 275.1",  "A 7 271.0" }

Example from above.

1)
{"STANFORD 85.3 90.1 82.6 84.6 96.6 94.5 87.3 90.3",
 "MIT 95.5 83.9 80.4 85.5 98.7 98.3 96.7 82.7",
 "PRINCETON 99.2 79.1 87.6 85.1 93.6 96.4 86.0 90.6",
 "HARVARD 83.6 92.0 85.5 94.3 97.5 91.5 92.5 83.0",
 "YALE 99.5 92.6 86.2 82.0 96.4 92.6 84.5 78.6",
 "COLUMBIA 97.2 87.6 81.7 93.7 88.0 86.3 95.9 89.6",
 "BROWN 92.2 95.8 92.1 81.5 89.5 87.0 95.5 86.4",
 "PENN 96.3 80.7 81.2 91.6 85.8 92.2 83.9 87.8",
 "CORNELL 88.0 83.7 85.0 83.8 99.8 92.1 91.0 88.9"}

Returns: { "PRINCETON 34 717.6",  "MIT 36 721.7",  "HARVARD 38 719.9",  "COLUMBIA 39 720.0",  "STANFORD 39 711.3",  "YALE 40 712.4",  "BROWN 41 720.0",  "CORNELL 42 712.3",  "PENN 51 699.5" }

2)
{}

Returns: { }

3)
{"AA 90.0 80.0 70.0 60.0 50.0 40.0",
 "BBB 80.0 70.0 60.0 50.0 40.0 90.0",
 "EEE 70.0 60.0 50.0 40.0 90.0 80.0",
 "AAA 60.0 50.0 40.0 90.0 80.0 70.0",
 "DDD 50.0 40.0 90.0 80.0 70.0 60.0",
 "CCC 40.0 90.0 80.0 70.0 60.0 50.0"}

Returns: { "AA 21 390.0",  "AAA 21 390.0",  "BBB 21 390.0",  "CCC 21 390.0",  "DDD 21 390.0",  "EEE 21 390.0" }

4)
{"A 00.1", "B 05.2", "C 29.0","D 00.0"}

Returns: { "C 1 29.0",  "B 2 5.2",  "A 3 0.1",  "D 4 0.0" }

Remember that, for numbers between 0.0 and 0.9, inclusive, you must display a 0 before the decimal point.  Do not display any extraneous leading zeros if a number is between 1.0 and 9.9, inclusive.

*/
// END CUT HERE

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"A 90.7 92.9 87.4",
 "B 90.5 96.6 88.0",
 "C 92.2 91.0 95.3"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "C 5 278.5",  "B 6 275.1",  "A 7 271.0" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, sortResults(Arg0)); }
	void test_case_1() { string Arr0[] = {"STANFORD 85.3 90.1 82.6 84.6 96.6 94.5 87.3 90.3",
 "MIT 95.5 83.9 80.4 85.5 98.7 98.3 96.7 82.7",
 "PRINCETON 99.2 79.1 87.6 85.1 93.6 96.4 86.0 90.6",
 "HARVARD 83.6 92.0 85.5 94.3 97.5 91.5 92.5 83.0",
 "YALE 99.5 92.6 86.2 82.0 96.4 92.6 84.5 78.6",
 "COLUMBIA 97.2 87.6 81.7 93.7 88.0 86.3 95.9 89.6",
 "BROWN 92.2 95.8 92.1 81.5 89.5 87.0 95.5 86.4",
 "PENN 96.3 80.7 81.2 91.6 85.8 92.2 83.9 87.8",
 "CORNELL 88.0 83.7 85.0 83.8 99.8 92.1 91.0 88.9"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "PRINCETON 34 717.6",  "MIT 36 721.7",  "HARVARD 38 719.9",  "COLUMBIA 39 720.0",  "STANFORD 39 711.3",  "YALE 40 712.4",  "BROWN 41 720.0",  "CORNELL 42 712.3",  "PENN 51 699.5" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, sortResults(Arg0)); }
	void test_case_2() { string Arr0[] = {}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, sortResults(Arg0)); }
	void test_case_3() { string Arr0[] = {"AA 90.0 80.0 70.0 60.0 50.0 40.0",
 "BBB 80.0 70.0 60.0 50.0 40.0 90.0",
 "EEE 70.0 60.0 50.0 40.0 90.0 80.0",
 "AAA 60.0 50.0 40.0 90.0 80.0 70.0",
 "DDD 50.0 40.0 90.0 80.0 70.0 60.0",
 "CCC 40.0 90.0 80.0 70.0 60.0 50.0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "AA 21 390.0",  "AAA 21 390.0",  "BBB 21 390.0",  "CCC 21 390.0",  "DDD 21 390.0",  "EEE 21 390.0" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, sortResults(Arg0)); }
	void test_case_4() { string Arr0[] = {"A 00.1", "B 05.2", "C 29.0","D 00.0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "C 1 29.0",  "B 2 5.2",  "A 3 0.1",  "D 4 0.0" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, sortResults(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  ContestScore test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
