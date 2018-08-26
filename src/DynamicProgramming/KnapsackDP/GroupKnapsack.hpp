#pragma once

#ifndef MAX
#define MAX 1024
#endif
#include <iostream>
#include <algorithm>


//
// interface
//

/**
 * ��Ʒ��Ϊ n ��
 * �� i ������ group_n[i] ����Ʒ ��ΧΪ [ 1, group_n[i] ]
 * group[i][j] Ϊ�� i ���еĵ� j ����Ʒ
 * ����Ʒ item �ļ�ֵΪ item.value ����Ϊ item.weight
 * ������װ�ص��������Ϊ tot_weight
*/
struct Item {
  int value;
  int weight;
};

int GroupKnapsack(Item group[MAX][MAX], int *group_n, int n, int tot_weight);


//
// implement
//

bool ItemCompare(const Item & a, const Item & b) {
  double rate_a = (double)a.value / (double)a.weight;
  double rate_b = (double)b.value / (double)b.weight;
  if (rate_a != rate_b)
    return rate_a > rate_b;
  else
    return a.weight < b.weight;
}

int GroupKnapsack(Item group[MAX][MAX], int *group_n, int n, int tot_weight) {
  // f[k][j] ǰ k ������������ j ������ֵ
  int f[MAX][MAX];

  // ��ʼ��
  for (int i = 0; i < MAX; i++)
    for (int j = 0; j < MAX; j++)
      f[i][j] = 0;

  // �����з����������
  for (int i = 1; i <= n; i++) {
    std::sort( (Item*)group[i] + 1,
               (Item*)group[i] + 1 + group_n[i],
               ItemCompare );
  }

  // �� k ����Ʒ
  for (int k = 1; k <= n; k++) {
    // һ���еĵ� i ����Ʒ
    for (int i = 1; i <= group_n[k]; i++) {
      // ���������� j
      for (int j = 0; j <= tot_weight; j++) {
        // ��ͬһ�� k �еĲ�ͬ��Ʒ i ֮���ǻ����
        // ����ֻ��ѡ��һ��
        // ѡ����Ʒ i ��ǰһ����Ʒ i-1 ֮�м�ֵ����
        int tmp;
        if (j >= group[k][i].weight) {
          tmp = std::max( f[k-1][j],
                          f[k-1][ j - group[k][i].weight ] + group[k][i].value );
        } else {
          tmp = f[k-1][j];
        }
        f[k][j] = std::max( f[k][j], tmp );
      }
    }
  }

  return f[n][tot_weight];
}
