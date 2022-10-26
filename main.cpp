#include <SFML/Graphics.hpp>
#include<iostream>
//for running the code type this in the terminal
//	g++ -Isrc/include -c main.cpp
//	g++ main.o -o main -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system
//  .\main.exe

int main()
{
    //Make sure to save the file for changes to be applied
    //Setting up the Window and giving its properties
    std::string Name = "SFML - 1";
    int WindowHeight = 350;
    int WindowWidth = 550;
    bool IsFullScreen = false;
    sf::RenderWindow Window(sf::VideoMode(WindowWidth, WindowHeight), Name);

    //Drawing a shape onto the Window
    sf::CircleShape Circle(100.0f);
    Circle.setFillColor(sf::Color::White);

    //Creating a game loop and chacking if the Window open
    while (Window.isOpen())
    {
        //Creating a Event to check if anything has happend to the Window examples, clicking, key being pressed and so on
        sf::Event Event;

        while (Window.pollEvent(Event))
        {
            //Checks a if a Event happend this doesnt include Keyboard Events
            switch(Event.type)
            {
                case sf::Event::Closed:
                    //Checks if the user pressed the close button in the Window
                    Window.close();
                    break;

                //Checks the Event and sees if the window has been resized    
                case sf::Event::Resized:
                    std::cout<<"Window has been resized in the width axis : " << Event.size.width << "\n";
                    std::cout<<"Window has been resized in the height axis : " << Event.size.height << "\n";
                    break;

                //Checks if the user has lost focus to the window
                case sf::Event::LostFocus:
                    std::cout<<"Lost focus to the window, please gain focus to the window\n";

                //Checks if the user has gained focus to the window
                case sf::Event::GainedFocus:
                    std::cout<<"Gained focus to the window\n";

            }
            //this checks Keyboard Events
            switch(Event.key.code)
            {
                    case sf::Keyboard::Escape:
                    //Checks the Event then reading the Event to see if the user has pressed the "escape" key
                    Window.close();
                    break;


                    //Checks if "Q" has been pressed and if true it will be returned to its default size
                    case sf::Keyboard::Q:
                        WindowHeight = 350;
                        WindowWidth = 550;
                        break;
            }
        }

        //Clearing the Window, drawing to the Window, displaying to the Window
        Window.clear(sf::Color::Blue);
        Window.draw(Circle);
        Window.display();
    }

    return 0;
}