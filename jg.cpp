#include <SFML/Graphics.hpp>
using namespace sf;

int main()
{
    RenderWindow window(VideoMode(800, 600), "My window");
    window.setFramerateLimit(60);
    
    int posX = 300;
    int posY = 300;
    CircleShape shooter(50.f,4);
    shooter.rotate(45);
    shooter.setPosition(posX,posY);

    while (window.isOpen())
    {

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::Right) {
                    posX+=10;
                    shooter.setPosition(posX,posY);
                }
                if (event.key.code == Keyboard::Left) {
                    posX-=10;
                    shooter.setPosition(posX,posY);
                }
                if (event.key.code == Keyboard::Up) {
                    posY-=10;
                    shooter.setPosition(posX,posY);
                }
                if (event.key.code == Keyboard::Down) {
                    posY+=10;
                    shooter.setPosition(posX,posY);
                }
            }
        }

        window.clear(Color::Black);
        
        shooter.setFillColor(Color(100, 250, 50));
        //shooter.setPosition(300,300);
        
        window.draw(shooter);
        window.display();
    }

    return 0;
}
