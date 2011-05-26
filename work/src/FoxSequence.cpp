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
#define DUMP(x) std::cerr << #x << " = " << x << std::endl;

using namespace std;

class FoxSequence {
 public:
  string isValid(vector <int> seq) {
    // -- main code --

    int n = seq.size();

    int cda = seq[1] - seq[0];
    if(not cda > 0) return "NO";
    
    FOR(a, 1, n - 1) {
      bool valid_a = (a >= 1);
      UPTO(aa, 1, a) {
        if(seq[aa] - seq[aa-1] != cda) {
          valid_a = false;
          break;
        }
      }
      if(not valid_a) continue;
      //DUMP(a);
      //DUMP(seq[a]);
      
      FOR(b, a + 1, n - 1) {
        int cdb = seq[a+1] - seq[a];
        if(not cdb < 0) break;

        bool valid_b = (b > a + 1);
        UPTO(bb, a + 1, b) {
          if(seq[bb] - seq[bb-1] != cdb) {
            valid_b = false;
            break;
          }
        }
        if(not valid_b) continue;
        //DUMP(b);
        //DUMP(seq[b]);
        
        FOR(c, b, n - 1) {
          bool valid_c = true;
          UPTO(cc, b, c) {
            if(seq[cc] != seq[b]) {
              valid_c = false;
              break;
            }
          }
          if(not valid_c) continue;
          //DUMP(c);
          //DUMP(seq[c]);
          
          FOR(d, c + 1, n - 1) {
            int cdd = seq[c+1] - seq[c];
            if(not cdd > 0) break;
            
            bool valid_d = (d > c + 1);
            UPTO(dd, c + 1, d) {
              if(seq[dd] - seq[dd-1] != cdd) {
                valid_d = false;
                break;
              }
            }
            if(not valid_d) continue;

            int cde = seq[d+1] - seq[d];
            if(not cde < 0) break;

            //DUMP(d);
            //DUMP(seq[d]); 
            //DUMP(cde);
            
            bool valid_e = (n - 1 > d + 1);
            UPTO(ee, d + 1, n - 1) {
              if(seq[ee] - seq[ee-1] != cde) {
                valid_e = false;
                break;
              }
            }
            if(not valid_e) continue;
            //DUMP(d);
            
            return "YES";
          }
        }
      }
    }
    
    return "NO";	
  }

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Fox Ciel likes sequences.  One day, she invented a new type of sequence and named it the fox sequence.  A sequence seq containing N elements is called a fox sequence if and only if there exist four integers a, b, c and d such that 0 < a < b <= c < d < N-1 and the following five conditions are met:

seq[0], seq[1], ... , seq[a] forms an arithmetic progression with a positive common difference.  An arithmetic progression is a sequence where the difference between successive elements is equal.  The difference between successive elements is called the common difference.  Note that 0 is neither positive nor negative.
seq[a], seq[a+1], ... , seq[b] forms an arithmetic progression with a negative common difference.
seq[b], seq[b+1], ... , seq[c] are all equal.
seq[c], seq[c+1], ... , seq[d] forms an arithmetic progression with a positive common difference.
seq[d], seq[d+1], ... , seq[N-1] forms an arithmetic progression with a negative common difference.


In the following image, the top 3 sequences are fox sequences, while the bottom 3 sequences are not:



You are given a sequence seq.  Return "YES" if it is a fox sequence, or "NO" if it is not (all quotes for clarity).

DEFINITION
Class:FoxSequence
Method:isValid
Parameters:vector <int>
Returns:string
Method signature:string isValid(vector <int> seq)


CONSTRAINTS
-seq will contain between 1 and 50 elements, inclusive.
-Each element of seq will be between 1 and 2,000, inclusive.


EXAMPLES

0)
{1,3,5,7,5,3,1,1,1,3,5,7,5,3,1}


Returns: "YES"

This is the top-left sequence of the image shown in the statement.  The next five examples are also from that image.

1)
{1,2,3,4,5,4,3,2,2,2,3,4,5,6,4}


Returns: "YES"



2)
{3,6,9,1,9,5,1}


Returns: "YES"



3)
{1,2,3,2,1,2,3,2,1,2,3,2,1}


Returns: "NO"



4)
{1,3,4,3,1,1,1,1,3,4,3,1}


Returns: "NO"



5)
{6,1,6}


Returns: "NO"



*/
// END CUT HERE

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,3,5,7,5,3,1,1,1,3,5,7,5,3,1}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(0, Arg1, isValid(Arg0)); }
	void test_case_1() { int Arr0[] = {1,2,3,4,5,4,3,2,2,2,3,4,5,6,4}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(1, Arg1, isValid(Arg0)); }
	void test_case_2() { int Arr0[] = {3,6,9,1,9,5,1}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(2, Arg1, isValid(Arg0)); }
	void test_case_3() { int Arr0[] = {1,2,3,2,1,2,3,2,1,2,3,2,1}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(3, Arg1, isValid(Arg0)); }
	void test_case_4() { int Arr0[] = {1,3,4,3,1,1,1,1,3,4,3,1}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(4, Arg1, isValid(Arg0)); }
	void test_case_5() { int Arr0[] = {6,1,6}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(5, Arg1, isValid(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  FoxSequence test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
