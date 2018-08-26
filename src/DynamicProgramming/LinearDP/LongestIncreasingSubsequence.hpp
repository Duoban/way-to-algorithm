#pragma once

#ifndef MAX
#define MAX 1024
#endif
#include <algorithm>


int LongestIncreasingSubsequence(const int *s, int n) {
  // ����a��b�ķ�Χ��[1,n]
  int f[MAX];

  // ��ʼ��
  f[0] = 0;

  for (int i = 1; i <= n; i++) {
    f[i] = 1;
    int max_length = 0;
    for (int k = 1; k < i; k++) {
      if (s[i] > s[k])
        max_length = std::max(max_length, f[k]);
    }
    f[i] = max_length+1;
  }

  int list = 1;
  for (int i = 1; i <= n; i++) {
    list = std::max(list, f[i]);
  }

  return list;
}
