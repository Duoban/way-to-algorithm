#ifndef COMBINATION_HPP
#define COMBINATION_HPP

#include <algorithm>
#include <cassert>
#include <unordered_set>
#include <vector>
using namespace std;
#ifndef MAX
#define MAX 1024
#endif

void MakeChoice(vector<int>& choose, int prev, int prev_one, int s[MAX], int n,
                int m, vector<unordered_set<int>>& comb) {
    if (prev == m) {
        unordered_set<int> tmp;
        for (int i = 0; i < choose.size(); i++) {
            if (choose[i] == 1) tmp.insert(s[i]);
        }
        comb.push_back(tmp);
        return;
    }

    // prev从0开始 每次增加一个1
    // prev_one表示上一轮的数组中最后一个1的位置
    for (int i = prev_one + 1; i < n; i++) {
        if (choose[i] == 0) {
            choose[i] = 1;
            MakeChoice(choose, prev + 1, i, s, n, m, comb);
            choose[i] = 0;
        }
    }
}

vector<unordered_set<int>> Combination(int s[MAX], int n, int m) {
    // 初始化choose=[0, 0, 0, ..., 0]
    vector<int> choose(n, 0);
    vector<unordered_set<int>> comb;
    // 初始时1的数量为0个 最后一个1的位置为-1
    MakeChoice(choose, 0, -1, s, n, m, comb);

    return comb;
}

#endif
