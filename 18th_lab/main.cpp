#include <SFML/Graphics.hpp>

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 16;

    sf::RenderWindow window(sf::VideoMode(530, 320), "SFML window", sf::Style::Default, settings);
    window.setFramerateLimit(60);

    //
    sf::RectangleShape rectangle({130.f, 60.f});
    rectangle.setFillColor({245, 108, 64});
    rectangle.setOutlineThickness(2.f);
    rectangle.setOutlineColor({255, 255, 255});

    rectangle.setPosition({100.f, 200.f});
    rectangle.setRotation({15});

    //
    sf::CircleShape circle(55.f);
    circle.setFillColor({127, 64, 245});
    circle.setOutlineThickness(2.f);
    circle.setOutlineColor({255, 255, 255});

    circle.setPosition({300.f, 180.f});

    //
    sf::CircleShape triangle(50.f, 10.f); 
    triangle.setFillColor({245, 64, 64});
    triangle.setOutlineThickness(2.f);
    triangle.setOutlineColor({255, 255, 255});

    triangle.setPosition({75.f, 50.f});
    triangle.setRotation({-15});

    //
    sf::ConvexShape polygon;
    polygon.setPointCount(5);

    polygon.setPoint(0, {0.f, 0.f});
    polygon.setPoint(1, {150.f, 10.f});
    polygon.setPoint(2, {90.f, 90.f});
    polygon.setPoint(3, {80.f, 100.f});
    polygon.setPoint(4, {0.f, 50.f});

    polygon.setFillColor({64, 146, 245});
    polygon.setOutlineThickness(2.f);
    polygon.setOutlineColor({255, 255, 255});

    polygon.setPosition({300.f, 30.f});

    //
    sf::RectangleShape line({70.f, 5.f});

    line.rotate({45});
    line.setPosition({225.f, 125.f});

    //
    sf::Font font;
    font.loadFromFile("SpaceMono-Regular.ttf");

    sf::Text text;
    text.setFont(font); 

    text.setString("Hello, world!");
    text.setCharacterSize(25); 
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Regular | sf::Text::Italic);

    //text.setPosition({100.f, 100.f});

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(circle);
        window.draw(rectangle);
        window.draw(triangle);
        window.draw(polygon);
        window.draw(line);
        window.draw(text);
        window.display();
    }

    return 0;
}
