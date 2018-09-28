#pragma once
#include <cstring>
#ifndef MAX
#define MAX 1024
#endif

struct FenwickTree {
  /*�����±��1��ʼ*/
  int bit[MAX];
};

FenwickTree *FenwickTreeNew();
FenwickTree *FenwickTreeNewFromArray(int *s);
void FenwickTreeFree(FenwickTree *t);
void FenwickTreeAdd(FenwickTree *t, int i, int v);
int FenwickTreeSum(FenwickTree *t, int i);

