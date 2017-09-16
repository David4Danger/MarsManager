#include <iostream>
#include <mutex>
using namespace std;

// Mutex to prevent multiple threads from sending output at the same time
mutex mtx;

void safePrint(string output) {
  mtx.lock();
  cout << output;
  mtx.unlock();
}
