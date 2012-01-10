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

class SMBus {
 public:
  int transmitTime(vector <string> messages, vector <int> times) {
    // -- main code --

    int msz = messages.size();
    int total_time = 0;
    int transmitting = 0;
    
    vector<bool> done(msz, false);
    vector<bool> stopping(msz, false);
    
    while(true) {
      // break condition
      bool d = true;
      TIMES(i, msz) {
        if(done[i] == false) {
          d = false;
        }
      }
      if(d) break;

      // time consumption
      int tc = 0;
      TIMES(i, msz) {
        if(done[i] == false and stopping[i] == false) {
          tc = max(tc, times[i]);
        }
      }

      // collision detect and stop?
      char minb = '9' + 1;
      FOR(i, 0, msz) {
        if(transmitting < (int)messages[i].size()) {
          minb = min(minb, messages[i][transmitting]);
        }
      }
      FOR(i, 0, msz) {
        if(transmitting < (int)messages[i].size() and minb < messages[i][transmitting]) {
          stopping[i] = true;
        }
      }

      // update;
      ++transmitting;
      total_time += tc;

      TIMES(i, msz) {
        if(done[i] == true and stopping[i] == false and (int)messages[i].size() == transmitting) {
          transmitting = 0;
          done[i] = true;
          TIMES(j, msz) {
            stopping[j] = false;
          }
          break;
        }
      }

    }
    
    return total_time;	
  }

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
On most modern PC systems, there is a 2-wire bus called the System Management Bus, or SMBus, which is based on the I2C protocol.  This bus is used to talk to multiple devices on the system such as temperature sensors, or batteries.  The most significant achievement of the I2C protocol is that it requires no more than 2 wires, and is not susceptible to collisions (unlike other hardware protocols, like ethernet).  Collisions occur when two masters (devices which transmit messages) try to transmit at the same time and the resulting data is invalid.  For I2C, the first bit transmitted by one master which is different than the bit transmitted by another master causes an "arbitration" to occur.  The data being transmitted on the bus is the logic and-ed value of all the data being transmitted by the masters.  Therefore, if one master is transmitting a '1' and another is transmitting a '0', the '0' will be transmitted and the '1' will not.  The master transmitting the '1' detects that it is not able to transmit, and stops transmitting.  The arbitration is not detected by the master transmitting the '0', or by the slave receiving the '0', so the message can continue without any collisions.



Since '0' bits that occur earlier in messages always win, the master transmitting the lowest byte always wins arbitration.  For example, if one master was transmitting "01234", and another master was transmitting "01245", both masters would transmit the first three bytes, but the first master would win arbitration on the fourth data byte, since '3' is less than '4'.



Multiple masters can start transmissions at the same time, but if a transmission has already started, another master cannot start one in the middle of the transmission.  Therefore, if one master is transmitting "01234", and has already transmitted the '0', another master wanting to transmit "1234" cannot start its transmission until the first master is finished.



The speed of transmission of each master is also allowed to vary.  The speed at which each byte is transferred is determined by the slowest transmitting master.  If a master loses arbitration of the bus, it continues to drive the clock signal (which determines the speed) for the remainder of the current byte, but then stops driving the clock for the rest of the transmission.  In other words, the speed that each byte is transmitted at is determined by the slowest master attempting to transmit during that byte, even if the master loses arbitration during that byte.



Given the description of the I2C protocol above, you are to simulate multiple masters transmitting messages on the bus, and return how long it takes to transmit them.  You will be given a vector <string> messages, where each element is a message to be transmitted by a master device, and the messages consist of numeric digits '0'-'9'.  You will also be given a vector <int> times, where each element is the number of milliseconds it takes for the corresponding master to transmit a byte.  The master transmitting element i of messages is described by element i of times.  Each master that loses arbitration will retry transmitting its message after the current message is finished.  Note that all masters try transmitting their messages at the very beginning of the simulation.


DEFINITION
Class:SMBus
Method:transmitTime
Parameters:vector <string>, vector <int>
Returns:int
Method signature:int transmitTime(vector <string> messages, vector <int> times)


CONSTRAINTS
-messages will contain between 1 and 50 elements, inclusive.
-Each element of messages will contain between 1 and 50 characters, inclusive.
-Each element of messages will consist only of numeric digits '0'-'9', inclusive.
-No element of messages will be a prefix of, or be exactly the same as, any other element of messages.
-times will contain the same number of elements as messages.
-Each element of times will be between 1 and 100, inclusive.


EXAMPLES

0)
{"123","124","134"}
{1,2,3}

Returns: 25


Here is a graph of the bytes that are transmitted, which masters are transmitting for each byte, and how long each byte takes to transmit.  '-' means the master is transmitting, and '+' means the master was driving clock, but lost arbitration:


Data:       123124134
Master1:    ---
Master2:    --+---
Master3:    -+ -+ ---
Time taken: 332332333



