#include <iostream>
#include <mutex>
using namespace std;

// Mutex to prevent multiple threads from sending output at the same time
mutex printMtx;

void safePrint(string output) {
  printMtx.lock();
  cout << output;
  printMtx.unlock();
}
