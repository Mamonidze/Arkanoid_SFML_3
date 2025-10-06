
#include <iostream>
#include <SFML/Graphics.hpp>


class Platform
{
public:
    sf::RectangleShape Platform_Body{{100,20}};  
    static constexpr float Platform_Speed{0.1f};
    static constexpr sf::Vector2<float> Platform_Origin_Point{400,790};


    
    void Move_Left_Right(const float& direction, const float& speed)
    {
        this->Platform_Body.move({direction*speed, 0.f});
    }
    
    void Release_The_Ball()
    {
        std::cout << "Released";
    }
};

class Ball
{
public:
    sf::CircleShape Ball_Body{10}; //размер шарика
    float Ball_Speed{0.1f};
    static constexpr sf::Vector2<float> Ball_Origin_Point{400,760};

    void Detect_Collision(float &Collision_Point){}

    
    void Ball_Movement(const float& direction, const float& speed)
    {
        
    }
    
};




int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 800}), "SFML works!");

    
    Platform Player{};
    Player.Platform_Body.setOrigin({50,10});
    Player.Platform_Body.setPosition(Player.Platform_Origin_Point);
    Player.Platform_Body.setFillColor(sf::Color::Red);

    Ball Ball{};
    Ball.Ball_Body.setOrigin({10,10});
    Ball.Ball_Body.setPosition(Ball.Ball_Origin_Point);
    Ball.Ball_Body.setFillColor(sf::Color::Green);


    


    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();

            if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
            {
                if (keyPressed->scancode == sf::Keyboard::Scan::Space)
                {
                    Player.Release_The_Ball();
                }
            }
        }

        window.clear();
        window.draw(Player.Platform_Body);
        window.draw(Ball.Ball_Body);
        window.display();

        float Direction{};

        if (isKeyPressed(sf::Keyboard::Key::Left))
        {
            Direction = -1;
            Player.Move_Left_Right(Direction, Player.Platform_Speed);
        }

        if (isKeyPressed(sf::Keyboard::Key::Right))
        {
            Direction = 1;
            Player.Move_Left_Right(Direction, Player.Platform_Speed);
        }

        
    }
}