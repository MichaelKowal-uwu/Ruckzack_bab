#ifndef KNAPSACK_SOLVER_H
#define KNAPSACK_SOLVER_H

#include <vector>

struct Item {
    int w, v;
    double d;
};

class KnapsackSolver {
public:
    KnapsackSolver(int cap, int num);
    void readItems();
    int solve();

private:
    int capacity, n, max_v;
    std::vector<Item> items;

    void find(int i, int cur_w, int cur_v);
    double get_bound(int i, int cur_w, int cur_v);
};

#endif
