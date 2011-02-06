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

class Collision {
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// You are working on the backend of a particular system in which you want to assign a unique ID to each client.  However, the system is distributed, and there are a number of components, each of which must be able to assign IDs to clients.  In other words, you want to have each of the components assign the IDs with as little communication between the components as possible.  You have decided that it is more important to keep the system distributed than it is to ensure that all of the clients have unique IDs.  Thus, you are considering having each of the components independently assign IDs randomly from a large pool of possible IDs, and synchronizing the assigned IDs at the end of each day.  In other words, each component will update its list of available IDs at the end of each day, based on the IDs assigned by all of the components.
Now, there are two ways that you can do this.  The first is to have each of the components assign a random ID each time from the list of available IDs obtained at the beginning of each day.  In other words, have components without any memory of which IDs they have assigned during the day, which may assign the same ID more than once during the day.  The second way to assign the IDs is to have the components each remember which IDs they have assigned, so that no component assigns the same ID more than once.  This way, two different components may assign the same ID, but no one component will assign an ID more than once.  Now, it turns out that the first system is slightly cheaper to implement, but it will clearly result in more collisions (a collision occurs when the same ID is assigned to multiple clients).  So, to help decide which system to implement, you want to run a simulation.
Your task is to simulate both systems and figure out the probability that some ID is assigned to more than one client in both of the systems, and then return the difference in the two probabilities.  You will be given an int, ids, which represents the number of IDs in the pool of possible IDs that each component may assign at the beginning of some day (all components draw IDs from the same pool).  You will also be given a vector <int>, assignments, each of whose elements represents the number of IDs that some component assigns during the day.  You are to return a double representing the difference in the probabilities between the two systems.


DEFINITION
Class:Collision
Method:probability
Parameters:vector <int>, int
Returns:double
Method signature:double probability(vector <int> assignments, int ids)


NOTES
-Your result need not be precisely the same as the result shown in the examples.  As long as your result is within 1e-9 of the result in the example, your submission will be evaluated as correct.
-If more IDs are assigned than there are total IDs, return 0, since there must be a collision in this case.


CONSTRAINTS
-ids will be between 1000 and 2147483647, inclusive.
-assignments will contain between 2 and 50 elements, inclusive.
-Each element of assignments will be between 0 and 10,000, inclusive.


EXAMPLES

0)
{20,20}
1000

Returns: 0.2113618990410422

The probability that there will be no collision if the components have memory is about 0.6649899283281026.
The probability that there will be no collision if the components do not have memory is about 0.45362802928706036.

1)
{123,456}
123456

Returns: 0.3769052883184334

2)
{10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000}
2147483647

Returns: 0.0069090268185510555

3)
{1005,1005}
1000

Returns: 0.0

*/
// END CUT HERE

 public:
  double probability(vector <int> assignments, int ids) {
    // -- main code --
    double r0 = has_memory(assignments, ids);
    double r1 = no_memory(assignments, ids);

    return r0 - r1;	
  }

  double no_memory(vector<int> assignments, int ids) {
    double r = 1.0;
    vector<double> prob;
    int assigned = 0;
    for(int i = 0; i < static_cast<int>(assignments.size()); ++i) {
      if(ids < assignments[i]) {
        return 0;
      }
      for(int k = 0; k < assignments[i]; ++k) {
        prob.push_back(1 - assigned / (double)ids);
        ++assigned;
      }
    }
    for(int m = 0; m < prob.size(); ++m) {
      r *= prob[ prob.size() - m - 1];
    }
    return r;
  }

  double has_memory(vector<int> assignments, int ids) {
    double r = 1.0;
    vector<double> prob;
    int assigned = 0;
    for(int i = 0; i < static_cast<int>(assignments.size()); ++i) {
      if(ids < assignments[i]) {
        return 0;
      }
      for(int k = 0; k < assignments[i]; ++k) {
        prob.push_back(1 - assigned / (double)ids);
      }
      assigned += assignments[i];
    }
    for(int m = 0; m < prob.size(); ++m) {
      r *= prob[ prob.size() - m - 1];
    }
    return r;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {20,20}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000; double Arg2 = 0.2113618990410422; verify_case(0, Arg2, probability(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {123,456}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 123456; double Arg2 = 0.3769052883184334; verify_case(1, Arg2, probability(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2147483647; double Arg2 = 0.0069090268185510555; verify_case(2, Arg2, probability(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1005,1005}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000; double Arg2 = 0.0; verify_case(3, Arg2, probability(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  Collision test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE

