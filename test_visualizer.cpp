#include <SFML/System/Sleep.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/Window.hpp>
#include <iostream>
#include <vector>
#include "./visualizer.cpp"
using namespace std;

int main() {
    vector<double> list{5, 10, 2, 3};

    sf::RenderWindow window(sf::VideoMode(640, 480), "Visualizer");
    // Create the circle shape
    sf::CircleShape circle(50); // 50 is the radius of the circle

    // Set the position of the circle
    circle.setPosition(100, 100); // 100, 100 is the position of the center of the circle

    // Set the color of the circle
    circle.setFillColor(sf::Color::Red); // The circle will be filled with red color

    // Draw the circle to the render target
    window.draw(circle); // window is an instance of sf::RenderWindow

    window.display();

    sf::sleep(sf::seconds(2));
}
