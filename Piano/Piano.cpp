#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Audio.hpp>
#include <cmath>
#include <vector>

int main()
{
    sf::Keyboard::Scan keys[] = 
    {
    sf::Keyboard::Scan::Tab,
    sf::Keyboard::Scan::Q,
    sf::Keyboard::Scan::W,
    sf::Keyboard::Scan::E,
    sf::Keyboard::Scan::R,
    sf::Keyboard::Scan::T,
    sf::Keyboard::Scan::Y,
    sf::Keyboard::Scan::U,
    sf::Keyboard::Scan::I,
    sf::Keyboard::Scan::O,
    sf::Keyboard::Scan::P,
    sf::Keyboard::Scan::LBracket,
    sf::Keyboard::Scan::RBracket,
    sf::Keyboard::Scan::Backslash,
    sf::Keyboard::Scan::Num1,
    sf::Keyboard::Scan::Num3,
    sf::Keyboard::Scan::Num4,
    sf::Keyboard::Scan::Num5,
    sf::Keyboard::Scan::Num7,
    sf::Keyboard::Scan::Num8,
    sf::Keyboard::Scan::Num0,
    sf::Keyboard::Scan::Hyphen,
    sf::Keyboard::Scan::Equal,

    };
    
    std::vector<sf::SoundBuffer> soundBuffers(4);
    
    if (!soundBuffers[0].loadFromFile("Sounds/C.mp3")) {
        std::cerr << "Failed to load Sounds/C.mp3" << std::endl;
        return 1;
    }
    if (!soundBuffers[1].loadFromFile("Sounds/music.mp3")) {
        std::cerr << "Failed to load Sounds/music.mp3" << std::endl;
        return 1;
    }
    if (!soundBuffers[2].loadFromFile("Sounds/nya.mp3")) {
        std::cerr << "Failed to load Sounds/nya.mp3" << std::endl;
        return 1;
    }
    if (!soundBuffers[3].loadFromFile("Sounds/Guitar.mp3")) {
        std::cerr << "Failed to load Sounds/Guitar.mp3" << std::endl;
        return 1;
    }

    int currentBufferIndex = 0;
    
    sf::Sound sound_D1(soundBuffers[0]);  sound_D1.setPitch(std::pow(2, -10/12.f));
    sf::Sound sound_E1(soundBuffers[0]);  sound_E1.setPitch(std::pow(2,  -8/12.f));
    sf::Sound sound_F1(soundBuffers[0]);  sound_F1.setPitch(std::pow(2,  -7/12.f));
    sf::Sound sound_G1(soundBuffers[0]);  sound_G1.setPitch(std::pow(2,  -5/12.f));
    sf::Sound sound_A1(soundBuffers[0]);  sound_A1.setPitch(std::pow(2,  -3/12.f));
    sf::Sound sound_B1(soundBuffers[0]);  sound_B1.setPitch(std::pow(2,  -1/12.f));
    sf::Sound sound_C2(soundBuffers[0]);
    sf::Sound sound_D2(soundBuffers[0]);  sound_D2.setPitch(std::pow(2,   2/12.f));
    sf::Sound sound_E2(soundBuffers[0]);  sound_E2.setPitch(std::pow(2,   4/12.f));
    sf::Sound sound_F2(soundBuffers[0]);  sound_F2.setPitch(std::pow(2,   5/12.f));
    sf::Sound sound_G2(soundBuffers[0]);  sound_G2.setPitch(std::pow(2,   7/12.f));
    sf::Sound sound_A2(soundBuffers[0]);  sound_A2.setPitch(std::pow(2,   9/12.f));
    sf::Sound sound_B2(soundBuffers[0]);  sound_B2.setPitch(std::pow(2,  11/12.f));
    sf::Sound sound_C3(soundBuffers[0]);  sound_C3.setPitch(2.f);

    sf::Sound sound_Dsharp1(soundBuffers[0]); sound_Dsharp1.setPitch(std::pow(2, -9/12.f)); 
    sf::Sound sound_Esharp1(soundBuffers[0]); sound_Esharp1.setPitch(std::pow(2, -7/12.f));  
    sf::Sound sound_Fsharp1(soundBuffers[0]); sound_Fsharp1.setPitch(std::pow(2, -6/12.f)); 
    sf::Sound sound_Gsharp1(soundBuffers[0]); sound_Gsharp1.setPitch(std::pow(2, -4/12.f)); 
    sf::Sound sound_Asharp1(soundBuffers[0]); sound_Asharp1.setPitch(std::pow(2, -2/12.f)); 

    sf::Sound sound_Csharp2(soundBuffers[0]); sound_Csharp2.setPitch(std::pow(2, 1/12.f));  
    sf::Sound sound_Dsharp2(soundBuffers[0]); sound_Dsharp2.setPitch(std::pow(2, 3/12.f));
    sf::Sound sound_Esharp2(soundBuffers[0]); sound_Esharp2.setPitch(std::pow(2, 5/12.f));   
    sf::Sound sound_Fsharp2(soundBuffers[0]); sound_Fsharp2.setPitch(std::pow(2, 6/12.f));
    sf::Sound sound_Gsharp2(soundBuffers[0]); sound_Gsharp2.setPitch(std::pow(2, 8/12.f));
    sf::Sound sound_Asharp2(soundBuffers[0]); sound_Asharp2.setPitch(std::pow(2, 10/12.f));
    sf::Sound sound_Csharp3(soundBuffers[0]); sound_Csharp3.setPitch(std::pow(2, 13/12.f));

    sf::RectangleShape shape;
    shape.setFillColor(sf::Color::White);
    shape.setOutlineColor(sf::Color::Black);
    shape.setOutlineThickness(-1.f);
    sf::RenderWindow window(sf::VideoMode({1000, 300}), "PiaNo");
    window.setMinimumSize(window.getSize());
            window.setMaximumSize(window.getSize());

    std::vector<sf::Sound*> sounds = {&sound_D1, &sound_E1, &sound_F1, &sound_G1, &sound_A1, &sound_B1, &sound_C2, &sound_D2, &sound_E2, &sound_F2, &sound_G2, &sound_A2, &sound_B2, &sound_C3, &sound_Dsharp1, &sound_Esharp1, &sound_Fsharp1, &sound_Gsharp1, &sound_Asharp1, &sound_Csharp2, &sound_Dsharp2, &sound_Esharp2, &sound_Fsharp2, &sound_Gsharp2, &sound_Asharp2, &sound_Csharp3};

    for (auto* sound : sounds) 
    {
    sound->setVolume(300.f);
    }
    while (window.isOpen())
    {
        while (std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
                        
            else if (auto key = event->getIf<sf::Event::KeyPressed>())
            {
                 if (key->scancode == sf::Keyboard::Scan::Space) 
                 {
                    currentBufferIndex = (currentBufferIndex + 1) % 4;
                    for (auto* sound : sounds) {
                        sound->setBuffer(soundBuffers[currentBufferIndex]);
                    }
                }
                if (key->scancode == keys[0])  sound_D1.play();
                if (key->scancode == keys[1])  sound_E1.play();
                if (key->scancode == keys[2])  sound_F1.play();
                if (key->scancode == keys[3])  sound_G1.play();
                if (key->scancode == keys[4])  sound_A1.play();
                if (key->scancode == keys[5])  sound_B1.play();
                if (key->scancode == keys[6])  sound_C2.play();
                if (key->scancode == keys[7])  sound_D2.play();
                if (key->scancode == keys[8])  sound_E2.play();
                if (key->scancode == keys[9])  sound_F2.play();
                if (key->scancode == keys[10])  sound_G2.play();
                if (key->scancode == keys[11])  sound_A2.play();
                if (key->scancode == keys[12])  sound_B2.play();
                if (key->scancode == keys[13])  sound_C3.play();  
                if (key->scancode == keys[14])  sound_Dsharp1.play();
                if (key->scancode == keys[15])  sound_Fsharp1.play();
                if (key->scancode == keys[16])  sound_Gsharp1.play();
                if (key->scancode == keys[17])  sound_Asharp1.play();
                if (key->scancode == keys[18])  sound_Csharp2.play();
                if (key->scancode == keys[19])  sound_Dsharp2.play();
                if (key->scancode == keys[20])  sound_Fsharp2.play();
                if (key->scancode == keys[21])  sound_Gsharp2.play();
                if (key->scancode == keys[22])  sound_Asharp2.play();
            }
          
        }
        float window_w = window.getView().getSize().x;
        float window_h = window.getView().getSize().y;

        window.clear(sf::Color(64,64,64));
        int key_n = 14;
        float key_w = window_w / key_n;
        for (int i = 0; i < key_n; i++)
        {
            shape.setSize({key_w,window_h});
            shape.setPosition({i* key_w, 0.f});
            if (sf::Keyboard::isKeyPressed(keys[i]))
            shape.setFillColor(sf::Color(0,170,255));
            else
                shape.setFillColor(sf::Color::White);
            window.draw(shape);
            if (i == 0 or i == 1 or
                i == 3 or i == 4 or i == 5 or
                i == 7 or i == 8 or
                i == 10 or i == 11 or i == 12)
            {
                bool isPressed = false;
                if (i == 1 && sf::Keyboard::isKeyPressed(keys[14])) isPressed = true;
                if (i == 3 && sf::Keyboard::isKeyPressed(keys[15])) isPressed = true;
                if (i == 4 && sf::Keyboard::isKeyPressed(keys[16])) isPressed = true;
                if (i == 5 && sf::Keyboard::isKeyPressed(keys[17])) isPressed = true;
                if (i == 7 && sf::Keyboard::isKeyPressed(keys[18])) isPressed = true;
                if (i == 8 && sf::Keyboard::isKeyPressed(keys[19])) isPressed = true;
                if (i == 10 && sf::Keyboard::isKeyPressed(keys[20])) isPressed = true;
                if (i == 11 && sf::Keyboard::isKeyPressed(keys[21])) isPressed = true;
                if (i == 12 && sf::Keyboard::isKeyPressed(keys[22])) isPressed = true;
                shape.setFillColor(isPressed ? sf::Color::White : sf::Color::Black);
                shape.setSize({key_w/2, window_h*0.6f});
                shape.setPosition({(i-0.25f)* key_w, 0.f});
                window.draw(shape);

            }
        }
        window.display();
    }
        return 0;
}


