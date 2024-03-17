#include <SFML/Graphics.hpp>
#include "Sim.h"
#include <iostream>


void ProcessEvents(sf::RenderWindow& window)
{
    // check all the window's events that were triggered since the last iteration of the loop
    sf::Event event;
    while (window.pollEvent(event))
    {
        // "close requested" event: we close the window
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }
    }
}

// https://www.sfml-dev.org/documentation/2.6.1/classsf_1_1Shader.php
void LoadShaders(sf::Shader& shader)
{
    // check if shaders are available
    if (!sf::Shader::isAvailable())
    {
        // shaders are not available...
        std::cout << "no shaders ! exiting" << std::endl;
        while (true);
    }

    // check if geometry shaders are supported
    if (!sf::Shader::isGeometryAvailable())
    {
        // shaders are not available...
        std::cout << "no geometry shaders! exiting" << std::endl;
        while (true);
    }

    // i guess main has a different file path than everything else in source.
    if (!shader.loadFromFile(R"(shaders\vertex_shader.glsl)", R"(shaders\fragment_shader.glsl)"))
    {
        // error...
        std::cout << "could not load shaders" << std::endl;
        while (true);
    }
}


// TODO:
// this might be something to look into as it matches your use case. vertexarrays and vertexbuffers

int main()
{
    // Create window
    sf::RenderWindow window(sf::VideoMode(640, 480), "Balls on Balls on Balls");

    // create object
    //sf::RectangleShape rect({ 100.f, 100.f });
    //rect.setFillColor(sf::Color::Magenta);
    
    sf::CircleShape circle(100.f);

    // shader things
    sf::Shader shader;
    LoadShaders(shader);

    

    // Main loop
    while (window.isOpen())
    {
        ProcessEvents(window);

        // Draw
        window.clear();
        window.draw(circle, &shader);
        window.display();
    }

    



#if 0
    Sim sim;
    sim.Run();
#endif
    return 0;
}