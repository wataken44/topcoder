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

class RelativePath {

 public:
  void split(string str, char delim, vector<string>& result)
  {
    int pos = 0;

    if(str[pos] == delim) pos += 1;

    string buf;
    while(pos < static_cast<int>(str.size())) {
      if(str[pos] != delim) {
        buf += str[pos];
      }else {
        result.push_back(buf);
        buf = "";
      }
      ++pos;
    }

  }

  string makeRelative(string path, string currentDir)
  {
    string result;
    // -- main code --

    if(currentDir[currentDir.size()-1] != '/') {
      currentDir += '/';
    }
    
    int csz = currentDir.size();
    int psz = path.size();
    int cp = csz - 1;
    
    while(cp >= 0) {
      if(currentDir[cp] == '/') {
        if(cp != csz - 1) {
          result += "../";
        }
        if(psz > cp) {
          if(path.substr(0, cp+1) == currentDir.substr(0, cp+1)) {
            result += path.substr(cp + 1, psz - cp - 1); 
            break;
          }
        }
      }
      --cp;
    }
    
    return result;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// In a typical filesystem, there are files, representing complete units of data.  These files are contained in directories, and these directories, in turn, may be contained in other directories, and so on. A path is a pointer to a specific file or directory in this stucture. Most Unix-like OSes have a single root directory, that has all other directories and files directly or indirectly (via other directories) inside it. Such OSes use the following structure for file paths:
/<directory-name>/<directory-name>/.../<directory-name>/<file-name>
and, correspondingly, the following structure for directory paths:
/<directory-name>/<directory-name>/.../<directory-name>
For example, "/etc/passwd" (all quotes here and below are for clarity only) points to a file named "passwd" inside a directory named "etc" inside the root directory. Other valid file names might be "/home/user/pictures/me" or just "/file". In this problem, we allow only nonempty sequences of lowercase letters ('a'-'z') as file and directory names.
A special case is the root directory itself, which is referred to as just "/".
When a user works with such an OS, one of the directories is chosen as 'current'. Such a designation allows her to refer to the files in that directory without specifying the full path to the current directory. For example, if the current directory is "/home/user/pictures", then one might refer to the file "/home/user/pictures/me" as just "me" (note that such a short form can be easily spotted by the absence of the starting '/' character). Moreover, the files in subdirectories of the current directory can also be referred to in a short manner: "/home/user/pictures/others/she" can be referred to as "others/she".
And even more exciting is the ability to have short references for files outside the current folder. More specifically, ".." means "the directory one level above the current directory", "../.." means "the directory two levels above the current directory", and so on. For example, if the current directory is "/home/user/pictures", and you want to refer to "/home/top/data/file", you can express that as "../../top/data/file".
Given a string path, indicating the complete path to the file that needs to be referred to, and a string currentDir, indicating the current directory, return a String that contains the relative path to that file according to the above rules. You should choose the shortest of all possible relative paths (for example, if the current directory is "/home/user/pictures", you should use "../movies/title" and not "../../user/movies/title" as a pointer to "/home/user/movies/title").
Some files and/or directories may have coinciding names, but it is impossible to have two files or two directories or a file and a directory with the same name inside the same directory, so file and directory paths are not ambiguous. It is guaranteed that the given data describes a valid file and directory according to the above rules. In particular, they will not contradict - for example, path="/home/user/some" and currentDir="/home/user/some/other" are a contradiction, since it implies that a file and a directory both named "some" exist inside the directory "/home/user".

DEFINITION
Class:RelativePath
Method:makeRelative
Parameters:string, string
Returns:string
Method signature:string makeRelative(string path, string currentDir)


NOTES
-A file name never ends with the '/' character.  A directory name never ends with the '/' character, with the exception of the root directory, which is specified as just "/".


CONSTRAINTS
-path and currentDir will each contain between 1 and 50 characters, inclusive.
-Each character of path and currentDir will be '/', or a lowercase letter ('a'-'z').
-path will contain a valid file path according to the above rules.
-currentDir will contain a valid directory path according to the above rules.
-path and currentDir will not contradict (see the last paragraph of the statement).


EXAMPLES

0)
"/home/top/data/file"
"/home/user/pictures"

Returns: "../../top/data/file"

The example from the problem statement.

1)
"/home/user/movies/title"
"/home/user/pictures"

Returns: "../movies/title"

And another one from the statement.

2)
"/file"
"/"

Returns: "file"

Remember about the root directory.

3)
"/a/b/a/b/a/b"
"/a/b/a/a/b/a/b"

Returns: "../../../../b/a/b"

Some file and directory names may be the same.

4)
"/root/root/root"
"/root"

Returns: "root/root"

Some files and/or directories can be named "root" - but that doesn't make them root directories.

*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "/home/top/data/file"; string Arg1 = "/home/user/pictures"; string Arg2 = "../../top/data/file"; verify_case(0, Arg2, makeRelative(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "/home/user/movies/title"; string Arg1 = "/home/user/pictures"; string Arg2 = "../movies/title"; verify_case(1, Arg2, makeRelative(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "/file"; string Arg1 = "/"; string Arg2 = "file"; verify_case(2, Arg2, makeRelative(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "/a/b/a/b/a/b"; string Arg1 = "/a/b/a/a/b/a/b"; string Arg2 = "../../../../b/a/b"; verify_case(3, Arg2, makeRelative(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "/root/root/root"; string Arg1 = "/root"; string Arg2 = "root/root"; verify_case(4, Arg2, makeRelative(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  RelativePath test;

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
