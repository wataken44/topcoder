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

class UFT {
 public:
  UFT(int size) : m_body(size, -1) {}

  int GetRoot(int n)
  {
    while(true) {
      int p = m_body[n];
      if(p < 0) return n;
      if(m_body[p] >= 0) m_body[n] = m_body[p];
      n = p;
    }
    return -1;
  }

  void Unite(int n, int m) {
    int pn = GetRoot(n);
    int pm = GetRoot(m);

    if(pn == pm) return;

    if(m_body[pn] < m_body[pm]) swap(pn, pm);
    m_body[pn] += m_body[pm];
    m_body[pm] = pn;
  }

  int GetParent(int n)
  {
    return m_body[n];
  }

  int GetSize(int n)
  {
    return -m_body[GetRoot(n)];
  }

  void Optimize()
  {
    FOR(i, 0, m_body.size()) {
      if(m_body[i] >= 0) {
        m_body[i] = GetRoot(i);
      }
    }
  }

  void Dump()
  {
    DUMP(m_body);
  }
 private:
  vector<int> m_body;
};

class NetworkSecurity {

 public:
  int secureNetwork(vector <string> clientCable, vector <string> serverCable)
  {
    int csz = clientCable.size();
    int ssz = serverCable[0].size();

    int result = 0;

    UFT uft(csz);
    
    FOR(x, 0, csz) {
      FOR(y, 0, csz) {
        if(clientCable[y][x] == 'N') continue;
        uft.Unite(x, y);
        //DUMP(x);DUMP(y);uft.Dump();
      }
    }

    uft.Optimize();
    //uft.Dump();

    //DUMP(csz);DUMP(ssz);
    
    FOR(s, 0, ssz) {
      set<int> connected;
      FOR(c, 0, csz) {
        if(serverCable[c][s] == 'Y') {
          int g = uft.GetRoot(c);
          if(find(connected.begin(), connected.end(), g) == connected.end()) {
            connected.insert(g);
            ++result;
          }
        }
      } 
      //DUMP(connected);
    }// -- main code --
    
    return result;	
  }

// BEGIN CUT HERE
  void debug()
  {
    string Arr0[] = {"N"};
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    string Arr1[] = {"NYYYYYYYY"};
    vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arg2 = 8; verify_case(10, Arg2, secureNetwork(Arg0, Arg1));
  }
/*
// PROBLEM STATEMENT
// NOTE: This problem statement contains images that may not display properly if viewed outside of the applet. 


TopCoder Security Agency (TSA) has been hired to secure a network system. In this network, there are several client computers and server computers which for the sake of conciseness will be called clients and servers, respectively. There are several one directional data cables in the network: between clients and from clients to servers. A data path in the network is defined as a series of 2 or more computers C1, C2, C3, ..., CN such that for each i between 1 and N-1, there exists a data cable from Ci to C(i+1). To avoid infinite data loops, the network is acyclic, that is, there does not exist a data path that originates and ends at the same computer. A client C is connected to a server S if there exists a data path originating at C and ending at S.


TSA is going to secure the network by installing data gates on some of the cables. The network is said to be secure if for every pair of connected client and server, there exists at least one data path between them which uses at least one cable on which a data gate is installed.


There are N clients numbered 0 through N-1 and M servers numbered 0 through M-1. The data cables are given as vector <string> clientCable and vector <string> serverCable. The j-th character of the i-th element of clientCable is 'Y' if there exists a data cable from client i to client j, or 'N' otherwise. The j-th character of the i-th element of serverCable is 'Y' if there exists a data cable from client i to server j, or 'N' otherwise.


Return the minimum number of data gates that needs to be installed to make the network secure.

DEFINITION
Class:NetworkSecurity
Method:secureNetwork
Parameters:vector <string>, vector <string>
Returns:int
Method signature:int secureNetwork(vector <string> clientCable, vector <string> serverCable)


CONSTRAINTS
-clientCable will contain between 1 and 50 elements, inclusive.
-Each element of clientCable will contain exactly N characters, where N is the number of elements in clientCable.
-Each character in clientCable will be 'Y' or 'N'.
-The i-th character of the i-th element of clientCable will be 'N'.
-serverCable will contain the same number of elements as clientCable.
-Each element of serverCable will contain between 1 and 50 characters, inclusive.
-All elements of serverCable will contain the same number of characters.
-Each character in serverCable will be 'Y' or 'N'.
-The network will be acyclic as described in the problem statement.


EXAMPLES

0)
{"NYN"
,"NNN"
,"NYN"}
{"YN"
,"YN"
,"NY"}

Returns: 2



All three clients are connected to server 0 and only client 2 is connected to server 1. If the data gates are installed on the two cables as shown in the picture above, then each of the following data paths between a client and server will contain at least one cable on which a data gate is installed: 

C0->C1->S0
C1->S0
C2->C1->S0
C2->S1


1)
{"NN"
,"NN"}
{"NNN"
,"NNN"}

Returns: 0

No client is connected to any server and hence the network is secure.

2)
{"NYNN"
,"NNNN"
,"NNNY"
,"NNNN"}
{"YYN"
,"NNN"
,"NNY"
,"NNN"}

Returns: 3



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"NYN"
,"NNN"
,"NYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"YN"
,"YN"
,"NY"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(0, Arg2, secureNetwork(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"NN"
,"NN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NNN"
,"NNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(1, Arg2, secureNetwork(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"NYNN"
,"NNNN"
,"NNNY"
,"NNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"YYN"
,"NNN"
,"NNY"
,"NNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(2, Arg2, secureNetwork(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  NetworkSecurity test;

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
