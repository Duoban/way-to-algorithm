#pragma once

#ifndef MAX
#define MAX 1024
#endif
#include <algorithm>
#include <vector>

// ǰ i ����Ʒ���������� j ������ֵ

int ZeroOneKnapsack(int *value, int *weight, int count, int tot_weight)
{
    int f[MAX][MAX];

    // ��ʼ��
    for (int i = 0; i < MAX; i++) {
        f[0][i] = 0;
        f[i][0] = 0;
    }

    // �� i ����Ʒ
    for (int i = 1; i <= count; i++) {
        // ���������� j
        for (int j = 0; j <= tot_weight; j++) {
            if (j >= weight[i])
                f[i][j] =
                    std::max(f[i - 1][j], f[i - 1][j - weight[i]] + value[i]);
            else
                f[i][j] = f[i - 1][j];
        }
    }

    return f[count][tot_weight];
}
