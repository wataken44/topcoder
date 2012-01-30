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
#include <iomanip>

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

class ThreePhotos {

 public:
  int n;

  int id(int x, int y, int z)
  {
    return z * n * n + y * n + x;
  }

  void dump(vector<int>& cube)
  {
    FOR(z, 0, n) {
      FOR(y, 0, n) {
        FOR(x, 0, n) {
          cout << cube[id(x,y,z)] << " ";
        }
        cout << endl;
      }
      cout << endl;
    }
  }
  
  int removeCubes(vector <string> A, vector <string> B, vector <string> C)
  {
    n = A.size();

    vector<int> cube(n * n * n, 1);

    FOR(y, 0, n) {
      FOR(x, 0, n) {
        if(A[x][y] == 'N') {
          FOR(z, 0, n) {
            cube[id(x,y,z)] = 0;
          }
        }
      }
    }

    FOR(z, 0, n) {
      FOR(y, 0, n) {
        if(C[y][z] == 'N') {
          FOR(x, 0, n) {
            cube[id(x,y,z)] = 0;
          }
        }
      }
    }

    FOR(x, 0, n) {
      FOR(z, 0, n) {
        if(B[x][z] == 'N') {
          FOR(y, 0, n) {
            cube[id(x,y,z)] = 0;
          }
        }
      }
    }

    /*
      check
     */
    // cerr << "A" << endl;
    FOR(y, 0, n) {
      FOR(x, 0, n) {
        if(A[x][y] == 'Y') {
          bool ok = false;
          FOR(z, 0, n) {
            if(cube[id(x,y,z)] != 0) ok = true;
          }
          if(!ok) {
            dump(cube);
            return -1;
          }
        }
      }
    }

    // cerr << "B" << endl;
    FOR(z, 0, n) {
      FOR(y, 0, n) {
        if(C[y][z] == 'Y') {
          bool ok = false;
          FOR(x, 0, n) {
            if(cube[id(x,y,z)] != 0) ok = true;
          }
          if(!ok) return -1;
        }
      }
    }

    // cerr << "C" << endl;
    FOR(x, 0, n) {
      FOR(z, 0, n) {
        if(B[x][z] == 'Y') {
          bool ok = false;
          FOR(y, 0, n) {
            if(cube[id(x,y,z)] != 0) ok = true;
          }
          if(!ok) return -1;
        }
      }
    }

    
    // DUMP(cube);
    
    int result = 0;
    // -- main code --

    FOR(i, 0, cube.size()) {
      if(cube[i] == 0) ++result;
    }
    
    return result;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// A cube of size NxNxN was divided into small cubes of size 1x1x1.  Then, some of the small cubes were removed, and three photos of the large cube were taken.  You are given these three photos in the vector <string>s A, B and C.  Character y of element x of A will be 'Y' if at least one small cube with x-coordinate x and y-coordinate y wasn't removed, or 'N' otherwise.  Character z of element x of B will be 'Y' if at least one small cube with x-coordinate x and z-coordinate z wasn't removed, or 'N' otherwise.  Character z of element y of C will be 'Y' if at least one small cube with y-coordinate y and z-coordinate z wasn't removed, or 'N' otherwise.  Return the minimal number of small cubes which could've been removed to result in those three photos.  If there is no way the three photos can be valid, return -1 instead.

DEFINITION
Class:ThreePhotos
Method:removeCubes
Parameters:vector <string>, vector <string>, vector <string>
Returns:int
Method signature:int removeCubes(vector <string> A, vector <string> B, vector <string> C)


CONSTRAINTS
-N will be between 1 and 50, inclusive. 
-A,  B and C will each contain exactly N elements. 
-Each element of A,  B and C will contain exactly N characters. 
-Each element of A,  B and C will contain only 'Y' or 'N' characters. 


EXAMPLES

0)
{"YY","YY"}
{"YY","YY"}
{"YY","YY"}

Returns: 0

Remove no cubes.

1)
{"NNN","NNN","NNN"}
{"NNN","NNN","NNN"}
{"NNN","NNN","NNN"}

Returns: 27

You will have to remove all cubes.

2)
{"NNNNN","NNNNN","NNNNN","YYNNN","NNNNN"}
{"NNNNN","NNNNN","NNNNN","NNYNY","NNNNN"}
{"NNYNN","NNNNY","NNNNN","NNNNN","NNNNN"}

Returns: 123

3)
{"YY","YY"}
{"YY","YY"}
{"YN","YN"}

Returns: -1



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"YY","YY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"YY","YY"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"YY","YY"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(0, Arg3, removeCubes(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"NNN","NNN","NNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NNN","NNN","NNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"NNN","NNN","NNN"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 27; verify_case(1, Arg3, removeCubes(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"NNNNN","NNNNN","NNNNN","YYNNN","NNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NNNNN","NNNNN","NNNNN","NNYNY","NNNNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"NNYNN","NNNNY","NNNNN","NNNNN","NNNNN"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 123; verify_case(2, Arg3, removeCubes(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"YY","YY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"YY","YY"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"YN","YN"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -1; verify_case(3, Arg3, removeCubes(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  ThreePhotos test;

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
