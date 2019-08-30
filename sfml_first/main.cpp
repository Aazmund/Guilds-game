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
		{
			Vector2f currPos(j * 32, i * 32);
			switch (TileMap[i][j])
			{
			case 'P': cells.push_back(new Port(currPos)); break;
			case 'S': cells.push_back(new Sowmill(currPos)); break;
			case 'H': cells.push_back(new Horse(currPos)); break;
			case 'M': cells.push_back(new Mine(currPos)); break;
			case 0: cells.push_back(new zeroCell(currPos)); break;
			case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10: case 11: case 12: case 13: case 14: case 15: case 16: cells.push_back(new oneCell(currPos)); break;
			case '*': cells.push_back(new emptyCell(currPos)); break;
			case 'C': cells.push_back(new transitCell(currPos)); break;
			}
		}

	printf("2%c2%c2\n", 1, 49);
    
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
