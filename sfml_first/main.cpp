#include <SFML/Graphics.hpp>
#include "map.h"
#include "cells.h"
#include <iostream>

using namespace sf;

int main(){
	srand(time(0));
    random_square();
    mix_special_cell();
    map_generator();
    
    RenderWindow window(sf::VideoMode(640, 480), "qq");

	std::vector<Cell*> cells;
	//cells.push_back(new Cell());
	//cells.push_back(new Port(Vector2f(100, 100)));
	//cells.push_back(new Sowmill(Vector2f(200, 200)));
	//cells.push_back(new Horse(Vector2f(300, 300)));
	//cells.push_back(new Mine(Vector2f(400, 400)));

	for (int i = 0; i < h_map; i++)
		for (int j = 0; j < w_map; j++)
			if (TileMap[i][j] == 'P' || TileMap[i][j] == 'S' || TileMap[i][j] == 'H' || TileMap[i][j] == 'M')
			{
				switch (TileMap[i][j])
				{
				case 'P': cells.push_back(new Port(Vector2f(j * 32, i * 32))); break;
				case 'S': cells.push_back(new Sowmill(Vector2f(j * 32, i * 32))); break;
				case 'H': cells.push_back(new Horse(Vector2f(j * 32, i * 32))); break;
				case 'M': cells.push_back(new Mine(Vector2f(j * 32, i * 32))); break;
				}
			}
			else
			{
				cells.push_back(new emptyCell(Vector2f(j * 32, i * 32)));
			}
    
	for (Cell* i : cells)
	{
		i->action();
	}

    while (window.isOpen()){
        Event event;
        while (window.pollEvent(event)){
            if (event.type == Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(s_map);
		for (Cell* i : cells)
		{
			window.draw(i->get_sprite());
		}
        window.display();
    }
    
    return 0;
}
