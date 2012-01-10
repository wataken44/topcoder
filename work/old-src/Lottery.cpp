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
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>

// -- utility --


using namespace std;

class Lottery {
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// In most states, gamblers can choose from a wide variety of different lottery games.  The rules of a lottery are defined by two integers (choices and blanks) and two boolean variables (sorted and unique).  choices represents the highest valid number that you may use on your lottery ticket.  (All integers between 1 and choices, inclusive, are valid and can appear on your ticket.)  blanks represents the number of spots on your ticket where numbers can be written.

The sorted and unique variables indicate restrictions on the tickets you can create.  If sorted is set to true, then the numbers on your ticket must be written in non-descending order.  If sorted is set to false, then the numbers may be written in any order.  Likewise, if unique is set to true, then each number you write on your ticket must be distinct.  If unique is set to false, then repeats are allowed.

Here are some example lottery tickets, where choices = 15 and blanks = 4:
{3, 7, 12, 14} -- this ticket is unconditionally valid.
{13, 4, 1, 9} -- because the numbers are not in nondescending order, this ticket is valid only if sorted = false.
{8, 8, 8, 15} -- because there are repeated numbers, this ticket is valid only if unique = false.
{11, 6, 2, 6} -- this ticket is valid only if sorted = false and unique = false.

Given a list of lotteries and their corresponding rules, return a list of lottery names sorted by how easy they are to win.  The probability that you will win a lottery is equal to (1 / (number of valid lottery tickets for that game)).  The easiest lottery to win should appear at the front of the list.  Ties should be broken alphabetically (see example 1).

DEFINITION
Class:Lottery
Method:sortByOdds
Parameters:vector <string>
Returns:vector <string>
Method signature:vector <string> sortByOdds(vector <string> rules)


CONSTRAINTS
-rules will contain between 0 and 50 elements, inclusive.
-Each element of rules will contain between 11 and 50 characters, inclusive.
-Each element of rules will be in the format "<NAME>:_<CHOICES>_<BLANKS>_<SORTED>_<UNIQUE>" (quotes for clarity). The underscore character represents exactly one space. The string will have no leading or trailing spaces.
-<NAME> will contain between 1 and 40 characters, inclusive, and will consist of only uppercase letters ('A'-'Z') and spaces (' '), with no leading or trailing spaces.
-<CHOICES> will be an integer between 10 and 100, inclusive, with no leading zeroes.
-<BLANKS> will be an integer between 1 and 8, inclusive, with no leading zeroes.
-<SORTED> will be either 'T' (true) or 'F' (false).
-<UNIQUE> will be either 'T' (true) or 'F' (false).
-No two elements in rules will have the same name.


EXAMPLES

0)
{"PICK ANY TWO: 10 2 F F"
,"PICK TWO IN ORDER: 10 2 T F"
,"PICK TWO DIFFERENT: 10 2 F T"
,"PICK TWO LIMITED: 10 2 T T"}

Returns: { "PICK TWO LIMITED",  "PICK TWO IN ORDER",  "PICK TWO DIFFERENT",  "PICK ANY TWO" }

The "PICK ANY TWO" game lets either blank be a number from 1 to 10.  Therefore, there are 10 * 10 = 100 possible tickets, and your odds of winning are 1/100.

The "PICK TWO IN ORDER" game means that the first number cannot be greater than the second number.  This eliminates 45 possible tickets, leaving us with 55 valid ones.  The odds of winning are 1/55.

The "PICK TWO DIFFERENT" game only disallows tickets where the first and second numbers are the same.  There are 10 such tickets, leaving the odds of winning at 1/90.

Finally, the "PICK TWO LIMITED" game disallows an additional 10 tickets from the 45 disallowed in "PICK TWO IN ORDER".  The odds of winning this game are 1/45.

1)
{"INDIGO: 93 8 T F",
 "ORANGE: 29 8 F T",
 "VIOLET: 76 6 F F",
 "BLUE: 100 8 T T",
 "RED: 99 8 T T",
 "GREEN: 78 6 F T",
 "YELLOW: 75 6 F F"}


Returns: { "RED",  "ORANGE",  "YELLOW",  "GREEN",  "BLUE",  "INDIGO",  "VIOLET" }

Note that INDIGO and BLUE both have the exact same odds (1/186087894300).  BLUE is listed first because it comes before INDIGO alphabetically.

2)
{}

Returns: { }

Empty case

*/
// END CUT HERE

 public:
  class rule_comparator {
   public:
    bool operator() (const string& lhs, const string& rhs) {
      rule_object left(lhs);
      rule_object right(rhs);

      long lv = left.valid_tickets();
      long rv = right.valid_tickets();

      if(lv == rv) {
        return left.name < right.name;
      }else {
        return lv < rv;
      }
    }
  };

  struct rule_object {
   public:
    rule_object(const string& rule) {
      int pos;
      string temp;
      pos = rule.find(":");

      name = rule.substr(0, pos);;

      istringstream iss(rule.substr(pos + 1, rule.size()));

      iss >> choices;
      iss >> blanks;
      iss >> temp;
      sorted = (temp == "T" ? true : false);
      iss >> temp;
      unique = (temp == "T" ? true : false);
    }
    string name;
    int choices;
    int blanks;
    bool sorted;
    bool unique;

    std::string get_name() const {
      return name.substr(0, name.size() - 1);
    }

    long valid_tickets() const {
      if(sorted && unique) {
        return combination(choices, blanks);
      }else if(!sorted && unique) {
        return permutation(choices, blanks);
      }else if(sorted && !unique) {
        return combination(choices + blanks - 1, blanks);
      }else if(!sorted && !unique) {
        return power(choices, blanks);
      }
      // never reach
      return 0;
    }

    long combination(int p, int q) const {
      long r = permutation(p, q) / permutation(q, q);
      return r;
    }

    long permutation(int p, int q) const {
      long r = 1;
      for(int i = 0; i < q; ++i) {
        r *= (p - i);
      }
      return r;
    }

    long power(int p, int q) const {
      long r= 1;
      for(int i = 0; i < q; ++i) {
        r *= p;
      }
      return r;
    }
  };
  
  vector <string> sortByOdds(vector <string> rules) {
    vector <string> result;
    // -- main code --
    sort(rules.begin(), rules.end(), rule_comparator());
    for(int i = 0; i < static_cast<int>(rules.size()); ++ i) {
      result.push_back(rule_object(rules[i]).name);
    }
    return result;
  }

  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"PICK ANY TWO: 10 2 F F"
,"PICK TWO IN ORDER: 10 2 T F"
,"PICK TWO DIFFERENT: 10 2 F T"
,"PICK TWO LIMITED: 10 2 T T"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "PICK TWO LIMITED",  "PICK TWO IN ORDER",  "PICK TWO DIFFERENT",  "PICK ANY TWO" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, sortByOdds(Arg0)); }
	void test_case_1() { string Arr0[] = {"INDIGO: 93 8 T F",
 "ORANGE: 29 8 F T",
 "VIOLET: 76 6 F F",
 "BLUE: 100 8 T T",
 "RED: 99 8 T T",
 "GREEN: 78 6 F T",
 "YELLOW: 75 6 F F"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "RED",  "ORANGE",  "YELLOW",  "GREEN",  "BLUE",  "INDIGO",  "VIOLET" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, sortByOdds(Arg0)); }
	void test_case_2() { string Arr0[] = {}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, sortByOdds(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  Lottery test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE

