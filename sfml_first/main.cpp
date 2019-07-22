#include <SFML/Graphics.hpp>
#include "map.h"
#include "cells.h"
#include <iostream>

using namespace sf;

int main(){
    
    random_square();
    map_generator();
    
    
    
    RenderWindow window(sf::VideoMode(640, 480), "qq");
    
    Port cell;
    
    while (window.isOpen()){
        Event event;
        while (window.pollEvent(event)){
            if (event.type == Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(s_map);
        window.display();
    }
    
    return 0;
}
