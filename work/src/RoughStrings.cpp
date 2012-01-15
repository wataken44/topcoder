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
#ifndef DUMP
#define DUMP(x) cout << x << endl; 
#endif

class RoughStrings {

 public:

  int roughness(string s)
  {
    vector<int> cnt;
    count(s, cnt);

    int min_c = INT_MAX;
    int max_c = 0;

    FOR(k, 0, cnt.size()) {
      if(cnt[k] == 0) continue;
      min_c = min(cnt[k], min_c);
      max_c = max(cnt[k], max_c);
    }
    //DUMP(s); DUMP(count);
    //DUMP(max_c); DUMP(min_c);
    return max_c - min_c;
  }

  void count(string s, vector<int>& ret)
  {
    ret = vector<int>('z' + 1, 0);
    FOR(i, 0, s.size()) {
      ++ret[s[i]];
    }
  }

  class CLess {
   public:
    CLess(vector<int>& cnt) : m_cnt(cnt) {};
    bool operator()(const char& lhs, const char& rhs)
    {
      if(m_cnt[lhs] != m_cnt[rhs]) {
        return m_cnt[lhs] < m_cnt[rhs];
      } else {
        return lhs < rhs;
      }
    }
   private:
    vector<int>& m_cnt;
  };
  
  int minRoughness(string s, int n)
  {
    int ret = roughness(s);
    vector<int> cnt; 
    count(s, cnt);

    sort(s.begin(), s.end(), CLess(cnt));

    int sz = s.size();
    UPTO(i, 0, n) {
      UPTO(j, 0, n-i) {
        if(sz - j <= 0) break;
        string ns = s.substr(i, sz - j);
        int r = roughness(ns);
        ret = min(ret, r);
        cout << r << " " << ns << endl;
      }
    }

    return ret;
  }

};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
