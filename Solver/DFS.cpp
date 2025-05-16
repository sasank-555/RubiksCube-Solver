#include <bits/stdc++.h>
#include "../Model/RubiksCube.h"
using namespace std;

template <typename T>
class dfsSolver {
private:
    int max_search_depth;
    vector<RubiksCube::MOVE> moves;
    bool dfs_helper(int depth) {
        if (rubiksCube.isSolved()) return true;
        if (depth < 0) return false;
        for (int i = 0 ; i < 18;i++) {
            rubiksCube.move(RubiksCube::MOVE(i));
            moves.push_back(RubiksCube::MOVE(i));
            if (dfs_helper(depth - 1)) return true;
            moves.pop_back();
            rubiksCube.invert(RubiksCube::MOVE(i));
        }
        return false;
    }
public:
    T rubiksCube;

    dfsSolver(T rb , int maxD) {
        this->max_search_depth = maxD;
        this->rubiksCube = rb;
    }
    vector<RubiksCube::MOVE> solve(int max_depth = 9) {
        dfs_helper(max_depth);
        return moves;
    }
};