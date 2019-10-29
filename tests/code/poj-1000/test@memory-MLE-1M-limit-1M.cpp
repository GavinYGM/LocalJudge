#include <iostream>
#ifdef _WINDOWS
#include <windows.h>
#else
#include <unistd.h>
#define Sleep(x) usleep((x)*1000)
#endif
using namespace std;
/**
 * Memory Limit: 1M
 * POJ  Memory: 1716K		Time: 0MS
**/

int main() {
  int n, m;
  char *p = new char[1024*1024];
  fill(p, p + 1024 * 1024, 1);
  cin >> n >> m;
  cout << n + m << endl;
  Sleep(1000);
  return 0;
}