
/*
  bucket_test.cpp
 */

#include <iostream>
#include <list>
#include <utility>

#include "bucket.cpp"

using namespace std;

int main(int argc, char *argv[])
{

  Bucket<int, int> bucket(20, 3);

  bucket.divide(3);
  bucket.divide(14);
  
  for(int i = 0; i < 20; ++i) {
    cout << i << " ";
    cout << bucket.find(i)->first << " " ;
    cout << bucket.left(i) << " ";
    cout << bucket.right(i) << " ";
    cout << bucket.find(i)->second++ ;
    cout << endl;
  }
  
  return 0;
}
