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

class WhatSort {
 public:
  string sortType(vector <string> name, vector <int> age, vector <int> wt) {
    // -- main code --
    /*
    NAW  -- name was the primary, age secondary, weight the final field
    NWA  -- name was the primary, weight secondary, age final
    ANW  -- age was primary, name was secondary, weight final
    AWN  -- age was primary, weight was secondary, name final
    WAN  -- weight primary, age secondary, name final
    WNA  -- weight primary, name secondary, age final
    IND  -- indeterminate: more than one of the above is possible
    NOT  -- none of the above sorting methods was used
     */

    int sz = name.size();
    
    bool ind = false;
    bool any = false;
    bool nt = true;

    bool naw = true;
    TIMES(i, sz - 1) {
      if(name[i] < name[i+1] or (name[i] == name[i+1] and age[i] < age[i+1]) or (name[i] == name[i+1] and age[i] == age[i+1] and wt[i] < wt[i+1]) ) {
      }else {
        naw = false;
        break;
      }
    }
    if(naw == true) {
      if(any) {
        ind = true;
      }
      nt = false;
      any = true;
    }
    
    bool nwa = true;
    TIMES(i, sz - 1) {
      if(name[i] < name[i+1] or (name[i] == name[i+1] and wt[i] < wt[i+1]) or (name[i] == name[i+1] and wt[i] == wt[i+1] and age[i] < age[i+1]) ) {
      }else {
        nwa = false;
        break;
      }
    }
    if(nwa == true) {
      if(any) {
        ind = true;
      }
      nt = false;
      any = true;
    }

    bool anw = true;
    TIMES(i, sz - 1) {
      if(age[i] < age[i+1] or (age[i] == age[i+1] and name[i] < name[i+1]) or (age[i] == age[i+1] and name[i] == name[i+1] and wt[i] < wt[i+1]) ) {
      }else {
        anw = false;
        break;
      }
    }
    if(anw == true) {
      if(any) {
        ind = true;
      }
      nt = false;
      any = true;
    }

    bool awn = true;
    TIMES(i, sz - 1) {
      if(age[i] < age[i+1] or (age[i] == age[i+1] and wt[i] < wt[i+1]) or (age[i] == age[i+1] and wt[i] == wt[i+1] and name[i] < name[i+1]) ) {
      }else {
        awn = false;
        break;
      }
    }
    if(awn == true) {
      if(any) {
        ind = true;
      }
      nt = false;
      any = true;
    }

    bool wan = true;
    TIMES(i, sz - 1) {
      if(wt[i] < wt[i+1] or (wt[i] == wt[i+1] and age[i] < age[i+1]) or (wt[i] == wt[i+1] and age[i] == age[i+1] and name[i] < name[i+1]) ) {
      }else {
        wan = false;
        break;
      }
    }
    if(wan == true) {
      if(any) {
        ind = true;
      }
      nt = false;
      any = true;
    }

    bool wna = true;
    TIMES(i, sz - 1) {
      if(wt[i] < wt[i+1] or (wt[i] == wt[i+1] and name[i] < name[i+1]) or (wt[i] == wt[i+1] and name[i] == name[i+1] and age[i] < age[i+1]) ) {
      }else {
        wna = false;
        break;
      }
    }
    if(wna == true) {
      if(any) {
        ind = true;
      }
      nt = false;
      any = true;
    }

    if(nt) return "NOT";
    if(ind) return "IND";
    if(naw) return "NAW";  
    if(nwa) return "NWA";  
    if(anw) return "ANW";  
    if(awn) return "AWN";  
    if(wan) return "WAN";  
    if(wna) return "WNA";  

    return "===";
  }

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// We have a sorted list of customer information. Each customer has an age, a weight,
and a name.  We want to determine the basis on which they were sorted.  We
believe that the customers were sorted based on alphabetical order of names,  ascending order of
ages, and descending order of weights. One of these fields was the primary field, 
used to initially sort the customers. Then one of these fields was used as the
secondary field to break ties between customers that were indistinguishable based
on the primary field.  And finally the remaining field was used to break ties
between customers that had the same values for their primary and secondary fields.

Create a class WhatSort that contains method sortType that is given a vector <string> name,
a vector <int> age, and a vector <int> wt that gives the attributes of the customers. The first elements of name, age, and wt correspond to the first customer in the sorted list of customers, the
second elements to the second customer, etc.
Your method will return a string that tells what sort of sort was used:

    NAW  -- name was the primary, age secondary, weight the final field
    NWA  -- name was the primary, weight secondary, age final
    ANW  -- age was primary, name was secondary, weight final
    AWN  -- age was primary, weight was secondary, name final
    WAN  -- weight primary, age secondary, name final
    WNA  -- weight primary, name secondary, age final
    IND  -- indeterminate: more than one of the above is possible
    NOT  -- none of the above sorting methods was used




DEFINITION
Class:WhatSort
Method:sortType
Parameters:vector <string>, vector <int>, vector <int>
Returns:string
Method signature:string sortType(vector <string> name, vector <int> age, vector <int> wt)


CONSTRAINTS
-name will contain between 1 and 50 elements inclusive
-age and wt will contain the same number of elements as name
-each element in name will contain between 1 and 50 characters inclusive
-each character in each element of name will contain only uppercase letters 'A'-'Z'
-each element of age and wt will be between 1 and 300 inclusive


EXAMPLES

0)
{"BOB","BOB","DAVE","JOE"}
{22, 35, 35, 30}
 {122, 122, 195,  200}

Returns: "IND"


   The ages are not in ascending order and the weights are not in descending order
   so the primary field must be name.  The tie between the 2 BOB's could have been
   broken by increasing age, leaving the weight field as final. But it is also 
   possible that the weight field was secondary, leaving the 2 BOB tie to be 
   resolved by age.  So we cannot determine which of those two sorts was used.



1)
{"BOB","BOB","DAVE","DAVE"}
{22, 35, 35, 30}
 {122, 122, 195,  200}

Returns: "NOT"



   The ages are not in ascending order and the weights are not in descending order
   so the primary field must be name.  There is a tie between the 2 BOB's and
   between the 2 DAVE's. If the secondary field were age, then the DAVE's would
   have been placed in the other order. That is also true if weight were the
   secondary field. So none of the sorts could have been used.


2)
{"BOB","BOB","DAVE","DAVE"}
 {22, 35, 35, 30}
{122, 122, 195,  190}

Returns: "NWA"


   The ages are not in ascending order and the weights are not in descending order
   so the primary field must be name.  Weight as secondary field properly orders
   the 2 DAVE's and leaves the ordering of the 2 BOB's up to the final field.


*/
// END CUT HERE

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"BOB","BOB","DAVE","JOE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {22, 35, 35, 30}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] =  {122, 122, 195,  200}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "IND"; verify_case(0, Arg3, sortType(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"BOB","BOB","DAVE","DAVE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {22, 35, 35, 30}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] =  {122, 122, 195,  200}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "NOT"; verify_case(1, Arg3, sortType(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"BOB","BOB","DAVE","DAVE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] =  {22, 35, 35, 30}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {122, 122, 195,  190}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "NWA"; verify_case(2, Arg3, sortType(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  WhatSort test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
