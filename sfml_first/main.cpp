#include <SFML/Graphics.hpp>
#include "map.h"
#include "cells.h"
#include <SFML/Window/Mouse.hpp>
#include <iostream>

using namespace sf;

int main() {
	srand(time(0));
	random_square();
	mix_special_cell();
	map_generator();

	RenderWindow window(sf::VideoMode(640, 480), "qq");

	Player *currSelectedPlayer = nullptr;

	std::vector<Cell*> cells;
	std::vector<Player*> players;
	std::vector<GameDrawable*> draws;
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
			draws.push_back(cells.back());
		}
	for (int i = 0; i < 3; i++)
	{
		players.push_back(new Player(cells[i]));
		draws.push_back(players.back());
	}

	while (window.isOpen()) {

		for (Cell* c : cells)
		{
			if (Mouse::isButtonPressed(Mouse::Left))
				break;
			if (emptyCell * cl = dynamic_cast<emptyCell*>(c))
				continue;
			if (c->isPointOverSprite(Mouse::getPosition(window)))
				c->setSpriteHovered();
			else
				c->setSpriteActive();
		}

		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
			{
				for (auto p : cells)
					delete p;
				for (auto p : players)
					delete p;
				for (auto p : draws)
					delete p;
				window.close();
			}

			if (event.type == Event::MouseButtonPressed)
			{
				Vector2i mousePos = Mouse::getPosition(window);
				if (Mouse::isButtonPressed(Mouse::Button::Left))
				{	
					std::vector<GameDrawable*> pressedItems;

					for (Cell* c : cells)
					{
						if (emptyCell * cl = dynamic_cast<emptyCell*>(c))
							continue;
						if (c->isPointOverSprite(mousePos))
						{
							c->setSpritePressed();
							players[rand() % players.size()]->moveToCell(c);
							c->action();
						}
					}

					for (Player* p : players)
					{
						//if (p->isPointOverSprite(mousePos))
							//p->action();
					}

					for (GameDrawable* p : draws)
					{
						if (p->isPointOverSprite(mousePos))
						{
							pressedItems.push_back(p);
						}
					}

					/*

					for (GameDrawable* p : pressedItems)
					{
						Cell* lp = dynamic_cast<Cell*>(p);
						if (lp)
							lp->action();
						printf("'");
					}

					*/

				}
			}
		}
		window.clear();
		window.draw(s_map);
		for (GameDrawable* i : draws)
		{
			window.draw(i->get_sprite());
		}
		window.display();
	}

	return 0;
}
