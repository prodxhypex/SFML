#include <SFML/Graphics.hpp>
#include<iostream>
//for running the code type this in the terminal
//	g++ -Isrc/include -c main.cpp
//	g++ main.o -o main -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system
//  .\main.exe

class Unicode
{
    public:
        int A = 65; int B = 66; int C = 67; int D = 68;
        int E = 69; int F = 70; int G = 71; int H = 72;
        int I = 73; int J = 74; int K = 75; int L = 76;
        int M = 77; int N = 78; int O = 79; int P = 80;
        int Q = 81; int R = 82; int S = 83; int T = 84;
        int U = 85; int V = 86; int W = 87; int X = 88;
        int Y = 89; int Z = 90;

        int a = 97; int b = 98; int c = 99; int d = 100;
        int e = 101; int f = 102; int g = 103; int h = 104;
        int i = 105; int j = 106; int k = 107; int l = 108;
        int m = 109; int n = 110; int o = 111; int p = 112;
        int q = 113; int r = 114; int s = 115; int t = 116;
        int u = 117; int v = 118; int w = 119; int x = 120;
        int y = 121; int z = 122;
};


int main()
{
    //Make sure to save the file for changes to be applied
    //Setting up the Window and giving its properties
    std::string Name = "SFML - 1";
    Unicode Unicode;
    const int WindowHeight = 350;
    const int WindowWidth = 550;
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
                    break;

                //Checks if the user has gained focus to the window
                case sf::Event::GainedFocus:
                    std::cout<<"Gained focus to the window\n";
                    break;

                //Dectects a if the user Entered the text
                case sf::Event::TextEntered:
                    if(Event.text.unicode == Unicode.F)
                    {
                        std::cout<<"This took a long time\n";
                    }
                    break;

            }
            //this checks Keyboard Events
            switch(Event.key.code)
            {
                    case sf::Keyboard::Escape:
                    //Checks the Event then reading the Event to see if the user has pressed the "escape" key
                    Window.close();
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
