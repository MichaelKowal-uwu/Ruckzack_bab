#include "knapsack_solver.h"
#include <iostream>
#include <algorithm>

bool compareItems(Item a, Item b) {
    return a.d > b.d;
}

KnapsackSolver::KnapsackSolver(int cap, int num) : capacity(cap), n(num), max_v(0) {}

void KnapsackSolver::readItems() {
    for (int i = 0; i < n; i++) {
        int v, w;
        std::cin >> v >> w;
        items.push_back({w, v, (double)v / w});
    }
    std::sort(items.begin(), items.end(), compareItems);
}

double KnapsackSolver::get_bound(int i, int cur_w, int cur_v) {
    double b = cur_v;
    int left_w = capacity - cur_w;
    
    for (int j = i; j < n; j++) {
        if (items[j].w <= left_w) {
            left_w -= items[j].w;
            b += items[j].v;
        } 
        else if (left_w > 0) {
            b += items[j].d * left_w;
            left_w = 0;
        }
    }
    return b;
}

void KnapsackSolver::find(int i, int cur_w, int cur_v) {
    if (cur_v > max_v) {
        max_v = cur_v;
    }

    if (i < n) {
        if (cur_w + items[i].w <= capacity) {
            find(i + 1, cur_w + items[i].w, cur_v + items[i].v);
        }

        if (get_bound(i + 1, cur_w, cur_v) > max_v) {
            find(i + 1, cur_w, cur_v);
        }
    }
}

int KnapsackSolver::solve() {
    max_v = 0;
    find(0, 0, 0);
    return max_v;
}
