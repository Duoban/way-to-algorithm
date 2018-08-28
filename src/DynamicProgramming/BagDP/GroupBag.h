#pragma once
#ifndef MAX
#define MAX 1024
#endif

/**
 * ��Ʒ��Ϊn��
 * ��i������group_n[i]����Ʒ ��ΧΪ[1, group_n[i]]
 * group[i][j]Ϊ��i���еĵ�j����Ʒ
 * ����Ʒitem�ļ�ֵΪitem.value����Ϊitem.weight
 * ������װ�ص��������Ϊtot_weight
 */
struct Item {
  int value;
  int weight;
};

int GroupBag(Item group[MAX][MAX], int *group_n, int n, int tot_weight);

