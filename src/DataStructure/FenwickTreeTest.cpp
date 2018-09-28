#include "FenwickTree.h"
#include <cassert>
using namespace std;

#define TEST_MAX 1024

int main() {
  for (int i = 0; i < TEST_MAX; i++) {
    FenwickTree *t = FenwickTreeNew();
    assert(t);
    int sum = 0;
    for (int j = 1; j < MAX; j++) {
      FenwickTreeAdd(t, j, i);
      sum += i;
      assert(FenwickTreeSum(t, MAX - 1) == sum);
    }
  }

  return 0;
}

