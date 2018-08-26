#pragma once

#ifndef MAX
#define MAX 1024
#endif
#include <vector>
#include <algorithm>


// ����a��b�ķ�Χ��[1,n]
int LongestCommonSubsequence(const int *a, const int *b, int n) {
  int f[MAX][MAX];

  // ��ʼ��
  for (int i = 0; i < MAX; i++) {
    f[i][0] = 0;
    f[0][i] = 0;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (a[i] == b[j])
        f[i][j] = f[i-1][j-1] + 1;
      else
        f[i][j] = std::max( f[i-1][j], f[i][j-1] );
    }
  }

  return f[n][n];
}
