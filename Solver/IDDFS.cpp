//
// Created by Lenovo on 21-05-2025.
//
#include <bits/stdc++.h>
#include "../Model/RubiksCube.h"
using namespace std;

#include "DFS.cpp"
template <typename T>
class IDDFS {
private:
    int maxi;
    T rubikscube;
    vector<RubiksCube::MOVE> moves;
    void helper() {
        for (int i=1;i<=maxi;i++) {
            dfsSolver<T> dfs_solver(rubikscube,i);
            auto temp =   dfs_solver.solve(i);
            if (dfs_solver.rubiksCube.isSolved())  {
                moves = temp;
                break;
            }
        }
    }
public:
    IDDFS(T rb,int max_depth = 7) {
        this->maxi = max_depth;
        this->rubikscube = rb;
    }

    vector<RubiksCube::MOVE> solve() {
        helper();

        return moves;
    }
};