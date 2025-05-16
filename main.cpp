
#include  "../Rubiks/Model/RubiksCube3D.cpp"
#include "../Rubiks/Solver/DFS.cpp"
#include "../Rubiks/Solver/BFS.cpp"
using namespace std;
// Created By Sasank
int main() {
    rubiksCube3D cube;
    auto x= cube.randomShuffleCube(7);
    cout<<"Shuffle order\n";
    for (auto const i : x) {
        cout<<RubiksCube::getMove(i)<<" ";
    }
    cout<<endl;
    cube.print();
    BfsSolver <rubiksCube3D , Hash3d > dd(cube);
    vector<RubiksCube::MOVE> ans = dd.solve();
    cout<<"Solution \n";
    for (const auto i : ans) {
        cout<<RubiksCube::getMove(i)<<" ";
    }
    cout<<endl;
    return 0;

}