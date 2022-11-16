#include <SFML/Graphics.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/Window.hpp>

using namespace std;

class visualizer {
public:
    sf::Window window;
    int n;

    visualizer() {
        window = sf::Window(sf::VideoMode(640, 480), "Visualizer");
    }

    void move(vector<int> a, vector<int> b) {
    }
    
}
