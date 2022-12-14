#include <SFML/System/Sleep.hpp>
#include <SFML/System/Time.hpp>
#include <algorithm>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/Window.hpp>
#include <string>

using namespace std;

sf::RenderWindow window;
int n;
double max_val;
double win_w;
double win_h;
double win_pad;
double gap;
double bar_w;
double max_bar_h;
double min_x;
double min_y;
double anim_duration;
double fps;
string sort_type;

int main() {
    win_w = 640;
    win_h = 480;
    window.create(sf::VideoMode(win_w, win_h), "Visualizer");

    cout << "Number of elements: " << endl;
    cin >> n;

    int list[n];
    int max_val;
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". " << endl;
        cin >> list[i];
        max_val = max(max_val, list[i]);
    }

    win_pad = 0.05 * win_w;
    gap = 0.01 * win_w;
    bar_w = (win_w - 2 * win_pad - (n - 1) * gap) / n;
    max_bar_h = win_h - 2 * win_pad;

    cout << "FPS: " << endl;
    cin >> fps;
    
    cout << "Animation duration: " << endl;
    cin >> anim_duration;

    cout << "Sorting Type: " << endl;
    cin >> sort_type;

    if (sort_type == "binary") {

    }
}

// Draws bar using SFML Rectangle
void draw_bar(double val, int x, bool highlight) {
    sf::RectangleShape bar;
    double bar_h = max_bar_h * val / max_val;
    double bar_x = win_pad + x;
    double bar_y = win_h - win_pad - bar_h;
    // std::cout << val << " " << bar_w << " " << bar_h << " " << bar_x << " " << bar_y;
    bar.setSize(sf::Vector2f(bar_w, bar_h));
    bar.setPosition(bar_x, bar_y);
    bar.setFillColor(sf::Color::White);
    if (highlight)
        bar.setFillColor(sf::Color::Red);
    window.draw(bar);
}

// Returns x value for a SFML rectangle for a bar for element at position i
double x_pos(int i) {
    return win_pad + i * (bar_w + gap);
}

// Draw all elemnents
void draw_all(vector<double> list) {
    window.clear();
    for (int i = 0; i < n; i++) {
        draw_bar(list[i], x_pos(i), false);
    }

    window.display();
    sf::Time wait = sf::seconds(0.5);
    sf::sleep(wait);
}

// Animate moving every element at i to new_positions[i]
void move(vector<double> list, vector<int> new_positions, vector<int> highlighted) {
    // Calculate number of frames it takes to for animation to last 
    // approximately the desired animated duration
    int num_frames = anim_duration * fps;
    for (int f = 0; f <= num_frames; f++) {
        window.clear();

        for (int i = 0; i < n; i++) {
            // Calulate x position for bar i at current frame
            double x = x_pos(i) + f * (x_pos(new_positions[i]) - x_pos(i)) / num_frames;
            bool highlight = find(highlighted.begin(), highlighted.end(), i) != highlighted.end();
            draw_bar(list[i], x, highlight);
        }

        // Calculate how long to pause per frame based on fps
        window.display();
        sf::Time pause = sf::seconds(1.0 / fps);
        sf::sleep(pause);
    }

    sf::sleep(sf::seconds(1.0));
}

void quit() {
    window.close();
}