For the first message, all masters successfully transmit the first byte.  Since the slowest is 3 milliseconds, the first byte takes 3 milliseconds to transfer.  On the second byte, the third master is arbitrated out since the other two transmit a lower byte.  However, the third master still drives the clock for the byte, so it is transmitted at 3 milliseconds.  The third byte is transmitted by the first two masters, and even though the second master loses arbitration, it drives the clock at 2 milliseconds.  The total time for the first message is therefore 3+3+2 = 8 milliseconds long.



At this point, the second and third master still haven't transmitted their messages.  The second message again takes 8 milliseconds because the third master is arbitrated out on the second byte.



The final message is transmitted only by the third master, and therefore takes 9 milliseconds to transmit.  The total time for the entire sequence is 8+8+9=25 milliseconds.


1)
{"012", "1234", "1233", "1223", "1123"}
{4,1,5,2,9}

Returns: 94


Again, here is a graph which displays the bytes transmitted, which masters are transmitting, and the resulting times for each byte.  '-' means the master is transmitting and '+' means the master is driving clock, but lost arbitration:



Data:       0121123122312331234
Master1:    ---
Master2:    +  -+  --+ ---+----
Master3:    +  -+  --+ ----
Master4:    +  -+  ----
Master5:    +  ----
Time taken: 9449999555255551111


2)
{"0002019289019101039663222896280025447",
 "00201873554718989597528841094293294387326",
 "010699029378761", "0110118", "011143279122561420",
 "001046384966198", "00200570375817801109530240012",
 "0003163277589822", "01100240744590150136673219652442108",
 "012033596872642679096489479354", "0121059494098",
 "00001002303019117948961792176", "00216399923558", "02014",
 "00224999120803846121427603894967637446889670369",
 "01101009414735635151893037596051740080475886",
 "0000101211809647472761605153430927981533514",
 "176845042961739039392207791589",
 "02000047506929386333221966659552927385017901842706",
 "021001117450487502127241076595509511",
 "021010776262723557108100899515",
 "0210114830738951774606917781619656",
 "0211798433083855430", "00000005842153604632996228135814",
 "0001000766929248550736138555144997170272757787",
 "0001010247593342056062432721557",
 "01100004828618452515832113396660046634951",
 "0132559984733529872911444204991646138116334788",
 "0224149857349431864906523152249992",
 "00001142929552573133212195441932219",
 "0011090498947092002457447355036811372647896489218",
 "000001275414757476198997466", "00010014",
 "00111025861963467834393486017602553072649743",
 "000102085", "00120882661783539",
 "01100018938145727291185020",
 "01100191373790478446634214244459341793", "0001129060",
 "001111287431066271555393813846448",
 "011010160778408696098486370196313", "0002125146381515395"}
{42, 86, 47, 86, 32, 95, 2, 98, 17, 58, 31, 32, 85, 77,
 87, 61, 1, 20, 15, 80, 20, 95, 55, 87, 52, 14, 55, 68,
 2, 66, 67, 3, 28, 97, 100, 67, 65, 20, 28, 77, 93, 64}

Returns: 71048

*/
// END CUT HERE

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"123","124","134"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 25; verify_case(0, Arg2, transmitTime(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"012", "1234", "1233", "1223", "1123"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4,1,5,2,9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 94; verify_case(1, Arg2, transmitTime(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"0002019289019101039663222896280025447",
 "00201873554718989597528841094293294387326",
 "010699029378761", "0110118", "011143279122561420",
 "001046384966198", "00200570375817801109530240012",
 "0003163277589822", "01100240744590150136673219652442108",
 "012033596872642679096489479354", "0121059494098",
 "00001002303019117948961792176", "00216399923558", "02014",
 "00224999120803846121427603894967637446889670369",
 "01101009414735635151893037596051740080475886",
 "0000101211809647472761605153430927981533514",
 "176845042961739039392207791589",
 "02000047506929386333221966659552927385017901842706",
 "021001117450487502127241076595509511",
 "021010776262723557108100899515",
 "0210114830738951774606917781619656",
 "0211798433083855430", "00000005842153604632996228135814",
 "0001000766929248550736138555144997170272757787",
 "0001010247593342056062432721557",
 "01100004828618452515832113396660046634951",
 "0132559984733529872911444204991646138116334788",
 "0224149857349431864906523152249992",
 "00001142929552573133212195441932219",
 "0011090498947092002457447355036811372647896489218",
 "000001275414757476198997466", "00010014",
 "00111025861963467834393486017602553072649743",
 "000102085", "00120882661783539",
 "01100018938145727291185020",
 "01100191373790478446634214244459341793", "0001129060",
 "001111287431066271555393813846448",
 "011010160778408696098486370196313", "0002125146381515395"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {42, 86, 47, 86, 32, 95, 2, 98, 17, 58, 31, 32, 85, 77,
 87, 61, 1, 20, 15, 80, 20, 95, 55, 87, 52, 14, 55, 68,
 2, 66, 67, 3, 28, 97, 100, 67, 65, 20, 28, 77, 93, 64}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 71048; verify_case(2, Arg2, transmitTime(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  SMBus test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
