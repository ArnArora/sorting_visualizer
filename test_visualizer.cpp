#include <iostream>
#include <vector>
#include "./visualizer.cpp"
using namespace std;

int main() {
    vector<double> list{5, 10, 2, 3};
    visualizer vis(list, 1280, 720, 60);

    vis.draw_all();
}
