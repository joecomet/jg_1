#include <SFML/Graphics.hpp>
using namespace sf;

int main()
{
    RenderWindow window(VideoMode(400, 400), "My window");
    window.setFramerateLimit(60);
    
    Clock myclock;
    
    int posX = 0;
    int posY = 0;
    CircleShape shooter(20.f,4);

    shooter.setPosition(posX,posY);
    shooter.setOrigin(0,20);
    shooter.rotate(45);
    bool LtoR = true;

    while (window.isOpen())
    {
        Time elapsed1 = myclock.getElapsedTime();
        if (elapsed1.asSeconds() > 1) {
            if (posX > 360) {
                LtoR = false;
            }
            if (posX <= 0) {
                LtoR = true;
            }
            if (LtoR == true) {
                posX+=10;
            } else {
                posX-=10;
            }
            
            shooter.setPosition(posX,posY);
            myclock.restart();
        }
    
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
                if (event.key.code == Keyboard::Space) {
                    shooter.rotate(5);
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
