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

class RedBlack {
 public:
  int numTwists(vector <int> keys) {
    // -- main code --
    
    return ;	
  }

  struct node {
    node* left;
    node* right;
    int value;
  };
  
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
Balanced binary search trees are among the most studied data structures in computer science.
However, implementing them can be rather tricky.  Most designs of balanced binary search trees
are based on the same four basic transformations--left single rotations, right single rotations, left double
rotations, and right double rotations--but differ in exactly when and where these transformations are
applied.



Red-black trees are one of the most popular kinds of balanced binary search trees.  In a red-black tree, every node is 
colored either red or black, and no red node is allowed to have a red parent.  In addition, every path from the root to a leaf contains
the same number of black nodes.  Most books on data structures contain a description 
of how to maintain the red-black properties, based on the usual four rotations.  In this problem, we will consider a simpler
scheme for maintaining red-black trees, based on a single transformation, called a twist.



Inserting a new key into a red-black tree proceeds in two phases: a search phase followed by a rebalancing phase.  In the search phase,
you start at the root and walk down the tree, going left when the new key is smaller than the key at the current node and going right when the new key is larger than the key at the current node.  (You may assume the new key will not be equal to the key at the current
node.)  When the search reaches the bottom of the tree, the new key is added as a new child of the last node in the search path, on the
left or right, as appropriate.  The new node is always a leaf and is always colored red.



If the new node's parent is also red, then we now have a violation of the rule that no red node may have a red parent.  The job of
the rebalancing phase is to detect such situations, and to correct them using a transformation called a twist.  A twist involves the red node, its red parent, and its black grandparent.  There are four possible configurations for these three nodes, shown below:


     (Blk) z         (Blk) z               x (Blk)         x (Blk)
          / \             / \             / \             / \
   (Red) y   T4    (Red) x   T4         T1   z (Red)    T1   y (Red)
        / \             / \                 / \             / \
 (Red) x   T3         T1   y (Red)   (Red) y   T4         T2   z (Red)
      / \                 / \             / \                 / \
    T1   T2             T2   T3         T2   T3             T3   T4

where T1, T2, T3, and T4 are subtrees (possibly empty).
All four configurations are rewritten to exactly the same shape:

                             (Red) y
                                  / \
                                 /   \
                          (Blk) x     z (Blk)
                               / \   / \
                              T1 T2 T3 T4  

After the twist, y's parent may be red, so the process continues until there are no more positions where a twist can be 
applied.  Note that there will never be more than one red node with a red parent at the same time.


There is one last case to worry about.  It is possible to have a red node with a red parent, but with no grandparent because the parent
is the root.  A twist cannot be applied without the grandparent, so to protect against this case, we color the root black at the
end of every insert.



Given a sequence of numbers to be inserted one at a time into an initially empty red-black tree, your task is to determine the 
total number of twists that occur during the inserts.



As an example, consider the steps involved in inserting the numbers {1,2,3}.  Initially the tree is empty, so when we
insert the 1 node, it becomes the new root.  The new node starts out red, but, because it is the root, it is recolored black 
at the end of the insert.  The tree now looks like


            1 (Blk)

When we insert the 2 node, it goes on the right.  The new node is colored red.

            1 (Blk)
             \
              2 (Red)

When we insert the 3 node, it again goes on the right and is colored red.

            1 (Blk)
             \
              2 (Red)
               \
                3 (Red)

The new node starts out red, but it has a red parent, so a twist is necessary.  After the twist, the tree looks like

            2 (Red)
           / \
    (Blk) 1   3 (Blk)

However, the root is recolored black at the end of every insert, so the final tree is

            2 (Blk)
           / \
    (Blk) 1   3 (Blk)

Altogether, this series of inserts requires 1 twist, so your method should return 1.

DEFINITION
Class:RedBlack
Method:numTwists
Parameters:vector <int>
Returns:int
Method signature:int numTwists(vector <int> keys)


CONSTRAINTS
-keys contains between 1 and 50 elements, inclusive.
-keys is a permutation of the numbers between 1 and n, inclusive, where n is the length of keys.


EXAMPLES

0)
{ 1,2,3 }

Returns: 1

The example above.

1)
{ 1,2,3,4,5,6,7 }

Returns: 4

One twist happens when we insert the 3, and another happens when we insert the 5, leaving

            2 (Blk)
           / \
    (Blk) 1   4 (Red)
             / \
      (Blk) 3   5 (Blk)

When we insert the 7, we initially get

            2 (Blk)
           / \
    (Blk) 1   4 (Red)
             / \
      (Blk) 3   5 (Blk)
                 \
                  6 (Red)
                   \
                    7 (Red)

but the 7 node has a red parent, so we do a twist

            2 (Blk)
           / \
    (Blk) 1   4 (Red)
             / \
      (Blk) 3   6 (Red)
               / \
        (Blk) 5   7 (Blk)

Now, the 6 node has a red parent, so we do another twist.

            4 (Red)
           / \
          /   \
   (Blk) 2     6 (Blk)
        / \   / \
       1   3 5   7   <--- all four leaves are black

At the end of the insert, we recolor the root black.

            4 (Blk)
           / \
          /   \
   (Blk) 2     6 (Blk)
        / \   / \
       1   3 5   7   <--- all four leaves are black

Altogether, 4 twists were required.

2)
{ 7,1,4,6,3,5,2 }

Returns: 3

3)
{ 5,10,15,14,3,4,11,2,1,12,6,9,7,13,8 }

Returns: 11

4)
{ 6,8,10,12,4,2,18,14,16,19,7,15,9,17,13,5,11,3,1 }

Returns: 5

*/
// END CUT HERE

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 1,2,3 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, numTwists(Arg0)); }
	void test_case_1() { int Arr0[] = { 1,2,3,4,5,6,7 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(1, Arg1, numTwists(Arg0)); }
	void test_case_2() { int Arr0[] = { 7,1,4,6,3,5,2 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(2, Arg1, numTwists(Arg0)); }
	void test_case_3() { int Arr0[] = { 5,10,15,14,3,4,11,2,1,12,6,9,7,13,8 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 11; verify_case(3, Arg1, numTwists(Arg0)); }
	void test_case_4() { int Arr0[] = { 6,8,10,12,4,2,18,14,16,19,7,15,9,17,13,5,11,3,1 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(4, Arg1, numTwists(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  RedBlack test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
