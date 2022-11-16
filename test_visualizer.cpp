#include <SFML/System/Sleep.hpp>
#include <SFML/System/Time.hpp>
#include <iostream>
#include <vector>
#include "./visualizer.cpp"
using namespace std;

int main() {
    vector<double> list{5, 10, 2, 3};
    visualizer vis(list, 640, 480, 60);

    vis.draw_all();
}
