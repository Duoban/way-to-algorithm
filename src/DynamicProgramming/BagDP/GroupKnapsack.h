#pragma once
#ifndef MAX
#define MAX 1024
#endif

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
