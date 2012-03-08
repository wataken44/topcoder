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

class DNADeletion {

 public:
  int differentProteins(vector <string> DNASequence, vector <string> codonTable)
  {
    int result;
    // -- main code --
    
    return result;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// In genetics, a DNA sequence is a sequence of nucleotides (A, C, G or T).  Some DNA sequences translate to proteins, which are non-empty sequences of amino acids.  Let's examine the DNA translation process::

From left to right, split the DNA sequence into consecutive, non-overlapping triples of nucleotides.  Each triple is called a codon.  There may be one or two nucleotides left over at the end - those should be ignored.  For example, the DNA sequence "ACCTGTACG" will produce the codon sequence "ACC", "TGT", "ACG".  The DNA sequence "ACCTGTAC" will produce the codon sequence "ACC", "TGT" ("AC" is left over and ignored).
You are given a codon table that maps codons to their associated amino acids.  From left to right, look up each codon in the sequence generated above and replace it with its associated amino acid.  Every codon in the sequence must have an associated amino acid - otherwise, the DNA sequence does not translate to a protein.  For example, if "ACC" and "ACG" each map to threonin ("thr") and "TGT" maps to cysteine ("cys"), the DNA sequence "ACCTGTACG" will translate to the protein "thr cys thr".

Sometimes, after replication, one or more nucleotides in a DNA sequence go missing.  This situation is called deletion.  After a deletion, a DNA sequence can become any of its subsequences.  For example, "ACTG" may become "ACG" or "CG".

You are given a vector <string> DNASequence containing a DNA sequence.  Concatenate the elements of DNASequence to obtain the DNA sequence.  You are also given a vector <string> codonTable containing the codon table.  Each element is formatted "CODON AMINOACID" (quotes for clarity), where AMINOACID is the name of the amino acid associated with codon CODON.  Compute the number of different possible proteins that the given DNA sequence can translate to after undergoing zero or more deletions.  Since this number can be quite large, return its value modulo 1000000007.  Remember that only nonempty amino acid sequences are considered proteins.


DEFINITION
Class:DNADeletion
Method:differentProteins
Parameters:vector <string>, vector <string>
Returns:int
Method signature:int differentProteins(vector <string> DNASequence, vector <string> codonTable)


CONSTRAINTS
-DNASequence will contain between 1 and 50 elements, inclusive.
-Every element of DNASequence will contain between 1 and 50 characters, inclusive.
-Every element of DNASequence will contain only characters 'A', 'C', 'T', 'G'.
-codonTable will contain between 1 and 50 elements, inclusive.
-Every element of codonTable will contain a codon, followed by a single space, followed by an amino acid.
-Every codon in codonTable will contain exactly 3 characters.
-Every codon in codonTable will contain only characters 'A', 'C', 'T', 'G'.
-Every codon in codonTable will be unique.
-Every amino acid in codonTable will contain between 1 and 20 characters.
-Every amino acid in codonTable will contain only letters ('a'-'z', 'A'-'Z').


EXAMPLES

0)
{"ACTG"}
{"ACT gua", "ACG cys", "ATG leu", "CTG thr"}

Returns: 4

You can get proteins:
"gua" (deletion of 'G' or no deletion),
"cys" (deletion of 'T'),
"leu" (deletion of 'C'),
"thr" (deletion of 'A').
Other deletions do not result in proteins.

1)
{"AAACCC"}
{"AAA thr", "CCC cys"}

Returns: 3

You can get proteins: "thr", "cys" and "thr cys".

2)
{"AAATCCC"}
{"AAA gua","TCC dop","AAT dop","CCC gua"}

Returns: 5

You can get proteins:
"gua",
"dop",
"gua dop" (from sequence "AAATCC"),
"dop gua" (from sequence "AATCCC"),
"gua gua" (from sequence "AAACCC").

3)
{"ATGCGCATTAACCTCCTACCATGGAAGGGACGTAACCCGGCAATTTGATC",
 "CTGATGACGGCATAAGCTACCCCTAGAGGTAAAAATGCATACTGCGTGCT",
 "ATGCAG"}
{"AAC RpjZt","AAT ZeiC","GCA ChZwh","TCC RpjZt","GAA I",
 "TAG ZeiC","CTG dVK","GAG ZeiC","GTG I","AAG q","ATT dVK",
 "AGA cJEjM","GGG KONUd","GTC ZRV","GGC ZeiC","TTA KONUd",
 "GAC q","CCA q","GCC ZRV","GCG RpjZt","CCT ZRV","ATG dVK",
 "ATC ChZwh","CTC cJEjM","CCC q","ATA dWjz","TTG DkEG",
 "CAG q","CAA ZRV","ACT dVK","TCG dVK","ACC I","CGC dVK"}

Returns: 455985264

Be sure to concatenate the elements of DNASequence.

*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"ACTG"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"ACT gua", "ACG cys", "ATG leu", "CTG thr"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(0, Arg2, differentProteins(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"AAACCC"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"AAA thr", "CCC cys"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(1, Arg2, differentProteins(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"AAATCCC"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"AAA gua","TCC dop","AAT dop","CCC gua"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(2, Arg2, differentProteins(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"ATGCGCATTAACCTCCTACCATGGAAGGGACGTAACCCGGCAATTTGATC",
 "CTGATGACGGCATAAGCTACCCCTAGAGGTAAAAATGCATACTGCGTGCT",
 "ATGCAG"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"AAC RpjZt","AAT ZeiC","GCA ChZwh","TCC RpjZt","GAA I",
 "TAG ZeiC","CTG dVK","GAG ZeiC","GTG I","AAG q","ATT dVK",
 "AGA cJEjM","GGG KONUd","GTC ZRV","GGC ZeiC","TTA KONUd",
 "GAC q","CCA q","GCC ZRV","GCG RpjZt","CCT ZRV","ATG dVK",
 "ATC ChZwh","CTC cJEjM","CCC q","ATA dWjz","TTG DkEG",
 "CAG q","CAA ZRV","ACT dVK","TCG dVK","ACC I","CGC dVK"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 455985264; verify_case(3, Arg2, differentProteins(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  DNADeletion test;

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
