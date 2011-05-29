
/*
  pq_test.cpp
 */

#include <iostream>
#include <list>
#include <algorithm>
#include <utility>
#include <string>

#include "pq.cpp"

void echo(const std::string& msg);
void dump(PQ<int, int>& pq);

int main(int argc, char *argv[])
{
  PQ<int, int> pq;

  echo("push 4@1");
  pq.push(1, 4);
  dump(pq);

  echo("push 3@24");
  echo("push 5@4");
  pq.push(24, 3);
  pq.push(4, 5);
  dump(pq);

  echo("pop");
  pq.pop();
  dump(pq);

  echo("push 3@6");
  pq.push(6,3);
  dump(pq);
  
  return 0;
}

using namespace std;

void echo(const std::string& msg)
{
  cout << msg << endl;
}

void dump(PQ<int,int>& pq)
{
  for(PQ<int, int>::iterator iter = pq.begin();
      iter != pq.end(); ++iter)
  {
    cout << "<" << iter->first << " " << iter->second << "> ";
  }
  cout << endl;
}

