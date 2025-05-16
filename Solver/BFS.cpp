#include <bits/stdc++.h>
#include "../Model/RubiksCube.h"
using namespace std;
#ifndef RUBIKS_CUBE_SOLVER_BFSSOLVER_H
#define RUBIKS_CUBE_SOLVER_BFSSOLVER_H

template <typename T ,typename h>
class BfsSolver {
    private:
    vector<RubiksCube::MOVE> bfs_helper(T rubrikscube) {
        queue<T> q;
        vector<RubiksCube::MOVE> res;

        q.push(rubrikscube);
        unordered_map<T, bool, h> visited;
        unordered_map<T, pair<T, RubiksCube::MOVE>, h> move_done;

        visited[rubrikscube] = true;

        while (!q.empty()) {
            T node = q.front();
            q.pop();

            if (node.isSolved()) {
                T curr = node;

                while (move_done.find(curr) != move_done.end()) {
                    res.push_back(move_done[curr].second);
                    curr = move_done[curr].first;
                }

                reverse(res.begin(), res.end());
                return res;
            }

            for (int i = 0; i < 18; i++) {
                auto curr_move = RubiksCube::MOVE(i);
                T next = node;
                next.move(curr_move);

                if (!visited[next]) {
                    visited[next] = true;
                    move_done[next] = {node, curr_move};
                    q.push(next);
                }
            }
        }

        return res;
    }
    public:
    T rubrikscube;
    BfsSolver(T rb) {
        this->rubrikscube = rb;
    }
    vector<RubiksCube::MOVE> solve() {
        return bfs_helper(rubrikscube);
    }

};




#endif
