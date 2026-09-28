#include <iostream>
#include "knapsack_solver.h"

int main() {
    int n, cap;
    if (std::cin >> n >> cap) {
        KnapsackSolver solver(cap, n);
        solver.readItems();
        std::cout << solver.solve() << std::endl;
    }
    return 0;
}
