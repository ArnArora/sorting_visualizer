#include <SFML/System/Sleep.hpp>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/Window.hpp>

using namespace std;

class visualizer {
public:
    sf::RenderWindow window;
    // vector<double> list;
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

    // Constructor
    visualizer(int num_in_list, int max, int win_width, int win_height, double framerate, double animation_duration) {
        // Get window height and width as parameters
        win_w = win_width;
        win_h = win_height;

        window.create(sf::VideoMode(win_w, win_h), "Visualizer");
        // list = vec;
        // n = vec.size();
        n = num_in_list;
        
        // Find maximum in list
        for (int i = 0; i < n; i++) {
            max_val = max;
        }

        // Calculate window padding and gap between bars
        win_pad = 0.05 * win_w;
        gap = 0.01 * win_w;

        // Calculate width of each bar and maximum height based on win_w,
        // win_h, padding, and gap
        bar_w = (win_w - 2 * win_pad - (n - 1) * gap) / n;
        max_bar_h = win_h - 2 * win_pad;

        fps = framerate;
        anim_duration = animation_duration;
    }

    // Draws bar using SFML Rectangle
    void draw_bar(double val, int x) {
        sf::RectangleShape bar;
        double bar_h = max_bar_h * val / max_val;
        double bar_x = win_pad + x;
        double bar_y = win_h - win_pad - bar_h;
        // std::cout << val << " " << bar_w << " " << bar_h << " " << bar_x << " " << bar_y;
        bar.setSize(sf::Vector2f(bar_w, bar_h));
        bar.setPosition(bar_x, bar_y);
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
            draw_bar(list[i], x_pos(i));
        }

        window.display();
        sf::Time wait = sf::seconds(0.5);
        sf::sleep(wait);
    }
    
    // Animate moving every element at i to new_positions[i]
    void move(vector<double> list, vector<int> new_positions) {
        // Calculate number of frames it takes to for animation to last 
        // approximately the desired animated duration
        int num_frames = anim_duration * fps;
        for (int f = 0; f <= num_frames; f++) {
            window.clear();

            for (int i = 0; i < n; i++) {
                // Calulate x position for bar i at current frame
                double x = x_pos(i) + f * (x_pos(new_positions[i]) - x_pos(i)) / num_frames;
                draw_bar(list[i], x);
            }

            // Calculate how long to pause per frame based on fps
            window.display();
            sf::Time pause = sf::seconds(1.0 / fps);
            sf::sleep(pause);
        }
    }

    void quit() {
        window.close();
    }
};
