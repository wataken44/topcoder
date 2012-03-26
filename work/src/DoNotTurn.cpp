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

#define MP(y, x) make_pair(yy, xx)

class DoNotTurn {

 public:
  

  int minimumTurns(int N, int X0, int A, int B, int Y0, int C, int D, int P, int M)
  {
    int result = -1;
    // -- main code --

    typedef long long ll;
    
    vector< vector< int > > maze(N, vector<int>(N, 0));

    ll xx = X0 % P;
    ll yy = Y0 % P;
    
    TIMES(i, M) {
      maze[yy % N][xx % N] = 1;
      
      xx = (xx * A + B) % P;
      yy = (yy * C + D) % P;
    }

    maze[yy % N][xx % N] = 1;

    maze[0][0] = 0;
    maze[N-1][N-1] = 0;

    DUMP(maze);
    
    vector< vector< int > > visited(N, vector<int>(N, 0));

    typedef pair<int, pair<int, int> > pipii;
    set< pipii > queue;

      
    TIMES(x, N) {
      if(maze[0][x] == 1) break;
      int y = 0;
      queue.insert(make_pair(y, make_pair(y, x)));
    }

    TIMES(y, N) {
      if(maze[y][0] == 1) break;
      queue.insert(make_pair(0, make_pair(y, 0)));
    }

    while(queue.empty() == false) {
      set< pipii >::iterator it = queue.begin();
      pipii cur = *it;
      int cp = cur.first;
      int cx = cur.second.second;
      int cy = cur.second.first;
      
      queue.erase(it);

      if(cx == N-1 && cy == N-1) {
        return cp;
      }

      if(visited[cy][cx] == 1) continue;
      visited[cy][cx] = 1;

      DOWNTO(x, cx - 1, 0) {
        if(maze[cy][x] == 1) break;
        if(visited[cy][x] == 1) continue;
        queue.insert(make_pair(cp + 1, make_pair(cy, x)));
      }

      UPTO(x, cx + 1, N - 1) {
        if(maze[cy][x] == 1) break;
        if(visited[cy][x] == 1) continue;
        queue.insert(make_pair(cp + 1, make_pair(cy, x)));
      }

      DOWNTO(y, cy - 1, 0) {
        if(maze[y][cx] == 1) break;
        if(visited[y][cx] == 1) continue;
        queue.insert(make_pair(cp + 1, make_pair(y, cx)));
      }

      UPTO(y, cy + 1, N - 1) {
        if(maze[y][cx] == 1) break;
        if(visited[y][cx] == 1) continue;
        queue.insert(make_pair(cp + 1, make_pair(y, cx)));
      }

      
    }
    
    return result;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// There is a NxN maze where each cell contains either a wall or empty space.  You are currently in the top-left cell at coordinates (0, 0) and your goal is to reach the bottom-right cell at coordinates (N-1, N-1) making as few turns as possible.  You can choose any of the four cardinal directions as your starting direction.  Then, from each cell, you can either move forward one cell in your current direction or turn left or right by 90 degrees.  You can only walk into empty cells, not walls.

You are given ints M, X0, Y0, A, B, C and D. Generate lists X and Y, each of length M, using the following recursive definitions:
X[0] = X0 MOD P 
X[i] = (X[i-1]*A+B) MOD P (note that X[i-1]*A+B may overflow a 32-bit integer)

Y[0] = Y0 MOD P 
Y[i] = (Y[i-1]*C+D) MOD P (note that Y[i-1]*C+D may overflow a 32-bit integer) 

Cell (x, y) of the maze contains a wall if and only if it is neither the top-left cell nor the bottom-right cell and there exists a value of i between 0 and M-1, inclusive, such that x=X[i] MOD N and y=Y[i] MOD N.  Return the minimum number of turns you must make to reach the bottom-right cell of this maze, or return -1 if it is impossible.


DEFINITION
Class:DoNotTurn
Method:minimumTurns
Parameters:int, int, int, int, int, int, int, int, int
Returns:int
Method signature:int minimumTurns(int N, int X0, int A, int B, int Y0, int C, int D, int P, int M)


NOTES
-In the statement, "A MOD B" represents the remainder of integer division of A by B. For example, 14 MOD 5 = 4 and 20 MOD 4 = 0.
-The author's solution does not depend on any properties of the pseudorandom generator. It would solve any input of allowed size within the given limits.


CONSTRAINTS
-N will be between 2 and 500, inclusive. 
-M will be between 0 and 1,000,000, inclusive. 
-X0, Y0, A, B, C and D will each be between 0 and 1,000,000, inclusive.
-P will be between 1 and 1,000,000, inclusive.


EXAMPLES

0)
2
0
0
1
0
0
1
10
2

Returns: 1

There are no walls, so you will have to make only one turn.

1)
3
0
1
1
1
1
0
3
3

Returns: -1

The maze in this case looks as follows ('#' denotes a wall, '.' denotes an empty cell):

.#.
.#.
.#.

The target is unreachable.

2)
3
0
1
1
1
1
1
3
3

Returns: 3

The maze in this case looks as follows ('#' denotes a wall, '.' denotes an empty cell):

.#.
..#
#..

There is only one possible path and it requires 3 turns.

3)
10
911111
845499
866249
688029
742197
312197
384409
40

Returns: 12

The maze and the optimal path in it are given below ('#' denotes a wall, '.' denotes an empty cell, the path is illustrated using 'p' characters):

pp##..#..#
#pp..###..
.#p#.....#
##p...#.#.
.#p.##.#..
##p##.#...
#pp####...
pp#.#...#.
p#pppp#...
ppp##ppppp


4)
5
23
2
3
35
5
7
9
3

Returns: 2

The maze in this case looks as follows ('#' denotes a wall, '.' denotes an empty cell):

...#.
.....
...#.
.....
..#..


5)
2
0
0
0
0
0
0
1
0

Returns: 1



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 0; int Arg2 = 0; int Arg3 = 1; int Arg4 = 0; int Arg5 = 0; int Arg6 = 1; int Arg7 = 10; int Arg8 = 2; int Arg9 = 1; verify_case(0, Arg9, minimumTurns(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 0; int Arg2 = 1; int Arg3 = 1; int Arg4 = 1; int Arg5 = 1; int Arg6 = 0; int Arg7 = 3; int Arg8 = 3; int Arg9 = -1; verify_case(1, Arg9, minimumTurns(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 0; int Arg2 = 1; int Arg3 = 1; int Arg4 = 1; int Arg5 = 1; int Arg6 = 1; int Arg7 = 3; int Arg8 = 3; int Arg9 = 3; verify_case(2, Arg9, minimumTurns(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 911111; int Arg2 = 845499; int Arg3 = 866249; int Arg4 = 688029; int Arg5 = 742197; int Arg6 = 312197; int Arg7 = 384409; int Arg8 = 40; int Arg9 = 12; verify_case(3, Arg9, minimumTurns(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_4() { int Arg0 = 5; int Arg1 = 23; int Arg2 = 2; int Arg3 = 3; int Arg4 = 35; int Arg5 = 5; int Arg6 = 7; int Arg7 = 9; int Arg8 = 3; int Arg9 = 2; verify_case(4, Arg9, minimumTurns(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_5() { int Arg0 = 2; int Arg1 = 0; int Arg2 = 0; int Arg3 = 0; int Arg4 = 0; int Arg5 = 0; int Arg6 = 0; int Arg7 = 1; int Arg8 = 0; int Arg9 = 1; verify_case(5, Arg9, minimumTurns(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  DoNotTurn test;

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
