#include <SFML/Graphics.hpp>

int main()
{
    // Create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Circle");

    // Set the window's vertical sync enabled
    window.setVerticalSyncEnabled(true);

    // Create the circle shape
    sf::CircleShape circle(100.f);

    // Set the circle's fill color
    circle.setFillColor(sf::Color::Green);

    // Create a clock to track time elapsed
    sf::Clock clock;

    // Main loop
    while (window.isOpen())
    {
        // Handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        // Clear the window
        window.clear();

        // Get the elapsed time
        sf::Time elapsed = clock.getElapsedTime();

        // Check if 2 seconds have elapsed
        if (elapsed.asSeconds() < 2.0f)
        {
            // Draw the circle
            window.draw(circle);
        }

        // Display the window's contents on the screen
        window.display();
    }

    return 0;
}

